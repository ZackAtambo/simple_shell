#include "shell.h"

/**
 * exit_handler - function to handle the exit status/rank
 * @val: the tokenized register
 * @regy: the register
 * Return: 0 on success
 */

int exit_handler(char **val, char *regy)
{
	int status;
	int ind;

	status = 0;
	if (val[1] != NULL)
		status = atoi(val[1]);
	for (ind = 0; val[ind] != NULL; ind++)
		free(val[ind]);
	free(regy);
	free(val);

	if (status > 0)
		exit(status);
	else if (status == 0)
		exit(EXIT_SUCCESS);
	else
	{
		return (-1);
	}
}
