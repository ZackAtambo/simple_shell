#include "shell.h"
/**
 * main - it is the entry
 * @argc: it is the number of arguments
 * @argv: the array arguments
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int zen = 0;
	ssize_t xy = 0;
	char *path_t, **val = NULL, **directory = NULL, *regy = NULL;
	size_t tracker = 0;

	if (!(argc != 0))
		perror("error encountered");
	while (1)
	{
		zen++;
		show_display();
		fflush(stdout);
		xy = getline(&regy, &tracker, stdin);
		if (xy == EOF)
			end_of_file(regy);
		read_error(xy, regy);
		if ((strcmp(regy, "\n") == 0) || (regy[0] == ' ') || (regy[0] == '#'))
			continue;
		new_regy(&regy);
		del_var(regy);
		val = str_parser(regy);
		if (strcmp(val[0], "exit") == 0)
			exit_handler(val, regy);
		if (strchr(val[0], '/') != NULL)
		{
			handle_path(val, argv, regy);
			continue;
		}
		else
			path_t = get_path(val, directory);
		if (!(access(path_t, F_OK) == 0))
			fprintf(stderr, "%s: %d: %s: path not found\n", argv[0], zen, regy);
		else
			execute(path_t, val);
		if (val != NULL)
			_free(val);
	}
	free(regy);
	return (0);
}
