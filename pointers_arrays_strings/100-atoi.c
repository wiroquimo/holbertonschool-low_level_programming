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
	unsigned int multiplier = 1, number = 0;

    /* sign calculation*/

	while (*s)
	{   
		if (*s == '-')
			sign *= -1;
		/*else if current character of s is a digit and next character of s is not a digit */
		else if (*s >= '0' && *s <= '9' && !(*(s + 1) >= '0' && *(s + 1) <= '9'))
			break; /* break the cycle */
		s++;
	}
    
	/* number calculation */
	while (*s >= '0' && *s <= '9')
	{
		number += (*s - '0') * multiplier;
		multiplier *= 10;
		s--;
	}

    /* answer calculation */
	return (sign * number);
}
