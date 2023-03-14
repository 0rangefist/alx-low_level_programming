#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 *
 * @width: width of the 2d array
 * @height: height of the 2d array
 *
 * Return: pointer to the 2d array or NULL on failure
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int	  i = 0;
	int	  j = 0;

	if (height <= 0 || width <= 0) /* check for invalid input */
		return (NULL);
	/* allocate the first dimension of the array*/
	grid = malloc(height * sizeof(int *));

	if (grid == NULL) /* on allocation fail, return NULL */
		return (NULL);

	/* allocate 2nd dimension of the array */
	for (i = 0; i < height; i++)
	{
		grid[i] = malloc(width * sizeof(int));

		if (grid[i] == NULL) /* on allocation fail */
			return (NULL);
		/* initialize grid elements to 0 */
		for (j = 0; j < width; j++)
		{
			grid[i][j] = 0;
		}
	}
	return (grid); /* return poiter to 2d array */
}
