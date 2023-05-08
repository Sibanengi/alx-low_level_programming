#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
* read_textfile - reads a text file and
* prints it to the POSIX standard output
* @filename: the name of the file to be read
* @letters: the number of letters to be read and printed
*
* Return: number of letters read and printed, or 0 on failure
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
    int fd;
    ssize_t nread, nwritten;
    char *buf;

    if (filename == NULL)
        return (0);

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (0);

    buf = malloc(sizeof(char) * letters);
    if (buf == NULL)
        return (0);

    nread = read(fd, buf, letters);
    if (nread == -1)
    {
        free(buf);
        close(fd);
        return (0);
    }
    nwritten = write(STDOUT_FILENO, buf, nread);
    if (nwritten == -1 || nwritten != nread)
    {
        free(buf);
        close(fd);
        return (0);
    }

    free(buf);
    close(fd);
    return (nwritten);
}
