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
	unsigned long sum = 0;
	int			  i;
	char		 *char_ptr;

	if (argc == 1)
	{
		printf("0\n");
	}
	else if (argc > 1)
	{
		for (i = 1; i < argc; i++)
		{
			/*detect each char in each argv string */
			char_ptr = argv[i];
			while (*char_ptr != '\0')
			{
				if (!(*char_ptr >= '0' && *char_ptr <= '9'))
				{
					printf("Error\n");
					return (1);
				}
				char_ptr++;
			}
			sum = sum + atoi(argv[i]);
		}
		printf("%lu\n", sum);
	}

	return (0);
}
