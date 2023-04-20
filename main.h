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

#define BUFFSIZE 1024

typedef struct {
    char *cmd;
    char *seprator;
    char **argv;
    char **environ;
} command_t;

void execute_file(char *filename);
void prompt (void);
void throw_error(char *err);
char *replace_aliases(char *cmd);
char *replace_vars(char *cmd);
command_t *split(char *cmd);
int execute_commands(command_t * cmds);
#endif
