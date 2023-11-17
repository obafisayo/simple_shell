#include "hsh.h"

/**
 * main - This is the main entry point
 * @argc: This is the argument count
 * @argv: This is the argument vector
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	dets_t *dets = init_dets(argc, argv);

	signal(SIGINT, _sigint);
	while (read_input(dets))
	{
		dets->commands = cmd_to_list(dets->line);
		while ((dets->tokens = pop_cmd(&(dets->commands))))
		{
			exec(dets);
			free_tokens(&(dets->tokens));
		}
		free(dets->line);
		dets->line = NULL;
	}
	if (dets->from_terminal)
		write(STDOUT_FILENO, "\n", 1);
	if (dets->file)
		close(dets->filenom);
	exit(free_dets(dets));
}
