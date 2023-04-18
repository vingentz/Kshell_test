#include "main.h"
/**
 * main - start of function
 * @ac: unused variable
 * @argv: arguements
 * Return: 0
 */
int main(int ac, char **argv)
{
	char *prompt = "(Kshell) $: ";
	char *lineptr, *lineptr_copy;
	char *token;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_tokens = 0;
	int i;
	int counter;

	(void)ac;/* declare unused variables as void */
	while (1)/* Loop to not leave the shell after one line */
	{
		printf("%s", prompt);/* created shell prompt */
		nchars_read = getline(&lineptr, &n, stdin);/* user input */
		if (nchars_read == -1)/* if nothing is input, print error and exit */
		{
			printf("Exiting Shell.....\n");
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
