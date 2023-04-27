#include "main.h"

/**
 * replace_vars - replace variables
 * @cmd: command struct
 *
 * Return: void
 */

void replace_vars(command_t cmd)
{
	int i = 1, j = 0;
	char **args = cmd.argv;
	char *var;

	while (args[i])
	{
		var = malloc(_strlen(args[i]) * sizeof(char));
		if (args[i][j] == '$')
		{
			j++;
			while (args[i][j] != '\0' && (_isalnum(args[i][j]) || args[i][j] == '_'))
			{
				var[j - 1] = args[i][j];
				j++;
			}

			var[j] = '\0';
			_strcpy(cmd.argv[i], getenv(var));
		}
		i++;
		j = 0;
	}
}

/**
 * throw_error - error
 *
 * @error: error
 * Return: void
 */

int throw_error(char *error)
{
	perror(error);
	return (EXIT_FAILURE);
}
