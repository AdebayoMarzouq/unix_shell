#include "shell.h"

/**
 *
*/

void print_env()
{
	int i;

	/** Iterate through `environ` to print all environment variables */
	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\n');
	}
	return;
}