#include "main.h"


void parse_command(char *cmd)
{
	int argc = 0;
	command_t *head;
	command_t *new;
	char* f_token = strtok(str, " ");
	char seps[3] = {";", "&&", "||"};

	head = NULL;
	new = malloc(sizeof(command_t));
	if (!new)
		return (NULL);

	while (seps[i])
	{
		if (f_token == seps[i])
			return(NULL);
		i++;
	}


	if (*head == NULL)
	{
		*head = temp;
		return (temp);
	}

	while (f_token != NULL) 
	{
		add_arg(&new->argv, f_token);
		new->cmd = strcat("/bin/", f_token);
		new->separator = f_token;

			printf("%s ", token);
		token = strtok(NULL, " ");
	}
}
