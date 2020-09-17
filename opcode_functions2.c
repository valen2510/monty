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
}
/**
 * add - add the two first elements in a stack
 * @stack: stack
 * @line_number: line number or the command
 */
void add(stack_t **stack, unsigned int line_number)
{
	int result;
	(void)line_number;
	if (!(*stack) || !(*stack)->next)
		exit(error_msg(8));

	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	pop(stack, line_number);

}
