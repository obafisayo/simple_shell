#include "builtins.h"

/**
 * __setenv - sets the environment variables
 * @dets: arguments passed
 *
 * Return: status
 */
int __setenv(dets_t *dets)
{
	env_t *var;
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
		var = get_dict_node(dets->env, args[0]);
		if (var)
		{
			free(var->val);
			var->val = _strdup(val);
		}
		else
		{
			add_dict_node_end(&dets->env, args[0], val);
		}
		dets->status = EXIT_SUCCESS;
	}
	else
	{
		__env(dets);
	}
	return (dets->status);
}
