#include "shell.h"

/**
 *
 */

void make_exit(void)
{
	exit(1);
}

/**
 *
*/

void print_env(char *env_var)
{
	int i;

	if (env_var == NULL)
		return;

	/** Iterate through `environ` to print all environment variables */
	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\0');
	}
	return;
}