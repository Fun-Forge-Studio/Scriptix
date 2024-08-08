/**
 * @author DevByEagle
 * @copyright Copyright 2024 Fun Forge Studio
 * @version 0.1.0
 * @file scriptix.h
 */

#pragma once

// Includes

// Defines
#define True 1
#define False -1

typedef enum SRESULT {
	SUCCESS = 0,
	INVALID_INPUT,
	FILE_NOT_FOUND,
	CONNECTION_FAILED,
	NOT_IMPLEMENTED,
} SRESULT;

#ifdef __cplusplus
namespace Scriptix {
	typedef signed int Number;

	void GetError(SRESULT RESULT);
}
#else
typedef signed int Number;

void GetError(SRESULT RESULT);
#endif