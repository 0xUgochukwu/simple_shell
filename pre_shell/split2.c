#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int split_string(char *str, char *delimiter, char ***words) {
    char *token;
    int count = 0;

    // Get the first token
    token = strtok(str, delimiter);

    // Loop through the string to extract all tokens
    while (token != NULL) {
        // Add the token to the array of words
        (*words)[count] = token;
        count++;

        // Get the next token
        token = strtok(NULL, delimiter);
    }

    return count;
}

int main() {
    char *str_literal = "This is a test string";
    char *delimiter = " ";
    char *str = malloc(strlen(str_literal) + 1);
    strcpy(str, str_literal);
    char **words = malloc(sizeof(char *) * strlen(str));

    int count = split_string(str, delimiter, &words);

    printf("The string has %d words:\n", count);
    for (int i = 0; i < count; i++) {
        if (words[i] != NULL) {
            printf("%d: %s\n", i+1, words[i]);
        }
    }

    free(words);
    free(str);
    return 0;
}

