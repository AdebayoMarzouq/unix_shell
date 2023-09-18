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
	int i, cmd_count;

	do
	{
		if (isatty(STDIN_FILENO))
			prompt(NULL);
		bytes_read = getline(&line, &len, stdin);
		if (bytes_read == -1)
		{
			printf("Exiting shell....\n");
			/** Error function with exit here*/
			i = 0;
			while (argv[i])
			{
				free(argv[i]);
				i++;
			}
			free(argv);
			free(line);
			i = 0;
			while (argv)
			exit(1);
		}
		parse_str(line, ' ', &cmd_args, &cmd_count);
		exec(argv);
	} while (1);
	/** Free 2D array here */
	return (0);
}
