#include <iostream>

int main() {

	// Const Auto --> const is a type specifier
	// ----------------------------------------------
	int firstNumber = 10;
	const auto x = firstNumber; // y --> const int 
	auto const y = firstNumber; // z --> const int

	// Const Auto Ref : 
	// ----------------------------------------------
	auto& refAuto = firstNumber;        // refAuto -->  int &
	const auto &refConstAuto = refAuto; // refConstAuto --> const int& --> very common usage
	
	// Static Auto -->  static is not a type specifier
	// ----------------------------------------------
	static int staticNumber = 10;
	auto staticNum = staticNumber; // staticNum --> int 
	
}

	







