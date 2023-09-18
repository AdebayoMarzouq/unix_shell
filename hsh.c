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
	char *line = NULL;
	size_t len = 0;
	ssize_t bytes_read = 0;

	do
	{
		if (isatty(STDIN_FILENO))
			prompt(NULL);
		bytes_read = getline(&line, &len, stdin);
		if (bytes_read == -1)
		{
			printf("Exiting shell....\n");
			/** Error function with exit here*/
			exit(1);
		}
		parse_str(line, ' ', &argv, &argc);
		exec(argv);
	} while (1);
	/** Free 2D array here */
	free(argv);
	free(line);
	return (0);
}
