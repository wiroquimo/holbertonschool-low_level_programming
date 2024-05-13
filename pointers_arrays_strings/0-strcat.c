#include "main.h"

/**
 * _strcat - Function that concatenates two strings. This function appends the
 * src string to the dest string, overwriting the terminating null byte (\0) at
 * the end of dest, and then adds a terminating null byte
 * @dest: char *dest is a pointer to string to the dest string
 * @src: char *src is a pointer to string
 *
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *ans = dest;

	while (*dest != '\0')
		dest++;

	while (*src != '\0')
	{
		*dest = *src;
		dest++, src++;
	}

	*dest = '\0';

	return (ans);
}
