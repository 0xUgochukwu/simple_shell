#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    char *path = getenv("PATH");
    char *token = strtok(path, ":");

    while (token != NULL) {
        char filename[100];
        sprintf(filename, "%s/%s", token, argv[1]);

        struct stat st;
        if (stat(filename, &st) == 0 && st.st_mode & S_IXUSR) {
            printf("%s\n", filename);
            return 0;
        }

        token = strtok(NULL, ":");
    }

    printf("%s: command not found\n", argv[1]);
    return 1;
}

