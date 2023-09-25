#include "shell.h"

/**
 * print_env - prints enviroment variables
 *
 * Return: has no return value
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
