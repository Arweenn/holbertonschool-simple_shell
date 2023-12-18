#include "main.h"

/**
 * exec - executes the input received
 * @args: arguments
 * Return: void
 */

void exec(char **args)
{
	char *input = NULL;
	int status, statExit;
	pid_t childPid;

	childPid = fork();
	if (childPid == -1)
		perror("failed fork");
	else if (childPid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			fprintf(stderr, "%s: No such file or directory\n", "./test");
			free(args[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			statExit = WEXITSTATUS(status);
			if (statExit != 0)
			{
				free(args[0]);
				free(input);
				exit(2);
			}
		}
	}
}
