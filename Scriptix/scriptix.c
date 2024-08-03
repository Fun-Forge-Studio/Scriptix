#include <stdio.h>
#include "scriptix.h"

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
	if (openFile == NULL) {
		openFile->result = FileNotFound;
		return openFile;
	}
}