#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define BUFFSIZE 1024

int num_paths;
extern char **environ;

typedef struct {
	char *cmd;
	char *op;
	char **argv;
} command_t;

void execute_file(char *filename);
void prompt (void);
char *replace_aliases(char *cmd);
char *replace_vars(char *cmd);
command_t *split(char *cmd);
int execute_commands(command_t *cmds);
int builtin_check(char *cmd);
char **get_paths(void);
int execute_cmd(command_t cmd_s);
int operator_check(char *op, int status);
#endif
