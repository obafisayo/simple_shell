#ifndef _DETS_H_
#define _DETS_H_

#include <stdlib.h>
#include <unistd.h>

#include "typedef.h"
#include "dict.h"
#include "envt.h"
#include "string.h"
#include "err.h"
#include "getline.h"
#include "alias.h"
#include "quote.h"
#include "tokens.h"
#include "command.h"
extern char **environ;

/**
 * struct dets - details from shell
 * @argv: stores the argument vector
 * @argc: stores the argument count
 * @from_terminal: checks if its from the terminal
 * @filenom: stores the file descriptor number
 * @status: stores the status of the shell
 * @file: stores the file name if present
 * @cwd: stores the current working directory
 * @line: stores the inputed line
 * @exe: stores an executabe string
 * @tokens: stores an array of delimited string
 * @linenom: stores the no of lines
 * @my_pid: stores the current pid value
 * @envt: stores a duplicate of the environ string
 * @path: stores the path value
 * @aliases: stores the created alias
*/
struct dets
{
	char **argv;
	int argc;
	int from_terminal;
	int filenom;
	int status;
	char *file;
	char *cwd;
	char *line;
	char *exe;
	char **tokens;
	size_t linenom;
	pid_t my_pid;
	envt_t *envt;
	list_t *path;
	alias_t *aliases;
	cmdlist_t commands;
};

dets_t *init_dets(int argc, char **argv);
int free_dets(dets_t *dets);
char **arrdup(char **arr);
char *get_path(dets_t *dets, list_t *path);
char **arrjoin(char **arr1, char **arr2);

#endif /* _DETS_H_*/
