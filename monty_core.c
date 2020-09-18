#include "monty.h"
/**
 ** op_func - get the operation at the given commands
 * Return: Operation perfoming or message error
 */
void (*op_func(void))(stack_t **stack, unsigned int line_number)
{
	int i;

	instruction_t op_func[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};

	for (i = 0; op_func[i].opcode != NULL; i++)
	{
		if (global->arr[0] != NULL)
		{
			if ((strcmp(global->arr[0], op_func[i].opcode)) == 0)
			{
				global->op = op_func[i].opcode;
				return (op_func[i].f);
			}
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
