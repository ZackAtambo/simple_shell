#include "shell.h"

/**
  * strcat_x -  function that concatenates two strings
  * @src: first string t be concatenated
  * @dest: second string to be concatenated with the first one
  * Return: the  concatenated string
  */
char *strcat_x(char *src, char *dest)
{
	char *output;
	int k, l;
	int number;

	k = 0;
	l = 0;

	number = strlen(src) + strlen(dest) + 2;
	output = malloc(sizeof(char) * number);
	if (!output)
	{
		return (NULL);
	}
	while (src[k] != '\0')
	{
		output[l] = src[k];
		k++;
		l++;
	}
	if (l != 0)
	{
		output[l] = '/';
		l++;
	}
	k = 0;
	while (dest[k] != '\0')
	{
		output[l] = dest[k];
		k++;
		l++;
	}
	output[l] = '\0';
	free(dest);
	return (output);
}
