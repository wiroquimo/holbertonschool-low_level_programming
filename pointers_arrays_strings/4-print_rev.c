#include "main.h"

/**
 * print_rev - prints a string, in reverse, followed by a new line
 * @s: string to be printed in reverse
 *
 * Return: Nothing
 */

void print_rev(char *s)
{
	char *aux = s;

	while (*aux)
		aux++;

	while (aux > s)
		_putchar(*(--aux));

	_putchar('\n');
}
