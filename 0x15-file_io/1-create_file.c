#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "main.h"

/**
* create_file - creates a file with the given name
* and writes the given text to it
* @filename: the name of the file to be created
* @text_content: the text to write to the file
*
* Return: 1 on success, -1 on failure
*/
int create_file(const char *filename, char *text_content)
{
int fd, nwritten, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[len] != '\0')
len++;
}

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
nwritten = write(fd, text_content, len);
if (nwritten == -1 || nwritten != len)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
