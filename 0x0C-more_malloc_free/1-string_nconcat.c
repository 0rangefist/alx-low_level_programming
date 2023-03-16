#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings
 *
 * @s1: first string
 * @s2: second string
 * @n: the first n bytes of s2 to use in concatenation,
 * the whole of s2 is used if n is greater/equal to its length
 *
 * Return: pointer to the allocated memory
 * or exit with status of 98 on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char		*str_cat;
	unsigned int i;
	unsigned int s1_len = 0;
	unsigned int s2_len = 0;

	if (s1 == NULL) /* make s1 empty string if NULL is passed */
		s1 = "";

	if (s2 == NULL) /* make s2 empty string if NULL is passed */
		s2 = "";

	while (s1[s1_len] != '\0') /* find length of s1 */
		s1_len++;

	while (s2[s2_len] != '\0') /* find length of s2 */
		s2_len++;

	if (n >= s2_len) /* make n equal to the length of s2 if larger */
		n = s2_len;

	str_cat = malloc(sizeof(*str_cat) * (s1_len + n + 1));
	/* +1 is for the extra null byte */

	if (str_cat == NULL) /* return null on allocation failure */
		return (NULL);

	for (i = 0; i < s1_len; i++) /* copy the content of s1 into str_cat */
		str_cat[i] = s1[i];

	for (i = s1_len; i < s1_len + n;
		 i++) /* continue copy of s2 into str_cat from where s1_len left off */
		str_cat[i] = s2[i - s1_len];

	str_cat[i] = '\0';
	return (str_cat);
}
