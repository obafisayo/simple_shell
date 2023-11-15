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

	while (_strlen(line) > 0 && line[_strlen(line) - 1] == '\\')
	{
		if (dets->from_terminal)
		{
			write(STDOUT_FILENO, "> ", 2);
		}
		dets->linenom += 1;

		line[_strlen(line) - 1] = '\0';
		temp = line;
		line = strjoin(NULL, "", temp, _getline(dets->filenom));
		free(temp);
	}

	dets->line = line;

	return true;
}
