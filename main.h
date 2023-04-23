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

int num_commands;

extern char **environ;

typedef struct {
	char *cmd;
	int (*fnc)(char **argv);
} cmds_t;

int bi_exit(char **argv);
int bi_env(char **argv);

typedef struct {
	char *cmd;
	char *op;
	char **argv;
} command_t;

void execute_file(char *filename);
void prompt(void);
command_t *parse_command(char *cmd);
char *replace_aliases(char *cmd);
char *replace_vars(char *cmd);
command_t *split(char *cmd);
int execute_commands(command_t *cmds);
int builtin_check(char *cmd, char **argv);
char **get_paths(void);
char *get_path(char* cmd);
int execute_cmd(command_t cmd_s);
int operator_check(char *op, int status);
#endif
