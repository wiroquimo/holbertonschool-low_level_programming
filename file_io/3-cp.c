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
	ssize_t fd_dest_open = 0, fd_src_open = 0, w = 0, r = 0;
	ssize_t fd_dest_close = 0, fd_src_close = 0;

	if (argc != 3)
		exit_97();

	fd_src_open = open(argv[1], O_RDONLY);
	if (fd_src_open == -1)
		exit_98(argv[1]);

	fd_dest_open = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_dest_open == -1)
		exit_99(argv[2]);

	r = read(fd_src_open, buffer, 1024);
	w = write(fd_dest_open, buffer, r);
	do {
		if (r == -1)
			break;

		if (r != w)
			break;
	
		r = read(fd_src_open, buffer, 1024);
		w = write(fd_dest_open, buffer, r);
	} while (r > 0);

	if (r == -1)
		exit_98(argv[1]);

	if (r != w)
		exit_99(argv[2]);

	fd_src_close = close(fd_src_open);
	if (fd_src_close == -1)
		exit_100(fd_src_open);

	fd_dest_close = close(fd_dest_open);
	if (fd_dest_close == -1)
		exit_100(fd_dest_open);

	return (0);
}
