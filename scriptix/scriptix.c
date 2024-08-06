#include <stdio.h>
#include <string.h>
#include "scriptix.h"

void TypeLine(String msg) {
    printf("%s\n", msg);
}

void input(char *prompt, char *buffer, int bufferSize) {
    printf("%s", prompt);
    if(fgets(buffer, bufferSize, stdin) != NULL) {
        // Remove newline character if persent
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
    } else {
        // Handle input error
        fprintf(stderr, "Error: Invalid input provided. %s\n", __FILE__);
    }
}

void GetError(SRESULT RESULT) {
    switch (RESULT) {
        case INVALID_INPUT:
            fprintf(stderr, "Error: Invalid input provided. %i (code: %d)\n", __LINE__, RESULT);
            break;
        case FILE_NOT_FOUND:
            fprintf(stderr, "Error: File not found (code: %d)\n", RESULT);
            break;
        case CONNECTION_FAILED:
            fprintf(stderr, "Error: Connection failed. (code: %d)\n", RESULT);
            break;
        case NOT_IMPLEMENTED:
            fprintf(stderr, "Error: Not implemented. (code: %d) at %s:%d\n", RESULT, __FILE__, __LINE__);
            break;
        default:
            break;
    }
    exit(RESULT);
}
