#include "monty.h"
/**
 * main - Entry point
 * @argc: number ofarguments in command line
 * @argv: string of elements from the command line
 * Return: (EXIT_SUCCESS) or (EXIT_FAILURE)
 */
int main(int argc, char **argv)
{
	size_t line_size = 0;
	unsigned int line_number = 1;

	global = malloc(sizeof(global_t));
	if (global == NULL)
		return (error_msg(2));
	initialize(global, argv);

	if (argc != 2)
		return (error_msg(0));

	global->fp = fopen(argv[1], "r");
	if (!global->fp)
		return (error_msg(1));

	global->arr = malloc(sizeof(char *) * 100);
	if (!global->arr)
		return (error_msg(2));
	while (getline(&global->command, &line_size, global->fp) != -1)
	{
		global->ln = line_number++;
		splitline(global->command);
		if (global->arr[0] == NULL)
			continue;
		op_func()(&global->stack, line_number);
		free(global->command);
		global->command = NULL;
		line_size = 0;
	}
	free_all();
	return (EXIT_SUCCESS);
}
