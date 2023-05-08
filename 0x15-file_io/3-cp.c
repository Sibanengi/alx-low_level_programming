#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

/**
 * error_msg_and_exit - Print error message and exit with specified code
 * @msg: Error message to print
 * @exit_code: Exit code to use when exiting
 */
void error_msg_and_exit(char *msg, int exit_code)
{
	dprintf(STDERR_FILENO, "%s", msg);
	if (exit_code == 98 || exit_code == 99 || exit_code == 100)
	dprintf(STDERR_FILENO, "%s\n",
	(exit_code == 98) ? "NAME_OF_THE_FILE" : "FD_VALUE");
	exit(exit_code);
}

/**
 * main - Entry point, implements file copy functionality
 * @argc: Argument count
 * @argv: Array of argument strings
 *
 * Return: 0 on success, exit with error code on failure
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
		error_msg_and_exit("Usage: cp file_from file_to\n", 97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_msg_and_exit("Error: Can't read from file ", 98);

	fd_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_msg_and_exit("Error: Can't write to ", 99);
	}

	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written != bytes_read)
		{
			close(fd_from);
			close(fd_to);
			error_msg_and_exit("Error: Can't write to ", 99);
		}
	}

	if (bytes_read == -1)
		error_msg_and_exit("Error: Can't read from file ", 98);

	if (close(fd_from) == -1)
		error_msg_and_exit("Error: Can't close fd ", 100);

	if (close(fd_to) == -1)
		error_msg_and_exit("Error: Can't close fd ", 100);

	return (0);
}
