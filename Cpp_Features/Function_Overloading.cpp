#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;
class Geeks {
public:
	// function with 1 int parameter 
	void func(int x) {
		std::cout << "value of x is " << x << "\n";
	}

	// function with same name but 1 double parameter 
	void func(double x) {
		std::cout << "value of x is " << x << "\n";
	}

	// function with same name and 2 int parameters 
	void func(int x, int y) {
		std::cout << "value of x and y is " << x << ", " << y << "\n";
	}
};

//int main() {
//
//	Geeks obj1;
//
//	// Which function is called will depend on the parameters passed 
//	// The first 'func' is called -->  func(int x) 
//	obj1.func(7);
//
//	// The second 'func' is called --> func(double x) 
//	obj1.func(9.132);
//
//	// The third 'func' is called --> func(int x, int y)
//	obj1.func(85, 64);
//	return 0;
//}
