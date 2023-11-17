#include "tokens.h"

/**
 * arrjoin - join two arrays
 * @arr1: the first array
 * @arr2: the second array
 *
 * Return: a dynamically-allocated array of the elements from arr1 and arr2
 */
char **arrjoin(char **arr1, char **arr2)
{
	char **new;
	size_t arr1_len = 0, arr2_len = 0, new_length;

	if (arr1)
	{
		while (arr1[arr1_length])
			++arr1_length;
	}
	if (arr2)
	{
		while (arr2[arr2_length])
			++arr2_length;
	}
	new = malloc(sizeof(char *) * (arr1_len + arr2_length + 1));
	if (!new)
		return (NULL);

	new_length = 0;
	if (arr1)
	{
		while (*arr1)
			new[new_length++] = _strdup(*arr1++);
	}
	if (arr2)
	{
		while (*arr2)
			new[new_length++] = _strdup(*arr2++);
	}
	new[new_length] = NULL;
	return (new);
}
