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
project.

* The partner not handing in the project must submit a text file stating
who their partner is.

* Both partners receive the same grade.

* Any partnership problems must be worked out by you.

### Project Requirements

* Requirements are spelled out in each specification.

* Any deviation from the specification results in penalties.

* Generating even a single warning during building your own code will
result in a 10 percent penalty.

* Commenting is required. Failure to adequately comment is a mandatory 5
percent penalty.

### Warmup Projects

Follow the specification, take a picture of the screen and turn in the
picture.
