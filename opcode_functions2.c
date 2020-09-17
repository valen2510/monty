#include "monty.h"
/**
 * nop - this function doesn't do anything
 * @stack: stack
 * @line_number: line number or the command
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	(void)stack;
	exit(EXIT_SUCCESS);
}
