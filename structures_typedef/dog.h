#ifndef _DOG_H
#define _DOG_H

/**
 * struct dog - Defines a new structure dog.
 * @name: char *name parameter for the name.
 * @age: float *age parameter for the age.
 * @owner: char *owner parameter for the owner.
 *
 * Description: Longer description
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);

#endif
