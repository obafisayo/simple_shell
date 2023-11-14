#ifndef _GETLINE_H_
#define _GETLINE_H_

#include <stdlib.h>
#include <unistd.h>

#include "string.h"

#define GETLINE_BUFFER_SIZE 4096

/**
 * struct buf_s - input buffer
 * @buffer: This is the buffer
 * @next: This is the pointer to the next value
 * @remaining: This is the number of values remaining
 */
typedef struct {
    char buffer[GETLINE_BUFFER_SIZE];
    char *next;
    size_t remaining;
} buf_t;

/**
 * struct buf_table_node_s - This is the input buffer hash table
 * @fd: This is the file descriptor
 * @buf: This is the associated buffer
 * @next: this is the next buffer in chain
 */
typedef struct buf_table_node_s {
    int fd;
    buf_t buf;
    struct buf_table_node_s *next;
} buf_table_node_t;

typedef buf_table_node_t *buf_table_t[127];

char *_getline(const int fd);

#endif /* _GETLINE_H_ */
