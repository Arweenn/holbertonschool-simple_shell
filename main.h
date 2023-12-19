#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sched.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void exec(char **args, char *input);
void tokenize(char *input, char *args[]);
void handlePath(const char* path, int length);
void printEnv(void);
char *handle_path(char *input);

#endif /*MAIN_H*/
