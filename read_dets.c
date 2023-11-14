#include "hsh.h"


/**
 * read_dets - This is used to get the details
 * @dets: This is the shell details
 * Return: This returns the size of the line
*/
bool read_dets(dets_t *dets)
{
    if (dets->from_terminal)
	   write(STDERR_filenom, "$ ", 2);

    dets->linenom += 1;

    char *line = _getline(dets->filenom);
    if (!line) {
	   return false;
    }

    while (line[strlen(line) - 1] == '\\' && _getline(dets->filenom))
    {
	   if (dets->from_terminal)
		  write(STDERR_FILENO, "> ", 2);
	   dets->linenom += 1;

	   char *temp = line;
	   line = strjoin(NULL, "", temp, dets->line);
	   free(temp);
	   free(dets->line);
    }

    dets->line = line;

    return true;
}

