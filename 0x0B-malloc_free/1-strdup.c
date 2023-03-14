#include "main.h"
#include <stdlib.h>
#include <string.h>

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
	unsigned int len;

	if (str == 0) /* return null if string is null */
	{
		return (0);
	}

	len		= strlen(str);
	str_cpy = malloc(len + 1);

	if (str_cpy == 0) /* if null return null */
	{
		return (0);
	}

	/* duplicate the content of str into str_cpy */
	for (i = 0; i < len; i++)
	{
		str_cpy[i] = str[i];
	}
	str_cpy[i] = '\0';
	return (str_cpy);
}
