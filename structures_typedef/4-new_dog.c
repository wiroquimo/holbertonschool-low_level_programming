#include <stdlib.h>
#include "dog.h"

/**
 * _strlen - function that returns the length of a string.
 * @s: string to be measured
 *
 * Return: the length of string s
 */
int _strlen(char *s)
{
	int length = 0;

	while (s[length])
		length++;

	return (length);
}

/**
 * _strcpy - Function that copies a string
 * @dest: *dest buffer pointed to by dest
 * @src: *src string pointed to by src
 *
 * Return: char*, the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\0';

	return (dest);
}

/**
 * new_dog - Function that creates a new type dog struct
 * @name: Parameter name
 * @age: Parameter age
 * @owner: Paramter owner
 *
 * Return: A type struct dog
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *puppie = NULL;

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

	_strcpy(puppie->name, name);

	puppie->age = age;

	_strcpy(puppie->owner, owner);

	return (puppie);
}
