#include "main.h"
#include <stdio.h>

/**
 * print_times_table - prints the nth times table,
 * starting with 0
 * @n: nth number of table
 * Return: void
 */

void print_times_table(int n)
{
	int i;
	int j;
	int product;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				product = i * j;
				if (product >= 100 && j != 0)
				{
					printf(" ");
				}
				else if (product >= 10 && j != 0)
				{
					printf("  ");
				}
				else if (j != 0)
				{
					printf("   ");
				}
				printf("%d", product);
				if (j != n)
				{
					printf(",");
				}
			}
			printf("\n");
		}
	}
}
