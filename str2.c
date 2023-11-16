#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "string.h"

/**
 * _strtok - This function works the same way as the strtok function.
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
    while (*str != '\0' && _strchr(delim, *str) == -1)
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
 * split_string - Split a string into an array of strings based on a delimiter string
 * @string: The input string to be split
 * @delimiter: The delimiter string used for splitting
 * Return: An array of strings or NULL if memory allocation fails
 */
char **split_string(const char *string, const char *delimiter)
{
    int i, t;
    size_t len;
    char *str, *token;
    char **words_arr;
    const char *delim = delimiter;

    t = 0;
    str = _strdup(string);
    token = _strtok(str, delim);
    for (; token != NULL; token = _strtok(NULL, delim))
    {
    t++;
    }
    free(str);

    words_arr = (char **)malloc((t + 1) * sizeof(char *));
    if (words_arr == NULL)
    {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
    }

    i = 0;
    str = _strdup(string);
    token = _strtok(str, delim);
    for (; token != NULL; token = _strtok(NULL, delim))
    {
    len = _strlen(token);
    if (len > 0 && token[len - 1] == '\n')
    {
        token[len - 1] = '\0';
    }
    words_arr[i++] = _strdup(token);
    if (words_arr[i - 1] == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    }
    words_arr[i] = NULL;
    free(str);

    return words_arr;
}
