#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

int main() {
    char *line = NULL;
    size_t line_buf_size = 0;

    while (1) {
        // Print prompt
        printf("$ ");

        // Read user input
        ssize_t num_bytes_read = getline(&line, &line_buf_size, stdin);

        // Check for errors
        if (num_bytes_read == -1) {
            perror("getline");
            break;
        }

        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Create child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
            break;
        } else if (pid == 0) {
            // Child process
            char *argv[2];
            argv[0] = line;
            argv[1] = NULL;
            execv(line, argv);

            // If execv returns, it means there was an error
            perror("execv");
            exit(EXIT_FAILURE);
        } else {
            // Parent process
            int status;
            wait(&status);
        }
    }

    free(line);
    return 0;
}

