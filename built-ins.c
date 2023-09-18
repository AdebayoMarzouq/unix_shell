#include "shell.h"

/**
 *
*/

int built_ins(char *command)
{
	int settings;

	if (!command)
		return (-1);

	if (strcmp("exit", command) == 0)
	{
		/** run exit here */
		puts("exit command");
		return (0);
	}

	if (strcmp("env", command) == 0)
	{
		/** print env vars here */
		puts("env command");
		return (0);
	}

	return (-1)
}