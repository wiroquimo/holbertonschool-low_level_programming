#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * op_add - add function
 * @a: int number a
 * @b: int number b
 *
 * Return: sum of a and b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - substract function
 * @a: int number a
 * @b: int number b
 *
 * Return: difference of a and b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - multiply function
 * @a: int number a
 * @b: int number b
 *
 * Return: product of a and b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - division function
 * @a: int number a
 * @b: int number b
 *
 * Return: the result of the division of a by b
 */
int op_div(int a, int b)
{
	if (b != 0)
		return (a / b);
	printf("Error\n");
	exit(100);
}

/**
 * op_mod - modulo function
 * @a: int number a
 * @b: int number b
 *
 * Return: remainder of the division of a by b
 */
int op_mod(int a, int b)
{
	if (b != 0)
		return (a % b);
	printf("Error\n");
	exit(100);
}
