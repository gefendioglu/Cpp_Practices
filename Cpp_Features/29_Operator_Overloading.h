#pragma once


#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Complex {
public:
	Complex(int r = 0, int i = 0) { real = r; imag = i; }

	// This function is called when '+' is used with 
	// between two Complex objects 
	Complex& operator + (Complex const& obj) {
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	void print() {
		std::cout << real << " + i" << imag << "\n";
	}
private:
	int real, imag;
};

//int main()
//{
//	Complex c1(10, 5), c2(2, 4);
//	Complex c3 = c1 + c2; // An example call to "operator+" 
//	c3.print();
//}





