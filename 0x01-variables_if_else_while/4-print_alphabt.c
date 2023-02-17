#include <stdio.h>

/**
 *main - Entry point
 *
 *Description: Prints the alphabet in lowercase
 *and uppercase, followed by a new line
 *using only the putchar function twice.
 *
 *Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 97; i < 123; i++)
	{
		if (i == (int)
			'q' || i == (int)
			'e')
		{
			/* do nothing */
		}
		else
		{
			putchar(i);
		}
	}

	putchar('\n');

	return (0);
}
