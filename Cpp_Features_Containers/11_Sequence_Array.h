#pragma once

// std::array 
// --------------------------------------------
// --------------------------------------------

#ifdef SEQUENCE_ARRAY

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm> 
#include <array> 
#include <iterator> 
#include <string> 

using namespace std;

int main() {

	array<int, 5> ar1{ {3, 4, 5, 1, 2} };
	array<int, 5> ar2 = { 1, 2, 3, 4, 5 };
	array<string, 2> ar3 = { {string("a"), "b"} };

	std::cout << "Sizes of arrays are" << std::endl;
	std::cout << ar1.size() << std::endl; // 5
	std::cout << ar2.size() << std::endl; // 5
	std::cout << ar3.size() << std::endl; // 2

	std::cout << "\nInitial ar1 : ";
	for (auto i : ar1)
		std::cout << i << ' '; // Initial ar1 : 3 4 5 1 2

	// container operations (ex. sorting) are supported 
	sort(ar1.begin(), ar1.end());

	std::cout << "\nsorted ar1 : ";
	for (auto i : ar1)
		std::cout << i << ' '; // sorted ar1 : 1 2 3 4 5

	// Filling ar2 with 10 
	ar2.fill(10);

	std::cout << "\nFilled ar2 : ";
	for (auto i : ar2)
		std::cout << i << ' '; // Filled ar2 : 10 10 10 10 10

	// ranged for loop is supported 
	std::cout << "\nar3 : ";
	for (auto& s : ar3)
		std::cout << s << ' '; // ar3 : a b

	return 0;
}

#endif // SEQUENCE_ARRAY