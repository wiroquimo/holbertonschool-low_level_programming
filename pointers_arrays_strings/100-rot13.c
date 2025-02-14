#include "main.h"

/**
 * rot13 - function that encodes a string using rot13
 * @s: pointer to string to be rot13 encoded
 *
 * Return: pointer to the rot13 encoded string
 */

char *rot13(char *s)
{
	char *aux = s;
	char bases[2] = {'a', 'A'};
	int i;

	while (*aux)
	{
		if ((*aux >= 'a' && *aux <= 'z') || (*aux >= 'A' && *aux <= 'Z'))
		{
			i = (*aux >= 'A' && *aux <= 'Z');
			*aux = (*aux - bases[i] + 13) % 26 + bases[i];
		}
		aux++;
	}

	return (s);
}
