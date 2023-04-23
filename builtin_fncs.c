#include "main.h"

extern char **environ;

/**
 * bi_exit - ...
 *
 * @argv:
 * Return
 */

int bi_exit(char **argv)
{
	int status = is_num(argv[1]);

	if (status >= 0)
		exit(status);
	else
	{
		perror("status");
		return (EXIT_FAILURE);
	}
}


/**
 * bi_env - ...
 *
 * @argv:
 * Return
 */

int bi_env(char __attribute__((unused)) **argv)
{
	char **env = environ;
	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
	return (0);
}

int is_num(char *str)
{
	int i = 0, mul = 1;
	int num = 0;

	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (isdigit(*str) == 0)
			return (-1);
		num += (str[i] * mul);
		mul *= 10;
		i--;
	}

	return (num);

}
