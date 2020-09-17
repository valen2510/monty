#include "monty.h"
/**
 * main - Entry point
 * @argc: number ofarguments in command line
 * @argv: string of elements from the command line
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE)
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t line_size = 0;
	unsigned int line_number = 1;
	stack_t *head = NULL;

	global = malloc(sizeof(global_t));
	if (!global)
		return (error_msg(2));

	global->argv = argv;
	if (argc != 2)
		exit(error_msg(0));

	global->fp = fopen(argv[1], "r");
	if (!global->fp)
		exit(error_msg(1));

	global->array = malloc(sizeof(char *) * 10);
	if (!global->array)
		return (error_msg(2));

	while (getline(&line, &line_size, global->fp) != -1)
	{
		splitline(line);
		global->command = line;
		global->line_num = line_number;
		op_func(&head)(&head, line_number);
		line_number++;
	}
	free_all();
	exit(EXIT_SUCCESS);
}
