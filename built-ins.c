#include "shell.h"

/**
 *
 */

int make_exit(void)
{
	exit(1);
}

/**
 *
*/

int print_env(char *env_var)
{
	int i;

	if (name == NULL)
		return NULL;

	/** Iterate through `environ` to print all environment variables */
	for (i = 0; environ[i]; i++)
	{
		_puts(environ[i]);
		_putchar('\0');
	}
	return (NULL);
}