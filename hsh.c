#include "hsh.h"

/**
 * main - This is the main entry point
 * @argc: This is the argument count
 * @argv: This is the argument vector
 * 
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	dets_t *dets = init_dets(argc, argv);

	signal(SIGINT, _sigint);
	while (read_dets(dets))
	{
		parse_dets(dets);
		while (dets->tokens)
		{
			exec(dets);
		}
		while (_strcmp(*dets->tokens, "env") == 0)
		{
			printf("%s=%s\n", dets->envt->key, dets->envt->value);
			dets->envt = dets->envt->next_node;
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
