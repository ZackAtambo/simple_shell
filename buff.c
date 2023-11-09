#include "shell.h"

/**
 * new_regy - function that removes comments froma string
 * @regy: pointer to string with comments
  */

void new_regy(char **regy)
{
	size_t tk2;
	char *rm_hash;
	char *buf;

	if (!(strncmp(*regy, "echo", 4) == 0))
	{
		rm_hash = strchr(*regy, '#');
		if (rm_hash != NULL)
		{
			tk2 = strlen(*regy) - strlen(rm_hash);
			buf = (char *) malloc(tk2 + 100);
			if (buf != NULL)
			{
				strncpy(buf, *regy, tk2);
				buf[tk2] = '\0';
				free(*regy);
				*regy = buf;
			}
		}
	}
}
