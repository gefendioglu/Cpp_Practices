#pragma once

#ifdef CLASSES

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// myclass.h
class MyClass {
public:
	void func();       // --> void func(MyClass* const this);
	void foo() const; // --> (const MyClass* const this);
private:
	int mx, my;
};

MyClass global;

// myclass.cpp
void MyClass::func() {
	this = &global; // NOT OK, this pointer is R-Value expression
	                // this is a const itself
}

int sum_square(int x, int y) {
	return x * x + y * y;
}

int main() {
	
	int number1 = 10, number2 = 20;
	int result = sum_square(number1, number2);
	// int result = number1 * number1 + number2 * number2; 
}

#endif // CLASSES
