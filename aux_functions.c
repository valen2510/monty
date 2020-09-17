#include "monty.h"
/**
 * error_msg - error messages
 * @error: error case
 * Return: error message and exit status 1
 */
int error_msg(int error)
{
	if (error == 0)
		printf("USAGE: monty file\n");
	else if (error == 1)
		printf("Error: Can't open file %s\n", global->argv[1]);
	else if (error == 2)
		perror("Error: malloc failed");
	else if (error == 3)
		printf("L%u: unknown instruction %s\n", global->line_num, global->array[0]);
	else if (error == 4)
		printf("L%u: usage: push integer\n", global->line_num);
	else if (error == 5)
		printf("L%u: can't pint, stack empty\n", global->line_num);
	else if (error == 6)
		printf("L%u: can't pop an empty stack\n", global->line_num);
	else if (error == 7)
		printf("L%u: can't swap, stack too short\n", global->line_num);

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
	free(global->command);
	free(global->array);
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
