#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "scriptix.hpp"
#include "string.hpp"

using namespace scriptix;

/*Bool begin() {
    bool success = false;
    if(!success) {
        //errorHandler.setError(ErrorCode::InitializationFailed);
        return false;
    } 
    //errorHandler.setError(ErrorCode::None);
    return true;
}*/

/*Bool end() {
    bool success = true;

    if(!success) {
        //errorHandler.setError(ErrorCode::CleanupFailed);
        return false;
    }

    //errorHandler.setError(ErrorCode::None);
    return true;
}*/

void delay(int seconds) {
	sleep(seconds);
}

string input(const char* prompt){
	string input;
	cout << prompt;
	getline(cin, input);
	return input;
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
	printf("%s\n", data);
}
