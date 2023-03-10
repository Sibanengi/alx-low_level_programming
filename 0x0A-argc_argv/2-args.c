#include <stdio.h>

/**
 * main -  prints all arguments it receives.
 * @argc: the number of command line arguments
 * @argv: An array containing the program command line arguments.
 *
 * Return: Always 0 (success).
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
