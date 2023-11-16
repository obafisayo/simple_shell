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

	signal(SIGINT, _sigint);
	printf("ls oj"); 
}
