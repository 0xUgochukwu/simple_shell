#include "main.h"

/**
 * main - simple shell
 *
 * argc: argument count
 * argv: list of arguments
 */

int main (int __attribute__((unused)) ac, char **av) 
{
	char *err_msg = malloc(1024);
	int err_len;
	char *args [3]= {"clear", NULL};
	command_t *test;
	test = malloc(sizeof(command_t));

	err_len = sprintf(err_msg, "Usage: %s or %s [filename]\n", av[0], av[0]);

	if (ac > 2)
	{
		write(STDOUT_FILENO, err_msg, err_len);
		return (0);
	}

	else
	{
		test->cmd = "clear";
		test->seprator = NULL;
		test->argv = args;
		execute_cmd(test);
	}

	free(err_msg);
	return (0);
}
