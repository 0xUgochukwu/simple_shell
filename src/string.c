#include "shell.h"
/**
 * _strdup - string duplicate
 * @str: Input String to be duplicated
 * Return: Pointer to the duplicated string
 */
char *_strdup(char *str)
{
	unsigned int k, len;
	char *dup;

	if (str == NULL)
		return (NULL);

	for (len = 0; str[len] != '\0'; len++)
		;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	for (k = 0; k <= len; k++)
	{
		dup[k] = str[k];
	}
	return (dup);
}

/**
 * _strcmp - compares two strings
 * @s1: first string.
 * @s2: second string.
 *
 * Return: 0 if s1 and s2 are equals,
 * and number > 0 if s1 is greater while number
 * number < 0 if s2 is greater.
 */
int _strcmp(char *s1, char *s2)
{

	int i = 0, rv = 0;

	while (rv == 0)
	{
		if ((*(s1 + i) == '\0') && (*(s2 + i) == '\0'))
		break;
		rv = *(s1 + i) - *(s2 + i);
		i++;
	}

	return (rv);

}

/**
 * _strlen - Holds the length of string char *str
 * @str: String whose length is to be found
 *
 * Return: The length ot the string
 */

int _strlen(const char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);

	while (str[len] != '\0')
		len++;
	return (len);
}
