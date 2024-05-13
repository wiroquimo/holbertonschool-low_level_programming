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

	if (*s >= 'a' && *s <= 'z')
	{
		*s -= ('a' - 'A');
		/* *s = *s - ('a' - 'A'); */
		/* *s -= 32; */
		/* s[0] = s[0] - 32; */
		s++;
	}

	for (; *s != '\0'; s++)
	{
		if ((*s == '\t' || *s == '\n' || *s == ' '
			 || *s == '!' || *s == '\"' || *s == '('
			 || *s == ')' || *s == ',' || *s == '.'
			 || *s == ';' || *s == '?' || *s == '{'
			 || *s == '}') && (*(s + 1) >= 'a' && *(s + 1) <= 'z'))
		{
			*(s + 1) -= ('a' - 'A');
			/* *(s + 1) = *(s + 1) - ('a' - 'A'); */
			/* *(s + i + 1) = *(s + i + 1) - ('a' - 'A'); */
		}
	}

	return (ans);
}
