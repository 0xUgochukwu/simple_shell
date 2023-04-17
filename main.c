#include "main.h"

/**
 * main - simple shell
 *
 * argc: argument count
 * argv: list of arguments
 */

int main (ac, **av) 
{
	if (!(ac <= 2))
		return (0);

	if (ac == 2)
		execute_file(av[1]);
	else
		start_shell();

	return (0);
}
