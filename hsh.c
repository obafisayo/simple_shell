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
	int i;

	dets_t *dets = init_dets(argc, argv);

	signal(SIGINT, _sigint);
	while (read_dets(dets))
	{
		dets->tokens = split_string(dets->line, " ");
		for (i = 0; dets->tokens[i] != NULL; i++)
		{
			printf("token[%d]: %s\n", i, dets->tokens[i]);
		}
		exec(dets);
		if (dets->tokens != NULL)
		{
			free_string_array(dets->tokens);
			dets->tokens = NULL;
		}
	}
	if (dets->from_terminal)
		write(STDOUT_FILENO, "\n", 1);
	if (dets->file)
		close(dets->filenom);
	exit(free_dets(dets));
}
