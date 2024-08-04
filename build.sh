set -xm
rm -rf bin
mkdir bin

gcc main.c -o bin/Scriptix.exe -std=c99 -Wall -Wextra -Werror -Wno-unused-parameter -Wno-unused-varables -lm