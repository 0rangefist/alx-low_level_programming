#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * check_num - check if string is a positive number
 *
 * @string: string to be checked
 *
 * Return: 1 if string is a positive integer, 0 otherwise
 */
int check_num(char *string)
{
	int i = 0;

	/* if any char isnt a digit return 0 */
	while (string[i] != '\0')
	{
		if (!(string[i] >= '0' && string[i] <= '9'))
		{
			return (0);
		}
		i++;
	}

	/* if while loop completed, then string is a number */
	return (1);
}

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument array
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	/* check that we have correct num of inputs */
	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}

	/* check if arg1 & arg2 contain only digits */
	if (check_num(argv[1]) == 0 || check_num(argv[2]) == 0)
	{
		printf("Error\n");
		exit(98);
	}

	/* print the multiplication of the 2 positive numbers */
	printf("%d\n", (atoi(argv[1]) * atoi(argv[2])));

	return (0);
}
