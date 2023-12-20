#include "main.h"

/**
 * tokenize - function that splits a string into multiple ones
 * @input: users input
 * @args: arguments
 * Return: void
 */

void tokenize(char *input, char *args[])
{
	char *token;
	unsigned int i = 0;

	token = strtok(input, " ");
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");
	}
	args[i] = NULL;

	if (strcmp(input, "env") == 0)
	{
		printEnv();
		return;
	}

	if (strcmp(input, "exit") == 0 && args[1] == NULL)
	{
		free(args[0]);
		exit(0);
	}

	token = strdup(args[0]);
	args[0] = handle_path(args[0]);
	if (args[0] != NULL)
	{
		exec(args, input);
		free(args[0]);
	}
}
