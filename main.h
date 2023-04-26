#ifndef MAIN_H
#define MAIN_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* Constants */
#define ARG_MAX 1024

/* Global variable */
extern char **environ;

/* Function prototypes */
int main(void);
int execute(char **args);
char **split_line(char *line);
int _puts(const char *str);

#endif

