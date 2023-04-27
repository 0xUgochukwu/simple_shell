#include "main.h"

/**
 * bi_cd - ...
 *
 * @argv: arguments
 * Return: int
 */

int bi_cd(char __attribute__((unused)) **argv)
{
	struct stat st;
	char *path = argv[1] == NULL ? _getenv("HOME") : argv[1];

	if (_strcmp(path, ".") == 0)
		return (0);

	if (_strcmp(path, "-") == 0)
		path = _getenv("OLDPWD");

	if (stat(path, &st) == 0 && st.st_mode & S_IXUSR)
	{
		setenv("OLDPWD", _getenv("PWD"), 1);
		chdir(path);
		setenv("PWD", path, 1);

		return (0);
	}

	perror("cd");

	return (1);
}

/**
 * bi_alias - ...
 *
 * @argv: arguments
 * Return: int
 */

int bi_alias(char __attribute__((unused)) **argv)
{
	int i = 1, j = 0;
	char *alias_name, *alias, *token;

	alias_name = malloc(BUFFSIZE);
	alias = malloc(BUFFSIZE);

	while (argv[i])
	{
		printf("%s\n", argv[i]);
		while (token != NULL)
		{
			if (j == 0)
				alias_name = token;
			alias = token;
			token = strtok(strdup(argv[i]), "=");
			token = strtok(NULL, "=");
			j++;
		}
		printf("%s\n", alias_name);
		printf("%s\n", alias);
		i++;
	}

	return (0);
}
