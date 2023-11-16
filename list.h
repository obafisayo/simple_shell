#ifndef _LIST_H_
#define _LIST_H_

#include <stdlib.h>

#include "string.h"
#include "typedef.h"

/**
 * struct list_s - This is a singly linked list
 * @str: This is a dynamically allocated string
 * @next: This is a pointer to the next node
 */
struct list_s
{
	char *str;
	struct list_s *next;
};

list_t *str_to_list(const char *str, char delim);
list_t *_str_to_list(list_t **tailptr, const char *str, char delim);
list_t *add_node(list_t **headptr, const char *str);
list_t *add_node_end(list_t **headptr, const char *str);
void free_list(list_t **headptr);

#endif /* _LIST_H_ */
