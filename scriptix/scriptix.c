#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "scriptix.h"

void TypeLine(String message) {
    printf("%s\n", message);
}

void GetError(SRESULT RESULT) {
    switch(RESULT) {
		case INVALID_INPUT:
			fprintf(stderr, "[ERROR] Invalid input provided. %i\n", __LINE__);
			break;
		case FILE_NOT_FOUND:
			fprintf(stderr, "[ERROR] File not found\n");
			break;
		case CONNECTION_FAILED:
			fprintf(stderr, "[ERROR] Connection failed (code: %d)\n", RESULT);
			break;
		case NOT_IMPLEMENTED:
			fprintf(stderr, "[ERROR] Not implemented yet at %s:%d\n", __FILE__, __LINE__);
			break;
		default:
			break;
	}
    exit(RESULT);
}