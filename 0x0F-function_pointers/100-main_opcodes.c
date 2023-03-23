#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of main
 * @argc: argument count
 * @argv: argument array
 *
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	char *opcodes;
	int	  i;
	int	  num_of_bytes;

	/* if arguments is not exactly 2, bad input*/
	if (argc != 2)
	{
		printf("Error\n");
		exit(1);
	}

	/* convert the string of the num of bytes into an int */
	num_of_bytes = atoi(argv[1]);

	/* Error on -ve number of bytes*/
	if (num_of_bytes < 0)
	{
		printf("Error\n");
		exit(2);
	}

	opcodes = (char *) main;
	for (i = 0; i < num_of_bytes; i++)
	{ /* we use a bitwise  & against 0xFF to extract the */
		/* last 8 bits or 2 hex digits of opcodes[i]  */
		printf("%02x", opcodes[i] & 0xFF);
		if (i != num_of_bytes - 1)
		{
			printf(" ");
		}
	}

	printf("\n");
	return (0);
}
