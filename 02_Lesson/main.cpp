#include <iostream>
#include "ValueCategory.h"

int main() {

	int array[2] = { 0,1 };
	sizeof(array[3]);

	valuecategory(sizeof(array[3])); // Value category of "sizeof(array[3])" is : PR Value

	std::cout << "sizeof(array[3]) :  " << sizeof(array[3]) << "\n";
	// sizeof(array[3]) :  4
}



