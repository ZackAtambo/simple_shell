#include "shell.h"

/**
  *get_tok_path - is a function that gets and  tokenizes path
  *Return: the tokenirized path if it was found
  */
char **get_tok_path(void)
{
	char **directory;
	char *path1;
	char *path_copy;
	char *tk1;
	char *tk2;
	char *delimeta = ":";
	int ind = 0;
	int count = 0;
	size_t store;

	store = strlen(getenv("PATH"));
	path1 = malloc(store + 1);
	strcpy(path1, getenv("PATH"));
	path_copy = strdup(path1);
	if (path_copy == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	tk1 = strtok(path1, delimeta);
	while (tk1 != NULL)
	{
		count++;
		tk1 = strtok(NULL, delimeta);
	}
	directory = malloc(sizeof(char *) * (count + 1));
	tk2 = strtok(path_copy, delimeta);
	ind = 0;
	while (tk2 != NULL)
	{
		directory[ind] = (char *) strdup(tk2);
		tk2 = strtok(NULL, delimeta);
		ind++;
	}
	directory[ind] = NULL;
	free(path_copy);
	free(path1);
	return (directory);
}

/**
  *get_path - gets the concatenated command for execve
  *@val: pointer to array that holds tokenized input from strparse
  *@directory: pointer to array that holds tokenized path
  *Return: returns 1st argument for execve
  */

char *get_path(char **val, char **directory)
{
	char *current;
	int ind;
	struct stat _fileinfo;

	directory = get_tok_path();
	current = getcwd(NULL, 0);
	for (ind = 0; directory[ind] != NULL; ind++)
	{
		chdir(directory[ind]);
		if (stat(val[0], &_fileinfo) == 0)
		{
			val[0] = strcat_x(directory[ind], val[0]);
			break;
		}
	}
	for (ind = 0; directory[ind] != NULL; ind++)
		free(directory[ind]);
	chdir(current);
	free(current);
	free(directory[ind]);
	free(directory);
	return (val[0]);
}
