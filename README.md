# Scriptix

Scripix is a simple C library providing utility functions for string manipulation, mathematical operations, and custom input handling.

## Features
- Basic allocater
- Basic boolean operations
- Custom input handling

## Usage

### Input Functions
```.c
#include "scriptix/scriptix.c"

char name[50];
input("Enter your name: ", name, sizeof(name));
printf("Hello, %s!\n", name);
```
