#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "dets.h"

/**
 * init_dets - initialize shell dets
 * @argc: the arg count
 * @argv: the arg values
 * Return: pointer to the dets
 */
dets_t *init_dets(int argc, char **argv)
{
	static dets_t dets;
	char *error = NULL;

	dets.argc = argc;
	dets.argv = argv;
	dets.fileno = STDIN_FILENO;
	if (argc > 1)
	{
		dets.file = argv[1];
		dets.fileno = open(dets.file, O_RDONLY);
		if (dets.fileno == -1)
		{
			error = strjoin(NULL, " ", "Can't open", dets.file);
			perrorl_default(*argv, dets.lineno, error, NULL);
			free(error);
			dets.status = 127;
			exit(free_dets(&dets));
		}
	}
	dets.interactive = isatty(dets.fileno);
	dets.pid = getpid();
	dets.cwd = getcwd(NULL, 0);
	dets.env = env_to_dict(environ);
	return (&dets);
}


/**
 * free_dets - free and nullify dynamically allocated dets
 * @dets: pointer to the dets
 * Return: current exit status
 */
int free_dets(dets_t *dets)
{
	free(dets->line);
	dets->line = _getline(-1);
	free_tokens(&dets->tokens);
	free(dets->cwd);
	dets->cwd = NULL;
	free(dets->exe);
	dets->exe = NULL;
	free_dict(&dets->env);
	free_list(&dets->path);
	free_dict(&dets->aliases);
	free_cmdlist(&dets->commands);
	return (dets->status);
}
