#include "main.h"

/**
 * cap_string - Function that capitalizes all words of a string.
 * Separators of words: space, tabulation, new line, ,, ;, ., !, ?,
 * ", (, ), {, and }
 * @s: char *s is a pointer to char to the string to capitalize
 *
 * Return: pointer to char to the string capitalized
 */

char *cap_string(char *s)
{
	char *ans = s;

	while (*s)
	{
		if ((*s == '\t' || *s == '\n' || *s == ' '
			 || *s == '!' || *s == '\"' || *s == '('
			 || *s == ')' || *s == ',' || *s == '.'
			 || *s == ';' || *s == '?' || *s == '{'
			 || *s == '}') && (*(s + 1) >= 'a' && *(s + 1) <= 'z'))
		{
			*(s + 1) -= ' ';
		}
		s++;
	}

	if (*ans >= 'a' && *ans <= 'z')
		*ans -= ' ';

	return (ans);
}
