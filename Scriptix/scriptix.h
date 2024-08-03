#pragma once

#include <unistd.h>
#include <string>
#include <unordered_map>

using namespace std;

#define Bool bool
#define True 1
#define False -1

/*typedef enum SRESULT {
	NONE = 0,
	ERROR,
	SUCCESS,
} SRESULT;*/

enum class ErrorCode {
    None,
    InitializationFailed,
    CleanupFailed,
    // other error codes
};

void delay(int seconds);
string input(const char* prompt);

class ErrorHandler {
private:
	ErrorCode currentError = ErrorCode::None;

	static const unordered_map<ErrorCode, std::string> errorMessages;
public:
	void setError(ErrorCode code);

	ErrorCode GetError() const;
};

extern ErrorHandler errorHandler;

Bool begin();

Bool end();