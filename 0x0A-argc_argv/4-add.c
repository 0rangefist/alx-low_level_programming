#include <stdio.h>
#include <stdlib.h>

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
	int sum		  = 0;
	int bad_input = 0;
	int i;

	if (argc == 1)
	{
		printf("0\n");
	}
	else if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			if (!(*argv[i] >= '0' && *argv[i] <= '9'))
			{
				bad_input = 1;
				break;
			}
			sum = sum + atoi(argv[i]);
		}

		if (bad_input)
		{
			printf("Error\n");
			return (1);
		}

		printf("%d\n", sum);
	}

	return (0);
}
