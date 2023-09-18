#include "shell.h"

/**
 *
*/

void free2DArray(char **arr)
{
	int i;

	if (!arr)
		return;
	if (!arr[0])
	{
		free(arr);
		return;
	}

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}