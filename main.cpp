#include "Scriptix/scriptix.h"
#include "Scriptix/scriptix.cpp"

int main() {
    /*String message("Hello ");
    message.AppendString("World");
    message.TypeLine();*/
    OpenFile* RESULT = Open("Hello.txt", "r");
    GetLog(RESULT->result);
    return 0;
}