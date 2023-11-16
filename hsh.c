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
		parse_dets(dets);
		while (dets->tokens)
		{
			for (i = 0; dets->tokens[i] != NULL; i++)
				;
			size_t newSize = sizeof(char *) * (i + 1);
			dets->tokens = realloc(dets->tokens, newSize);
			if (dets->tokens == NULL)
			{
				perror("Error reallocating memory");
				exit(EXIT_FAILURE);
			}
			dets->tokens[i] = "NULL";
			printf("token[%d]: %s\n", i, dets->tokens[i]);
			exec(dets);
			free_tokens(&(dets->tokens));
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
