#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct var_global - global variables for monty interpreter
 * @arr: array for command arguments
 * @argv: arguments from the prompt
 * @ln: number of the line that is being processed
 * @command: command entered in array[0]
 * @fp: poniter to object in stream
 * @stack: pointer to stack
 *
 * Description: global variables for monty interpreter
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct var_global
{
	char **arr;
	char **argv;
	unsigned int ln;
	char *command;
	FILE *fp;
	stack_t *stack;
} global_t;
global_t *global;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void (*op_func(stack_t **stack))(stack_t **stack, unsigned int line_number);
char **splitline(char *line);
int _atoi(char *s);
int error_msg(int error);
void free_all(void);
void free_stack(stack_t *stack);
#endif
