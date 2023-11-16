#ifndef _DICT_H_
#define _DICT_H_

#include <stdlib.h>

#include "typedef.h"
#include "string.h"

/**
 * struct dict - This is a singly linked list of key=value pairs
 * @key: This is the key variable
 * @value: This is the value variable of the key
 * @next_node: This is a pointer to the next key=value pair node
*/
struct dict
{
	char *key;
	char *value;
	struct dict *next_node;
};

dict_t *dict_add_node_end(dict_t **headptr,
const char *key, const char *value);
dict_t *dict_get_node(dict_t *head, const char *key);
char *dict_get_value(dict_t *head, const char *key);
dict_t *dict_del_node(dict_t **headptr, const char *key);
void free_dict(dict_t **headptr);

#endif /* _DICT_H_ */
