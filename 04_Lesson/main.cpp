#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


int main() {

	int value = 10;
	decltype(value);
	std::cout << "the type of value: " << typeid(decltype(value)).name();

}








