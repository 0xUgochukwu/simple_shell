#include "main.h"


/**
 * set_status - sets status global variable
 * @status: status to set to
 */

void set_status(int status)
{
	g_main_status = status;
}

/**
 * get_status - gets the status global variable
 * Return: global status variable
 */

int get_status(void)
{
	return (g_main_status);
}


/**
 * set_num_commands - sets num_commands global variable
 * @num: number to set to
 */

void set_num_commands(int num)
{
	g_num_commands = num;
}

/**
 * get_num_commands - gets the num_commands global variable
 * Return: global num_commands variable
 */
int get_num_commands(void)
{
	return (g_num_commands);
}
