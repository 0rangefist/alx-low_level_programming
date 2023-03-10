#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * argstostr - concatenates all the arguments of your program
 *
 * @ac: argument count
 * @av: argument value
 *
 * Return: pointer to new string or NULL on failure
 */
char *argstostr(int ac, char **av)
{
	char		 *string;
	unsigned long i;
	unsigned long j;
	unsigned long k;
	unsigned long total_len = 0;

	if (ac == 0 || av == NULL)
		return (NULL);

	/* find total length to allocate to new string */
	/* by summing the lengths of each argument */
	for (i = 0; i < (unsigned long) ac; i++)
	{
		total_len = total_len + strlen(av[i]) + 1;
		/* +1 is for a newline char added after each arg */
	}
	string = malloc((total_len + 1) * sizeof(char));
	/* +1 is for the null byte at the end of the output string */

	if (string == NULL) /* on allocation failure */
		return (NULL);
	/*copy the chars from each argument into string */
	k = 0; /* index for output string */
	for (i = 0; i < (unsigned long) ac; i++)
	{
		for (j = 0; j < strlen(av[i]); j++)
		{
			string[k] = av[i][j];
			k++;
		}

		string[k] = '\n'; /* add newline after arg */
		k++;
	}
	/* add null byte at end of output string */
	string[k] = '\0';
	return (string); /*return pointer to output string */
}
