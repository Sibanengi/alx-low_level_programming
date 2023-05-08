#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
* append_text_to_file - appends text to the end of a file
* @filename: the name of the file to append to
* @text_content: the text to append
*
* Return: 1 on success, -1 on failure
*/

int append_text_to_file(const char *filename, char *text_content)
{
int fd, nwritten, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[len] != '\0')
len++;
}

fd = open(filename, O_WRONLY | O_APPEND);
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
