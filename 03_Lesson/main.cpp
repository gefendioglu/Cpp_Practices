#include <iostream>

void func(int , int , int z=10);
void foo1(int x = 30, int y =20 , int z=10);

void foo2(int x, int y =20 , int);		   // Syntax Error
void foo3(int x, int y =20 , int z = 10);  // Not Syntax Error


int main() {

	func(10, 20, 30);  // OK --> z = 30
	func(10, 20);      // OK --> z = 10
	func(10);		   // NOT OK --> second argument shall be sent !
	func();			   // NOT OK --> first and second arguments shall be sent !
	func(1, 2, 3, 4);  // NOT OK --> No fourth parameters in function declaration

	foo1();       // OK --> foo1(30,20,10);
	foo1(1);      // OK --> foo1(1,20,10);
	foo1(1, 2);   // OK --> foo1(1,2,10);
	foo1(1, 2,3); // OK --> foo1(1,2,3);
	
}

	







