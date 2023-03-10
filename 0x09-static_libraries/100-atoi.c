#include "main.h"

/**
 * _atoi - converts a string to an integer
 *
 * @s: pointer to a string
 *
 * Return: int
 */

int _atoi(char *s)
{
	int sign;
	int total;
	int i;

	sign  = 1;
	total = 0;
	i     = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			/* multiply sign by -ve if encountered*/
			sign = sign * -1;
		}
		else if (s[i] == '+')
		{
			/* do nothing, keep sign the same */
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			total = (total * 10) + (s[i] - '0');
		}
		else if (total > 0)
		{
			/* stop accumulating if we encounter a non-numeric */
			/* character after the first chain of digits */
			break;
		}

		i++;
	}
	return (sign * total);
}
