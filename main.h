#ifndef MAIN_H
#define MAIN_H

typedef struct {
    char *cmd;
    char *seprator;
    char **argv;
    char **environ;
} command_t;

#endif
