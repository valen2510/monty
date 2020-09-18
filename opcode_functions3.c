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

	if ((*stack)->n < 0  || (*stack)->n > 128)
		exit(error_msg(9));

	printf("%c\n", (char)(*stack)->n);
}
/**
 ** rotl - change head of the stack at the end
 * @stack: head of the stack
 * @line_number: number of current line
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_head, *tail = *stack;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (tail->next)
		tail = tail->next;
	aux_head = (*stack)->next;
	(*stack)->next = tail->next;
	(*stack)->prev = tail;
	tail->next = *stack;
	aux_head->prev = NULL;
	*stack = aux_head;
}
/**
 ** rotr - reverse the elements in a stack
 * @stack: head of the stack
 * @line_number: number of current line
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node, *next_node;
	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;

	current_node = NULL;
	while (*stack)
	{
		next_node = (*stack)->next;
		(*stack)->prev = next_node;
		(*stack)->next = current_node;
		current_node = *stack;
		*stack = next_node;
	}
	*stack = current_node;
}
