#include "main.h"


int main_status = 0;

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
	cmd_copy = replace_vars(cmd_copy);
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
	return cmd;
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
			sprintf(p, "%d", main_status);
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

	return new_cmd;
}



/**
 * replace_vars - replace variables in a command
 * @cmd: command to replace variables in
 *
 * Return: pointer to new string
 */

char *replace_vars(char *cmd)
{
	char *result = NULL;
	char *p = cmd;
	char *q = NULL;
	char var_name[256] = {0};
	char *var_value = NULL;
	int i = 0;

	while (*p != '\0') 
	{
		if (*p == '$' && *(p + 1) != '\0')
		{
			p++;

			while (*p != '\0' && isalnum(*p))
			{
				var_name[i] = *p;
				i++;
				p++;
			}

			var_name[i] = '\0';

			var_value = getenv(var_name);

			if (var_value != NULL) {
				if (result == NULL) {
					result = (char *)malloc(strlen(cmd) + strlen(var_value) + 1);
					q = result;
				} 
				else
				{
					result = (char *)realloc(result, strlen(result) + strlen(var_value) + 1);
					q = result + strlen(result);
				}

				q += sprintf(q, "%s", var_value);
			}
			else
			{
				if (result == NULL) {
					result = (char *)malloc(strlen(cmd) + strlen(var_name) + 1);
					q = result;
				}
				else 
				{
					result = (char *)realloc(result, strlen(result) + strlen(var_name) + 1);
					q = result + strlen(result);
				}

				q += sprintf(q, "$%s", var_name);
			}
		}
		else 
		{
			if (result == NULL)
			{
				result = (char *)malloc(2);
				q = result;
			}
			else 
			{
				result = (char *)realloc(result, strlen(result) + 2);
				q = result + strlen(result);
			}

			*q = *p;
			q++;
			p++;
		}
	}

	if (result == NULL) {
		result = (char *)malloc(1);
		result[0] = '\0';
	} else {
		q = result + strlen(result);
		*q = '\0';
	}

	return result;
}
