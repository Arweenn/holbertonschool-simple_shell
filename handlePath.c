#include "main.h"

/**
 * handle_path - Finds the path of the command to execute
 * @input: User's input
 * Return: The full path of the command if found, NULL otherwise
 */

char *handle_path(char *input)
{
	int i;
	char *env_entry, *token, *result;

	if (strchr(input, '/') != NULL)
		return (strdup(input));

	for (i = 0; environ[i] != NULL; i++)
	{
		env_entry = strdup(environ[i]);
		token = strtok(env_entry, "=");
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
					free(env_entry);
					return (NULL);
				}
				sprintf(result, "%s/%s", token, input);
				if (access(result, X_OK) == 0)
				{
					free(env_entry);
					return (result);
				}

				free(result);
				token = strtok(NULL, ":");
			}
		}

		free(env_entry);
		i++;
	}

	free(input);
	return (NULL);
}
