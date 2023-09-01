/*  Author: Perry Kivolowitz
            Chair, Computer Science at Carthage College.
            
    An example of exec'ing demonstrating that the address space
    of a process really is overlaid by the code of another program.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int test_variable = 0;

/*  This program will cause an exec to itself. Notice the pid (process
    id) stays the same. Notice the value passed to the new process is
    incremented by 1 showing that it is a new process.
*/

int main(int argc, char ** argv) {
    if (argc != 2) {
        printf("Not invoked correctly!\n");
        printf("Use: ./a.out 1\n");
        exit(1);
    }
    int argument = atoi(argv[1]);

    char buffer[256];
    printf("PID: %d invoked with argument: %d --- ^C to end\n", 
        getpid(), argument);
    argument++;
	sprintf(buffer, "%d", argument);
	execl("./a.out", "a.out", buffer, 0);
    printf("Should not be able to get past the exec.\n");
	exit(1);
}
