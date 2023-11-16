#include "builtin.h"

/**
 * __alias_add - add an alias to a list of aliases
 * @aliases: a pointer to a list of aliases
 * @name: the name of the alias
 * @value: the value of the alias
 */
void __alias_add(alias_t **aliases, const char *name, const char *value)
{
	alias_t *alias = dict_get_node(aliases ? *aliases : NULL, name);

	if (alias)
	{
		free(alias->value);
		alias->value = _strdup(value);
	}
	else
	{
		dict_add_node_end(aliases, name, value);
	}
}


/**
 * __alias_print - print an alias
 * @alias: the alias to print
 */
void __alias_print(alias_t *alias)
{
	write(STDOUT_FILENO, alias->key, _strlen(alias->key));
	write(STDOUT_FILENO, "='", 2);
	write(STDOUT_FILENO, alias->value, _strlen(alias->value));
	write(STDOUT_FILENO, "'\n", 2);
}


/**
 * __alias - create and display aliases
 * @dets: shell dets struct
 *
 * Return: status
 */
int __alias(dets_t *dets)
{
	alias_t *alias;
	char *name, **args = dets->tokens + 1;
	ssize_t name_len;

	dets->status = EXIT_SUCCESS;
	if (*args)
	{
		do {
			name_len = _strchr(*args, '=');
			if (name_len == -1)
			{
				alias = dict_get_node(dets->aliases, *args);
				if (alias)
				{
					__alias_print(alias);
				}
				else
				{
					perrorl("not found", *dets->tokens, *args, NULL);
					dets->status = EXIT_FAILURE;
				}
			}
			else
			{
				name = _strndup(*args, name_len);
				__alias_add(&dets->aliases, name, *args + name_len + 1);
				free(name);
			}
		} while (*++args);
	}
	else
	{
		for (alias = dets->aliases; alias; alias = alias->next_node)
			__alias_print(alias);
	}
	return (dets->status);
}
