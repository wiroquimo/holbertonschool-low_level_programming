#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - function that returns the length of a string.
 * @s: char *s string to be measured
 *
 * Return: the length of s string
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
 * new_dog - Function that creates a new type dog struct.
 * @name: Parameter name.
 * @age: Parameter age.
 * @owner:Paramter owner.
 * Return: A type struct dog.
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *puppie;
	int name_length = 0, owner_length = 0, i;

	if (name == NULL || owner == NULL)
		return (NULL);

	name_length = _strlen(name);
	owner_length = _strlen(owner);

	puppie = malloc(sizeof(dog_t));
	if (puppie == NULL)
	return (NULL);

	puppie->name = malloc(name_length + 1);
	if (puppie->name == NULL)
	{
		free(puppie);
		return (NULL);
	}

	puppie->owner = malloc(owner_length + 1);
	if (puppie->owner == NULL)
	{
		free(puppie->name);
		free(puppie);
		return (NULL);
	}

	for (i = 0; i < (name_length + 1); i++)
		puppie->name[i] = name[i];

	puppie->age = age;

	for (i = 0; i < (owner_length + 1); i++)
		puppie->owner[i] = owner[i];

	return (puppie);
}
