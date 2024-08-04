#include <stdio.h>
#include "../include/os.h"

Bool typeline(String message) {
    if(message != NULL) {
        printf("%ps\n", message);
        return True;
    } else {
        return False;
    }
}
