#include <stdio.h>

void __attribute__((constructor)) premain(void);

/**
 * premain - Prints a message before the main function is executed
 */
void premain(void)
{
	printf(
		"You're beat! and yet, you must allow,\n"
		"I bore my house upon my back!\n");
}
