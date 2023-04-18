#include <stdio.h>
/**
 * main - start
 * @argc: number of items in v
 * @argv: array of strings
 */

int main(int argc, char **argv)
{
	int i;

	printf("Command line arguments are:\n");
	for (i = 1; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return 0;
}
