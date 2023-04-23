#include "main.h"


/**
 * split - split a command into an array of commands
 * @cmd: command to split
 *
 * Return: pointer to array of commands
 */


command_t *split(char *cmd)
{
	int argc = 0;
	char *token;
	command_t *commands = malloc(sizeof(command_t));

	num_commands = 1;
	commands[0].op = NULL;
	commands[0].argv = malloc(sizeof(char*));

	token = strtok(cmd, " ");

	while (token != NULL)
	{
		if (*token == ';' || *token == '&' || *token == '|') {
			/* End the current command and start a new one */

			if (argc > 0)
				commands[num_commands - 1].cmd = commands[num_commands - 1].argv[0];
			else
				commands[num_commands - 1].cmd = NULL;

			commands = realloc(commands, (++num_commands) * sizeof(command_t));
			commands[num_commands - 1].op = (*token == ';') ? NULL : token;
			commands[num_commands - 1].argv = malloc(sizeof(char*));

			argc = 0;
		}
		else
		{
			/* Add the current token to the current command's argv array */
			commands[num_commands - 1].argv = realloc(commands[num_commands - 1].argv, (argc + 2) * sizeof(char*));
			commands[num_commands - 1].argv[argc++] = strdup(token);
			commands[num_commands - 1].argv[argc] = NULL;
		}

		token = strtok(NULL, " ");
	}
	/* Set the last command's cmd field */
	if (argc > 0)
		commands[num_commands - 1].cmd = commands[num_commands - 1].argv[0];

	else
		commands[num_commands - 1].cmd = NULL;

	return commands;
}
