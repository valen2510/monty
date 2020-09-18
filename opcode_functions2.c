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
		exit(error_msg(7));

	result = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = result;
	pop(stack, line_number);

}
/**
 * sub - subtract the  first elements with the second in a stack
 * @stack: stack
 * @line_number: line number or the command
 */
void sub(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!(*stack) || !(*stack)->next)
		exit(error_msg(7));

	(*stack)->next->n -= (*stack)->n;
	pop(stack, line_number);

}
/**
 * _div - divide the two first elements in a stack
 * @stack: stack
 * @line_number: line number or the command
 */
void _div(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!(*stack) || !(*stack)->next)
		exit(error_msg(7));
	if ((*stack)->n == 0)
		exit(error_msg(8));

	(*stack)->next->n /= (*stack)->n;
	pop(stack, line_number);

}
/**
 * mul - multiply the two first elements in a stack
 * @stack: stack
 * @line_number: line number or the command
 */
void mul(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!(*stack) || !(*stack)->next)
		exit(error_msg(7));

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);

}
