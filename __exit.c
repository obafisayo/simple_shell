#include "builtins.h"

/**
  * __exit - exits from shell
  * @dets: arguments passed
  * Return: int
  */
int __exit(dets_t *dets)
{
	char **arguments = dets->tokens + 1;

	if (*arguments)
	{
		if (_isnumber(*arguments) && atou(*arguments) <= INT_MAX)
		{
			dets->status = atou(*arguments);
		}
		else
		{
			perrorl_default(*dets->argv, dets->lineno, *arguments,
					*dets->tokens, "Illegal number", NULL);
			dets->status = 2;

			return (dets->status);
		}
	}
	if (dets->file)
		close(dets->fileno);

	exit(free_dets(dets));
}
