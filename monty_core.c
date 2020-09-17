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
		if (global->arr[0] != NULL)
		{
			if ((strcmp(global->arr[0], op_func[i].opcode)) == 0)
			return (op_func[i].f);
		}
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
		global->arr[position] = word;
		word = strtok(NULL, " \n\t");
		position++;
	}
	global->arr[position] = NULL;
	return (global->arr);
}
/**
 * _atoi - convert sring into integer
 * @s: pointer
 * Return: integer
 */
int _atoi(char *s)
{
	int sign = 0;
	unsigned int r = 0;

	while (*s != '\0')
	{
		if (*s == '-')
			sign++;

		else if (*s >= '0' && *s <= '9')
			r = r * 10 + (*s - '0');

		else if (r > 0)
			break;
		s++;
	}
	if (sign % 2 != 0)
		return (r * -1);

	return (r);
}
