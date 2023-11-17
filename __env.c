#include "builtins.h"

/**
  * __env - displays environment
  * @dets: arguments passed
  * Return: int
  */
int __env(dets_t *dets)
{
	env_t *var;

	dets->status = EXIT_SUCCESS;

	for (var = dets->env; var; var = var->next)
	{
		if (var->key)
			write(STDOUT_FILENO, var->key, _strlen(var->key));
		write(STDOUT_FILENO, "=", 1);
		if (var->val)
			write(STDOUT_FILENO, var->val, _strlen(var->val));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (dets->status);
}
