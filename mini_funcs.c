#include "main.h"


extern char **environ;

/**
 * parse_command - format a command to be executed
 * @cmd: command to parse
 *
 * Return: void
 */

void parse_command(char *cmd)
{
    command_t *commands = NULL;
    char *cmd_copy = NULL;

    cmd_copy = replace_aliases(cmd);
    cmd_copy = replace_vars(cmd_copy);
    commands = split(cmd_copy);

    execute_commands(commands);
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
 * replace_vars - replace variables in a command
 * @cmd: command to replace variables in
 *
 * Return: pointer to new string
 */

char *replace_vars(char *cmd)
{
    char *result;
    char *p;
    char *q;
    char *var_start;
    char *var_end;
    char *var_value;

    result = (char *)malloc(strlen(cmd) + 1);
    p = cmd;
    q = result;

    while (*p != '\0')
    {
        if (*p == '$' && *(p + 1) != '\0')
        {
            var_start = p + 1;
            var_end = var_start;

            while (*var_end != '\0' && isalnum(*var_end))
            {
                var_end++;
            }

            *var_end = '\0';
            var_value = getenv(var_start);

            if (var_value != NULL)
            {
                q += sprintf(q, "%s", var_value);
                p = var_end;
            }
            else
            {
                *q++ = '$';
                q += sprintf(q, "%s", var_start);
                p = var_end;
            }
        }
        else
        {
            *q++ = *p++;
        }
    }

    *q = '\0';
    return result;
}




