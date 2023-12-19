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

    char *commandPath = handle_path(args[0]);

    if (commandPath == NULL)
    {
        fprintf(stderr, "%s: command not found\n", args[0]);
        return;
    }

    childPid = fork();
    if (childPid == -1)
    {
        perror("fork\n");
        exit(EXIT_FAILURE);
    }
    else if (childPid == 0)
    {
        execve(commandPath, args, environ);
        perror("execve");
        free(commandPath);
        free(args[0]);
        exit(EXIT_FAILURE);
    }
    else
    {
        free(commandPath);
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
