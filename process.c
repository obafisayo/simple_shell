#include "hsh.h"

void process(dets_t *dets)
{
     char **tokens;
     int i;
     pid_t child_pid;
     int status;
     struct stat st;

     child_pid = fork();
     if (child_pid == -1)
     {
          perror("Error: Can't create child process");
          exit(EXIT_FAILURE);
     }
     if (child_pid == 0)
     {
          tokens = dets->tokens;
          execute_file(tokens, &st, env, argv);
          for (i = 0; tokens[i] != NULL; i++)
          {
               free(tokens[i]);
          }
          free(tokens);
     }
     if (waitpid(child_pid, &status, 0) == -1)
     {
          perror("Error: Can't wait for child_pid");
          exit(EXIT_FAILURE);
     }
}