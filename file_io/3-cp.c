#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void error(int code, const char *str, const char *file)
{
	dprintf(STDERR_FILENO, str, file);
	exit(code);
}
/**
 * main - Copy content of a source file to the destination file
 * @argc: numbers of arguments
 * @argv: content of the arguments
 * Return: 0 if it succeeds
 */
int main(int argc, char *argv[])
{
int fd_from, fd_to, read_bytes;
char buffer[1024];

/* vérif le nombre d'argv (commmande, fichier source, fichier destination) */
if (argc != 3)
error(97, "Usage: cp file_from file_to\n", "");

fd_from = open(argv[1], O_RDONLY); /* ouvre fichier source */
if (fd_from == -1)
error(98, "Error: Can't read from file %s\n", argv[1]);

/* ouvre fichier destination ou le crée */
fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
error(99, "Error: Can't write to %s\n", argv[2]);

/* lit fd_from jusqu'à qu'il n'y ai plus d'octet à lire */
while ((read_bytes = read(fd_from, buffer, 1024)) > 0)
{
	/* écrit et vérifie si une erreur c'est produite */
	if (write(fd_to, buffer, read_bytes) != read_bytes)
		error(99, "Error: Can't write to %s\n", argv[2]);
}

if (read_bytes == -1) /* vérif si une erreur de lecture c'est produite */
error(98, "Error: Can't read from file %s\n", argv[1]);

if (close(fd_from) == -1) /* close source file */
error(100, "Error: Can't close fd %d\n", argv[1]);

if (close(fd_to) == -1) /* close destination file */
error(100, "Error: Can't close fd %d\n", argv[2]);

return (0);
}