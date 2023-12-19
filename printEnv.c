#include "main.h"

/**
 * printEnv - print the environment variables
 * Return: void
 */

void printEnv(void)
{
	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
