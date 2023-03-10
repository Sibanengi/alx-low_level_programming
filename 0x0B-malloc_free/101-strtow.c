#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
* strtow - a function that concatenates all the arguments of your program
* @str: array
* Return: duble pointer
*/
char **strtow(char *str)
{
	int k = 0, i = 0, count = 0, height = 0, word = 0;
	char **p;

	if (str == 0 || *str == 0)
		return (NULL);
	while (str[i] != '\0')
	{
		count++;
		if (str[i] != 32 && (str[i + 1] == 32 || str[i + 1] == '\0'))
		{ height++; }
	i++;
	}
	if (height == 0)
		return (NULL);
	p = (char **)malloc(sizeof(char *) * (height + 1));
	if (p == NULL)
		return (NULL);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] != 32)
		count++;
		if (count > 0 && (str[i + 1] == 32 || str[i + 1] == '\0'))
		{
			p[word] = (char *)malloc((count + 1) * sizeof(char));
			if (p[word] == NULL)
			return (NULL);
			for (k = 0; k < count; k++)
			{
				p[word][k] = str[i - count + 1 + k];
			}
			p[word][k] = '\0';
			word++;
			count = 0;
		}
		i++;
	}
	p[height] = '\0';
return (p);
}
