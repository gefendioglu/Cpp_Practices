#define _CRT_SECURE_NO_WARNINGS
#include <iostream>



int main()
{
	int x = 10;
	int y = 20;

	// forwarding reference (both ref1 and ref2)
	// universal reference (called by Scott Meyers)
	auto&& ref1 = x;      // OK, x --> L-Value 
	auto&& ref2 = x + 10; // OK,  x + 10 --> R-Value
    
	// R-Value ref. (both ref3 and ref4)
	int&& ref3 = x;    // NOT OK, x is L-Value is not assigned to R-Value ref. syntax error 
	int&& ref4 = x+10; // OK,  x + 10 --> R-Value, ref4 is alsý R-Value ref. here 
}