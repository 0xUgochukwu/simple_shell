#include "main.h"


void start_shell(void)
{
	char *command;
	char *buffer[BUFFSIZE];
	ssize_t read_chars;

	command = malloc(BUFFSIZE);
	if (command == NULL)
	{
		perror("Unable to allocate buffer");
		exit(errno);
	}
	write(STDOUT_FILENO, "$ ", 2);
	fflush(stdout);
	read_chars = getline(&command, &buffer, STDIN_FILENO);
	parse_command(command);
	free(command);
}

void execute_file(char *filename)
{
	printf("My file is %s\n", filename);
}
