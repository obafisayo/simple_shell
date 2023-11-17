#include "builtins.h"

/**
 * __help - show help for builtins commands
 * @dets: shell dets
 * Return: status
 */
int __help(struct dets *dets)
{
	const builtin_t *bprinter = NULL;
	char * const *args = dets->tokens + 1;
	const char *desc = NULL;
	size_t len = 0;

	if (*args)
	{
		dets->status = EXIT_FAILURE;
		while (*args)
		{
			bprinter = get_builtin(*args);
			if (bprinter)
			{
				write(STDOUT_FILENO, bprinter->name, _strlen(bprinter->name));
				write(STDOUT_FILENO, ": ", 2);
				write(STDOUT_FILENO, bprinter->help, _strlen(bprinter->help));
				write(STDOUT_FILENO, "\n", 1);
				for (desc = bprinter->desc; (len = _strlen(desc)); desc += len + 1)
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
	for (bprinter = get_builtins(); bprinter->name; bprinter += 1)
	{
		write(STDOUT_FILENO, bprinter->help, _strlen(bprinter->help));
		write(STDOUT_FILENO, "\n", 1);
	}
	return (dets->status);
}
