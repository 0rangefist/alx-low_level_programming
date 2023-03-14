#include "main.h"
#include <stdlib.h>

/**
 * _strdup -   returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter
 *
 * @str: string to be duplicated
 *
 * Return: pointer to duplicate of str or NULL on failure
 */
char *_strdup(char *str)
{
	char		*str_cpy;
	unsigned int i;
	unsigned int len = 0;

	if (str == NULL) /* return null if string is null */
		return (NULL);

	while (str[len] != '\0') /* find length of string */
	{
		len++;
	}

	str_cpy = malloc((len + 1) * sizeof(char));
	/* +1 is for the extra null byte */

	if (str_cpy == NULL) /* return null on allocation fail */
		return (NULL);

	/* duplicate the content of str into str_cpy */
	for (i = 0; i < len; i++)
	{
		str_cpy[i] = str[i];
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
