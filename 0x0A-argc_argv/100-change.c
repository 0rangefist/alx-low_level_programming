#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument array
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	int cents, coins = 0;

	/* Check that exactly one argument is passed */
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	/* Convert argument to integer */
	cents = atoi(argv[1]);

	/* Check that the amount is not negative */
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	/* Count the number of coins of each type needed */
	coins += cents / 25;
	cents = cents % 25;

	coins += cents / 10;
	cents = cents % 10;

	coins += cents / 5;
	cents = cents % 5;

	coins += cents / 2;
	cents = cents % 2;

	coins += cents;

	/* Print the result */
	printf("%d\n", coins);

	return (0);
}
