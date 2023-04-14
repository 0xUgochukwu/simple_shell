#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **split_string(char *string, const char *delimiter, int *count) {
    char **words = NULL;
    char *token;
    int i = 0;

    /* Count the number of words in the string */
    *count = 0;
    token = strtok(string, delimiter);
    while (token != NULL) {
        (*count)++;
        token = strtok(NULL, delimiter);
    }

    /* Allocate memory for the array of words */
    words = (char **) malloc((*count) * sizeof(char *));
    if (words == NULL) {
        perror("Error: ");
        exit(EXIT_FAILURE);
    }

    /* Split the string into words and store them in the array */
    token = strtok(string, delimiter);
    while (token != NULL) {
        words[i] = (char *) malloc(strlen(token) + 1);
        if (words[i] == NULL) {
            perror("Error: ");
            exit(EXIT_FAILURE);
        }
        strcpy(words[i], token);
        i++;
        token = strtok(NULL, delimiter);
    }

    return words;
}

int main(void) {
    char string[] = "This is a test string";
    const char delimiter[] = " ";
    int count;
    char *string_copy = strdup(string);
    char **words = split_string(string_copy, delimiter, &count);

    printf("The string has %d words:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, words[i]);
    }

    /* Free memory allocated for words */
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
    free(string_copy);

    return 0;
}

