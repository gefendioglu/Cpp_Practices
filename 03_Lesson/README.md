


## ASSIGNMENT 

* Example: Assigning a pointer and reference values 

```cpp
#include <iostream>

int main() {
	int firstNumber = 10;
	int secondNumber = 99;

	int* ptr = &firstNumber;
	int*& refPointer = ptr;

	std::cout << "ptr : " << ptr << "\n";				// ptr : 00AFFAF8
	std::cout << "refPointer : " << refPointer << "\n"; // refPointer : 00AFFAF8

	*refPointer = 300; // *refPointer --> firstNumber
	std::cout << "firstNumber : " << firstNumber << "\n";  // firstNumber : 300
		
	refPointer = &secondNumber;
	*refPointer = 700; // *refPointer --> secondNumber
	std::cout << "secondNumber : " << secondNumber << "\n"; // secondNumber : 700
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Assigning references 

```cpp
#include <iostream>

int main() {
	int firstNumber = 10;
	int secondNumber = 99;

	int& ref1 = firstNumber;
	int& ref2 = ref1;
	++ref2; 
  
	std::cout << "ref1 : " << ref1 << "\n"; // ref1: 11
	std::cout << "ref2 : " << ref2 << "\n"; // ref2 : 11
}
```

/----------------------------------------------
/----------------------------------------------

## DEFAULT ARGUMENT :
- Fonksiyonlarýn Varsayýlan Argüman Almasý
- Programda ayný argüman deðerlerini alan fonksiyon çaðrýlarý için default tanýmlamalarýn yapýlmasý, hataya karþý koruma saðlar.
- Run-time maliyeti bulunmaz. Tamamen compile-time'a yönelik bir mekanizmadýr. 

/----------------------------------------------
/----------------------------------------------

- variadic function --> function with ellipses token

```cpp
#include <iostream>

void func(int x, int y, int z);
void variadicFunc(int, ...);     // variadic function
int Printf(const char* p, ...);  // variadic function

int main() {
	func(10, 20, 30);  // OK
	func(10, 20);      // NOT OK
	func(10);		   // NOT OK
	func();			   // NOT OK
	func(1, 2, 3, 4);  // NOT OK

	variadicFunc(10, 20, 30);  // OK
	variadicFunc(10, 20);      // OK
	variadicFunc(10);		   // OK
	variadicFunc();			   // NOT OK --> first parameter shall be filled !!!
	variadicFunc(1, 2, 3, 4);  // OK

	Printf("gamze", 20, 30);   // OK
	Printf("gamze", 20);       // OK
	Printf("gamze");		   // OK
	Printf();			       // NOT OK --> first parameter shall be filled !!!
	Printf("gamze", 2, 3, 4);  // OK
}
```

/----------------------------------------------
/----------------------------------------------

- Default argümanlarýn fonksiyon bildiriminde (function definition) yapýlmasý yaygýndýr. Ancak özel durumlarda fonksiyon tanýmlarýnda (function declaration) da uygulanmaktadýr. Ancak he  bildirimde hem de tanýmda yapýlmasý hatadýr.

```cpp
#include <iostream>

void func(int , int , int z = 10);
void foo1(int x = 30, int y = 20 , int z = 10);

void foo2(int x, int y = 20 , int);		    // Syntax Error
void foo3(int x, int y = 20 , int z = 10);  // Not Syntax Error

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
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int g = 45;
int func(int y = g + 5) {
	return y;
}

int main() {
	std::cout << "func(120) : " << func(120) << "\n";  // func(120) : 120
	std::cout << "func() : " << func() << "\n";        // func() : 50
} 
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int func(int x, int y) {
	return x + y;
}

int funcDefArg(int x, int y = 10) {
	return x + y;
}

int foo(int y = func(15, 25)) {
	return y;
}

int fooDefArg(int y = funcDefArg(15)) {
	return y;
}

