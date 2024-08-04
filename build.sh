set -xm -Wall -Wextra
rm -rf bin
mkdir bin

gcc os.c -o bin/Scriptix.exe -std=c99 -Werror -Wno-unused-parameter -Wno-unused-varables -lm