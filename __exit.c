#include "builtins.h"

/**
  * __exit - exits from shell
  * @dets: arguments passed
  * Return: int
  */
int __exit(dets_t *dets)
{
	char **args = dets->tokens + 1;

	if (*args)
	{
		if (_isnumber(*args) && atou(*args) <= INT_MAX)
		{
			dets->status = atou(*args);
		}
		else
		{
			perrorl_default(*dets->argv, dets->lineno, *args,
					*dets->tokens, "Illegal number", NULL);
			dets->status = 2;

			return (dets->status);
		}
	}
	if (dets->file)
		close(dets->fileno);

	exit(free_dets(dets));
}
