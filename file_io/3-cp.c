#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * print_error_s - Prints an error message with an string an exit with a code
 * @msg: Error message
 * @arg: Argument to be passed of type char *
 * @code: Exit code error
 *
 * Return: void
 */
void print_error_s(const char *msg, const char *arg, int code)
{
	dprintf(STDERR_FILENO, "%s%s\n", msg, arg);
	exit(code);
}


/**
 * print_error_d - Prints an error message with a number an exit with a code
 * @msg: Error message
 * @arg: Argument to be passed of type int
 * @code: Exit code error
 *
 * Return: void
 */
void print_error_d(const char *msg, int arg, int code)
{
	dprintf(STDERR_FILENO, "%s%d\n", msg, arg);
	exit(code);
}

/**
 * main - Copies the content of a file to another file
 * @argc: Size of argv
 * @argv: Array of arguments
 *
 * Return: 0 for success, 1 otherwise
 */
int main(int argc, char **argv)
{
	int fd_from, fd_to;
	ssize_t bytes_readed, bytes_written;
	char buffer[1024];

	if (argc != 3)
		print_error_s("Usage: cp file_from file_to", "", 97);
	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		print_error_s("Error: Can't read from file ", argv[1], 98);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 00664);
	if (fd_to == -1)
		print_error_s("Error: Can't write to ", argv[2], 99);

	while ((bytes_readed = read(fd_from, buffer, 1024)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_readed);
		if (bytes_written == -1)
			print_error_s("Error: Can't write to ", argv[2], 99);
	}
	if (bytes_readed == -1)
		print_error_s("Error: Can't read from file ", argv[1], 98);

	if (close(fd_from) == -1)
		print_error_d("Error: Can't close fd ", fd_from, 100);
	if (close(fd_to) == -1)
		print_error_d("Error: Can't close fd ", fd_from, 100);

	return (0);
}
