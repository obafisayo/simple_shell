#include "hsh.h"


/**
 * read_dets - This is used to get the details
 * @dets: This is the shell details
 * Return: This returns the size of the line
*/
bool read_dets(dets_t *dets)
{
	char *temp, *line;

	if (dets->from_terminal)
		write(STDERR_FILENO, "$ ", 2);

	dets->linenom += 1;

	line = _getline(dets->filenom);
	if (!line) {
		return false;
	}

	while (line[_strlen(line) - 2] == '\\' && _getline(dets->filenom))
	{
		if (dets->from_terminal)
		{
			write(STDOUT_FILENO, "> ", 2);
		}
		dets->linenom += 1;

		temp = line;
		line = strjoin(NULL, "", temp, dets->line);
		free(temp);
		free(dets->line);
	}

	dets->line = line;

	return true;
}
