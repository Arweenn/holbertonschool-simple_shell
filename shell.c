#define _GNU_SOURCE
#define MAX_ARGS 64

#include "main.h"

/**
 * main - main function for the shell
 * Return: 0 on success
 */

int main(void)
{
	char *input = NULL, *args[2] = {NULL, NULL}, *token;
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
		if (inputRead == -1)
		{
			if (feof(stdin))
			{
				free(input);
				exit(EXIT_SUCCESS);
			}
			free(input);
			perror("Error");
		}

		input[inputRead - 1] = '\0';

		token = strtok(input, " ");
		while (token != NULL)
			token = strtok(NULL, " ");
		args[0] = input;
		exec(args);
	}
	free(input);
	return (0);
}