int main() {
	std::cout << "foo(func(27, 37)) : " << foo(func(27, 37)) << "\n"; // : 64
	std::cout << "foo(125) : " << foo(125) << "\n"; // foo(125) : 125 
	std::cout << "foo() : " << foo() << "\n";       // foo() : 40

	std::cout << "fooDefArg(funcDefArg(27)) : " << fooDefArg(funcDefArg(27)) << "\n"; 
	// fooDefArg(funcDefArg(27)) : 37
	std::cout << "fooDefArg(125) : " << fooDefArg(125) << "\n"; // fooDefArg(125) : 125
	std::cout << "fooDefArg() : " << fooDefArg() << "\n"; // fooDefArg() : 25
}
```

/----------------------------------------------
/----------------------------------------------

* Ara not: Fonksiyonlarýn hayata gelme sýrasý 

```cpp
#include <iostream>

int foo() {
	std::cout << "foo() is called !!! : " << "\n"; 
	return 10;
}

int globalVal = foo();

int main() {
	std::cout << "main() is called !!! : " << "\n";
	// Result: 
	// foo() is called !!!  --> first global function
	// main() is called !!! --> then main function
}
```

/----------------------------------------------
/----------------------------------------------
```cpp
func(12, , 45); // NOT OK --> all right arguments shall be filled !!!
```
/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

void foo(int x = 1, int y = 2, int z = 3);

int main() {
	
	foo();           // 1, 2, 3
	foo(10);		 // 10, 2, 3
	foo(10, 20);     // 10, 20, 3
	foo(10, 20, 30); // 10, 20, 30
}

void foo(int x, int y, int z) {
	std::cout << x << " , " << y << " , " << z <<  "\n";
}
```

/----------------------------------------------
/----------------------------------------------

- Default arguments for references 

```cpp
#include <iostream>

int globalVal = 25;

int func(int& ref = globalVal) {
	return ref + 5;
}

int main() {
	int value = 5;
	std::cout << "func(5)  : " << func(value) << "\n"; // func(5) : 10
	std::cout << "func()   : " << func() << "\n";      // func()-> func(globalValue): 30
}
```

/----------------------------------------------
/----------------------------------------------

- Default arguments for functions with pointer parameters  

```cpp
#include <iostream>

int globalVal = 25;

void func(int* ptr = nullptr) {
	std::cout << "func() is called !!! " << "\n";
}

int main() {
	int value = 10;
	func(&value);   // OK 
	func();			// OK --> func(nullptr);
}
```

/----------------------------------------------
/----------------------------------------------

- Default arguments for functions with string parameters (const char*) 

```cpp
#include <iostream>

void funcErr(std::string ptr = "Not enough memory !!") {
	std::cout << ptr << "\n";
}

int main() {
	funcErr("gamze");   // OK --> funcErr("gamze"); 
	funcErr();	    // OK --> func("Not enough memory !!");
}
```

/----------------------------------------------
/----------------------------------------------
```cpp
int* ptr;
void func(int& ref = *ptr);
```
/----------------------------------------------
/----------------------------------------------

- Default arguments for functions defined in a header file

```cpp
#include <iostream>

//func.h
void func(int x, int y, int z);
void func(int x, int y, int z = 0); // redecleration 

int main() {
	func(1, 2, 3); // OK --> func(1,2,3);
	func(1, 2);    // OK --> func(1,2,0);
	func(1);       // NOT OK --> All the left side parameters shall be filled
}
```

/----------------------------------------------
/----------------------------------------------

- Calling default arguments with wrapper functions

```cpp
#include <iostream>

void func(int x, int y, int z) {
	std::cout << "func(int x, int y, int z) is called !!! " << "\n";

}

void wrapperFunc(int x, int z, int y = 10) {
	func(x, y, z);
	std::cout << "wrapperFunc(int x, int z, int y = 10) is called !!! " << "\n";
}

int main() {
	wrapperFunc(10,20,30);  // OK     --> func(10,20,30);
	wrapperFunc(10,20);     // OK     --> func(10,10,20);
	wrapperFunc(10);        // NOT OK !!! 
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

void processDate(int day, int month, int year = -1);
void processDate(int day, int month, int year) {
	if (year == -1) {

	}
}

void time(time_t *ptr = nullptr){}
void func(int *ptr = nullptr){}

int main() {
	time();
	func();
}
```

/----------------------------------------------
/----------------------------------------------
