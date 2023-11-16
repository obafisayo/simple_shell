#ifndef _ENVT_H_
#define _ENVT_H_

#include <stdlib.h>
#include <sys/types.h>

#include "typedef.h"
#include "string.h"
#include "dict.h"

typedef dict_t envt_t;

envt_t *envt_to_dict(char **env);
envt_t *_envt_to_dict(envt_t **tailptr, char **env);
char **dict_to_envt(envt_t *head);

#endif /* _ENVT_H_ */