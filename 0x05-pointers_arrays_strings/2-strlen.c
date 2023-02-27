/**
 * _strlen - returns the length of a string
 *
 * @s: pointer to a
 *
 * Return: nothing
 */

int _strlen(char *s)
{
	int count;

	count = 0;

	while (*s++)
	{
		count++;
	}

	return (count);
}
