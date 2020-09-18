# Undefined Behaviour :
	- Always avoid undefined behaviour (ub)
	1 - Dereferencing null pointers
	2 - Changing string literals (read only)
	3 - Changing variables which assigned as const
	4 - Overflowing for signed variables
	5 - No returning value for a function
	6 - Using uninitialized auto variables 

# Undefined Specifier :
	- do not rely on unspecified behaviour
	- It depends on compiler type
	- It depends on the implementation (compiler here), implementation is not required to document which behaviour occurs; range of possible behaviours usually specified in standard
  
* Implementation Defined Behaviour: 
	- try not to rely on implemetation defined behaviour
	- this behaviour should be documented

* Unspecified Behaviour
/----------------------------------------------

#include <iostream>

int main() {

	int x = 10, y = 20;
	bool flag = &x > & y; // flag = true OR flag = false

	std::cout << "flag : " << flag << "\n";
}

/----------------------------------------------
/----------------------------------------------

#include <iostream>

int func1();
int func2();

int main() {

	int x = func1()*5 + func2();
	// which function is called first ? Not clear!
}

/----------------------------------------------
/----------------------------------------------

#include <iostream>

int g = 10;

int func1(int x, int y) { return x + y;}
int func2() {
	g += 5;
	return 100;
}
int func3() { return g + 3; }

int main() {

	int number = func1(func2(), func3());
	// which function is called first ? Not clear!
	// x value can be changed compiler to compiler

	std::cout << "number : " << number << "\n";
}

/----------------------------------------------
/----------------------------------------------

#include <iostream>
#include <cstdint>

int main() {

	int firstNumber;
	int32_t secondNumber; // guaranteed that secondNumber -->  32 bits 
}

/----------------------------------------------
/----------------------------------------------
