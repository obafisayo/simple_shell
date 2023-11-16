#include "hsh.h"

/**
 * exec - This is used to execute the commands
 * @dets: This points to the details for execution
 * 
 * Return: This returns the status
*/
int exec(dets_t *dets)
{
	int result;

	if (_strchr(*dets->tokens, '/'))
	{
		dets->exe = _strdup(*dets->tokens);
	}
	else
	{
		free_list(&dets->path);
		dets->path = str_to_list(dict_get_value(dets->envt, "PATH"), ':');
		dets->exe = get_path(dets, dets->path);
	}

	if (!dets->exe || access(dets->exe, X_OK) != 0)
	{
		perrorl_default(*dets->argv, dets->linenom, (dets->exe ? "Permission denied" : "Not found"), *dets->tokens, NULL);
		dets->status = (dets->exe ? 126 : 127);
		free(dets->exe);
		return dets->status;
	}

	result = _exec(dets);
	free(dets->exe);
	dets->exe = NULL;
	return result;
}

/**
 * _exec - This is used to fork and execute the current command
 * @dets: This is the shell details
 * Return: This is the exit status of the child process
*/
int _exec(dets_t *dets)
{
	char *exec, **av, **envt;
	switch (fork())
	{
	case 0:
		exec = dets->exe;
		av = dets->tokens;
		envt = dict_to_envt(dets->envt);

		dets->exe = NULL;
		dets->tokens = NULL;
		free_dets(dets);

		execve(exec, av, envt);
		perror(*av);

		if (dets->file)
			close(dets->filenom);
		
		free(exec);
		free_tokens(&av);
		exit(EXIT_FAILURE);
		break;

	case -1:
		perrorl_default(*dets->argv, dets->linenom, "Cannot fork", NULL);
		dets->status = 2;
		break;

	default:
		wait(&dets->status);
		dets->status = WEXITSTATUS(dets->status);
		break;
	}
	free(dets->exe);
	dets->exe = NULL;

	return (dets->status);
}
