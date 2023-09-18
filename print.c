#include "shell.h"

/**
 * _puts - prints a string to stdout
 * @str: The string
 *
 * Return: has no return value
 */

void _puts(char *str)
{
	int i;
	char ch;

	i = 0;
	while (str[i] != '\0')
	{
		ch = str[i];
		_putchar(ch);
		++i;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * error_message - prints error message for invalid command
 * @p: process number
 * @s: the shell name
 * @s: t\The command passed
 */
void error_message(char *s, char *cmd)
{
	int p = getpid();
	
	_puts(s);
	_puts(": ");
	print_number(p);
	_puts(": ");
	_puts(cmd);
	_puts(" not found\n");
}