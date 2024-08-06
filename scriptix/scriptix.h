/**
 * @author DevByEagle
 * @copyright Copyright 2024 Fun Forge Studio
 * @version 0.1.0
 * @file scriptix.h
 */

// Includes
#include "xalloc.c"

// Defines
#define Bool _Bool
#define True 1
#define False -1

// Types & Enums
typedef signed int Number;
typedef const char* String;

typedef enum SRESULT {
	SUCCESS = 0,
	INVALID_INPUT,
	FILE_NOT_FOUND,
	CONNECTION_FAILED,
	NOT_IMPLEMENTED,
} SRESULT;

// Functions
/** @brief Writes a message to the terminal. */
void TypeLine(String msg);
void input(char* prompt, char* buffer, int bufferSize);
void GetError(SRESULT RESULT);