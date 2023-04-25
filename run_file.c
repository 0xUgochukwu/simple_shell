#include "main.h"

/**
 * run_file - reads and executes commands from a file
 *
 * @file_name: name of file to read commands from
 */
void run_file(char *file_name)
{
	FILE *fp = fopen(file_name, "r");
	char *line = NULL;
	size_t len = 0;
	ssize_t read_size;
	command_t *cmds;
	size_t num_commands = 0;

	if (fp == NULL)
	{
		perror("fopen");
		return;
	}

	while ((read_size = getline(&line, &len, fp)) != -1)
	{
		if (line[read_size - 1] == '\n')
		{
			line[read_size - 1] = '\0';
		}

		if (line == NULL)
			continue;

		cmds = malloc(sizeof(command_t));
		cmds = parse_command(line);
		if (cmds != NULL)
		{
			execute_commands(cmds);
			free_commands(cmds, num_commands);
		}
	}

	if (line != NULL)
		free(line);

	fclose(fp);

}

/**
 * free_commands - frees the memory allocated for a command_t struct
 *
 * @cmds: command_t struct to be freed
 * @n_cmds: number of commands
 */

void free_commands(command_t *cmds, size_t n_cmds)
{
	size_t i, j;

	for (i = 0; i < n_cmds; i++)
	{
		free(cmds[i].cmd);
		free(cmds[i].op);

		if (cmds[i].argv != NULL)
		{
			j = 0;
			while (cmds[i].argv[j])
			{
				free(cmds[i].argv[j]);
				cmds[i].argv[j] = NULL; 
				j++;
			}
			free(cmds[i].argv);
			cmds[i].argv = NULL; 
		}
	}

	if (cmds != NULL)
		free(cmds);
}

