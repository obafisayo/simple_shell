#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

#include "hsh.h"
#include "dets.h"

/**
 * init_dets - This is used to set the shell details
 * @argc: This is the argument count
 * @argv: This is the argument vector
 * Return: This returns a pointer to the details
*/

dets_t *init_dets(int argc, char **argv)
{
	static dets_t dets;
	char *err = NULL;

	dets.argc = argc;
	dets.argv = argv;
	dets.filenom = STDIN_FILENO;
	if (argc > 1)
	{
		dets.file = argv[1];
		dets.filenom = open(dets.file, O_RDONLY);
		if (dets.filenom == -1)
		{
			err = strjoin(NULL, " ", "Can't open", dets.file);
			perrorl_default(*argv, dets.linenom, err, NULL);
			free(err);
			dets.status = 127;
			exit(free_dets(&dets));
		}
	}
	dets.from_terminal = isatty(dets.filenom);
	dets.my_pid = getpid();
	dets.cwd = getcwd(NULL, 0);
	dets.envt = envt_to_dict(environ);
	return (&dets);
}

/**
 * free_dets - free and nullify dynamically allocated info
 * @dets: pointer to the info
 * Return: current exit status
 */
int free_dets(dets_t *dets)
{
	free_tokens(&dets->tokens);
	free(dets->line);
	dets->line = _getline(-1);
	free(dets->cwd);
	dets->cwd = NULL;
	free(dets->exe);
	dets->exe = NULL;
	free_dict(&dets->envt);
	free_dict(&dets->aliases);
	free_list(&dets->path);
	free_cmdlist(&dets->commands);
	return (dets->status);
}
