#include "hsh.h"

/**
  * execute - execute a command
  * @dets: arguments passed
  *
  * Return: status
  */
int execute(dets_t *dets)
{
	const builtin_t *builtin = get_builtin(*dets->tokens);

	if (builtin)
	{
		return (builtin->f(dets));
	}
	if (_strchr(*dets->tokens, '/') == -1)
	{
		free_list(&dets->path);
		dets->path = str_to_list(get_dict_val(dets->env, "PATH"), ':');
		dets->exe = search_path(dets, dets->path);
	}
	else
	{
		dets->exe = _strdup(*dets->tokens);
	}
	if (dets->exe && access(dets->exe, X_OK) == 0)
	{
		return (_execute(dets));
	}
	if (dets->exe)
	{
		perrorl_default(*dets->argv, dets->lineno, "Permission denied",
				*dets->tokens, NULL);
		dets->status = 126;
	}
	else
	{
		perrorl_default(*dets->argv, dets->lineno, "not found",
				*dets->tokens, NULL);
		dets->status = 127;
	}
	return (dets->status);
}


/**
 * _execute - fork and exec the current command
 * @dets: shell detsrmation
 *
 * Return: exit status of the child process
 */
int _execute(dets_t *dets)
{
	char *exe, **argv, **env;

	switch (fork())
	{
	case 0:
		exe = dets->exe;
		argv = dets->tokens;
		env = dict_to_env(dets->env);

		dets->exe = NULL;
		dets->tokens = NULL;
		free_dets(dets);

		execve(exe, argv, env);
		perror(*argv);

		if (dets->file)
			close(dets->fileno);

		free(exe);
		free_tokens(&argv);
		free_tokens(&env);
		exit(EXIT_FAILURE);
		break;
	case -1:
		perrorl_default(*dets->argv, dets->lineno, "Cannot fork", NULL);
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
