#include "main.h"

/**
 * bi_exit - exit the shell 
 *
 * @argv: arguments
 * Return: int
 */

int bi_exit(char **argv)
{
	int status = is_num(argv[1]);

	if (status >= 0)
		exit(status);
	else
	{
		perror("status");
		return (1);
	}
}


/**
 * bi_env - ...
 *
 * @argv: arguments
 * Return: int
 */

int bi_env(char __attribute__((unused)) **argv)
{
	char **env = get_environ();

	while (*env)
	{
		env++;
	}
	return (0);
}

/**
 * bi_setenv - ...
 *
 * @argv: arguments
 * Return: int
 */

int bi_setenv(char **argv)
{
	char **env = get_environ(), **environ = env;
	char *newenv, *envname;
	int i = 0, j = -1;

	if (argv[1] == NULL || argv[2] == NULL)
	{
		perror("missing argument");
		return (1);
	}

	newenv = malloc(BUFFSIZE);
	newenv = str_concat(argv[1], argv[2], '=');
	while (env[i])
	{
		envname = strtok(_strdup(env[i]), "=");
		if (_strcmp(argv[1], envname) == 0)
			j = i;
		i++;
	}

	if (j >= 0 && j != i)
		environ[j] = newenv;
	else
	{
		environ[i++] = newenv;
		environ[i] = NULL;
	}

	set_environ(environ);

	return (0);
}

/**
 * bi_unsetenv - ...
 *
 * @argv: arguments
 * Return: int
 */

int bi_unsetenv(char **argv)
{
	char **env = get_environ(), **environ = env;
	char *envname;
	int i = 0, j = -1;

	if (argv[1] == NULL)
	{
		perror("missing argument");
		return (1);
	}

	while (env[i])
	{
		envname = strtok(_strdup(env[i]), "=");
		if (_strcmp(argv[1], envname) == 0)
			j = i;
		i++;
	}

	if (j < 0)
		return (0);

	while (j >= 0 && j < (i - 1))
	{
		environ[j] = environ[j + 1];
		j++;
	}

	environ[j] = NULL;
	set_environ(environ);

	return (0);
}

/**
 * is_num - checks if value passed is a num
 *
 * @str: exit status oassed by user
 * Return: int
 */

int is_num(char *str)
{
	char *num = str;

	if (str == NULL)
		return (0);
	while (*num)
	{
		if (_isdigit(*num) == 0)
			return (-1);
		num++;
	}

	return (_atoi(str));
}
