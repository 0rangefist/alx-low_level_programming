#include "main.h"

/**
 * print_chessboard -  prints the chessboard
 *
 * @a: 2 dimensional array of chars
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int row;
	int col;

	if (sizeof(*a) != 8 * 8)
	{
		return;
	}

	for (row = 0; row < 8; row++)
	{
		for (col = 0; col < 8; col++)
		{
			_putchar(a[row][col]);
		}
		_putchar('\n');
	}
}
