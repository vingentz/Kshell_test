#include <stdio.h>
#include <stdlib.h>

/**
 * main - start
 * @ac:item numbers
 * @argv: string array
 */

int main(int ac, char **argv)
{
	char *prompt = "$ ";
	char *lineptr;
	size_t n = 0; 

	(void)ac; (void)argv;
	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	printf("%s", lineptr);

	free(lineptr);
	return (0);
}
