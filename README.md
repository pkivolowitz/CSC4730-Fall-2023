<<<<<<< HEAD
# CSC4730-Fall-2023

## Meetings

| Days | Times | Room |
| ---- | ----- | ---- |
| TR | 2:20 PM to 4:00 PM | CC 114 |

## Office hours

All office hours are held via [ZOOM](
<https://carthage-edu.zoom.us/j/4456320007?pwd=UmZNa3ZDOTI2NHdhR21sSmxDR21KUT09>).
This link will remain valid all term.

| Day | Times |
| --- | ----- |
| M | 11 AM to 12 PM |
| T | 11 AM to 12 PM |
| R | 7 PM to 9 PM |
| F | 12 PM to 1 PM |

## Texts

Primary: [OSTEP](<https://pages.cs.wisc.edu/~remzi/OSTEP/>) This book is
free.

Ancillary:

1. Required: Advanced Programming in the UNIX environment, third
   edition. Will be called Stevens and Rago.

2. [xv6
   risc-v](<https://pdos.csail.mit.edu/6.S081/2020/xv6/book-riscv-rev1.pdf>)
   This book is free.

## Readings

There are two types of readings in this class.

1. Assigned readings will come from OSTEP.

2. Unassigned readings will come from the two ancillary texts. Being
unassigned, you will **not** be told when to do them. Instead, review
the table of contents in each of the two ancillary sources to get a
general idea of that they contain. Then, later in the course, when you
have a question, review the ancillary texts for details.

### Topics covered

The following are the topics which we can expect to be covered:

| OSTEP | Topic | OSTEP | Topic |
| ----- | ----- | ----- | ----- |
|  4 | Processes | 21 | Swapping Mechanisms |
|  5 | Process API | 22 | Swapping Policies |
|  6 | Direct Execution | 23 | Complete VM System |
|  7 | CPU Scheduling | 26 | Concurrency and Threads |
|  8 | Multi-level Feedback | 27 | Thread API |
|  9 | Lottery Scheduling | 28 | Locks |
| 10 | Multi-CPU Scheduling | 29 | Locked Data Structures |
| 13 | Address Spaces | 30 | Condition Variables |
| 14 | Memory API | 31 | Semaphores |
| 15 | Address Translation | 32 | Concurrency Bugs |
| 16 | Segmentation | 33 | Event-based Concurrency |
| 17 | Free Space Management | 34
| 18 | Introduction to Paging |
| 19 | Translation Lookaside Buffers |
| 20 | Advanced Page Table |


### man pages

Since early days, Unix has had the `man` command. For example:

`man man`

or

`man 2 chdir`

## Late work

Late work (factoring in one free grace day) will not be accepted. To
state this differently, if an assignment is due on day *n*, you have
until the end of day *n + 1* to turn it in. After that, it will not
be accepted.

## Attendance

Attendance will be taken at nearly every class. The only exceptions will
be when I am so excited to get down to business, that I forget to take
it.

You get 6 free absences. After that each absence will remove 1 percent
from your aggregate score at the end of the term. All absences are
treated equally. That is, there are no "excused" absences. The number
of free absences equates to three weeks of missed class time so it is
unlikely you'll exceed this and incur a penalty.

## Being late

Once attendance has been taken, anyone arriving after than will be
counted as absent. Generally, attendance will end between five and ten
minutes after the official start of class.

## Leaving early

No, your coach cannot force you to leave class early to make practice.

## Essays

[Here](./therac.md) is a link to one essay assignment. You can look at
it at your convenience but do it only when assigned.

## Projects

Below is a listing of 10 projects of which only 8 are truly projects.
One is a tutorial and another is just to provide proof you're ready to
tackle two other projects.

| Ordinal | Project | Space | Notes |
| ------- | ------- | ----- | ----- |
| - | `getopt` | User | WSL or terminal |
| 1 | Shell | User | WSL or terminal |
| - | Working xv6 | N/A | N/A |
| 2 | Add System Call | Kernel | xv6-riscv |
| 3 | Add Guard Page | Kernel | xv6-riscv |
| 4 | Stride Scheduler | User | WSL or terminal |
| 5 | MLFQ Scheduler | User | WSL or terminal |
| 6 | Semaphores | User | WSL or terminal |
| 7 | Named Pipe | User | WSL or terminal |
| 8 | File System | User | WSL of terminal |
=======
# Syllabus CSC4730-Fall-2023

## Course Summary

In this course you will not only open the curtain to see the wizard, you
will strip the clothes off the wizard revealing their deepest secrets.

The biggest parts of this course:

* We will cover nearly all of the great free textbook: OSTEP - Operating
Systems in Three Easy Pieces. This book is written at a popular level
and is very accessible.

* We will leverage the Unix programming environment in a deep and
meaningful way. You will learn deeply marketable skills.

* We will do up to 9 projects both inside an OS itself and in userland
programs.

## Learning Outcomes

There are too many learning outcomes in this course to name them all.
You can see this in the projects [table](#projects) under the column
*OSTEP* and *S&R*.

These four learning outcomes are highlighted:

1. At the end of this course, students will be able to design and
implement complex multi-process and threaded applications.

2. At the end of this course, students will be able to design and
implement  various synchronization schemes using mutexes, condition
variables and semaphores.

3. At the end of this course, students will have mastered user level
memory allocation schemes including free space management.

## Textbooks

| Title | Source | Cost | Required? |
| ----- | ------ | ---- | --------- |
| OSTEP | [LINK](<https://pages.cs.wisc.edu/~remzi/OSTEP/>) | Free | Yes |
| Advanced Programming in the UNIX Environment | Bookstore | ~$60 | Yes |
| XV6 Book | [LINK](https://pdos.csail.mit.edu/6.S081/2020/xv6/book-riscv-rev1.pdf) | Free | Strongly Advised |

## Grading Criteria

| Gradable Component | Weight  | Notes   |
| ------------------ | ------: | -----   |
| Projects           | 92%     |         |
| Attendance         | 6%      |         |
| `getopt`           | 1%      | warm up |
| `working xv6`      | 1%      | warm up |

## Attendance

Absences for any reason count.

| Number | Penalty |
| ------ | ------- |
| 0 - 4  | 0% |
| 5 - 6  | 2% |
| 7 - 8  | 4% |
| 9+     | 6% |

Should a long term absence due to uncontrollable circumstances become
necessary, please speak to me.

## Projects

The *Weight* column provides a weighting of the project within the
Project Grading Component. It suggests my anticipation of the relative
difficulty of each project compared to the others.

The *OSTEP* column indicates how the projects correspond to course
material. The indicated chapters will be most helpful.

The *S&R* column indicates which chapters of Stevens and Rago can be
helpful.


| # | Project       | Space  | Weight  | OSTEP      | S&R |
| - | -------       | -----  | ------: | -----      | --- |
| - | `getopt`      | User   | N/A     | N/A        | N/A |
| 1 | Shell         | User   |  70     | 4, 5       | 1, 3, 4, 5, 8, 15 |
| - | Working xv6   | N/A    |  N/A    | N/A        | N/A |
| 2 | System Call   | Kernel |  60     | 6          | N/A |
| 3 | Stride / MLFQ | User   |  70     | 7, 8, 9    | N/A |
| 4 | Guard Page    | Kernel |  60     | 13         | N/A |
| 5 | Move Stack    | Kernel |  90     | 14, 15, 16 | N/A |
| 6 | Free Space    | User   |  70     | 17         | 7   |
| 7 | Semaphores    | User   |  70     | 26, 27, 28, 29, 30, 31 | 8, 11, 12 |
| 8 | Named Pipe    | User   |  90     | 14, 17, 26, 27, 28, 29, 30, 31 | 8, 11, 12 |
| 9 | FSCK          | User   |  100    | 39, 40, 42 | 3, 4, 5 |

### Project Partners

* You are **required** to use a partner for all non-warmup projects.

* You are **prohibited** from using the same partner twice.

* Your partner will be **assigned** to you by me.

* Members of the team must be specified by the partner handing in the
project within the code they are handing in.

* The partner not handing in the project must submit a text file stating
who their partner is.

* Both partners receive the same grade.

* Any partnership problems should be worked out by you but I can step in
if necessary.

### Project Requirements

* Requirements are spelled out in each specification.

* Any deviation from the specification results in penalties.

* Generating even a single warning during building your own code will
result in a 10 percent penalty.

* Commenting is required. Failure to adequately comment is a mandatory 5
percent penalty.

### Extensions

There will be none. The due date is the due date.

### Warmup Projects

Follow the specification, take a picture of the screen and turn in the
picture.

## Office Hours

I will have five hours per week available for individual help.

* Monday 11 AM to Noon.

* Tuesday 11 AM to Noon.

* Wednesday 2 PM to 3 PM.

* Thursday nights from 7 to 9 PM (two hours) during the weekly BBQ.

All of these will be conducted via Zoom.

There will be no other hours offered.
>>>>>>> e34e356a2886e4903cb8409f64322823d8563ac1
