#ifndef _HSH_H_
#define _HSH_H_

#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>

#include "typedef.h"
#include "dict.h"
#include "envt.h"
#include "dets.h"
#include "string.h"
#include "getline.h"
#include "err.h"
#include "list.h"

extern char **environ;

bool read_dets(dets_t *dets);
int parse_dets(dets_t *dets);
void free_tokens(char ***tokens);
int exec(dets_t *dets);
int _exec(dets_t *dets);
void _sigint(int signal);
char *get_path(dets_t *dets, list_t *path);
int execute_file(char **args, struct stat *st, char **environ, char **argv);
bool check_file_status(char *pathname, struct stat *st, char **argv);
void process(dets_t *dets);
void free_word_arr(char **words_arr);

#endif /* _HSH_H_*/