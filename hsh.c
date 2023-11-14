#include "hsh.h"

/**
 * main - This is the main entry point
 * @argc: This is the argument count
 * @argv: This is the argument vector
 * 
 * Return: Always 0
*/

int main(int argc, char **argv)
{
	dets_t *dets = init_dets(argc, argv);

	signal(2, _sigint);
	while (read_dets(dets))
	{

	}
	if (dets->file)
		close(dets->filenom);
	if (dets->from_terminal)
		write(STDOUT_FILENO, "\n", 1);
	exit(free_dets(dets));
}