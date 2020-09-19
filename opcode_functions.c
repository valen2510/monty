#include "monty.h"
/**
 * push - push a new element in the stack
 * @stack: stack
 * @line_number: line number or the command
 */
void push(stack_t **stack, unsigned int line_number)
{
	int i = 0;

	global->ln = line_number;
	global->stack = *stack;

	if (global->arr[1] == NULL)
		exit(error_msg(4));

	for (; global->arr[1][i] != '\0'; i++)
	{
		if ((isdigit(global->arr[1][i]) == 0) && global->arr[1][0] != '-')
			exit(error_msg(4));
	}

	if (global->status == 0)
		add_node_stack();
	else
		add_node_queue();

}
/**
 * pall - print the elements in a stack
 * @stack: stack
 * @line_number: line number or the command
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_stack = *stack;

	global->ln = line_number;

	while (aux_stack != NULL)
	{
		printf("%d\n", aux_stack->n);
		aux_stack = aux_stack->next;
	}

}
/**
 * pint - get the value of the top of the stack
 * @stack: stack
 * @line_number: line number or the command
 */
void pint(stack_t **stack, unsigned int line_number)
{
	global->ln = line_number;
	global->stack = *stack;

	if ((*stack) == NULL)
		exit(error_msg(5));
	printf("%d\n", (*stack)->n);
}
/**
 * pop - delete the top of the stack
 * @stack: stack
 * @line_number: line number or the command
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *top_element;

	global->ln = line_number;

	if (!(*stack))
		exit(error_msg(6));

	top_element = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(top_element);

}
/**
 * swap - interchange the values of the first two elements in a stack
 * @stack: stack
 * @line_number: line number or the command
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int num;

	global->ln = line_number;
	global->stack = *stack;

	if (!(*stack) || !((*stack)->next))
		exit(error_msg(7));

	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}

