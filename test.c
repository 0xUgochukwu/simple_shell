#include "main.h"


void start_shell(void)
{
	char *command;
	
	do {

	command = prompt();
	if (!command)
	{
		perror("Error reading Input\n");
	}
	} while (!command);
	/*parse_command(command);*/
}

char *prompt (void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t read_bytes;

	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
	read_bytes = getline(&command, &len, stdin);

	free(command);
	if (read_bytes == -1)
		return (NULL);


	return (command);
}



void throw_error(char *err)
{
	perror(err);
}
