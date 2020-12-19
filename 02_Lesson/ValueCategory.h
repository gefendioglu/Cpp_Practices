#pragma once
#include <iostream>

template <typename T>
struct ValueCategory {
	constexpr static const char* ptrstr{ "PR Value" };
};

template <typename T>
struct ValueCategory<T&> {
	constexpr static const char* ptrstr{ "L Value" };
};

template <typename T>
struct ValueCategory<T&&> {
	constexpr static const char* ptrstr{ "X Value" };
};

/*
#define valuecategory(exp) (std::cout << "Value category of \"" #exp"\" is : " << ValueCategory<decltype((exp))>::ptrstr << "\n");


#include <iostream>
#include "ValueCategory.h"

int main() {

	int array[2] = { 0,1 };
	sizeof(array[3]);

	valuecategory(sizeof(array[3])); // Value category of "sizeof(array[3])" is : PR Value

	std::cout << "sizeof(array[3]) :  " << sizeof(array[3]) << "\n";
	// sizeof(array[3]) :  4
}
*/