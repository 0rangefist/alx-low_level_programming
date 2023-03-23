#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - prints anything
 *
 * @format: list of types of arguments
 *
 * Return: void
 */
void print_all(const char *const format, ...)
{
	va_list		arg_list;
	char	   *string;
	const char *format_ptr = format;

	/* initialize the arg_list_ptr to point to */
	/* point to the start of the user entered list */
	va_start(arg_list, format);
	while (format && *format_ptr != '\0')
	{
		switch (*format_ptr)
		{
			case 'c':
				printf("%c", (char) va_arg(arg_list, int));
				break;
			case 'i':
				printf("%d", va_arg(arg_list, int));
				break;
			case 'f':
				printf("%f", va_arg(arg_list, double));
				break;
			case 's':
				string = (char *) va_arg(arg_list, char *);
				if (string)
				{
					printf("%s", string);
					break;
				}
				printf("(nil)");
				break;
			default:
				break;
		}
		/* print the separator except for the last element */
		if ((*format_ptr == 'c' || *format_ptr == 'i' || *format_ptr == 'f'
			|| *format_ptr == 's') && *(format_ptr + 1) != '\0')
			printf(", ");
		format_ptr++;
	}
	va_end(arg_list);
	printf("\n");
}
