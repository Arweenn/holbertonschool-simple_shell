#define _GNU_SOURCE
#define MAX_ARGS 64

#include "main.h"

/**
 * EndOfFile - ckeck if end of file
 * @input: user's input to free if eof
 * @inputRead: input stored
 * Return: void
 */


void EndOfFile(char *input, ssize_t inputRead)
{
	if (inputRead == EOF)
	{
		free(input);
		printf("\n");
		exit(EXIT_SUCCESS);
	}
}


/**
 * main - main function for the simple shell
 * Return: 0
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
		if (inputRead == -1)
		{
			EndOfFile(input, inputRead);
			free(input);
			perror("Error");
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
