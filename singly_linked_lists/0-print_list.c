#include <stdio.h>
#include "lists.h"

/**
 * print_list - function that prints all the elements of a list_t list
 * @h: head of the list_t list
 *
 * Return: the number of nodes
 */

size_t print_list(const list_t *h)
{
	size_t nodes;

	for (h = h, nodes = 0; h != NULL; h = h->next, nodes++)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
	}

	return (nodes);
}
