#include <stdio.h>
#include "scriptix.h"

void geterr(SResult RESULT) {
    switch(RESULT) {
        case CONNECTION_FAILED:
            fprintf(stderr, "[ERROR] %i Connection failed\n", 400);
            break;
        case NOT_IMPLEMENTED:
            fprintf(stderr, "[ERROR] Not implemented yet at %s:%d\n", __FILE__, __LINE__);
            break;
        default:
            break;
    }
}

void TypeLine(string msg) {
    printf("%s\n", msg);
}