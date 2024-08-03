#pragma once

#include <unistd.h>
#include <string>

#define Bool bool
#define True 1
#define False -1

void delay(int seconds);
std::string input(const char* prompt);