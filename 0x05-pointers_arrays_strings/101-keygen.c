#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - entry point for the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int  i;
	int  random;
	int len;
	char password[100];

	len = 100;

	srand(time(NULL));

	for (i = 0; i < 100; i++)
	{
		random = rand() % 62;
		if (random < 26)
			password[i] = 'a' + random;
		else if (random < 52)
			password[i] = 'A' + random - 26;
		else
			password[i] = '0' + random - 52;
	}
	password[len] = '\0';

	printf("%s\n", password);
	return (0);
}
