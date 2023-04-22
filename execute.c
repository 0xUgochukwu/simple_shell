#include "main.h"

extern char **environ;


/**
 * execute_commands - executes all comands from user
 * @cmds: array of all comands
 *
 * Return: void
 */


int execute_commands(command_t *cmds)
{
	int i, status, op_check;

	for (i = 0; i < num_commands; i++)
	{
		if (cmds[i].op == NULL)
			status = execute_cmd(cmds[i]);
		else
		{
			op_check = operator_check(cmds[i].op, status);
			if (op_check)
				status = execute_cmd(cmds[i]);
			else
				return (status);
		}
	}

	return (status);
}

/**
 * operator_check - checks using an operator if the next command
 * should be executed or not
 * @op: operator
 * @status: status of previous command
 * Return: 1 if next should be executed, 0 if it shouldn't
 */

int operator_check(char *op, int status)
{
	if (strcmp(op, "&&") == 0)
	{
		if (status == 0)
			return (1);
		else
			return (0);
	}
	else if (strcmp(op, "||") == 0)
	{
		if (status != 0)
			return (1);
		else
			return (0);
	}
	else
		return (1);
}

/**
 * execute_cmd - execute cmd
 * @cmd: command struct
 *
 * Return: void
 */

int execute_cmd(command_t cmd_s)
{
	char **paths = get_paths();
	char *path = malloc(BUFFSIZE);
	struct stat sb;
	int i, status = -1;
	pid_t pid;

	status = builtin_check(cmd_s.cmd);

	for (i = 0; i < num_paths; i++)
	{
		sprintf(path, "%s/%s", strdup(paths[i]), cmd_s.cmd);
		printf("%s\n", path);
		status = stat(path, &sb);
		printf("%d\n", num_paths);
		if (status == 0)
			break;
	}

	if (status == -1)
	{
		perror("path");
		return (EXIT_FAILURE);
	}

	pid = fork();


	if (pid == -1)
	{
		perror("fork");
		return (EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/* Child process */
		execve(path, cmd_s.argv, environ);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Parent process */
		if (waitpid(pid, &status, 0) == -1)
		{
			perror("waitpid");
			return (EXIT_FAILURE);
		}

		if (WIFEXITED(status))
		{
			/* Child process terminated normally */
			if (WEXITSTATUS(status) != 0)
			{
				fprintf(stderr, "Command \"%s\" failed with exit code %d\n",
						cmd_s.cmd, WEXITSTATUS(status));
				return (EXIT_FAILURE);
			}
		}
		else
		{
			/* Child process terminated abnormally */
			fprintf(stderr, "Command \"%s\" terminated abnormally\n", cmd_s.cmd);
			return EXIT_FAILURE;
		}
	}
	i = 0;
	while (paths[i++])
		free(paths[i]);
	free(paths);

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
		printf("%s\n", paths[num_paths]);
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

