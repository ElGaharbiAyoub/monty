# Stacks, Queues - LIFO, FIFO

## About

- This is an introductory project that explains:
- What do LIFO and FIFO mean
- What is a stack, and when to use it
- What is a queue, and when to use it
- What are the common implementations of stacks and queues
- What are the most common use cases of stacks and queues
- What is the proper way to use global variables
- How to work with git submodules

## Requirements

- Ubuntu 20.04 LTS
- GCC with flags: -Wall -Werror -Wextra -pedantic -std=c89
- Use the Betty style. It will be checked using betty-style.pl and betty-doc.pl

## Installation

1. Clone the repository
   `https://github.com/ElGaharbiAyoub/monty`

2. Compile the program
   `gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty`

3. Run the program as follows:

- Usage: `monty <file.m>`
- Ex: `./monty ./bytecodes/00.m`

There are multiple `.m` files to choose from in the bytcodes files that run different Opcode functionality. Below is a table of all the Opcode options. Each file in the bytcodes folder contains different Opcodes that run their specific functionality.

| Opcode Name  | Opcode Description                                                                                      |
| :----------: | :------------------------------------------------------------------------------------------------------ |
|     push     | _pushes an element on to the stack_                                                                     |
|     pall     | _prints all the values on the stack, starting from the top_                                             |
|     pint     | _prints the value at the top of the stack_                                                              |
|     pop      | _removes the top element of the stack_                                                                  |
|     swap     | _swaps the top two elements of the stack_                                                               |
|     add      | _adds the top two elements of the stack_                                                                |
|     nop      | _doesn't do anything_                                                                                   |
|     sub      | _subtracts the top element of the stack from the second top element of the stack_                       |
|     div      | _divides the second top element of the stack by the top element of the stack_                           |
|     mul      | _multiplies the second top element of the stack with the top element of the stack_                      |
|     mod      | _computes the modulus of the second top element of the stack by the top element of the stack_           |
| comments (#) | _add a # to the beginning of the line to comment in the file_                                           |
|    pchar     | _prints the ASCII equivalent of the number at the top of the stack_                                     |
|     pstr     | _prints the ASCII equivalent of the numbers stored in each element in the stack, starting from the top_ |
|     rotl     | _rotates the top element of the stack to the bottom of the stack_                                       |
|     rotr     | _rotates the bottom element of the stack to the top of the stack_                                       |

## Example

```
elgharbi@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
elgharbi@ubuntu:~/monty$ ./monty ./bytecodes/000.m
3
2
1
0
6
5
4
3
2
1
0
elgharbi@ubuntu:~/monty$
```

## Other files

- monty.h - _Header file; Contains function, struct and global variable declarations_
- bytecodes - _A directory containing test files used while making this program_

## Bugs

No bugs found yet

## Authors

- El Gharbi Ayoub
- Abdelilah Bouchikhi
