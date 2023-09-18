#include "shell.h"

/**
 *
 */

int append_str(char **new_str, ...)
{
	char *str;
	va_list args;
	int len = 1, i, j = 0;

	va_start(args, new_str);
	*new_str = NULL;
	while (1)
	{
		str = va_arg(args, char *);
		if (!str)
			break;
		len += strlen(str);
		*new_str = realloc(*new_str, len);
		if (!(*new_str))
		{
			free((*new_str));
			return (-1);
		}
		i = 0;
		while (str[i])
		{
			(*new_str)[j] = str[i];
			i++;
			j++;
		}
	}
	*new_str = realloc((*new_str), len);
	if (!(*new_str))
	{
		free(*new_str);
		return (-1);
	}
	(*new_str)[j] = '\0';
	va_end(args);
	return (0);
}
