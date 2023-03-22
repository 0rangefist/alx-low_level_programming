#include "3-calc.h"

/**
 * get_op_func - returns the appropriate operation function
 *  based on the operation sting supplied
 *
 * @s: the operation string
 *
 * Return: pointer to a function that performs the right operation
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {{"+", op_add}, {"-", op_sub}, {"*", op_mul},
				  {"/", op_div}, {"%", op_mod}, {NULL, NULL}};
	int	 i;

	/* check for the operation char, s[0] in ops[]*/
	for (i = 0; i < 6; i++)
	{
		if (s[0] == ops[i].op[0])
		{
			/* return the function at index that made a match */
			return (ops[i].f);
		}
	}

	/* return NULL if no match was made */
	return (NULL);
}
