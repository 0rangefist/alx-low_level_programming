#include <stdio.h>

/**
 * print_buffer - Prints the contents of a buffer
 *
 * @b: Pointer to buffer
 * @size: Size of buffer in bytes
 *
 * Return: void
 */
void print_buffer(char *b, int size)
{
	int i, j;

	if (size <= 0) /* check for empty buffer */
	{
		printf("\n");
		return;
	}
	/* iterate through buffer in 10-byte chunks */
	for (i = 0; i < size; i += 10)
	{
		/* print position of first byte in line */
		printf("%08x: ", i);

		/* print hexadecimal representation of 10 bytes, 2 bytes at a time */
		for (j = i; j < i + 10; j += 2)
		{
			if (j < size)
				printf("%02x", *(unsigned char *) (b + j));
			else
				printf("  ");
			if (j + 1 < size)
				printf("%02x ", *(unsigned char *) (b + j + 1));
			else
				printf("   ");
		}

		/* print ASCII representation of 10 bytes */
		for (j = i; j < i + 10; j++)
		{
			if (j >= size)
				printf(" ");
			else if (*(b + j) >= 32 && *(b + j) <= 126)
				printf("%c", *(b + j));
			else
				printf(".");
		}
		printf("\n"); /* end line */
	}
}
