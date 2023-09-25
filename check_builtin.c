#include "shell.h"

/**
 * check_builtin - check built ins
 * @command: command to executer
 *
 * Return: 1, 0 or -1
*/

int check_builtin(char *command)
{
	if (!command)
		return (-1);

	/** use 2D array and function pointers if list gets long */
	if (strcmp("env", command) == 0)
	{
		/** enironment variable are printed here */
		print_env();
		return (0);
	}

	return (1);
}
