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
#include <fcntl.h>

#define BUFFSIZE 1024

extern int num_commands;
static int __attribute__((unused)) g_main_status;
extern char **environ;

/**
 * struct cmds - struct for builtin commands
 * @cmd: command
 * @fnc: builtin function
 *
 */

typedef struct cmds
{
	char *cmd;
	int (*fnc)(char **argv);
} cmds_t;

int bi_exit(char **argv);
int bi_env(char **argv);
int bi_cd(char **argv);
int bi_alias(char **argv);
int bi_setenv(char **argv);
int bi_unsetenv(char **argv);

/**
 * struct command - arguments struct
 * @cmd: builtin commands
 * @op: Operator
 * @argv: Argument Variables
 *
 */
typedef struct command
{
	char *cmd;
	char *op;
	char **argv;
} command_t;

command_t *parse_command(char *cmd);
command_t *split(char *cmd);
void prompt(void);
void run_file(char *file_name);
void replace_vars(command_t cmd);
void execute_file(char *filename);
void free_commands(command_t *cmds, size_t n_cmds);
char **get_paths(void);
char *get_path(char *cmd);
char *replace_s_vars(char *cmd);
char *replace_aliases(char *cmd);
int is_num(char *str);
int throw_error(char *error);
int execute_cmd(command_t cmd_s);
int execute_commands(command_t *cmds);
int operator_check(char *op, int status);
int builtin_check(char *cmd, char **argv);
void set_status(int status);
int get_status(void);
#endif
