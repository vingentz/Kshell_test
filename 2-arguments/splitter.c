#include "main.h"
/**
 * main - start
 * @ac: number of items in v
 * @argv: array of strings
 */

int main(int ac, char **argv)
{
	char *prompt = "(Eshell) $ ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	char *token;
	int num_tokens = 0;
	int i, counter;

/* declaring void variables */
	(void)ac; (void)argv;
/* Create a loop for the shell's prompt */
	while (1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
/* check if the getline function failed or reached EOF or user use CTRL + D */ 
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}
		lineptr_copy = malloc(sizeof(char) * nchars_read);/* space to hold string */
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		} /* get the copy function from github, not use strcpy */
		strcpy(lineptr_copy, lineptr);/* copy lineptr to lineptr_copy */
		token = strtok(lineptr, delim);/* calculate total token no from string */
		while (token != NULL)
		{
			num_tokens++;
			token = strtok(NULL, delim);
		}
		num_tokens++;
		argv = malloc(sizeof(char *) * num_tokens);/* Space to hold string array */
		token = strtok(lineptr_copy, delim);/* store token in the argv array */
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		for (counter = 0; argv[counter] != NULL; counter++)
		{
			printf("%s\n", argv[counter]);
		}
	}
	free(argv);
	free(lineptr);
	free(lineptr_copy);
	return (0);
}
