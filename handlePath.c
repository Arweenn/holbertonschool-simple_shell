#include "main.h"

/**
 * handle_path - Finds the path of the command to execute
 * @input: User input
 * Return: The full path of the command if found, NULL otherwise
 */

char *handle_path(char *input)
{
	int i = 0;
	char *cache, *token, *result;

	if (strchr(input, '/') != NULL)
		return (strdup(input));

	while (environ[i] != NULL)
	{
		cache = strdup(environ[i]);
		token = strtok(cache, "=");
		if (strcmp(token, "PATH") == 0)
		{
			token = strtok(NULL, "=");
			token = strtok(token, ":");
			while (token != NULL)
			{
				result = malloc(strlen(token) + strlen(input) + 2);
				if (result == NULL)
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
