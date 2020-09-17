#include "monty.h"
/**
 * push - push a new element in the stack
 * @stack: stack
 * @line_number: line number or the command
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_element = NULL;

	global->line_num = line_number;
	global->stack = *stack;

	if (global->array[1] == NULL)
		exit(error_msg(4));

	new_element = malloc(sizeof(stack_t));
	if (!new_element)
		exit(error_msg(2));

	new_element->n = atoi(global->array[1]);

	if (!(*stack))
	{
		new_element->prev = NULL;
		new_element->next = NULL;
		*stack = new_element;
	}
	else
	{
		new_element->next = *stack;
		new_element->prev = (*stack)->prev;
		(*stack)->prev = new_element;
		*stack = new_element;
	}
}
/**
 * pall - print the elements in a stack
 * @stack: stack
 * @line_number: line number or the command
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *aux_stack = *stack;

	while (aux_stack != NULL)
	{
		printf("%d\n", aux_stack->n);
		aux_stack = aux_stack->next;
	}
	(void)line_number;
}
/**
 * pint - get the value of the top of the stack
 * @stack: stack
 * @line_number: line number or the command
 */
void pint(stack_t **stack, unsigned int line_number)
{
	global->line_num = line_number;
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

	if (!(*stack))
		exit(error_msg(6));

	top_element = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;
	free(top_element);
	(void)line_number;
}
/**
 * swap - interchange the values of the first two elements in a stack
 * @stack: stack
 * @line_number: line number or the command
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int num;

	global->line_num = line_number;
	global->stack = *stack;

	if (!(*stack) || !((*stack)->next))
		exit(error_msg(7));

	num = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = num;
}

