#include "hsh.h"

/**
 * _sigint - This is a signal to check for ctrl c
 * @signal: This is a variable signal
*/
void _sigint(int signal __attribute__((unused)))
{
	fflush(STDIN_FILENO);
	write(STDERR_FILENO, "\n$ ", 3);
}
