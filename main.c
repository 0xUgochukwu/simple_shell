#include "main.h"

/**
 * main - entry point for the simple shell program
 *
 * Return: Always 0.
 */
int main(void)
{
	       char *line = NULL, **args = NULL;
        size_t line_size = 0;
        ssize_t read = 0;
        int status = 0, interactive = isatty(STDIN_FILENO);;

        while (1)
        {
                /* Display prompt and get command line */
		if (interactive)
                        _puts("$ ");
                read = getline(&line, &line_size, stdin);
                if (read == -1)
                        break;

                /* Remove newline character */
                if (line[read - 1] == '\n')
                        line[read - 1] = '\0';

                /* Split command line into arguments */
                args = split_line(line);

                /* Execute command */
                status = execute(args);

                /* Free memory and reset variables */
                free(line);
                free(args);
                line = NULL;
                args = NULL;
        }

        /* Free any remaining memory */
        free(line);
        free(args);

        /* Exit the shell */

	if (interactive)
        	_puts("\n");
        return (status);
}

/**
 * execute - execute a command with arguments
 * @args: list of arguments
 *
 * Return: 1 on success, 0 on failure.
 */
int execute(char **args)
{
	pid_t pid = 0;
	int status = 0;

	/* Fork a new process */
	pid = fork();

	/* Check for errors */
	if (pid == -1)
	{
		perror("fork");
		return (0);
	}
	else if (pid == 0)
	{
		/* Child process */

		/* Attempt to execute command */
		if (execve(args[0], args, environ) == -1)
		{
			/* Command not found */
			perror("execve");
			_exit(127);
		}
	}
	else
	{
		/* Parent process */

		/* Wait for child to complete */
		do
		{
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (1);
}

/**
 * split_line - split a command line into arguments
 * @line: command line
 *
 * Return: array of arguments
 */
char **split_line(char *line)
{
	char **args = NULL;
	char *token = NULL;
	size_t i = 0;

	/* Allocate memory for arguments */
	args = malloc(ARG_MAX * sizeof(char *));
	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* Split line into tokens */
	token = strtok(line, " ");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}

	/* Set last argument to NULL */
	args[i] = NULL;

	return (args);
}


int _puts(const char *str) {
    int num_chars = 0;
    while (*str != '\0')
    {
        write(STDOUT_FILENO, str++, 1);
        num_chars++;
    }
    return num_chars;
}
