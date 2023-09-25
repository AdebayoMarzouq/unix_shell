#include "shell.h"

/**
 * build_path - concatenates path
 * @new_str: pointer to the new string  2D array
 * @path: path env variable
 * @name: name of the command
 *
 * Return: 0 if successful else -1
 */

int build_path(char **new_str, char *path, char *name)
{
	int len = strlen(path) + strlen(name) + 2, i, j = 0;

	if (!new_str || !path || !name)
		return (-1);

	/** Allocated memory to arguments array */
	*new_str = malloc(sizeof(*new_str) * len);
	if (!(*new_str))
	{
		free(*new_str);
		return (-1);
	}
	i = 0;
	while (i < len)
	{
		while (path[i])
		{
			(*new_str)[j] = path[i];
			i++;
			j++;
			continue;
		}
		(*new_str)[j] = '/';
		j++;
		i = 0;
		while (name[i])
		{
			(*new_str)[j] = name[i];
			i++;
			j++;
			continue;
		}
		(*new_str)[j] = '\0';
		return (0);
	}
	return (0);
}

