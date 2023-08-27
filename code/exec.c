#include "types.h"
#include "param.h"
#include "memlayout.h"
#include "riscv.h"
#include "spinlock.h"
#include "proc.h"
#include "defs.h"
#include "elf.h"

/*  Comments looking like this are by Prof. Kivolowitz. These are the
    kind of comments that demonstrate you understand the code. These
    are the kind of comments you should strive to write.
*/

static int loadseg(pde_t *, uint64, struct inode *, uint, uint);

int flags2perm(int flags)
{
    int perm = 0;
    if(flags & 0x1)
      perm = PTE_X;
    if(flags & 0x2)
      perm |= PTE_W;
    return perm;
}

int
exec(char *path, char **argv)
{
  char *s, *last;
  int i, off;
  uint64 argc, sz = 0, sp, ustack[MAXARG], stackbase;
  struct elfhdr elf;
  struct inode *ip;
  struct proghdr ph;
  pagetable_t pagetable = 0, oldpagetable;
  struct proc *p = myproc();

    /*  begin_op() and end_op() are the logging system for the file
        system. The way these are implemented is poor. begin_op() can
        take a long time to complete AND there is no way to disable /
        enable logging at run time.
    */

  begin_op();

    /*  If the file specified in the path cannot be found, there is no
        point of continuing on. If the file is found, its inode is
        locked so that the file cannot be modified while the file is
        greedily read (i.e. all at once).
    */
  if((ip = namei(path)) == 0){
    end_op();
    return -1;
  }
  ilock(ip);

    /*  Here, the kernel's version of read() is used to load the first
        data in the file (as large as an ELF header). This version of
        read differs from the normal user version in argument 2. If 0,
        the destination buffer is in kernel space. If 1, the destination
        is in user space.

        The data comprising the ELF header is first inspected for a
        MAGIC NUMBER (the letters "ELF").

        The code found at "bad" will undo what resources have been
        allocated as we go. The use of goto here can be excused as it is
        a) far simpler construction than deep nesting and b) inside a C
        based OS where exceptions do not exist.
    */
  // Check ELF header
  if(readi(ip, 0, (uint64)&elf, 0, sizeof(elf)) != sizeof(elf))
    goto bad;

  if(elf.magic != ELF_MAGIC)
    goto bad;

    /*  Having passed the initial sniff test, a page table is allocated.
        In my opinion, there would have been benefits to reusing the
        existing page table since it is going to be freed anyway and
        functionally, it is being overlayed. Doing so would make the
        code slightly more clear.
    */
  if((pagetable = proc_pagetable(p)) == 0)
    goto bad;

    /*  The ELF header contains a the address of an array of program
        headers in the executable file. Some segments are to be expected
        such as the code+globals. After that, a programmer can pretty
        much decide how many additional segments to define (usually done
        in the linker).

        Each segment header is read and then subject to a series of
        sniff tests. One:

        if(ph.vaddr + ph.memsz < ph.vaddr)
        
        is odd. It says: if a + b < a suggesting this is a means of
        testing if memsz is negative. BUT, all these are unsigned longs
        so there are no negatives. The only way this if statement would
        be found true is if there were some exceptional garbage in these
        fields. Unlikely.

        After passing sniff tests, the segment itself is read all-at-
        once (greedy loading). Modern OS's usually do lazy loading. This
        however, would be beyond the scope of xv6 but is something that
        a student can add.

        sz depends on the simplistic view of process address space built
        into the virgin xv6. As you will see in a minute, the stack is
        wedged between the code+globals and the heap. If the stack were
        placed at the roof of the address space (a typical student
        project), sz wouldn't be adequate to describe the size of an
        application in ram.
    */
  // Load program into memory.
  for(i=0, off=elf.phoff; i<elf.phnum; i++, off+=sizeof(ph)){
    if(readi(ip, 0, (uint64)&ph, off, sizeof(ph)) != sizeof(ph))
      goto bad;
    if(ph.type != ELF_PROG_LOAD)
      continue;
    if(ph.memsz < ph.filesz)
      goto bad;
    if(ph.vaddr + ph.memsz < ph.vaddr)
      goto bad;
    if(ph.vaddr % PGSIZE != 0)
      goto bad;
    uint64 sz1;
    if((sz1 = uvmalloc(pagetable, sz, ph.vaddr + ph.memsz, flags2perm(ph.flags))) == 0)
      goto bad;
    sz = sz1;
    if(loadseg(pagetable, ph.vaddr, ip, ph.off, ph.filesz) < 0)
      goto bad;
  }

    /*  When we get here, we are finished with the executable file. Its
        inode is unlocked and the log is made to show a completed
        operation. ip is set to zero so that the inode is not unlocked
        a second time when this function exits.
    */
  iunlockput(ip);
  end_op();
  ip = 0;

    /*  myproc() is used to locate THIS proc's process table entry. The
        next line is another artifact of not reusing the same page table
        as I highlighted above.
    */
  p = myproc();
  uint64 oldsz = p->sz;

    /*  Here, the stack is allocated coming after a guard page. The
        stack is limited in size to one page because it is landlocked.

        Next, the data pointed to be argv is copied over to the user's
        stack area and argv is updated to point to the data. After that
        argv array itself is copied into the block of stack data.
    */

  // Allocate two pages at the next page boundary.
  // Make the first inaccessible as a stack guard.
  // Use the second as the user stack.
  sz = PGROUNDUP(sz);
  uint64 sz1;
  if((sz1 = uvmalloc(pagetable, sz, sz + 2*PGSIZE, PTE_W)) == 0)
    goto bad;
  sz = sz1;
  uvmclear(pagetable, sz-2*PGSIZE);
  sp = sz;
  stackbase = sp - PGSIZE;

  // Push argument strings, prepare rest of stack in ustack.
  for(argc = 0; argv[argc]; argc++) {
    if(argc >= MAXARG)
      goto bad;
    sp -= strlen(argv[argc]) + 1;
    sp -= sp % 16; // riscv sp must be 16-byte aligned
    if(sp < stackbase)
      goto bad;
    if(copyout(pagetable, sp, argv[argc], strlen(argv[argc]) + 1) < 0)
      goto bad;
    ustack[argc] = sp;
  }
  ustack[argc] = 0;

  // push the array of argv[] pointers.
  sp -= (argc+1) * sizeof(uint64);
  sp -= sp % 16;
  if(sp < stackbase)
    goto bad;
  if(copyout(pagetable, sp, (char *)ustack, (argc+1)*sizeof(uint64)) < 0)
    goto bad;

    /*  The trapframe contains the registers that will be restored into
        the process when it starts running. The location of argv array
        (the last thing to go onto the user's stack [so far]) is put
        where it needs to be to be picked up as the second argument to
        main().
    */

  // arguments to user main(argc, argv)
  // argc is returned via the system call return
  // value, which goes in a0.
  p->trapframe->a1 = sp;

    /*  This is finding the root name of the executable program. e.g.
        a.out. This name is stuffed into the process table.
    */
  // Save program name for debugging.
  for(last=s=path; *s; s++)
    if(*s == '/')
      last = s+1;
  safestrcpy(p->name, last, sizeof(p->name));
    
    /*  Here, some of this code could be eliminated has the existing
        page table been reused. Oh where. The proc_freepagetable() had
        to be called in any case.
    */
   
  // Commit to the user image.
  oldpagetable = p->pagetable;
  p->pagetable = pagetable;
  p->sz = sz;
  p->trapframe->epc = elf.entry;  // initial program counter = main
  p->trapframe->sp = sp; // initial stack pointer
  proc_freepagetable(oldpagetable, oldsz);

  return argc; // this ends up in a0, the first argument to main(argc, argv)

 bad:
  if(pagetable)
    proc_freepagetable(pagetable, sz);
  if(ip){
    iunlockput(ip);
    end_op();
  }
  return -1;
}

// Load a program segment into pagetable at virtual address va.
// va must be page-aligned
// and the pages from va to va+sz must already be mapped.
// Returns 0 on success, -1 on failure.
static int
loadseg(pagetable_t pagetable, uint64 va, struct inode *ip, uint offset, uint sz)
{
  uint i, n;
  uint64 pa;

  for(i = 0; i < sz; i += PGSIZE){
    pa = walkaddr(pagetable, va + i);
    if(pa == 0)
      panic("loadseg: address should exist");
    if(sz - i < PGSIZE)
      n = sz - i;
    else
      n = PGSIZE;
    if(readi(ip, 0, (uint64)pa, offset+i, n) != n)
      return -1;
  }
  
  return 0;
}
