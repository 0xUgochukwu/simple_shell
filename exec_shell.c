#include "main.h"



void prompt (void)
{
    char *command;
    size_t len = 0;
    ssize_t read_bytes;
    command_t *cmds;

    do {
        write(STDOUT_FILENO, "$ ", 2);
        fflush(stdout);
        read_bytes = getline(&command, &len, stdin);

        if (read_bytes == -1)
        break;

	command[strcspn(command, "\n")] = '\0';

        cmds = parse_command(command);

	execute_commands(cmds);

    } while (strcmp("exit\n", command) != 0);
}

void execute_file(char *filename)
{
    printf("My file is %s\n", filename);
}


