#include <stdio.h>
#include "scriptix.h"

void TypeLine(String msg) {
    printf("%s\n", msg);
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
