#include "hsh.h"


/**
 * read_dets - This is used to get the details
 * @dets: This is the shell details
 * Return: This returns the size of the line
*/
bool read_dets(dets_t *dets)
{
	char *temp, *line;
	ssize_t backslash_pos;
	
	if (dets->from_terminal)
		write(STDERR_FILENO, "$ ", 2);

	dets->linenom += 1;

	line = _getline(dets->filenom);
	if (!line) {
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
		line = strjoin(NULL, "", temp, _getline(dets->filenom));
		free(temp);
	}
	temp = line;
	while (_strlen(temp) > 0 && (backslash_pos = _strchr(temp, '\\')))
	{
		temp[backslash_pos] = '\0';
		temp += backslash_pos;
	}
	line = temp;
	free(temp);
	dets->line = line;

	return true;
}
