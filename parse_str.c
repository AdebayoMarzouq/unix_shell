#include "shell.h"

/**
 * parse_str - splits a string into a NULL terminated array
 * @src: source string to be tokenized
 * @delimiter: the delimiter to check for
 * @dest_arr: the array to store the tokenized words
 * @dest_len: a pointer to store the number of words
 *
 * Return: void (updated wordsArr and numWords via pointers)
 */

int parse_str(const char *src, const char delimiter, char ***dest_arr, int *dest_len)
{
	/** Calculate the number of strings */
	/** Assign memory space equal to number of strings +  NULL */
	/** Loop thru string then check for delimiter or null termination */
	/** Keep wordStart and wordIndex variables to estimate the length */
	/** of the word */
	/** Assign memory space Arr[index] to length of string */
	/** Free memory space allocated as necessary if error occurs*/
	int len, i, j, words_no = 0, word_start, word_index, word_length;

	if (!src)
		return (-1);

	len = strlen(src);
	if (len == 0)
	{
		*dest_arr = NULL;
		*dest_len = 0;
		return (-1);
	}

	words_no = 1;
	for (i = 0; i < len; i++)
	{
		if (src[i] == delimiter && src[i + 1] && src[i + 1] != delimiter)
			words_no++;
	}
	*dest_arr = malloc((words_no + 1) * sizeof(char *));
	if (!(*dest_arr))
	{
		*dest_len = 0;
		return (-1);
	}
	word_start = 0;
	word_index = 0;
	for (i = 0; i < len; i++)
	{
		if (src[i] == delimiter || src[i] == '\0' || src[i] == '\n')
		{
			word_length = i - word_start;
			(*dest_arr)[word_index] = malloc((word_length + 1) * sizeof(char));
			if (!(*dest_arr)[word_index])
			{
				for (j = 0; j < word_index; j++)
					free((*dest_arr)[j]);
				free(*dest_arr);
				*dest_len = 0;
				return (-1);
			}
			strncpy((*dest_arr)[word_index], src + word_start, word_length);
			(*dest_arr)[word_index][word_length] = '\0';
			word_start = i + 1;
			word_index++;
		}
	}
	(*dest_arr)[words_no] = NULL;
	*dest_len = words_no;

	return (0);
}
