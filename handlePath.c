#include "main.h"

/**
 * handle_path - Finds the path of the command to execute
 * @input: User's input
 * Return: The full path of the command if found, NULL otherwise
 */

char *handle_path(char *input)
{
    char **env_var;

    if (strchr(input, '/') != NULL)
        return strdup(input);

    for (env_var = environ; *env_var != NULL; env_var++)
    {
        char *env_entry = strdup(*env_var);
        char *token = strtok(env_entry, "=");

        if (strcmp(token, "PATH") == 0)
        {
            char *path_token = strtok(NULL, "=");

            path_token = strtok(path_token, ":");
            while (path_token != NULL)
            {
                char *result = malloc(strlen(path_token) + strlen(input) + 2);

                if (result == NULL)
                {
                    perror("Malloc is NULL");
                    free(env_entry);
                    return NULL;
                }

                sprintf(result, "%s/%s", path_token, input);

                if (access(result, X_OK) == 0)
                {
                    free(env_entry);
                    return result;
                }

                free(result);
                path_token = strtok(NULL, ":");
            }
        }

        free(env_entry);
    }

    free(input);
    return NULL;
}
