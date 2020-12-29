#pragma once

#ifdef CLASSES

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// data.h
class Data {
public:
	Data() {
		std::cout << "Data ctor is called..this : " << this << "\n";
	}
	~Data() {
		std::cout << "Data destructor is called..this : " << this << "\n";
	}
private:
	int mx, my;
};

// global class objects
Data globalData1;
Data globalData2;
Data globalData3;

int main() {
	std::cout << "main() function is called\n";
	std::cout << "&globalData : " << &globalData1 << "\n";
	std::cout << "main() function is ended\n";

	/*
		Data ctor is called..this : 00AEE138
		main() function is called
		&globalData : 00AEE138
		main() function is ended
		Data destructor is called..this : 00AEE138
	*/

	
}

#endif // CLASSES
