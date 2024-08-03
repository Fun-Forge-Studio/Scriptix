#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Types And Macros

#define Bool bool

typedef enum SRESULT {
    Success = 0,
	FileNotFound,
	NetworkError,
	UnknownError
} SRESULT;

typedef struct OpenFile {
	FILE* file;
	char mode[4];
	SRESULT result;
} OpenFile;

// Extern Values And Varables

// Functions And Classes 

static void delay(int seconds);
static void GetLog(SRESULT Result);

OpenFile* Open(const char* filename, const char* mode);