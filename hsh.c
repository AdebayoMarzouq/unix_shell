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
	int i;

	do
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
			i = 0;
			while (cmd_args[i])
			{
				puts("Ran frees");
				free(cmd_args[i]);
				i++;
			}
			free(cmd_args);
		}
		else
			puts("Error: could not parse string")
		/** create cleanups here */
	} while (1);
	/** Free 2D array here */
	if (cmd_args)
	{
		i = 0;
		while (cmd_args[i])
		{
			puts("Ran frees");
			free(cmd_args[i]);
			i++;
		}
		free(cmd_args);
	}
	free(line);
	return (0);
}
