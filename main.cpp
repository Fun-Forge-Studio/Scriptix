#include <stdio.h>
#include "Scriptix/scriptix.h"
#include "Scriptix/scriptix.cpp"

int main() {
    String message("Hello ");
    message.AppendString("World");
    message.TypeLine();
    return 0;
}