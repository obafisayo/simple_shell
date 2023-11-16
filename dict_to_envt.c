#include "envt.h"

/**
 * dict_to_envt - creates a linked list from the environment
 * @head: This is use to represent the pointer to the dictionary
 * Return: This is the pointer to linked list
*/
char **dict_to_envt(envt_t *head)
{
	char **envt;
	envt_t *temp = head;
	size_t len = 0;

	while (temp)
		++len, temp = temp->next_node;
	envt = malloc(sizeof(char *) * (len + 1));
	if (!envt)
		return (NULL);
	for (len = 0; head; head = head->next_node)
		envt[len++] = strjoin(NULL, "=", head->key, head->value);
	envt[len] = NULL;

	return (envt);
}
