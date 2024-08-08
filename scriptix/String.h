#include <string.h>

#ifdef __cplusplus
namespace Scriptix {
	class String {
	public:
		// No arguments Constructor
		String();

		// Constructor with 1 arguments
		String(const char* val);

	 	// Copy Constructor
		String(const String& source);

		// Move Constructor
		String(String&& source);

		~String() { delete str; }

		/** @brief Writes a message to the terminal. */
		void TypeLine() const;
	private:
		char* str;
	};
}
#else
typedef const char* String;

/** @brief Writes a message to the terminal. */
void TypeLine(String message);
#endif