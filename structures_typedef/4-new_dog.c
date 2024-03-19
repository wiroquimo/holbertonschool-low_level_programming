#include <stdlib.h>
#include "dog.h"

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
    dog_t *puppie = NULL;
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

    for(i = 0; name[i]; i++)
        puppie->name[i] = name[i];
    puppie->name[i] = '\0';

    puppie->age = age;

    for(i = 0; owner[i]; i++)
        puppie->owner[i] = owner[i];
    puppie->owner[i] = '\0';

    return (puppie);
}
