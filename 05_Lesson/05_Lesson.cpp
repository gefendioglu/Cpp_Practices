#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void func(const int &ref); // const L-Value reference
void func(int &&ref);      // R-Value reference

int main() {

	int x = 10;
	func(10); // both functions are viable !!
			  // R-Value ref. --> const L-Value ref. is OK !
} 

