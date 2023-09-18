#include "shell.h"

/**
 *
*/

int check_builtin(char *command)
{
	if (!command)
		return (-1);
	/** If list gets too long, use function pointers and arrays */

	if (strcmp("exit", command) == 0)
	{
		/** run exit here */
		make_exit()
		return (0);
	}

	if (strcmp("env", command) == 0)
	{
		/** print env vars here */
		print_env();
		return (0);
	}

	return (1);
}