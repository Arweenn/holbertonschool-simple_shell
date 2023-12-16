#define _GNU_SOURCE

#include "main.h"

/**
 * EndOfFile - ckeck if end of file
 * @input: user's input to free if eof
 * @status: exit value
 * @inputRead: input stored
 * Return: void
 */

void EndOfFile(char *input, ssize_t inputRead, int status)
{
	if (inputRead == EOF)
	{
		free(input);
		printf("\n");
		exit(status);
	}
}


/**
 * main - main function for the simple shell
 * Return: 0
 */

int main(void)
{
	int status;
	char *input = NULL, *args[2] = {NULL, NULL}, *token;
	size_t inputSize = 0;
	ssize_t inputRead;
	pid_t childPid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		inputRead = getline(&input, &inputSize, stdin);
		if (inputRead == -1)
		{
			EndOfFile(input, inputRead, status);
			free(input);
			perror("Error");
		}
		token = strtok(input, " ");
		while (token)
			token = strtok(NULL, " ");
		input[inputRead - 1] = '\0';
		args[0] = input;
		childPid = fork();
		if (childPid == -1)
			perror("fork");
		else if (childPid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				fprintf(stderr, "%s: command not found\n", args[0]);
				free(input), exit(EXIT_FAILURE);
			}
		}
		else
			wait(&status);
	}
	free(input);
	return (0);
}
