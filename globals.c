#include "main.h"


void set_status(int status)
{
	g_main_status = status;
}

int get_status(void)
{
	return (g_main_status);
}
