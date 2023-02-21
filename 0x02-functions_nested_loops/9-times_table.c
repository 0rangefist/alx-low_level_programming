#include "main.h"

/**
 * times_table - t prints the 9 times table,
 * starting with 0
 * Return: void
 */

void times_table(void)
{
	int i;
	int j;
	int product;

	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			product = i * j;
			if (product >= 10)
			{
				if (j != 0)
				{
					_putchar(' ');
				}
				_putchar('0' + (product / 10));
				_putchar('0' + (product % 10));
			}
			else
			{
				if (j != 0)
				{
					_putchar(' ');
					_putchar(' ');
				}
				_putchar('0' + product);
			}
			if (j != 9)
			{
				_putchar(',');
			}
		}
		_putchar('\n');
	}
}
