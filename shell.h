#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

void prompt(char *sym);
int parse_str(const char *src, const char delimiter, char ***dest_arr, int *dest_len);
void exec(char **args);
char *_getenv(const char *name);
int append_str(char **new_str, ...);
int run_command(char *command, char **args, char **env_vars);

#endif
