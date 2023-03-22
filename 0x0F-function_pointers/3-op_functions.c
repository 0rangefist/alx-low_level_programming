#include "3-calc.h"

/**
 * op_add - adds two integer numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: sum of num1 and num2
 */
int op_add(int num1, int num2)
{
	return (num1 + num2);
}

/**
 * op_sub - subctracts two integer numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: subraction of num1 from num2
 */
int op_sub(int num1, int num2)
{
	return (num1 - num2);
}

/**
 * op_mul - multiplies two integer numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: product of num1 and num2
 */
int op_mul(int num1, int num2)
{
	return (num1 * num2);
}

/**
 * op_div - divides two integer numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: the division of num1 by num2
 */
int op_div(int num1, int num2)
{
	return (num1 / num2);
}

/**
 * op_mod - finds the modulo of two integer numbers
 * @num1: first number
 * @num2: second number
 *
 * Return: remainder of division of num1 by num2
 */
int op_mod(int num1, int num2)
{
	return (num1 % num2);
}
