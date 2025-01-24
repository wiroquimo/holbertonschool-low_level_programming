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
	unsigned int mul = 1, num = 0;

	while (*s != '\0')
	{
		if (*s == '-')
		{
			sign *= -1;
		}
		else if (*s >= '0' && *s <= '9' && !(*(s + 1) >= '0' && *(s + 1) <= '9'))
		{
			s++;
			break;
		}
		s++;
	}
	s--;
	while (*s >= '0' && *s <= '9')
	{
		num += (*s - '0') * mul;
		mul *= 10;
		s--;
	}

	return (sign * num);
}
