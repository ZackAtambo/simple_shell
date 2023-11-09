#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;
int main(int argc, char *argv[]);
void end_of_file(char *regy);
void _free(char **val);
void new_regy(char **regy);
char *get_path(char **val, char **directory);
void show_display(void);
void handle_path(char **val, char **argv, char *regy);
void read_error(ssize_t xy, char *regy);
char **str_parser(char *regy);
char *del_var(char *str);
int exit_handler(char **val, char *regy);
void execute(char *path_t, char *val[]);
char *strcat_x(char *src, char *dest);
#endif
