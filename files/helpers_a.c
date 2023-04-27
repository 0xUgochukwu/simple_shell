#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated.
 * @old_size: The size in bytes of the allocated space for ptr.
 * @new_size: The size in bytes for the new memory block.
 *
 * Return: If new_size == old_size - ptr.
 *         If new_size == 0 and ptr is not NULL - NULL.
 *         Otherwise - a pointer to the reallocated memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *mem;
	char *ptr_copy, *filler;
	unsigned int index;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		mem = malloc(new_size);
		if (mem == NULL)
			return (NULL);

		return (mem);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	ptr_copy = ptr;
	mem = malloc(sizeof(*ptr_copy) * new_size);
	if (mem == NULL)
	{
		free(ptr);
		return (NULL);
	}

	filler = mem;

	for (index = 0; index < old_size && index < new_size; index++)
		filler[index] = *ptr_copy++;

	free(ptr);
	return (mem);
}

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}


/**
 * _atoi - converts a string of numbers to an integer
 * @s: string to convert
 *
 * Return: integer value of string
 */
int _atoi(char *s)
{
	int num = 0;
	int sign = 1;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign = -1;
			s++;
		}
		else if (*s >= '0' && *s <= '9')
		{
			num = (num * 10) + (*s - '0');
			s++;
		}
		else
		{
			s++;
		}
	}

	return (num * sign);
}

/**
 * _getenv - gets the value of the environmental variable "name"
 * @name: the name of the environmental variable
 *
 * Return: If "name" is found, return the value of the variable, otherwise NULL
 */

char *_getenv(char *name)
{
	int i = 0;
	char **environ = get_environ();
	char *env, *value;

	while (environ[i])
	{
		env = environ[i];
		value = strtok(env, "=");
		if (_strcmp(value, name) == 0)
		{
			value = strtok(NULL, "=");
			return (value);
		}
		i++;
	}

	return (NULL);
}

/**
 * _strcspn - finds the first occurrence of a character in a string
 *
 * @s: the string to search
 * @reject: the set of characters to search for
 *
 * Return: the number of characters in the initial segment of s which
 * consist only of characters not in reject.
 */

size_t _strcspn(const char *s, const char *reject)
{
	size_t len = 0;
	const char *r;

	while (*s)
	{
		r = reject;
		while (*r)
		{
			if (*s == *r)
				return (len);
			r++;
		}
		s++;
		len++;
	}

	return (len);
}
