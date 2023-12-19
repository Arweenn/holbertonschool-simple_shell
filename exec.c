#include "main.h"

/**
 * exec - executes the input received
 * @args: arguments
 * @input: input
 * Return: void
 */

void exec(char **args, char *input)
{

	int status, statusExit;
	pid_t childPid = 0;

	if (access(args[0], X_OK) != 0)
		fprintf(stderr, "%s: command not found\n", args[0]);

	childPid = fork();
	if (childPid == -1)
	{
		perror("fork\n");
		exit(EXIT_FAILURE);
	}
	else if (childPid == 0)
	{
		execve(args[0], args, environ);
		free(args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			statusExit = WEXITSTATUS(status);
			if (statusExit != 0)
			{
				free(args[0]);
				free(input);
				exit(EXIT_FAILURE);
			}
		}
	}
}
