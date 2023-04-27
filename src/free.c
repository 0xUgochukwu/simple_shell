#include "shell.h"

/**
 *free_grid - Free the allocated memory used in the last excercise
 *@grid: pointer to grid
 *@heigth: Heigth of the grid
 */
void free_grid(char **grid, int heigth)
{

	int i = 0;

	if (grid == NULL)
		return;

	while (i < heigth)
	{
		free(grid[i]);
		i++;
	}
}

/**
 * free_mem - Free the memory for the last execution
 * @entry: Input first entry
 */
void free_mem(char *entry)
{
	if (isatty(STDIN_FILENO))
	{
		_putchar('\n');
		free(entry);
	}
	if (!isatty(STDIN_FILENO))
		free(entry);
}
