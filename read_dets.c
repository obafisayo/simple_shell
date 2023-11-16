#include "hsh.h"


/**
 * read_dets - This is used to get the details
 * @dets: This is the shell details
 * Return: This returns the size of the line
*/
bool read_dets(dets_t *dets)
{
	char *temp = NULL, *line = NULL, *newline = NULL;
	ssize_t backslash_pos, old_pos = 1;

	if (dets->from_terminal)
		write(STDERR_FILENO, "$ ", 2);

	dets->linenom += 1;

	line = _getline(dets->filenom);
	if (!line)
		return (false);
	while (_strlen(line) > 0 && line[_strlen(line) - 2] == '\\')
	{
		if (dets->from_terminal)
		{
			write(STDOUT_FILENO, "> ", 2);
		}
		dets->linenom += 1;

		line[_strlen(line) - 2] = '\0';
		temp = line;
		newline = _getline(dets->filenom);
		line = strjoin(NULL, "", temp, newline);
		free(newline);
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
	return (true);
}
