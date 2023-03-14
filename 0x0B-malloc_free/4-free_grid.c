#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees the memory allocated to a 2d grid
 *
 * @grid: the 2d array
 * @height: height of the 2d array
 *
 * Return: pointer to the 2d array or NULL on failure
 */
void free_grid(int **grid, int height)
{
	int i = 0;

	/* free 2d array */
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
