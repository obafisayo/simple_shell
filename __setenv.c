#include "builtin.h"

/**
 * __setenv - sets the environment variables
 * @dets: arguments passed
 *
 * Return: status
 */
int __setenv(dets_t *dets)
{
	envt_t *var;
	char **args = dets->tokens + 1, *val;

	if (args[0])
	{
		if (args[1])
		{
			if (args[2])
			{
				perrorl("Too many arguments.", *dets->tokens, NULL);
				dets->status = EXIT_FAILURE;
				return (dets->status);
			}
			val = args[1];
		}
		else
		{
			val = "";
		}
		var = dict_get_node(dets->envt, args[0]);
		if (var)
		{
			free(var->value);
			var->value = _strdup(val);
		}
		else
		{
			dict_add_node_end(&dets->envt, args[0], val);
		}
		dets->status = EXIT_SUCCESS;
	}
	else
	{
		__env(dets);
	}
	return (dets->status);
}
