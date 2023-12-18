#define _GNU_SOURCE
#define MAX_ARGS 64

#include "main.h"

/**
 * main - main function for the shell
 * Return: 0 on success
 */

int main(void)
{
	unsigned int i = 0;
	char *input = NULL, *args[MAX_ARGS], *token;
	size_t inputSize = 0;
	ssize_t inputRead;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("$ ");
			fflush(stdout);
		}

		inputRead = getline(&input, &inputSize, stdin);
		if (inputRead == EOF)
		{
			free(input);
			printf("\n");
			exit(EXIT_SUCCESS);
		}

		input[inputRead - 1] = '\0';

		token = strtok(input, " ");
		while (token && i < 64 - 1)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;
		exec(args);
	}
	free(input);
	return (0);
}
