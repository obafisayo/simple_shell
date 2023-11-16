#include <stdlib.h>
#include <string.h>
#include "string.h"

/**
 * split_string - Split a string into an array of strings based on a delimiter string
 * @string: The input string to be split
 * @delimiter: The delimiter string used for splitting
 * Return: An array of strings or NULL if memory allocation fails
 */
char **split_string(const char *string, const char *delimiter)
{
    char **result = NULL;
    size_t count = 0;
    const char *temp = string;
    const char *delimiter_ptr = NULL;

    while ((delimiter_ptr = strstr(temp, delimiter)) != NULL) {
        count++;
        temp = delimiter_ptr + strlen(delimiter);
    }
    count++;

    result = (char **)malloc((count + 1) * sizeof(char *));
    if (result == NULL) {
        return NULL;
    }

    size_t i = 0;
    temp = string;

    while ((delimiter_ptr = strstr(temp, delimiter)) != NULL) {
        size_t length = delimiter_ptr - temp;
        result[i] = (char *)malloc((length + 1) * sizeof(char));
        if (result[i] == NULL) {
            while (i > 0) {
                free(result[--i]);
            }
            free(result);
            return NULL;
        }
        strncpy(result[i], temp, length);
        result[i][length] = '\0';
        temp = delimiter_ptr + strlen(delimiter);
        i++;
    }

    result[i] = strdup(temp);
    if (result[i] == NULL) {
        while (i > 0) {
            free(result[--i]);
        }
        free(result);
        return NULL;
    }

    result[count] = NULL;
    return result;
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
