#include "function_pointers.h"
/**
 * print_name -  prints a name
 *
 * @name: string to be printed
 * @f: pointer to function that does some type of
 * printing (basically a print callback function)
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	/* check that the pointers are not NULL */
	if (f && name)
	{
		f(name);
	}
}
