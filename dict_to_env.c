#include "env.h"

/**
  * dict_to_env - creates linked list from environment
  * @head: argument passed
  * Return: pointer to list
  */
char **dict_to_env(env_t *head)
{
	env_t *temporary = head;
	char **env;
	size_t length = 0;

	while (temporary)
		++length, temporary = temporary->next;

	env = malloc(sizeof(char *) * (length + 1));
	if (!env)
		return (NULL);

	for (length = 0; head; head = head->next)
		env[length++] = strjoin(NULL, "=", head->key, head->val);
	env[length] = NULL;

	return (env);
}
