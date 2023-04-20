#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
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
#endif
