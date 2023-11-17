#ifndef SHELL_H
#define SHELL_H

#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <errno.h>
#include <fcntl.h>

#include "alias.h"
#include "builtins.h"
#include "command.h"
#include "ctype.h"
#include "dict.h"
#include "env.h"
#include "error.h"
#include "dets.h"
#include "list.h"
#include "path.h"
#include "quote.h"
#include "string.h"
#include "tokens.h"
#include "types.h"

extern char **environ;

bool read_input(dets_t *dets);
quote_state_t _read_input(char **lineptr, int fd);

int parse(dets_t *dets);

int execute(dets_t *dets);
int _execute(dets_t *dets);

void expand_aliases(alias_t *aliases, char ***tokptr);
char *expand_alias(alias_t *aliases, char ***tokptr);

void expand_vars(dets_t *dets, char ***tokptr);
char **_expand_vars(dets_t *dets, char ***tokptr);

void remove_comments(cmdlist_t *cmd);

void open_script(dets_t *dets);

void _sigint(int signal);

#endif /* SHELL_H */
