#include "shell.h"

/**
 * exec - executes a command
 * @args: arguments
 *
 * Return: has no return value
 */

void exec(char **args)
{
	char *path, *token, *full_path = NULL;
	struct stat info;

	if (!args || !args[0])
	{
		perror("No argument passed:");
		return;
	}

	if (stat(args[0], &info) == 0)
	{
		if (access(args[0], X_OK) == 0)
			run_command(args[0], args, NULL);
		else
		{
			perror("File exists but is not executable: ");
			return;
		}
	}
	else
	{
		path = _getenv("PATH");
		if (!path)
		{
			perror("Path Does not exist: ");
			return;
		}
		token = strtok(path, ":");
		while (token)
		{
			append_str(&full_path, token, "/", args[0], NULL);
			if (stat(full_path, &info) == 0)
			{
				if (access(full_path, X_OK) == 0)
				{
					/** fork process here and handle all the nonsense here */
					run_command(full_path, args, NULL);
					return;
				}
				else
					perror("File exists but is not executable: ");
			}
			free(full_path);
			token = strtok(NULL, ":");
		}
		free(path);
		perror("Invalid command path");
	}
}
