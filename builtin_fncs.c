#include "main.h"

extern char **environ;

/**
 * bi_exit - ...
 *
 * @argv:
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
 * @argv: 
 * Return: int
 */

int bi_env(char __attribute__((unused)) **argv)
{
	char **env = environ;
	while (*env)
	{
		fprintf(stdout, "%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * bi_cd - ...
 *
 * @argv:
 * Return: int
 */

int bi_cd(char __attribute__((unused)) **argv)
{
	char **env = environ;
	while (*env)
	{
		fprintf(stdout, "%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * bi_setenv - ...
 *
 * @argv:
 * Return: int
 */

int bi_setenv(char __attribute__((unused)) **argv)
{
	char **env = environ;
	while (*env)
	{
		fprintf(stdout, "%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * bi_unsetenv - ...
 *
 * @argv:
 * Return: int
 */

int bi_unsetenv(char __attribute__((unused)) **argv)
{
	char **env = environ;
	while (*env)
	{
		fprintf(stdout, "%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * is_num - ...
 *
 * @argv:
 * Return: int
 */

int is_num(char *str)
{
	char *num = str;

	if (str == NULL)
		return (0);
	while (*num)
	{
		if (isdigit(*num) == 0)
			return (-1);
		num++;
	}

	return (atoi(str));
}
