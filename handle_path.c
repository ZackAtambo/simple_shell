#include "shell.h"
#include <stdio.h>

/**
 * handle_path - is a function that checks if path exists or not
 * @val: pointer to the string used to store parsed commands arguments
 * @argv: an array of characters
 * @regy:  is a pointer to a string and is used to store user input
 */
void handle_path(char **val, char **argv, char *regy)
{
	char *path_t = NULL;

	path_t = malloc((strlen(val[0]) + 1) * sizeof(char));
	if (path_t == NULL)
	{
		perror("allocation failed");
	}

	else
	{
		strcpy(path_t, val[0]);
		if (!(access(path_t, F_OK) == 0))
			dprintf(STDERR_FILENO, "%s: %s: path not found\n", argv[0], regy);
		else
			execute(path_t, val);
	}

	free(path_t);
	if (path_t)
	{
	if (val != NULL)
		_free(val);
	}
}

/**
 * read_error - is funtion that exists if getline ufunction fails
 * @xy: is a function that stores the return value of getline function
 * @regy: is a pointer to a string and is used to store user input
 * Return: void
 */
void read_error(ssize_t xy, char *regy)
{
	if (xy == -1)
	{
		free(regy);
		exit(EXIT_FAILURE);
	}
}
