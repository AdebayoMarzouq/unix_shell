#include "shell.h"

/**
 * _getenv - get the environment variable
 * @name: variable name
 *
 * Return: returns the env variable
*/

char *_getenv(const char *name)
{
	int i;
	char *temp;
	size_t len;

	if (name == NULL)
		return NULL;

	len = strlen(name);
	/** Iterate through `environ` to print all environment variables */
	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
			/** compare env variable to name */
			/** remember to free temp to prevent memory leaks */
			temp = strdup(environ[i] + len + 1);
			return (temp);
		}
	}
	return (NULL);
}
