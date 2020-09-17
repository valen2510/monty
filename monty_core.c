#include "monty.h"
/**
 ** op_func - get the operation at the given commands
 * @stack: hed of the stack
 * Return: Operation perfoming or message error
 */
void (*op_func(stack_t **stack))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{NULL, NULL}
	};
	global->stack = *stack;
	for (i = 0; op_func[i].opcode != NULL; i++)
	{
		if ((strcmp(global->array[0], op_func[i].opcode)) == 0)
			return (op_func[i].f);
	}
	exit(error_msg(3));
}
/**
 * splitline - get line from the file and locate it in global.array
 * @line: line string.
 * Return: array of strings.
 */
char **splitline(char *line)
{
	int position = 0;
	char *word;

	word = strtok(line, " \n\t");
	while (word != NULL)
	{
		global->array[position] = word;
		word = strtok(NULL, " \n\t");
		position++;
	}
	global->array[position] = NULL;
	return (global->array);
}
