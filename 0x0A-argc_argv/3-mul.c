#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the number of arguments passed into it.
 * @argc: the number of command line arguments
 * @argv: An array containing the program command line arguments.
 *
 * Return: Always 0 (success).
 */
int main(int argc, char *argv[])
{
	int mul = 1;

	if (argc == 3)
	{
		mul *= atoi(argv[argc - 2]);
		mul *= atoi(argv[argc - 1]);
		printf("%d\n", mul);
	}
	else
		printf("Error\n");
	return (0);

}
