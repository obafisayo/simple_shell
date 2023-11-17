#include "error.h"

/**
  * perrorl - print a formatted message to standard error
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl(const char *msg, ...)
{
	const char *string;
	va_list cont;

	va_start(cont, msg);
	while ((string = va_arg(cont, char *)))
	{
		write(STDERR_FILENO, string, _strlen(str));
		write(STDERR_FILENO, ": ", 2);
	}
	va_end(cont);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}


/**
  * perrorl_default - print a formatted message to standard error
  * @arg0: argument vector
  * @lineno: line number
  * @msg: error message
  * @...: NULL-terminated list of context strings to prepend
  */
void perrorl_default(const char *arg0, size_t lineno, const char *msg, ...)
{
	char *linenostr = num_to_str(lineno);
	const char *string = NULL;
	va_list ap;

	if (arg0)
		write(STDERR_FILENO, arg0, _strlen(arg0));
	write(STDERR_FILENO, ": ", 2);

	if (linenostr)
		write(STDERR_FILENO, linenostr, _strlen(linenostr));
	write(STDERR_FILENO, ": ", 2);

	va_start(ap, msg);
	while ((string = va_arg(ap, char *)))
	{
		write(STDERR_FILENO, string, _strlen(string));
		write(STDERR_FILENO, ": ", 2);
	}
	va_end(ap);

	if (msg)
		write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	free(linenostr);
}
