#pragma once

#include <unistd.h>
#include <string>

using namespace std;

#define Bool bool

typedef enum SRESULT {
    None,
    Ok,
    InputError,
} SRESULT;

namespace scriptix {
    static void delay(int seconds);
    string input(const char* prompt);
}