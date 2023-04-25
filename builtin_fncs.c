#include "main.h"

extern char **environ;

/**
 * bi_exit - ...
 *
 * @argv:
 * Return: int
 */

int bi_exit(char **argv)
{
	int status = is_num(argv[1]);

	if (status >= 0)
		exit(status);
	else
	{
		perror("status");
		return (1);
	}
}


/**
 * bi_env - ...
 *
 * @argv: 
 * Return: int
 */

int bi_env(char __attribute__((unused)) **argv)
{
	char **env = environ;
	while (*env)
	{
		fprintf(stdout, "%s\n", *env);
		env++;
	}
	return (0);
}

/**
 * bi_env - ...
 *
 * @argv: 
 * Return: int
 */

int bi_setenv(char **argv)
{
	char **env = environ;
	char *newenv, *envname;
	int i = 0, j = -1;

	if (argv[1] == NULL || argv[2] == NULL)
	{
		perror("missing argument");
		return (1);
	}

	newenv = malloc(BUFFSIZE);
	sprintf(newenv, "%s=%s", argv[1], argv[2]);
	while (env[i])
	{
		envname = strtok(strdup(env[i]), "=");
		if (strcmp(argv[1], envname) == 0)
			j = i;	
		i++;
	}

	if (j >= 0 && j != i)
		environ[j] = newenv;
	else
	{
		environ[i++] = newenv;
		environ[i] = NULL;
	}

	return (0);
}


/**
 * bi_env - ...
 *
 * @argv: 
 * Return: int
 */

int bi_unsetenv(char **argv)
{
	char **env = environ;
	char *envname;
	int i = 0, j = -1;

	if (argv[1] == NULL)
	{
		perror("missing argument");
		return (1);
	}

	while (env[i])
	{
		envname = strtok(strdup(env[i]), "=");
		if (strcmp(argv[1], envname) == 0)
			j = i;	
		i++;
	}

	if (j < 0)
		return (0);

	while (j >= 0 && j < (i - 1))
	{
		environ[j] = environ[j + 1];
		j++;
	}

	environ[j] = NULL;

	return (0);
}


/**
 * bi_env - ...
 *
 * @argv: 
 * Return: int
 */

int bi_cd(char __attribute__((unused)) **argv)
{
	struct stat st;
	char *path = argv[1] == NULL ? getenv("HOME") : argv[1];

	if (strcmp(path, ".") == 0)
		return (0);

	if (strcmp(path, "-") == 0)
		path = getenv("OLDPWD");

	if (stat(path, &st) == 0 && st.st_mode & S_IXUSR)
	{
		setenv("OLDPWD", getenv("PWD"), 1);
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
 * @argv: 
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


/**
 * is_num - ...
 *
 * @argv:
 * Return: int
 */

int is_num(char *str)
{
	char *num = str;

	if (str == NULL)
		return (0);
	while (*num)
	{
		if (isdigit(*num) == 0)
			return (-1);
		num++;
	}

	return (atoi(str));
}
