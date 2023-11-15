#ifndef _ERR_H_
#define _ERR_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

#include "string.h"

void perrorl(const char *msg, ...);
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...);

#endif /* _ERR_H_ */
