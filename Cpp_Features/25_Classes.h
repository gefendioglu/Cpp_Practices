#pragma once

#ifdef CLASSES

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// myclass.h
class MyClass {
public:
	void func();
	void foo()const; 
	void g()const;
private:
	int mx, my;
};

void MyClass::func() {
	foo(); // OK, not syntax error
	       // T* --> const T* is allowed !!!
}

void MyClass::foo() const {
	func(); // NOT OK, syntax error
	        // const T* --> T* is NOT allowed !!!
	g();  // OK, not syntax error, both are const func. 
}

int main() {
	MyClass myclass;
	const MyClass cmyclass;


}


#endif // CLASSES
