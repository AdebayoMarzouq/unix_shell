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
char **parse_str(const char *src, const char delimiter);
void exec(char **args);
char *_getenv(const char *name);
int build_path(char **new_str, char *path, char *name);
int run_command(char *command, char **args, char **env_vars);
int check_builtin(char *command);
void free2DArray(char **arr);
int make_exit(void);
int print_env(void);

#endif
