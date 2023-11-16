#include "builtin.h"

/**
  * __env - displays environment
  * @dets: arguments passed
  * Return: int
  */
int __env(dets_t *dets)
{
	envt_t *var;

	dets->status = EXIT_SUCCESS;

	for (var = dets->envt; var; var = var->next_node)
	{
		if (var->key)
			write(STDOUT_FILENO, var->key, _strlen(var->key));
		write(STDOUT_FILENO, "=", 1);
		if (var->value)
			write(STDOUT_FILENO, var->value, _strlen(var->value));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (dets->status);
}
