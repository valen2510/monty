#include "monty.h"
/**
 * error_msg - error messages
 * @error: error case
 * Return: error message and exit status 1
 */
int error_msg(int error)
{
	if (error == 0)
		fprintf(stderr, "USAGE: monty file\n");
	else if (error == 1)
		fprintf(stderr, "Error: Can't open file %s\n", global->argv[1]);
	else if (error == 2)
		fprintf(stderr, "Error: malloc failed\n");
	else if (error == 3)
		fprintf(stderr, "L%u: unknown instruction %s\n", global->ln, global->arr[0]);
	else if (error == 4)
		fprintf(stderr, "L%u: usage: push integer\n", global->ln);
	else if (error == 5)
		fprintf(stderr, "L%u: can't pint, stack empty\n", global->ln);
	else if (error == 6)
		fprintf(stderr, "L%u: can't pop an empty stack\n", global->ln);
	else if (error == 7)
		fprintf(stderr, "L%u: can't swap, stack too short\n", global->ln);
	else if (error == 8)
		fprintf(stderr, "L%u: can't add, stack too short\n", global->ln);

	free_all();
	exit(EXIT_FAILURE);
}
/**
 * free_all - free all the memory allocated and close open files
 */
void free_all(void)
{
	if (global->stack != NULL)
		free_stack(global->stack);
	if (global->command != NULL)
		free(global->command);
	if (global->arr != NULL)
		free(global->arr);
	if (global->fp != NULL)
		fclose(global->fp);

	free(global);
}
/**
 * free_stack - free the elements of a stack
 * @stack: head of the stack (top)
 */
void free_stack(stack_t *stack)
{
	stack_t *current_node;

	while (stack)
	{
		current_node = stack;
		stack = stack->next;
		free(current_node);
	}
}
