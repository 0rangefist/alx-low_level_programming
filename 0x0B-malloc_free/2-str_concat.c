#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 *
 * @s1: first string to use in concatenation
 * @s2: second string to use in concatenation
 *
 * Return: pointer to concatenation or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char		*str_cat;
	unsigned int i;
	unsigned int len1 = 0;
	unsigned int len2 = 0;

	if (s1 == NULL) /* make s1 empty string if NULL is passed */
		s1 = "";

	if (s2 == NULL) /* make s2 empty string if NULL is passed */
		s2 = "";

	while (s1[len1] != '\0') /* find length of s1 */
		len1++;

	while (s2[len2] != '\0') /* find length of s2 */
		len2++;

	str_cat = malloc((len1 + len2 + 1) * sizeof(char));
	/* +1 is for the extra null byte */

	if (str_cat == NULL) /* return null on allocation fail */
		return (NULL);

	/* copy the content of s1 into str_cat */
	for (i = 0; i < len1; i++)
		str_cat[i] = s1[i];

	/* continue copy of s2 into str_cat from where len1 left off */
	for (i = len1; i < len1 + len2; i++)
		str_cat[i] = s2[i];

	str_cpy[i] = '\0';
	return (str_cat);
}
