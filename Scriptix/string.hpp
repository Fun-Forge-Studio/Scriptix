#include <string.h>

class String {
private:
	char* data;
	int length;

public:
	String(const char* input = "");
	String(const String &other);
	String(String &&other) noexcept;
	~String();

    int GetLength() const;
    void TypeLine() const;
};