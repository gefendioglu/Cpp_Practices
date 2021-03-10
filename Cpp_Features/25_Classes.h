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
	std::cout << "main() function is called...\n";
	std::cout << "&globalData : " << &globalData1 << "\n";
	std::cout << "main() function is ended...\n";

	/*
		Data ctor is called..this : 00AEE138
		main() function is called
		&globalData : 00AEE138
		main() function is ended
		Data destructor is called..this : 00AEE138
	*/


}

#endif // CLASSES


// Static Class Data Members & Class Member Functions
// --------------------------------------------
// --------------------------------------------

#ifdef STATIC_MEMBERS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//complex.h
class Complex {
public:
	static Complex createCartesian(double r, double i) 
	{
		return Complex(r, i, 0);
	}
	static Complex createPolar(double distance, double angle)
	{
		return Complex(distance, angle);
	}
private:
	int mx;
	// adding int parameter to provide func. overloading
	Complex(double r, double i, int);
	Complex(double distance, double angle);
};

//complex.cpp

int main() {

	return EXIT_SUCCESS;
}

#endif // STATIC_MEMBERS