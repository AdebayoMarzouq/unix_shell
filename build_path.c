#include "shell.h"

/**
 *
 */

int build_path(char **new_str, char *path, char *name)
{
	int len = strlen(path) + strlen(name) + 2, i, j = 0;

	if (!new_str || !path || !name)
		return (-1);

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
