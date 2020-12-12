#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm> 
#include <array> 
#include <iterator> 
#include <string> 

// std::array 
// --------------------------------------------
// --------------------------------------------

using namespace std;

//int main() {
//
//	// construction uses aggregate initialization double-braces required 
//	array<int, 5> ar1{ {3, 4, 5, 1, 2} };
//	array<int, 5> ar2 = { 1, 2, 3, 4, 5 };
//	array<string, 2> ar3 = { {string("a"), "b"} };
//
//	cout << "Sizes of arrays are" << endl;
//	cout << ar1.size() << endl; // 5
//	cout << ar2.size() << endl; // 5
//	cout << ar3.size() << endl; // 2
//
//	cout << "\nInitial ar1 : ";
//	for (auto i : ar1)
//		cout << i << ' '; // Initial ar1 : 3 4 5 1 2
//
//	// container operations (ex. sorting) are supported 
//	sort(ar1.begin(), ar1.end());
//
//	cout << "\nsorted ar1 : ";
//	for (auto i : ar1)
//		cout << i << ' '; // sorted ar1 : 1 2 3 4 5
//
//	// Filling ar2 with 10 
//	ar2.fill(10);
//
//	cout << "\nFilled ar2 : ";
//	for (auto i : ar2)
//		cout << i << ' '; // Filled ar2 : 10 10 10 10 10
//
//	// ranged for loop is supported 
//	cout << "\nar3 : ";
//	for (auto& s : ar3)
//		cout << s << ' '; // ar3 : a b
//
//	return 0;
//}
