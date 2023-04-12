#include "3-calc.h"
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
	int	  num1;
	int	  num2;
	char *operator;
	int (*operation)(int, int);

	if (argc != 4) /* if arguments are more than 4, bad input */
	{
		printf("Error\n");
		exit(98);
	}

	/* put the arguments supplied by user into variables */
	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	operator = argv[2];

	/* if the operator contains more than one char, bad input */
	if (strlen(operator) > 1)
	{
		printf("Error\n");
		exit(99);
	}

	/* the operator string we get from user will be passed along */
	/* as an argument so we can get the right operation function */
	operation = get_op_func(operator);

	/* If func ptr returned is NULL, then it's a bad input */
	if (operation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	/* with the right operation function, run and print its result*/
	printf("%d\n", operation(num1, num2));

	return (0);
}
