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
	char *line = NULL, **cmd_args;
	size_t len = 0;
	ssize_t bytes_read = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt(NULL);
		bytes_read = getline(&line, &len, stdin);
		if (bytes_read == -1)
		{
			printf("Exiting shell....\n");
			/** Error function with exit here*/
			break;
		}
		cmd_args = parse_str(line, ' ');
		if (cmd_args)
		{
			exec(cmd_args);
			free2DArray(cmd_args);
		}
		else
			puts("Error: could not parse string");
		/** create cleanups here */
	}
	/** Free 2D array here */
	free2DArray(cmd_args);
	free(line);
	return (0);
}
