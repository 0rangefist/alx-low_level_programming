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
 * count_words - counts the number of words in a string
 *
 * @str: string to count words in
 *
 * Return: number of words in string
 */
int count_words(char *str)
{
	int	  num_of_words = 0;
	char *ptr		   = str;

	/* skip leading spaces */
	while (*ptr == ' ')
		ptr++;

	if (*ptr == '\0') /* if the string only contains spaces */
		return (0);

	/* count number of words in string */
	while (*ptr != '\0')
	{
		/* skip consecutive spaces */
		while (*ptr == ' ')
			ptr++;

		/* check for end of string */
		if (*ptr == '\0')
			break;

		/* found start of a word */
		num_of_words++;

		/* skip to end of word */
		while (*ptr != ' ' && *ptr != '\0')
			ptr++;
	}

	return (num_of_words);
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
	char  *ptr			= str;
	int	   num_of_words = 0;
	int	   len_of_word	= 0;
	int	   i			= 0;

	if (str == NULL || *str == '\0') /* if str is null or empty */
		return (NULL);

	num_of_words = count_words(str);

	/* allocate memory for the word array (+1 for assigning null at the end) */
	word_array = malloc((num_of_words + 1) * sizeof(char *));
	if (word_array == NULL) /* on allocation failure */
		return (NULL);

	/* extract each word from string and store in the word array */
	for (ptr = str; *ptr != '\0'; )
	{
		while (*ptr == ' ') /* skip leading spaces */
			ptr++;
		if (*ptr == '\0') /* check for end of string */
			break;
		/* allocate memory for a word string, + 1 is for the null byte */
		len_of_word = 0;
		while (*(ptr + len_of_word) != ' ' && *(ptr + len_of_word) != '\0')
			len_of_word++;
		word = malloc((len_of_word + 1) * sizeof(char));
		if (word == NULL) /* on allocation failure */
			return (NULL);
		_strncpy(word, ptr, len_of_word); /* copy word into buffer */
		word[len_of_word] = '\0'; /*add null byte at end of word */
		word_array[i++] = word; /* add word to array */
		ptr = ptr + len_of_word; /* skip to end of word */
	}
	word_array[i] = NULL; /* NULL placed at very end of array */
	return (word_array);
}
