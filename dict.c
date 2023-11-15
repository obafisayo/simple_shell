#include "dict.h"

/**
  * dict_add_node_end - adds node at the end of list
  * @headptr: pointer to dict
  * @key: entry key
  * @value: entry value
  * Return: pointer to list
  */
dict_t *dict_add_node_end(dict_t **headptr, const char *key, const char *value)
{
	dict_t *new_node, *current;

	if (!headptr)
		return (NULL);

	new_node = malloc(sizeof(dict_t));
	if (!new_node)
		return (NULL);

	new_node->key = _strdup(key);
	new_node->value = _strdup(value);
	new_node->next_node = NULL;

	if (*headptr == NULL)
	{
		*headptr = new_node;
	} else
	{
		current = *headptr;
		while (current->next_node != NULL)
		{
			current = current->next_node;
		}
		current->next_node = new_node;
	}

	return (new_node);
}

/**
 * dict_get_node - This is used to get a particular node using it's key
 * @head: This is the pointer
 * @key: This is the key
*/
dict_t *dict_get_node(dict_t *head, const char *key)
{
	if (head == NULL)
		return (NULL);
	if (_strcmp(head->key, key) == 0)
		return (head);
	return (dict_get_node(head->next_node, key));
}

/**
 * dict_get_value - This is used to get the value of a key from the dict
 * @head: This is a pointer to the first node of the dict
 * @key: This is the key whoose value is to be found
 * Return: This returns a pointer key's value if found otherwise null
*/
char *dict_get_value(dict_t *head, const char *key)
{
	if (key == NULL)
		return (NULL);

	while (head)
	{
		if (_strcmp(head->key, key) == 0)
			return (head->value);
		head = head->next_node;
	}
	return (NULL);
}

/**
 * dict_del_node - This is used to delete a particular node
 * @headptr: This is the pointer to the dict
 * @key: This is the entry key
 * Return: This returns a pointer to the resulting list
*/
dict_t *dict_del_node(dict_t **headptr, const char *key)
{
	dict_t *current, *prev;

	if (!headptr || !(*headptr))
		return (NULL);

	current = *headptr;
	prev = NULL;
	while (current != NULL)
	{
		if (_strcmp(current->key, key) == 0)
		{
			if (prev == NULL)
			{
				*headptr = current->next_node;
			} else
			{
				prev->next_node = current->next_node;
			}

			free(current->key);
			free(current->value);
			free(current);

			break;
		}
		prev = current;
		current = current->next_node;
	}
	return (*headptr);
}

/**
 * free_dict - This is used to free a linked list and set the headptr to null
 * @headptr: This is the head of the list
*/
void free_dict(dict_t **headptr)
{
	if(!*headptr)
		return;
	free_dict(&((*headptr)->next_node));
	free((*headptr)->key);
	free((*headptr)->value);
	free(*headptr);
	*headptr = NULL;
}