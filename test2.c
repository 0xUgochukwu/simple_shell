#include "main.h"

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

	i = 0;
	while (paths[i++])
		free(paths[i]);

	return (status);
}

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

int builtin_check(char __attribute__((unused)) * cmd)
{
	return (-1);
}
