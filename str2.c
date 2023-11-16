#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "string.h"

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
    token = strtok(str, delim);
    for (; token != NULL; token = strtok(NULL, delim))
    {
        t++;
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
    return words_arr;
}

/**
 * free_string_array - Free the memory allocated for an array of strings
 * @array: The array of strings to be freed
 */
void free_string_array(char **array)
{
    if (array == NULL) {
        return;
    }
    for (size_t i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}