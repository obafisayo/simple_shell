#include "path.h"

/**
  * search_path - searches for the directory with the executable program
  * @dets: argument passed
  * @path: argument passed
  * Return: pointer to directory string
  */
char *search_path(dets_t *dets, list_t *path)
{
	char *pathname, *command = *dets->tokens;
	struct stat sb;

	while (path)
	{
		if (*path->str == '\0')
			pathname = strjoin(NULL, "/", dets->cwd, command);
		else
			pathname = strjoin(NULL, "/", path->str, command);
		if (stat(pathname, &sb) == 0)
		{
			if ((sb.st_mode & S_IFMT) != S_IFDIR)
				return (pathname);
		}
		free(pathname);
		path = path->next;
	}
	return (NULL);
}
