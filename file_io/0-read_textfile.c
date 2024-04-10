#include "main.h"

/**
 * _strlen - returns string length of input string
 * @s: string to check length of
 *
 * Return: length of string
 */
size_t _strlen(const char *s)
{
	size_t i = 0;

	for (; *(s + i) != '\0'; i++)
		;

	return (i);
}

/**
 * read_textfile - function that reads a text file and prints it to the stdout
 * @filename: path to the file
 * @letters: the number of letters it should read and print
 *
 * Return: 0 it fails or the actual number of letters it could read and print
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t final_letters = -1;
	int file_descriptor = -1;
	char *buffer = NULL;

	if (filename == NULL)
		return (0);

	file_descriptor = open(filename, O_RDONLY);
	if (file_descriptor == -1)
		return (0);

	buffer = (char *)malloc(letters * sizeof(char));
	if (buffer == NULL)
		return (0);

	if (read(file_descriptor, buffer, letters) == -1)
	{
		free(buffer);
		return (0);
	}

	final_letters = write(STDOUT_FILENO, buffer, _strlen(buffer));
	if (final_letters == -1)
	{
		free(buffer);
		return (0);
	}

	if (close(file_descriptor) == -1)
	{
		free(buffer);
		return (0);
	}

	free(buffer);

	return (final_letters);
}
