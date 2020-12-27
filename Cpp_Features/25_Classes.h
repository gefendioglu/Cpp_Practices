#pragma once

#ifdef CLASSES

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class MyClass {
public:
	void func(int x, int y); 
private:
	void foo();
	int mx, my, mz; // sizeof(int) : 4 bytes
};


// myclass.cpp
#define PUBLIC
#define PRIVATE

PUBLIC void MyClass::func(int x, int y){
	//...
}


PRIVATE void MyClass::foo() {
	//...
}


int main() {


}


#endif // CLASSES
