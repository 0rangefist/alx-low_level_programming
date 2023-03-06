#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *s = "hello\0world";
    char *f;

    f = _strchr(s, '\0');

    if (f != NULL)
    {
        printf("%s\n", f);
    }

    if (f == NULL)
    {
        printf("The character was not found in the string '%s'.\n", s);
    }

    return (0);
}
