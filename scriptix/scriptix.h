#define True 1
#define False 0

typedef enum SResult {
    SUCCESS = 0,
    CONNECTION_FAILED,
    NOT_IMPLEMENTED
} SResult;

// Public Functions
void geterr(SResult RESULT);

#ifdef __cplusplus
// C++ Functions
#define Bool bool
namespace Scriptix {
    typedef signed int number;
    typedef const char* string;

    /** @brief Writes a message to the terminal. */
    void TypeLine(string msg);
}
#else
// C Functions
#define Bool _Bool

typedef signed int number;
typedef const char* string;

/** @brief Writes a message to the terminal. */
void TypeLine(string msg);
#endif