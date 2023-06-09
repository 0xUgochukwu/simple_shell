#include "main.h"

/**
 * main - simple shell
 *
 * @ac: argument count
 * @av: list of arguments
 * @envp: environment variables
 *
 * Return: int
 */

int main(int __attribute__((unused)) ac, char **av, char **envp)
{
	char *err_msg = malloc(1024);
	int err_len;
	char *command;
	size_t len = 0;
	ssize_t read_bytes;
	command_t *cmds;

	set_status(0);
	set_num_commands(1);
	set_environ(envp);

	err_len = sprintf(err_msg, "Usage: %s or %s [filename]\n", av[0], av[0]);
	if (ac > 2)
	{
		write(STDOUT_FILENO, err_msg, err_len);
		return (0);
	}
	else
	{
		if (ac == 2)
		{
			run_file(av[1]);
			exit(get_status());
		}
		if (!isatty(STDIN_FILENO))
		{
			fflush(stdout);
			read_bytes = getline(&command, &len, stdin);
			if (read_bytes == -1)
				exit(0);

			command[strcspn(command, "\n")] = '\0';
			cmds = parse_command(command);
			execute_commands(cmds);
		}
		else
			prompt();
	}
	free(err_msg);
	return (0);
}
