#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * buffer - create a buffer for 1024 bytes
 * @filename: name of the buffer
 * Return: pointer to the buffer
 */
char *buffer(char *filename)
{
	char *buf;

	buf = (char *)malloc(1024);
	if (!buf)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (buf);
}

/**
 * close_file - close a file
 * @fd: file descriptor
 */
void close_file(int fd)
{
	int i;

	i = close(fd);

	if (i == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - function that copies the content of a file to another file
 * @argv: arguments passed
 * @argc: number of arguments
 * Return: 0
 */
int main(int argc, char *argv[])
{
	int fd, x, wr, rd;
	char *buffer1;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer1 = buffer(argv[2]);
	fd = open(argv[1], O_RDONLY);
	rd = read(fd, buffer1, 1024);
	x = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR |
								S_IRGRP | S_IWGRP | S_IROTH);

	do {
		if (fd == -1 || rd == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			exit(98);
		}
		wr = write(x, buffer1, rd);
		if (x == -1 || wr != rd)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
		rd = read(fd, buffer1, 1024);
		x = open(argv[2], O_WRONLY | O_APPEND);
	} while (rd > 0);
	free(buffer1);
	close_file(fd);
	close_file(x);
	return (0);
}
