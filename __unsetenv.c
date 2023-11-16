#include "builtin.h"

/**
  * __unsetenv - unsets the environment variable
  * @dets: arguments passed
  * Return: status
  */
int __unsetenv(dets_t *dets)
{
	char **args = dets->tokens + 1;

	if (*args)
	{
		while (*args)
			dict_del_node(&dets->envt, *args++);
		dets->status = EXIT_SUCCESS;
	}
	else
	{
		perrorl("Too few arguments.", *dets->tokens, NULL);
		dets->status = EXIT_FAILURE;
	}
	return (dets->status);
}
