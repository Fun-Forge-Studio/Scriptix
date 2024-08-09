#define True 1
#define False 0

typedef signed int number;
typedef const char* string;

typedef enum SResult {
    SUCCESS = 0,
    CONNECTION_FAILED,
    NOT_IMPLEMENTED,
} SResult;

void TypeLine(string message);

