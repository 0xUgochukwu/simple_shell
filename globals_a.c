#include "main.h"


/**
 * set_environ - sets environment global variable
 * @envp: environ to set to
 */

void set_environ(char **envp)
{
	g_environ = envp;
}


/**
 * get_environ - gets the environment global variable
 * Return: global environ variable
 */

char **get_environ(void)
{
	return (g_environ);
}
