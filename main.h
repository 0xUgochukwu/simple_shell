#ifndef MAIN_H
#define MAIN_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct {
  char *cmd;
  char *seprator;
  char **argv;
  char **environ;
} command_t;

void execute_file(char *filename);
void start_shell(void);
#endif
