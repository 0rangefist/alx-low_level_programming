#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_strings - prints strings, followed by a new line
 *
 * @separator: the string to be printed between numbers
 * @n: the user-determined number of strings
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list arg_list;
	unsigned int i;
	char *string;

	if (n == 0)
	{
		printf("\n");
		return;
	}

	/* initialize the arg_list_ptr to point to */
	/* point to the start of the user entered list */
	va_start(arg_list, n);

	for (i = 0; i < n; i++)
	{
		string = (char *) va_arg(arg_list, char *);
		if (string) /* if string is non NULL */
		{
			printf("%s", string);
		}
		else
		{
			printf("(nil)");
		}

		if (i != n - 1)
		{ /* print separator if it isn't NULL */
			if (separator)
			{
				printf("%s", separator);
			}
		}
	}
	printf("\n");
	va_end(arg_list);
}
