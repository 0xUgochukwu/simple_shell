#include "main.h"


/**
 * _strlen - Returns the length of a string.
 * @s: A pointer to the characters string.
 *
 * Return: The length of the character string.
 */
int _strlen(const char *s)
{
	int length = 0;

	if (!s)
		return (length);
	for (length = 0; s[length]; length++)
		;
	return (length);
}


/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 *           which contains a copy of the string given as a parameter.
 *           The copied string ends with a null byte.
 * @str: the string to duplicate
 *
 * Return: If str is NULL or if insufficient memory is available,
 *         returns NULL; otherwise returns a pointer to the duplicated string.
 */
char *_strdup(const char *str)
{
	char *dup;
	size_t len, i;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;
	dup = malloc(len * sizeof(char));

	if (dup == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = str[i];

	return (dup);
}



/**
 * _strcpy - Copies the string pointed to by src, including the
 *           terminating null byte, to the buffer pointed by des.
 * @dest: Pointer to the destination of copied string.
 * @src: Pointer to the src of the source string.
 *
 * Return: Pointer to dest.
 */
char *_strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * _isalnum - checks if a character is alphanumeric
 * @c: the character to check
 *
 * Return: 1 if c is alphanumeric, 0 otherwise
 */
int _isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ||
			(c >= '0' && c <= '9'))
	{
		return (1);
	}
	return (0);
}

/**
 * _strcmp - compares two strings
 * @s1: the first string to be compared
 * @s2: the second string to be compared
 *
 * Return: an integer greater than, equal to, or less than 0, according to
 * whether s1 is greater than, equal to, or less than s2, respectively
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
	}

	return (s1[i] - s2[i]);
}
