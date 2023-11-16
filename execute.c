#include "hsh.h"

/**
 * execute_file - This function is used to execute files passed in the filepath
 * @environ: This is the environment variable
 * @st: This is the struct stat variable
 * @argv: This is an argument from the main variable
 * @args: This is the argument to be passed
 * Return: This function returns 0 if found and -1 on error
 */
int execute_file(char **args, struct stat *st, char **environ, char **argv)
{
	if (!check_file_status(args[0], st, argv))
	{
		perror("Error: File not found");
		exit(EXIT_FAILURE);
	}
	execve(args[0], args, environ);
	perror("Error: can't execute program");
	exit(EXIT_FAILURE);
}

/**
 * check_file_status - This is used to check if the file exists
 * @pathname: This is the pathname passed
 * @st: This is the st value
 * @argv: This is an argument from the main function
 * Return: This returns a boolean value
*/
bool check_file_status(char *pathname, struct stat *st, char **argv)
{
	int stat_return;
	bool retbool = false;

	stat_return = stat(pathname, st);
	if (stat_return == 0)
	{
		retbool = true;
		return (retbool);
	} else if (retbool == false)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, ": ", 2);
		perror("");
		exit(EXIT_FAILURE);
	}
	return (retbool);
}
