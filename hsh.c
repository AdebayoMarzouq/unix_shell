#include "shell.h"

/**
 * main - contains the main function of the program
 * @argc: Arguments passed into the CLI
 * @argv: Pointer to arguments string
 *
 * Description: A simple UNIX shell
 * Return: Always 0
 */

int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *line = NULL, **cmd_args = NULL;
	size_t len = 0;
	ssize_t bytes_read = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt(NULL);
		bytes_read = getline(&line, &len, stdin);
		if (bytes_read == -1)
		{
			free(line);
			exit(1);
		}
		cmd_args = parse_str(line, ' ');
		if (cmd_args)
		{
			if (cmd_args[0] && strcmp(cmd_args[0], "exit") == 0)
			{
				free2DArray(cmd_args);
				free(line);
				exit(1);
			}
			else if (check_builtin(cmd_args[0]))
				exec(cmd_args);
			free2DArray(cmd_args);
		}
	}
	return (0);
}
