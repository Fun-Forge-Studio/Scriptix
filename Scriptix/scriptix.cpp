#include <stdio.h>
#include "scriptix.h"
#include "string.hpp"

void delay(int seconds) {
	sleep(seconds);
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

void String::TypeLine() const {
	printf("%s\n", data);
}