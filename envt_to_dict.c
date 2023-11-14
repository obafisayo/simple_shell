#include "envt.h"

/**
 * envt_to_dict - creates a linked list from environment
 * @env: environment passed
 * Return: head of the linked list
 */
envt_t *envt_to_dict(char **env)
{
	envt_t *head = NULL;
	envt_t *tail = NULL;

	while (*env) {
		char *env_str = _strdup(*env);
		if (!env_str) {
			free_dict(&head);
			return NULL;
		}

		ssize_t key_len = _strchr(*env, '=');
		if (key_len == -1) {
			free(env_str);
			free_dict(&head);
			return NULL;
		}

		env_str[key_len] = '\0';
		tail = dict_add_node_end(&head, env_str, env_str + key_len + 1);
		free(env_str);

		if (!tail) {
			free_dict(&head);
			return NULL;
		}

		env++;
	}

	return head;
}
