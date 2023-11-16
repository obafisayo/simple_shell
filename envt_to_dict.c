#include "envt.h"

/**
 * envt_to_dict - creates a linked list from environment
 * @env: environment passed
 * Return: head of the linked list
 */
envt_t *envt_to_dict(char **env)
{
	envt_t *head = NULL;

	if (!_envt_to_dict(&head, env))
		free_dict(&head);
	
	return (head);
}

/**
 * _env_to_dict - turn the environment into a linked list (helper)
 * @tailptr: pointer to the tail of the list
 * @env: environment
 *
 * Return: pointer to the tail of the list
 */
envt_t *_envt_to_dict(envt_t **tailptr, char **env)
{
	envt_t *tail;
	char *env_str;
	ssize_t key_len;

	if (!*env)
		return (*tailptr);
	
	env_str = _strdup(*env);
	if (!env_str)
		return (NULL);
	
	key_len = _strchr(*env, '=');

	if (key_len == -1)
		return (NULL);
	
	env_str[key_len] = '\0';
	tail = dict_add_node_end(tailptr, env_str, env_str + key_len + 1);
	free(env_str);

	return (_envt_to_dict(&tail, env + 1));
}
