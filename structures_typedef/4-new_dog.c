#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - function that returns the length of a string
 * @s: string to be measured
 *
 * Return: the length of a string
 */
int _strlen(char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
	{
		++len;
	}
	return (len);
}

/**
 * new_dog - Function that creates a new type dog struct
 * @name: Parameter name
 * @age: Parameter age
 * @owner:Paramter owner
 *
 * Return: A type struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *puppie;
	int i;

	if (name == NULL || owner == NULL)
		return (NULL);

	puppie = malloc(sizeof(dog_t));
	if (puppie == NULL)
		return (NULL);

	puppie->name = malloc(_strlen(name) + 1);
	if (puppie->name == NULL)
	{
		free(puppie);
		return (NULL);
	}

	puppie->owner = malloc(_strlen(owner) + 1);
	if (puppie->owner == NULL)
	{
		free(puppie->name);
		free(puppie);
		return (NULL);
	}

	for (i = 0; name[i] != '\0'; i++)
		puppie->name[i] = name[i];

	puppie->age = age;

	for (i = 0; owner[i] != '\0'; i++)
		puppie->owner[i] = owner[i];


	return (puppie);
}
