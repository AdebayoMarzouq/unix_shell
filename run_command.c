#include "shell.h"

/**
 * run_command - forks a process and runs the command
 * @command: command to be executed
 * @args: command arguments
 * @env_vars: environment variables
 *
 * Return: 0 if success and 1 if it fails
*/

int run_command(char *command, char **args, char **env_vars)
{
	pid_t child_pid;
	int status;

	if (!command)
		return (0);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (child_pid == 0)
	{
		if (execve(command, args, env_vars) == -1)
		{
			perror("Does not execute Error:");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	return (0);
}

