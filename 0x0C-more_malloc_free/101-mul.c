#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 * multiply - multiply two arbitrarily long positive numbers
 *
 * @num1: first number
 * @num2: second number
 *
 * Return: the result of the multiplication as a string
 */
char *multiply(char *num1, char *num2)
{
	int	  i;
	int	  j;
	int	  carry;
	char *trimmed;
	int	  len1 = strlen(num1);
	int	  len2 = strlen(num2);
	int product;

	/* allocate memory for the result */
	char *result = malloc(sizeof(*result) * (len1 + len2 + 1));

	for (i = 0; i < len1 + len2; i++) /* set each element in memory to 0 */
		result[i] = '0';
	result[len1 + len2] = '\0'; /* set last element to null byte */

	if (result == NULL)/*on allocation fail*/
		return (NULL);
	/* multiply the two numbers digit by digit */
	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0')
						  + (result[i + j + 1] - '0') + carry;
			result[i + j + 1] = (product % 10) + '0';
			carry			  = product / 10;
		}
		result[i] = result[i] + carry;
	}
	/* remove leading zeros */
	trimmed = result;
	while (*trimmed == '0' && *(trimmed + 1) != '\0')
		trimmed++;
	/* return the result as a string */
	return (trimmed);
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
	char *result;

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

	/* multiplication of the 2 positive numbers */
	result = multiply(argv[1], argv[2]);
	if (result == NULL) 
	{
		printf("Error\n");
		exit(98);
	}
	
	printf("%s\n", result);

	return (0);
}
