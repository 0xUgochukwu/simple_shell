#include "main.h"

/**
 * parse_command - format a command to be executed
 * @cmd: command to parse
 *
 * Return: void
 */
command_t *parse_command(char *cmd)
{
	command_t *commands = NULL;
	char *cmd_copy = NULL;

	cmd_copy = replace_aliases(cmd);
	cmd_copy = replace_s_vars(cmd_copy);
	commands = split(cmd_copy);

	return (commands);
}

/**
 * replace_aliases - replace aliases in a command
 * @cmd: command to replace aliases in
 *
 * Return: pointer to new string
 */

char *replace_aliases(char *cmd)
{
	return (cmd);
}

/**
 * replace_s_vars - replace special variables in a string
 * @cmd: the string to replace variables in
 *
 * Return: a string with variables replaced
 */

char *replace_s_vars(char *cmd)
{
	char *new_cmd = malloc(strlen(cmd) * sizeof(char) + 1);
	char *p = new_cmd;
	char *s = cmd;

	while (*s)
	{
		if (s[0] == '$' && s[1] == '?')
		{
			/* Replace $? with main_status */
			sprintf(p, "%d", get_status());
			p += strlen(p);
			s += 2;
		}
		else if (s[0] == '$' && s[1] == '$')
		{
			/* Replace $$ with the process ID */
			sprintf(p, "%d", getpid());
			p += strlen(p);
			s += 2;
		}
		else
		{
			/* Copy regular character */
			*p++ = *s++;
		}
	}

	/* Null-terminate the new string */
	*p = '\0';

	return (new_cmd);
}
