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
	(void)line_number;

	if (!(*stack))
		exit(error_msg(5));

	if ((*stack)->n < 0  || (*stack)->n > 127)
		exit(error_msg(9));

	printf("%c\n", (char)(*stack)->n);
}
/**
 ** pstr - print the string started at the top of the stack
 * @stack: head of the stack
 * @line_number: number of current line
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;
	(void)line_number;

	while (current_node)
	{
		if (current_node->n == 0)
			break;

		if (current_node->n < 0 || current_node->n > 127)
			break;

		putchar(current_node->n);
		current_node = current_node->next;
	}
	putchar('\n');
}
/**
 ** rotl - change head of the stack at the end
 * @stack: head of the stack
 * @line_number: number of current line
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (tail->next)
		tail = tail->next;
	tail->next = *stack;
	tail->next->prev = tail;
	*stack = (*stack)->next;
	tail->next->next = NULL;
	(*stack)->prev = NULL;
}
/**
 ** rotr - reverse the elements in a stack
 * @stack: head of the stack
 * @line_number: number of current line
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *tail;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	tail = *stack;
	while (tail->next)
		tail = tail->next;

	tail->prev->next = tail->next;
	tail->next = *stack;
	tail->prev = (*stack)->prev;
	(*stack)->prev = tail;
	*stack = tail;
}
