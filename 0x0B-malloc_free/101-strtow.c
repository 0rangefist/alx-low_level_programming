#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _strncpy - copies a string
 *
 * @dest: pointer to destination string
 * @src: pointer to source string
 * @n: num of chars of src to use
 *
 * Return: pointer to resulting destination string
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *dest_ptr;
	char *src_ptr;

	dest_ptr = dest;

	/* Iterate through src_ptr n times, copying each value over to *dest_ptr*/
	for (src_ptr = src; n > 0 && *src_ptr != '\0'; src_ptr++, dest_ptr++, n--)
	{
		*dest_ptr = *src_ptr;
	}

	/* if n is greater than 0, continue counting down till 0,  */
	/* filling the remaining n chars of dest with \0 */
	for (; n > 0; dest_ptr++, n--)
	{
		*dest_ptr = '\0';
	}

	return (dest);
}

/**
 * strtow -  a function that splits a string into words
 *
 * @str: original string of words
 *
 * Return: pointer to array of words or NULL on failure
 */
char **strtow(char *str)
{
	char **word_array;
	char  *word;
	char  *ptr			  = str;
	char  *ptr_word_start = str;
	int	   num_of_words	  = 0;
	int	   len_of_word	  = 0;
	int	   i			  = 0;

	if (str == NULL || *str == '\0') /* if str is null or empty */
		return (NULL);
	for (; *ptr != '\0'; ptr++) /* scan through the string till the null byte */
	{
		if (*ptr != ' ' && (*(ptr + 1) == ' ' || *(ptr + 1) == '\0'))
			num_of_words++; /* count number of words in string */
	}
	/* allocate memory for the word array (+1 for assigning null at the end) */
	word_array = malloc((num_of_words + 1) * sizeof(char *));
	if (word_array == NULL) /* on allocation failure */
		return (NULL);
	for (ptr = str; *ptr != '\0'; ptr++) /* reset ptr back to start */
	{ /* extract each word from string and store in the word array */
		if (*ptr != ' ') /* if we havent hit a space delimiter */
		{
			ptr_word_start = ptr; /* save pointer to start of a word */
			while (*ptr != ' ' && *ptr != '\0')
				ptr++; /* incrementing ptr to the end of a word */
			/* allocate memory for a word string, + 1 is for the null byte */
			len_of_word = ptr - ptr_word_start; /* num of chars of word */
			if (len_of_word == 0) /* if string is empty space */
				return (NULL);
			word = malloc((len_of_word + 1) * sizeof(char));
			if (word == NULL) /* on allocation failure */
				return (NULL);
			_strncpy(word, ptr_word_start, len_of_word);
			word[len_of_word] = '\0'; /* null byte at end of word */
			word_array[i++]	  = word; /* place the word in word array */
		}
	}
	word_array[i] = NULL; /* NULL placed at very end of array */
	return (word_array);
}
