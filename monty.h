#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct buf_struct - Global buffers.
 * @read_buff: Buffer for read.
 * @list_cmd: Tokenized read buffer.
 * @tok_cmd: Tokenize each token from previous split based on spaces.
 * @argv: Arguments from command line.
 *
 * Description: - Buffers used globally throughout files.
 */
typedef struct buf_struct
{
	char *list_cmd[1000];
	char *tok_cmd[1000];
	char **argv;
} buf_struct;



char **split_line(char *line, buf_struct *bf);
int digits_only(char* str);
buf_struct *make_struct(char *argv[]);
void readLinesFromFile(char* filename, buf_struct *bf);
void free_stack(stack_t *head);
void execute_fun(buf_struct *bf);
int is_empty_line(char *line);
void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number);



/* functions monty*/

stack_t *push(stack_t **head, int n);
void pall_f( stack_t **head, unsigned int line);
void pint_f( stack_t **head, unsigned int line);
void pop_f(stack_t **head, unsigned int line);
void swap_f(stack_t **head, unsigned int line);
void add_f(stack_t **head, unsigned int line);
void nop_f(stack_t **head, unsigned int line);
void add_f(stack_t **head, unsigned int line);
void sub_f(stack_t **head, unsigned int line);
void div_f(stack_t **head, unsigned int line);
void mul_f(stack_t **head, unsigned int line);
void mod_f(stack_t **head, unsigned int line);
void pchar_f(stack_t **head, unsigned int line);
void pstr_f(stack_t **head, unsigned int line);
void rotr_f(stack_t **head, unsigned int line);
void rotl_f(stack_t **head, unsigned int line);
#endif
