#include "main.h"

void set_status(int status)
{
	g_main_status = status;
}

int get_status(void)
{
	return (g_main_status);
}

void set_num_commands(int num)
{
	g_num_commands = num;
}

int get_num_commands(void)
{
	return (g_num_commands);
}

void set_environ(char **envp)
{
	g_environ = envp;
}

char **get_environ(void)
{
	return (g_environ);
}
