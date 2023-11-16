#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <unistd.h>
#include <string.h>

/**
 * _strtok - This function works the same way as the _strtok function.
 * @str: This is the string to be tokenized
 * @delim: This is the delimiter
 * Return: returns a pointer to the next token, or NULL if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *lastToken = NULL;
	char *tokenStart;

	if (str == NULL)
		str = lastToken;
	while (*str != '\0' && _strchr(delim, *str) != -1)
		str++;
	if (*str == '\0')
	{
		lastToken = NULL;
		return (NULL);
	}
	tokenStart = str;
	while (*str != '\0' && _strchr(delim, *str) == -1)
		str++;
	if (*str != '\0')
	{
		*str = '\0';
		str++;
		lastToken = str;
	}
	else
		lastToken = NULL;
	return tokenStart;
}

/**
 * split_string - This is used to split the stings passed into it.
 * It returns an array of each word.
 * @string: This is the string to be parsed
 * @delim: This is the delimiter to parse the string
 * Return: This returns an array of words
 */
char **split_string(const char *string, const char *delim)
{
	int i, t = 0;
	size_t len;
	char *str, *token;
	char **words_arr;

	str = _strdup(string);
	token = strtok(str, delim);
	for (; token != NULL; token = strtok(NULL, delim))
	{
		t++;
	}
	free(str);

	words_arr = (char **)malloc((t + 1) * sizeof(char *));
	if (words_arr == NULL)
	{
		write(STDERR_FILENO, "Memory allocation failed", 25);
		exit(1);
	}
	i = 0;
	str = _strdup(string);
	token = strtok(str, delim);
	for (; token != NULL; token = strtok(NULL, delim))
	{
		len = _strlen(token);
		if (len > 0 && token[len - 1] == '\n')
		{
			token[len - 1] = '\0';
		}
		words_arr[i] = _strdup(token);
		i++;
	}
	words_arr[i] = NULL;
	free(str);
	for (int j = 0; j < i; j++)
	{
		free(words_arr[j]);
	}

	return words_arr;
}
