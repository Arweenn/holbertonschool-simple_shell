#define _GNU_SOURCE

#include "main.h"

/**
 * _EndOfFile - prototype
 * @input: user's input to free if eof
 * @status: exit
 * Return: void
 */

void _EndOfFile(char *input, int status)
{
	if (feof(stdin))
	{
		free(input);
		printf("\n");
		exit(status);
	}
}


/**
 * main - prototype
 * Return: 0
 */

int main(void)
{
	int status;
	char *input = NULL, *args[2] = {NULL, NULL};
	size_t inputSize = 0;
	ssize_t inputRead;
	pid_t childPid;

	while (1)
	{
		printf("$ ");
		inputRead = getline(&input, &inputSize, stdin);
		if (inputRead == -1)
		{
			_EndOfFile(input, status);
			perror("Error");
			continue;
		}
		input[inputRead - 1] = '\0';
		args[0] = input;
		childPid = fork();
		if (childPid == -1)
		{
			perror("fork");
			continue;
		}
		else if (childPid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				fprintf(stderr, "%s: command not found\n", args[0]), exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
				continue;
		}
	}
	free(input);
	return (0);
}

