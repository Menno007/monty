#ifndef MONTY_H
#define MONTY_H
#define  _GNU_SOURCE
#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void sub(stack_t **head, unsigned int line_number);
void divf(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void mod(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void pchar(stack_t **head, unsigned int line_number);
void pstr(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void _free(stack_t **head);
int check_intger(char *data);
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
void (*get_func(char *s, int line_number))(stack_t **, unsigned int);

/**
 * struct global_s - I just use one global variable
 * @file: file pointer to close it before any exit
 * @line: the current line in the file to read  it
 * @is_stack: specifies mode of the data structure
 */
typedef struct global_s
{
	FILE *monty_file;
	char *line;
	int is_stack;
} global_t;
extern global_t G;

#endif
