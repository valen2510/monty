#include "monty.h"
/**
 ** mod - get the result of module between two elements
* @stack: head of the stack
 * @line_number: number of current line
 */
void mod(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	if (!(*stack) || !(*stack)->next)
		exit(error_msg(7));

	if ((*stack)->n == 0)
		exit(error_msg(8));

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}
/**
 ** pchar - get the character at an elelement
 * @stack: head of the stack
 * @line_number: number of current line
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	global->ln = line_number;

	if (!(*stack))
		exit(error_msg(5));

	if ((*stack)->n < 0  && (*stack)->n > 128)
		exit(error_msg(9));

	printf("%c\n", (*stack)->n + '0');

}
