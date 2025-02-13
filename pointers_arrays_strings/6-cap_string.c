#include "main.h"

/**
 * cap_string - Function that capitalizes all words of a string
 * Separators of words: space, tabulation, new line, ,, ;, ., !, ?,
 * ", (, ), {, and }
 * @s: char *s is a pointer to char to the string to capitalize
 *
 * Return: pointer to char to the string capitalized
 */

char *cap_string(char *s)
{
	char *aux = s;

	while (*aux)
	{
		if ((*aux == '\t' || *aux == '\n' || *aux == ' '
			 || *aux == '!' || *aux == '\"' || *aux == '('
			 || *aux == ')' || *aux == ',' || *aux == '.'
			 || *aux == ';' || *aux == '?' || *aux == '{'
			 || *aux == '}')
			 && (*(aux + 1) >= 'a' && *(aux + 1) <= 'z'))
		{
			*(aux + 1) -= ' ';
		}
		aux++;
	}

	if (*s >= 'a' && *s <= 'z')
		*s -= ' ';

	return (s);
}
