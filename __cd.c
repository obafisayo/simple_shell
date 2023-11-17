#include "builtins.h"

/**
 * __cd_error - print an error upon failure to change directory
 * @dets: shell dets
 * @dir: directory
 */
void __cd_error(dets_t *dets, char *dir)
{
	char *error = strjoin(NULL, " ", "can't cd to", dir);

	perrorl_default(*dets->argv, dets->lineno, error, *dets->tokens, NULL);

	dets->status = 2;

	free(error);
}


/**
 * __cd_success - update the environment upon success
 * @dets: shell dets
 */
void __cd_success(dets_t *dets)
{
	char **tokens = dets->tokens;
	char *setenv_tokens[] = {"setenv", NULL, NULL, NULL};

	dets->tokens = setenv_tokens;

	setenv_tokens[1] = "OLDPWD";
	setenv_tokens[2] = dets->cwd;

	__setenv(dets);

	free(dets->cwd);
	dets->cwd = getcwd(NULL, 0);

	setenv_tokens[1] = "PWD";
	setenv_tokens[2] = dets->cwd;

	__setenv(dets);

	dets->tokens = tokens;

	dets->status = EXIT_SUCCESS;
}


/**
 * __cd - changes the directory
 * @dets: arguments passed
 *
 * Return: int
 */
int __cd(dets_t *dets)
{
	char *dir = NULL, **args = dets->tokens + 1;

	dets->status = EXIT_SUCCESS;
	if (*args)
	{
		if (!_strcmp(*args, "-"))
		{
			dir = get_dict_val(dets->env, "OLDPWD");
			if (!dir)
				dir = dets->cwd;

			dets->status = chdir(dir);
			if (!dets->status)
			{
				write(STDOUT_FILENO, dir, _strlen(dir));
				write(STDOUT_FILENO, "\n", 1);
			}
		}
		else
		{
			dir = *args;
			dets->status = chdir(dir);
		}
	}
	else
	{
		dir = get_dict_val(dets->env, "HOME");
		if (dir)
			dets->status = chdir(dir);
	}
	if (dets->status != -1)
		__cd_success(dets);
	else
		__cd_error(dets, dir);

	return (dets->status);
}
