#include "../Scriptix/scriptix.h"
#include "../Scriptix/scriptix.cpp"

int main() {
	string name = input("Enter your name: ");
	string age = input("Enter your age: ");
    cout << "Hello," << name << "! You age " << age << " years old." << endl;
	return 0;
}