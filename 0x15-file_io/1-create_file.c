#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * create_file - creates a file with the specified content
 * @filename: the name of the file to create
 * @text_content: the content to write to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
    int fd, len, ret;

    if (!filename)
        return (-1);

    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd == -1)
        return (-1);

    if (!text_content)
    {
        close(fd);
        return (1);
    }

    for (len = 0; text_content[len]; len++)
        ;

    ret = write(fd, text_content, len);
    if (ret == -1 || ret != len)
    {
        close(fd);
        return (-1);
    }

    close(fd);
    return (1);
}
