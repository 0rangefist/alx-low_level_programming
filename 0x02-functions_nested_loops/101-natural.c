#include <stdio.h>

/**
 * main - prints the sum of all multiples of 3 or 5 below 1024
 * Return: 0
 */

int main(void)
{
	int num;
	int sum;

	num = 0;
	sum = 0;

	while (num < 1024)
	{
		if (num % 3 == 0 || num % 5 == 0)
		{
			sum = sum + num;
		}
		num++;
	}

	printf("%i\n", sum);
	return (0);
}
