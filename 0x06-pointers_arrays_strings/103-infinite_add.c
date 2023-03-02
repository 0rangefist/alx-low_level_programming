#include <stdio.h>
#include <string.h>

/**
 * infinite_add - Adds two positive numbers represented as strings
 *
 * @n1: First number as a string
 * @n2: Second number as a string
 * @r: Buffer to store the result
 * @size_r: Size of the buffer
 *
 * Return: Pointer to the result, or 0 if the result cannot be stored in the
 * buffer
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1  = strlen(n1); /* length of first number */
	int len2  = strlen(n2); /* length of second number */
	int carry = 0;          /* carry from adding digits */
	int i     = len1 - 1;   /* index of current digit in first number */
	int j     = len2 - 1;   /* index of current digit in second number */
	int k     = 0;          /* index of current digit in result */
	int sum;                /* sum of current digits */

	/* Add digits from right to left, handling carry */
	while (i >= 0 || j >= 0 || carry)
	{
		int digit1 = i >= 0 ? n1[i] - '0'
							: 0; /* get current digit from first number */
		int digit2 = j >= 0 ? n2[j] - '0'
							: 0; /* get current digit from second number */
		sum        = digit1 + digit2 + carry; /* add current digits and carry */
		carry      = sum / 10;                /* calculate new carry */
		sum %= 10;                            /* calculate sum modulo 10 */
		if (k >= size_r - 1) /* check if result buffer is full */
		{
			return (0); /* if so, return 0 to indicate failure */
		}
		r[k++] = sum + '0'; /* add digit to result buffer and increment index */
		i--;                /* move to next digit in first number */
		j--;                /* move to next digit in second number */
	}
	r[k] = '\0'; /* terminate result string */

	/* Reverse result string */
	for (i = 0, j = k - 1; i < j; i++, j--)
	{
		char temp = r[i]; /* swap current digits */

		r[i] = r[j];
		r[j] = temp;
	}

	return (r); /* return pointer to result string */
}
