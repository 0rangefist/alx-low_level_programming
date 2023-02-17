#include <stdio.h>

/**
 *main - Entry point
 *
 *Description: Prints the alphabet in lowercase and uppercase,
 *followed by a new line using only the putchar function three
 *times.
 *
 *Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 97; i < 123; i++)
	{
		putchar(i);
	}

	for (i = 65; i < 91; i++)
	{
		putchar(i);
	}

	putchar('\n');

	return (0);
}
