#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
* append_text_to_file - appends text at the end of a file
* @filename: the name of the file to append to
* @text_content: the text to append to the file
*
* Return: 1 on success, -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, bytes_written;
size_t text_len;

if (filename == NULL)
return (-1);

if (access(filename, W_OK) == -1)
return (-1);

if (text_content == NULL)
return (1);

text_len = strlen(text_content);

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

bytes_written = write(fd, text_content, text_len);
if (bytes_written == -1 || bytes_written != (int)text_len)
{
close(fd);
return (-1);
}

close(fd);
return (1);
}
