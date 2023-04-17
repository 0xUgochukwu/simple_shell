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

	err_len = sprintf(err_msg, "Usage: %s or %s [filename]\n", av[0], av[0]);

	if (ac > 2)
	{
		write(STDOUT_FILENO, err_msg, err_len);
		return (0);
	}
	free(err_msg);

	if (ac == 2)
		execute_file(av[1]);
	else
		start_shell();

	return (0);
}
