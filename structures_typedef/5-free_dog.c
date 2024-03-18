#include <stdlib.h>
#include "dog.h"

/**
 * free_dog - Frees any memory allocated by type struct dog
 * @d: Pointer to a type struct dog
 *
 * Return: void.
 */
void free_dog(dog_t *d)
{
	if (d)
	{
		free(d->owner);
		free(d->name);
		free(d);
	}
}
