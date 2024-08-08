#include <stdio.h>
#include <stdlib.h>
#include "String.h"
#include "scriptix.h"

void Scriptix::GetError(SRESULT RESULT) {
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

Scriptix::String::String() : str{nullptr} 
{
    str = new char[1];
    str[0] = '\0';
}

Scriptix::String::String(const char* val) {
    if(val == nullptr) {
        str = new char[1];
        str[0] = '\0';
    } else {
        str = new char[strlen(val) + 1];

        strcpy(str, val);
        str[strlen(val)] = '\0';
    }
}

Scriptix::String::String(const String& source) {
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    str[strlen(source.str)] = '\0';
}

Scriptix::String::String(String&& source) {
    str = source.str;
    source.str = nullptr;
}

void Scriptix::String::TypeLine() const {
    printf("%s\n", str);
}