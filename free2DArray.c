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
		return
	}

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}