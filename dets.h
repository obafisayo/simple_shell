#ifndef _DETS_H_
#define _DETS_H_

#include <stdlib.h>
#include <unistd.h>

#include "typedef.h"
#include "dict.h"
#include "envt.h"

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
 * @my_pid: stores the current pid value
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
     pid_t my_pid;
     envt_t envt;
};

dets_t *init_dets(int argc, char **argv);
int free_dets(dets_t *dets);

#endif /* _DETS_H_*/