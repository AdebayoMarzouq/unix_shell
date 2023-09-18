#include "shell.h"

/**
 *
*/

int check_builtin(char *command)
{
	if (!command)
		return (-1);

	if (strcmp("env", command) == 0)
	{
		/** print env vars here */
		print_env();
		return (0);
	}

	return (1);
}