#include "builtins.h"

/**
 * __help - show help for builtins commands
 * @dets: shell dets
 * Return: status
 */
int __help(struct dets *dets)
{
	const builtin_t *bp = NULL;
	char * const *args = dets->tokens + 1;
	const char *desc = NULL;
	size_t len = 0;

	if (*args)
	{
		dets->status = EXIT_FAILURE;
		while (*args)
		{
			bp = get_builtin(*args);
			if (bp)
			{
				write(STDOUT_FILENO, bp->name, _strlen(bp->name));
				write(STDOUT_FILENO, ": ", 2);
				write(STDOUT_FILENO, bp->help, _strlen(bp->help));
				write(STDOUT_FILENO, "\n", 1);
				for (desc = bp->desc; (len = _strlen(desc)); desc += len + 1)
				{
					write(STDOUT_FILENO, "    ", 4);
					write(STDOUT_FILENO, desc, len);
					write(STDOUT_FILENO, "\n", 1);
				}
				dets->status = EXIT_SUCCESS;
			}
			args += 1;
		}
		if (dets->status == EXIT_FAILURE)
			perrorl_default(*dets->argv, dets->lineno, "No topics match",
					*dets->tokens, *(args - 1), NULL);
		return (dets->status);
	}
	dets->status = EXIT_SUCCESS;
	for (bp = get_builtins(); bp->name; bp += 1)
	{
		write(STDOUT_FILENO, bp->help, _strlen(bp->help));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (dets->status);
}
