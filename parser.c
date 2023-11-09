#include "shell.h"
#include <strings.h>

/**
 * str_parser - function that parses pointers to a string
 * @regy: string pointer to be passed
 * Return: the parsed string
 */

char **str_parser(char *regy)
{
	char *tok = NULL, *regy_copy = NULL, *tok_copy = NULL;
	char **tok_array = NULL;
	char *delimeta = " \t\n";
	int tok_count = 0, ind = 0, track = 0;

	regy_copy = malloc((strlen(regy) + 1) * sizeof(char));
	if (regy_copy == NULL)
	{
		perror("Mem Allocation Failed");
		return (NULL);
	}
	strcpy(regy_copy, regy);
	tok = strtok(regy, delimeta);
	while (tok != NULL)
	{
		tok_count++;
		tok = strtok(NULL, delimeta);
	}
	tok_array = malloc(sizeof(char *) * (tok_count + 1));
	if (tok_array == NULL)
		return (NULL);
	tok_copy = strtok(regy_copy, delimeta);
	while (tok_copy != NULL)
	{
		tok_array[ind] = strdup(tok_copy);
		if (tok_array[ind] == NULL)
		{
			for (track = 0; track < ind; track++)
				free(tok_array[track]);
			free(tok_array);
			free(regy_copy);
			return (NULL);
		}
		tok_copy = strtok(NULL, delimeta);
		ind++;
	}
	tok_array[ind] = NULL;
	free(regy_copy);
	return (tok_array);
}
