#ifndef PATH_H
#define PATH_H

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

#include "dets.h"
#include "list.h"
#include "string.h"
#include "types.h"

char *search_path(dets_t *dets, list_t *path);

#endif /* PATH_H */
