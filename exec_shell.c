#include "main.h"


void start_shell(void)
{
	char *command;

	command = prompt();
	if (!command)
		throw_error("Erroer reading Input");
	/*parse_command(command);*/
}

char *prompt (void)
{
	char *command;
	size_t len = 0;
	ssize_t read_bytes;

	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
	read_bytes = getline(&command, &len, STDIN_FILENO);

	if (read_bytes == -1)
		return (NULL);

	return (command);
}

void execute_file(char *filename)
{
	printf("My file is %s\n", filename);
}


void throw_error(char *err)
{
	perror(err);
	start_shell();	
}
