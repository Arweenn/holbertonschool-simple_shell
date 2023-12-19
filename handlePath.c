#include "main.h"

#define _GNU_SOURCE

/**
 * handle_path - function that finds the path of th command
 * to execute it
 *
 * @input: user's input
 *
 * Return: 'input' if the command has a slash char in it,
 * the result of the given input or NULL if nothing is found
 */

char *handle_path(char *input)
{
	int i = 0;
	char *token = NULL;
	char *cache;
	char *result = NULL;

	if (strchr(input, '/') != NULL)
		strdup(input);
	while (environ[i])
	{
		cache = strdup(environ[i]);
		token = strtok(cache, "=");
		if (strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			token = strtok(token, ":");
			while (token)
			{
				result = malloc(strlen(token) + strlen(input) + 2);
				if (result ==  NULL)
				{
					perror("Malloc is NULL");
					return (NULL);
				}
				sprintf(result, "%s/%s", token, input);
				if (access(result, X_OK) == 0)
				{
					free(cache);
					return (result);
				}
				free(result);
				token = strtok(NULL, ":");
			}
		}
		free(cache);
		i++;
	}
	free(input);
	return (NULL);
}
