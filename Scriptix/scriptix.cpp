#include <stdio.h>
#include <stdlib.h>
#include "scriptix.h"
#include "string.hpp"

static void delay(int seconds) {
    sleep(seconds);
}

static void GetLog(SRESULT Result) {
	switch(Result) {
		case Success:
			break;
		case FileNotFound:
			printf("Error: File not found.\n");
			break;
		case NetworkError:
			printf("Network error occurred.\n");
			break;
		default:
			printf("Error: Unknown error.\n");
			break;
	}
}

OpenFile* Open(const char* filename, const char* mode) {
	OpenFile* openFile = (OpenFile*)malloc(sizeof(OpenFile));
	if(openFile == NULL) {
		openFile->result = FileNotFound;
		return openFile;
	}
}

String::String(const char* input) {
	length = strlen(input);
	data = new char[length + 1];
	strcpy(data, input);
}

String::String(const String &other) {
	length = other.length;
	data = new char[length + 1];
	strcpy(data, other.data);
}

String::String(String &&other) noexcept {
	other.data = nullptr;
	other.length = 0;
}

String::~String() {
	delete[] data;
}

int String::GetLength() const {
	return length;
}

void String::AppendString(const char* suffix) {
	int new_length = length + strlen(suffix);
    char* new_data = (char *)realloc(data, (new_length + 1) * sizeof(char));
    if (new_data) {
        strcat(new_data, suffix);
        data = new_data;
        length = new_length;
    }
}

void String::TypeLine() const {
	if(this->data) {
		printf("%s\n", data);
	}
}