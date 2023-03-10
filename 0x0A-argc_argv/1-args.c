#include <stdio.h>

/**
 * main - prints the number of arguments passed into it.
 * @argc: the number of command line arguments
 * @argv: An array containing the program command line arguments.
 *
 * Return: always 0 (success)
 */

int main(int argc, char *argv[])
{
	int count;

	for (count = 0; count < argc; count++)
	{
		printf("%s\n", argv[count]);
	}
	return (0);
}
