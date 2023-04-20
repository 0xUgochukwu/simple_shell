#include "main.h"



/**
 * parse_command - format a command to be executed
 * @cmd: command to parse
 *
 * Return: void
 */

void parse_command(char *cmd)
{
	command_t *commands = NULL;
	char *cmd_copy = NULL;

	cmd_copy = replace_aliases(cmd);
	cmd_copy = replace_vars(cmd_copy);
	commands = split(cmd_copy);

	execute_commands(commands);
}



/**
 * replace_aliases - replace aliases in a command
 * @cmd: command to replace aliases in
 *
 * Return: pointer to new string
 */

char *replace_aliases(char *cmd)
{
	return cmd;
}



/**
 * replace_vars - replace variables in a command
 * @cmd: command to replace variables in
 *
 * Return: pointer to new string
 */

char *replace_vars(char *cmd)
{
	char *result;
	char *p;
	char *q;
	char *var_start;
	char *var_end;
	char *var_value;

	result = (char *)malloc(strlen(cmd) + 1);
	p = cmd;
	q = result;

	while (*p != '\0')
	{
		if (*p == '$' && *(p + 1) != '\0')
		{
			var_start = p + 1;
			var_end = var_start;

			while (*var_end != '\0' && isalnum(*var_end))
			{
				var_end++;
			}

			*var_end = '\0';
			var_value = getenv(var_start);

			if (var_value != NULL)
			{
				q += sprintf(q, "%s", var_value);
				p = var_end;
			}
			else
			{
				*q++ = '$';
				q += sprintf(q, "%s", var_start);
				p = var_end;
			}
		}
		else
		{
			*q++ = *p++;
		}
	}

	*q = '\0';
	return result;
}

/**
 * execute_cmd - execute cmd
 * @cmd: command struct
 *
 * Return: void
 */

int execute_cmd(command_t *cmd_s)
{
	char **paths = get_paths();
	char *path;
	struct stat sb;
	int i, status = -1;
	pid_t pid;

	status = builtin_check(cmd_s->cmd);
	if (status == -1)
	{
		for (i = 0; i < num_paths; i++)
		{
			path = strcat(paths[i], "/");
			strcat(path, cmd_s->cmd);
			status = stat(path, &sb);
			if (status == 0)
				break;
		}

		i = 0;
		while (paths[i] != NULL)
		{
			free(paths[i]);
			i++;
		}

		free(paths);
		if (status == -1)
			return (status);
		pid = fork();
		if (pid == -1)
			return (pid);
		else if (pid == 0)
		{
			if (execve(path, cmd_s->argv, environ) == -1)
				return (-1);
		}
		else
			wait(&status);
	}

	return (status);
}

/**
 * get_paths - gets all paths
 *
 * Return: Array of paths
 */

char **get_paths(void)
{
	char *str = getenv("PATH");
	char **paths = malloc(BUFFSIZE);
	char *token = strtok(str, ":");

	num_paths = 0;
	while (token != NULL)
	{
		paths[num_paths] = malloc(BUFFSIZE);
		strcpy(paths[num_paths], token);
		token = strtok(NULL, ":");
		num_paths++;
	}

	return paths;
}

/**
 * builtin_check - check if command is a builtin
 * @cmd: command to run
 *
 * Return: status
 */

int builtin_check(char __attribute__((unused)) * cmd)
{
	return (-1);
}
