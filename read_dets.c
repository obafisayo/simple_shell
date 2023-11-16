#include "hsh.h"
#include <stdio.h>

/**
 * read_dets - This is used to get the details
 * @dets: This is the shell details
 * Return: This returns the size of the line
*/
bool read_dets(dets_t *dets)
{
	char *temp = NULL, *line = NULL;
	ssize_t backslash_pos, old_pos = 1;
	int filenom = dets->filenom;

	if (dets->from_terminal)
		write(STDERR_FILENO, "$ ", 2);

	dets->linenom += 1;

	size_t size = 0;
	line = NULL;

	if (getline(&line, &size, filenom) == -1)
	{
		free(line);
		return false;
	}

	while (_strlen(line) > 0 && line[_strlen(line) - 2] == '\\')
	{
		if (dets->from_terminal)
		{
			write(STDOUT_FILENO, "> ", 2);
		}
		dets->linenom += 1;

		line[_strlen(line) - 2] = '\0';
		temp = line;
		if (getline(&line, &size, filenom) == -1)
		{
			free(temp);
			return false;
		}
		line = strjoin(NULL, "", temp, line);
	}

	temp = line;
	while ((backslash_pos = _strchr(temp, '\\')) != -1)
	{
		old_pos -= 1;
		line[old_pos + backslash_pos] = '\0';
		temp += backslash_pos + 1;
		line = strjoin(NULL, "", line, temp);
		old_pos += backslash_pos + 1;
	}

	dets->line = line;
	return true;
}
