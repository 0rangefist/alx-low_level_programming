#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - Entry point
 *
 * @argc: argument count
 * @argv: argument array
 *
 * Description: A program that peforms simple operations,
 * like addition, subtraction, multiplication, division & modulo.
 * Usage looks like: calc num1 operator num2;
 *
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *operator = argv[2];
	
	/* if  arguments are more than 4, bad input */
	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	/* if the operator contains more than one char, bad input */
	if (strlen(operator) != 1)
	{
		printf("Error\n");
		exit(99);
	}

	return (0);
}
