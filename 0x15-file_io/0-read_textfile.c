#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - reads a text file and
 * prints it to the POSIX standard output
 *
 * @filename: the name of the file to be read
 * @letters: the number of letters to be read and printed
 *
 * Return: the actual number of letters read
 * and printed on success, 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t n_read, n_written;
	char *buffer;

	if (filename == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters + 1));
	if (buffer == NULL)
	{
		close(fd);
		return (0);
	}

	n_read = read(fd, buffer, letters);
	if (n_read == -1)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	buffer[n_read] = '\0';

	n_written = write(STDOUT_FILENO, buffer, n_read);
	if (n_written != n_read)
	{
		close(fd);
		free(buffer);
		return (0);
	}

	close(fd);
	free(buffer);

	return (n_written);
}
