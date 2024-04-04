#include "lists.h"

/**
 * _strlen - return the lenggth from a string
 *  @s: pointer to first character of a string
 *
 *  Return: number of characters in a string
 */
unsigned int _strlen(const char *s)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		;

	return (i);
}

/**
 * _strdup - Returns a pointer to a copy of the string given as a parameter
 * @str: String given as a parameter
 *
 * Return: Pointer to a copy of str
 */
char *_strdup(const char *str)
{

	unsigned int i = 0, length = 0;
	char *s = NULL;

	if (str == NULL)
		return (NULL);

	length = _strlen(str);

	s = (char *)malloc((length + 1) * sizeof(char));
	if (s == NULL)
		return (NULL);

	for (; i < (length + 1); i++)
		*(s + i) = *(str + i);

	return (s);
}

/**
 * add_node_end - function that adds a new node at the end of a list_t list
 * @head: pointer to pointer to the beginning of the list_t list
 * @str: literal string to be added
 *
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node = NULL, *i = NULL;

	new_node = (list_t *)malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = _strdup(str);
	new_node->len = _strlen(str);
	new_node->next = NULL;

	if (*head == NULL)
		*head = new_node;
	else
	{
		for (i = *head; i->next != NULL; i = i->next)
			;

		i->next = new_node;
	}

	return (new_node);
}
