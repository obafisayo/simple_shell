#include "hsh.h"

/**
 * main - entry point
 * @argc: the argument count
 * @argv: the argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	dets_t *dets = init_dets(argc, argv);

	signal(2, _sigint);

	while (read_input(dets))
	{
		parse(dets);
		while ((dets->tokens = pop_cmd(&(dets->commands))))
		{
			execute(dets);
			free_tokens(&(dets->tokens));
		}
		free(dets->line);
		dets->line = NULL;
	}
	if (dets->interactive)
		write(STDOUT_FILENO, "\n", 1);

	if (dets->file)
		close(dets->fileno);

	exit(free_dets(dets));
}
