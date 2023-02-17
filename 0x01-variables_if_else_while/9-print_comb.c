#include <stdio.h>

/**
 *main - Entry point
 *
 *Description: Prints rints all possible
 *combinations of single-digit numbers
 *
 *Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
	{
		putchar(i + '0');

		if (i != 9)
		{
			putchar(',');
			putchar(' ');
		}
		else
		{
			putchar('\n');
		}

	}

	return (0);
}
