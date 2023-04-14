#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while (1) {
        printf("$ ");
        fflush(stdout);  // Make sure the "$ " is printed before waiting for input

        read = getline(&line, &len, stdin);

        if (read == -1) {  // End-of-file (Ctrl+D)
            break;
        }

        printf("%s", line);
    }

    free(line);
    return 0;
}

