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

	main_status = status;

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
	char *path = get_path(cmd_s.cmd);
	int status = -1;
	pid_t pid;

	status = builtin_check(cmd_s.cmd, cmd_s.argv);

	if (status == 0)
		return (status);

	if (path == NULL)
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

	return (status);
}

/**
 * get_path - gets the full path of a command
 * @cmd: command to get path
 * Return: full path of cmd or null
 */

char *get_path(char *cmd)
{
	char *path = getenv("PATH");
	char *token = strtok(strdup(path), ":");
	struct stat st;
	char *full_path = NULL;


	if (stat(cmd, &st) == 0 && st.st_mode & S_IXUSR)
		return (cmd);

	while (token != NULL)
	{
		full_path = malloc(strlen(token) + strlen(cmd) + 2);
		sprintf(full_path, "%s/%s", token, cmd);

		if (stat(full_path, &st) == 0 && st.st_mode & S_IXUSR)
			return (full_path);

		if (full_path != NULL)
		{
			free(full_path);
			full_path = NULL;
		}

		token = strtok(NULL, ":");
	}



	return (NULL);
}

/**
 * builtin_check - check if command is a builtin
 * @cmd: command to run
 *
 * Return: status
 */

int builtin_check(char __attribute__((unused)) *cmd, char **args)
{
	cmds_t bi_cmds[] = {
		{"exit", bi_exit},
		{"env", bi_env},
		{NULL, NULL}
	};
	int i = 0;

	while (i < 2)
	{
		if (strcmp(cmd, bi_cmds[i].cmd) == 0)
			return (bi_cmds[i].fnc(args));
		i++;
	}
	return (-1);
}

