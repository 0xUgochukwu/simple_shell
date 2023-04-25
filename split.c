#include "main.h"

/**
 * split - split a command into an array of commands
 * @cmd: command to split
 *
 * Return: pointer to array of commands
 */

command_t *split(char *cmd)
{
	int argc = 0, i, num_commands = 1;
	char *token;
	command_t *commands = malloc(sizeof(command_t));

	commands[0].op = NULL;
	commands[0].argv = malloc(sizeof(char *));
	token = strtok(cmd, " ");
	while (token != NULL)
	{
		i = num_commands - 1;
		if (*token == '#')
			break;
		if (*token == ';' || *token == '&' || *token == '|')
		{
			if (argc > 0)
				commands[i].cmd = commands[i].argv[0];
			else
				commands[i].cmd = NULL;

			commands = realloc(commands, (++num_commands) * sizeof(command_t));
			commands[i++].op = (*token == ';') ? NULL : token;
			commands[i].argv = malloc(sizeof(char *));
			argc = 0;
		}
		else
		{
			commands[i].argv = realloc(commands[i].argv, (argc + 2) * sizeof(char *));
			commands[i].argv[argc++] = strdup(token);
			commands[i].argv[argc] = NULL;
		}
		token = strtok(NULL, " ");
	}
	if (argc > 0)
		commands[num_commands - 1].cmd = commands[num_commands - 1].argv[0];
	else
		commands[num_commands - 1].cmd = NULL;
	set_num_commands(num_commands);

	return (commands);
}
