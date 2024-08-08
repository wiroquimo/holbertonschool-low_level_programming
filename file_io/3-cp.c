#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * exit_97 - exit status 97
 */
void exit_97(void)
{
	dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
	exit(97);
}

/**
 * exit_98 - exit status 98
 * @str: name of file
 */
void exit_98(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", str);
	exit(98);
}

/**
 * exit_99 - exit status 99
 * @str: name of file
 */
void exit_99(char *str)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", str);
	exit(99);
}

/**
 * exit_100 - exit status 100
 * @fd: name of file
 */
void exit_100(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(100);
}

/**
 * main - copies the contents of one file to another
 * @argc: integer number of arguments
 * @argv: pointer to string arguments
 *
 * Return: 0 on success, or one of 97, 98, 99, 100 on failure
 */
int main(int argc, char **argv)
{
	char buffer[1024];
	ssize_t fd_src = 0, fd_dest = 0, bytes_read = 0, bytes_written = 0;

	if (argc != 3)
		exit_97();

	fd_src = open(argv[1], O_RDONLY);
	if (fd_src == -1)
		exit_98(argv[1]);

	bytes_read = read(fd_src, buffer, 1024);
	if (bytes_read == -1)
		exit_98(argv[1]);

	fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);

	do {
		bytes_written = write(fd_dest, buffer, bytes_read);
		if ((fd_dest == -1) || (bytes_written < bytes_read))
			exit_99(argv[2]);

		bytes_read = read(fd_src, buffer, 1024);
		fd_dest = open(argv[2], O_WRONLY | O_APPEND);
	} while (bytes_read > 0);

	if (close(fd_src) == -1)
		exit_100(fd_src);

	if (close(fd_dest) == -1)
		exit_100(fd_dest);

	return (0);
}
