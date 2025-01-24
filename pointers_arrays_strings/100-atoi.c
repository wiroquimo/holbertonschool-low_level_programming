#include "main.h"

/**
 * _atoi - Function that convert a string to an integer.
 * @s: *s String to be converted to integer
 *
 * Return: int
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	/* Skip leading whitespace or non-digit characters */
	while (*s == ' ' || *s == '\t')  /*  Handle whitespace */
		s++;

	/* Handle possible sign at the beginning */
	if (*s == '-')
	{
		sign = -1;
		s++;  /* Move past the sign */
	}
	else if (*s == '+')
	{
		s++;  /* Move past the sign */
	}

	/* Convert the digits to an integer */
	while (*s >= '0' && *s <= '9')
	{
		num = num * 10 + (*s - '0');  /* Build the number */
		s++;
	}

	return (sign * num);  /* Apply the sign and return the result */
}
