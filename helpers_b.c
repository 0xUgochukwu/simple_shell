#include "main.h"

/**
 * str_concat - concatenates two strings with a delimiter
 * @s1: first string
 * @s2: second string
 * @delimiter: delimiter to use
 * Return: pointer to concatenated string, or NULL on failure
 */
char *str_concat(const char *s1, const char *s2, const char delimiter)
{
	char *result = NULL;
	size_t len1 = 0, len2 = 0, result_len = 0;
	size_t i = 0, j = 0;

	if (s1 != NULL)
		len1 = _strlen(s1);
	if (s2 != NULL)
		len2 = _strlen(s2);

	result_len = len1 + len2 + 2; /* +2 for delimiter and null byte */

	result = malloc(result_len * sizeof(char));
	if (result == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	result[i] = delimiter;

	for (j = 0; j < len2; j++)
		result[i + j + 1] = s2[j];

	result[i + j + 1] = '\0';

	return (result);
}
