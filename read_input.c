#include "hsh.h"
#include "getline.h"

/**
 * read_input - get input
 * @dets: shell detsrmation
 *
 * Return: line size
 */
bool read_input(dets_t *dets)
{
	char *line = NULL, *temporary = NULL;

	if (dets->interactive)
		write(STDERR_FILENO, "$ ", 2);

	dets->lineno += 1;
	while (_read_input(&dets->line, dets->fileno) &
		(QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
	{
		temporary = line;
		line = strjoin(NULL, "", temporary, dets->line);
		free(temporary);
		free(dets->line);
		if (dets->interactive)
			write(STDERR_FILENO, "> ", 2);
		dets->lineno += 1;
	}
	if (line)
	{
		temporary = dets->line;
		dets->line = strjoin(NULL, "", line, temporary);
		free(temporary);
		free(line);
	}
	return (dets->line);
}


/**
 * _read_input - read a single line
 * @lineptr: line buffer
 * @fd: file descriptor to read from
 *
 * Return: ending quote state
 */
quote_state_t _read_input(char **lineptr, int fd)
{
	char *line = *lineptr = _getline(fd);
	static quote_state_t state = QUOTE_NONE;
	size_t index = 0;

	if (line)
	{
		switch (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
		{
		case QUOTE_DOUBLE:
		case QUOTE_SINGLE:
			do {
				index += quote_state_len(line + index, state);
				if (line[index] == '\0')
					continue;
				if (state & (QUOTE_DOUBLE | QUOTE_SINGLE))
					index += 1;
				/* fall through */
		case 0:
				state = quote_state(line[index]);
				if (state & (QUOTE_DOUBLE | QUOTE_SINGLE | QUOTE_ESCAPE))
					index += 1;
			} while (line[index]);
		}
	}
	return (state);
}
