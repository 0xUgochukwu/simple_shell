#include "main.h"

/**
 * split - split a command into an array of commands
 * @cmd: command to split
 *
 * Return: pointer to array of commandss
 */

command_t *split(char *cmd)
{
	int argc = 0, n = 1;
	char *token;
	command_t *cmds = malloc(sizeof(command_t));

	n = 1;
	cmds[0].op = NULL;
	cmds[0].argv = malloc(sizeof(char *));
	token = strtok(cmd, " ");
	while (token != NULL)
	{
		if (*token == '#')
			break;
		if (*token == ';' || *token == '&' || *token == '|')
		{
			if (argc > 0)
				cmds[n - 1].cmd = cmds[n - 1].argv[0];
			else
				cmds[n - 1].cmd = NULL;
			cmds = realloc(cmds, (++n) * sizeof(command_t));
			cmds[n - 1].op = (*token == ';') ? NULL : token;
			cmds[n - 1].argv = malloc(sizeof(char *));
			argc = 0;
		}
		else
		{
			cmds[n - 1].argv = realloc(cmds[n - 1].argv, (argc + 2) * sizeof(char *));
			cmds[n - 1].argv[argc++] = strdup(token);
			cmds[n - 1].argv[argc] = NULL;
		}

		token = strtok(NULL, " ");
	}
	if (argc > 0)
		cmds[n - 1].cmd = cmds[n - 1].argv[0];
	else
		cmds[n - 1].cmd = NULL;
	set_num_commands(n);
	return (cmds);
}
