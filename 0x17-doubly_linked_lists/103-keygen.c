#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * f2 - Computes a value based on the given string.
 * @str: The input string.
 * @length: The length of the string.
 *
 * Return: The computed value.
 */
int f2(char *str, int length)
{
	int sum = 0;
	int i;

	for (i = 0; i < length; i++)
	{
		sum += (int) str[i];
	}

	return ((sum ^ 0x4f) & 0x3f);
}

/**
 * f3 - Computes a value based on the given string.
 * @str: The input string.
 * @length: The length of the string.
 *
 * Return: The computed value.
 */
int f3(char *str, int length)
{
	int product = 1;
	int i;

	for (i = 0; i < length; i++)
	{
		product *= (int) str[i];
	}

	return ((product ^ 0x55) & 0x3f);
}

/**
 * f4 - Computes a value based on the given string.
 * @str: The input string.
 * @length: The length of the string.
 *
 * Return: The computed value.
 */
int f4(char *str, int length)
{
	int random;
	int max_value = (int) str[0];
	int i;

	for (i = 0; i < length; i++)
	{
		if ((int) str[i] > max_value)
		{
			max_value = (int) str[i];
		}
	}
	srand(max_value ^ 0xe);
	random = rand();
	return (random & 0x3f);
}

/**
 * f5 - Computes a value based on the given string.
 * @str: The input string.
 * @length: The length of the string.
 *
 * Return: The computed value.
 */
int f5(char *str, int length)
{
	int sum = 0;
	int i;

	for (i = 0; i < length; i++)
	{
		sum += (int) str[i] * (int) str[i];
	}

	return ((sum ^ 0xef) & 0x3f);
}

/**
 * main - The entry point of the keygen program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: Prints generated key and returns 0 on success otherwise 1
 */
int main(int argc, char **argv)
{
	int	  username_length;	 /* length of username to find key for */
	char *username;			 /* username to find key for */
	char  key[7];			 /* key array to store found key chars */
	int	  ref_index;		 /* index to access chars of reference */
	int	  random = 0, i = 0; /* random number and index variable */

	char ref[]
		= "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	if (argc != 2) /* check if argc is 2 */
		return (1);

	username		= argv[1];
	username_length = strlen(username);

	/* use various functions to find appropriate ref_index,*/
	/* extract character from ref & save that as character in key*/
	ref_index = (username_length ^ 0x3b) & 0x3f;
	key[0]	  = ref[ref_index];
	ref_index = f2(username, username_length);
	key[1]	  = ref[ref_index];
	ref_index = f3(username, username_length);
	key[2]	  = ref[ref_index];
	ref_index = f4(username, username_length);
	key[3]	  = ref[ref_index];
	ref_index = f5(username, username_length);
	key[4]	  = ref[ref_index];
	for (i = 0; i < *username; i++) /* random num */
		random = rand();
	key[5] = ref[((random ^ 0xe5) & 0x3f)];
	key[6] = '\0'; /* null terminate the key */

	puts(key); /* print the key */
	return (0);
}
