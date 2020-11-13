## DEFAULT ARGUMENT :
- Defining default arguments for function parameters is a type of protection for function calls against errors. 
- There is no cost for run-time. It is completely a mechanism for compile time. 
  - int func(int x, int y);
  - int foo(int = func(12, 64));
  - Function calling for : foo();   --> foo(func(12, 64));
  - Function calling for : foo(45); --> foo(func(45, 64));

/----------------------------------------------
/----------------------------------------------

- **Example** : variadic function --> function with ellipses token
```cpp
#include <iostream>

void func(int x, int y, int z);
void variadicFunc(int, ...);     // variadic function
int Printf(const char* p, ...);  // variadic function

int main() {
	func(10, 20, 30);  // OK
	func(10, 20);      // NOT OK
	func(10);          // NOT OK
	func();		   // NOT OK
	func(1, 2, 3, 4);  // NOT OK

	variadicFunc(10, 20, 30);  // OK
	variadicFunc(10, 20);      // OK
	variadicFunc(10);	   // OK
	variadicFunc();		   // NOT OK --> first parameter shall be filled !!!
	variadicFunc(1, 2, 3, 4);  // OK

	Printf("gamze", 20, 30);   // OK
	Printf("gamze", 20);       // OK
	Printf("gamze");	   // OK
	Printf();		   // NOT OK --> first parameter shall be filled !!!
	Printf("gamze", 2, 3, 4);  // OK
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - It is common that default arguments are applied in the function definition.  
  - Default arguments can also be applied in function declarations for some special cases. 
  - Applying default argument both in function definitions and function declaration is an error. 
```cpp
#include <iostream>

void func(int , int , int z = 10);
void foo1(int x = 30, int y = 20 , int z = 10);

void foo2(int x, int y = 20 , int);	    // Syntax Error
void foo3(int x, int y = 20 , int z = 10);  // Not Syntax Error

int main() {
	func(10, 20, 30);  // OK --> z = 30
	func(10, 20);      // OK --> z = 10
	func(10);	   // NOT OK --> second argument shall be sent !
	func();		   // NOT OK --> first and second arguments shall be sent !
	func(1, 2, 3, 4);  // NOT OK --> No fourth parameters in function declaration

	foo1();       // OK --> foo1(30,20,10);
	foo1(1);      // OK --> foo1(1,20,10);
	foo1(1, 2);   // OK --> foo1(1,2,10);
	foo1(1, 2,3); // OK --> foo1(1,2,3);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Default arguments for value parameters (call by value)
```cpp
#include <iostream>

// default argument in function declaration
void func(int x = 1, int y = 2, int z= 3);

// no default argument in function definition
void func(int x, int y, int z) {
	std::cout << "x : " << x << " y : " << y << " z : " << z << "\n";
}

int main() {
	
	func();         // x : 1  y : 2  z : 3
	func(10);       // x : 10 y : 2  z : 3
	func(10,20);    // x : 10 y : 20 z : 3
	func(10,20,30); // x : 10 y : 20 z : 30
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Default arguments for value parameters with global values (call by value)
```cpp
#include <iostream>

int g = 45;
int func(int y = g + 5) { return y;}

int main() {
	std::cout << "func(120) : " << func(120) << "\n";  // func(120) : 120
	std::cout << "func() : " << func() << "\n";        // func() : 50
} 
```

/----------------------------------------------
/----------------------------------------------

```cpp
func(12, , 45); // NOT OK --> all right arguments shall be filled !!!
```

/----------------------------------------------
/----------------------------------------------

- **Example** :
```cpp
#include <iostream>

int func(int x, int y) { return x + y;}
int funcDefArg(int x, int y = 10) { return x + y;}
int foo(int y = func(15, 25)) {	return y;}
int fooDefArg(int y = funcDefArg(15)) {	return y;}

int main() {
	std::cout << "foo(func(27, 37)) : " << foo(func(27, 37)) << "\n"; // foo(func(27, 37)) : 64
	std::cout << "foo(125) : " << foo(125) << "\n"; 		  // foo(125) : 125 
	std::cout << "foo() : " << foo() << "\n";                         // foo() : 40

	std::cout << "fooDefArg(funcDefArg(27)) : " << fooDefArg(funcDefArg(27)) << "\n";  // fooDefArg(funcDefArg(27)) : 37
	std::cout << "fooDefArg(125) : " << fooDefArg(125) << "\n"; 			   // fooDefArg(125) : 125
	std::cout << "fooDefArg() : " << fooDefArg() << "\n"; 				   // fooDefArg() : 25
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The sequence of functions 
```cpp
#include <iostream>

int foo() {
	std::cout << "foo() is called !!! : " << "\n"; 
	return 10;
}

int globalVal = foo();

int main() {
	std::cout << "main() is called !!! : " << "\n";
	// foo() is called !!!  --> first global function
	// main() is called !!! --> then main function
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - If there is no default arguments in function decleration (in header file), it can be added with redecleration 
```cpp
#include <iostream>

void func(int x, int y, int z);
void func(int x, int y, int z=0); // redecleration

int main() {
	func(1, 2, 3); // OK --> func(1,2,3);
	func(1, 2);    // OK --> func(1,2,0);
	func(1);       // NOT OK --> All the left side parameters shall be filled
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function redecleration for default arguments
```cpp
#include <iostream>

void func(int x, int y, int z);
// redecleration, if no default argument for the same function definition
void func(int x, int y, int z = 0);

void foo(int x, int y, int z = 300);
// redecleration, merging two functions by compiler
void foo(int x, int y = 200, int z = 300);


int main() {
	func(1, 2, 3); // OK --> func(1,2,3);
	func(1, 2);    // OK --> func(1,2,0);
	func(1);       // NOT OK --> func does not take 1 arguments
	func();        // NOT OK --> func does not take 0 arguments
	
	foo(1,2,3);    // OK --> foo(1,2,3);
	foo(1,2);      // OK --> foo(1,2,300);
	foo(1);        // OK --> foo(1,200,300);
	foo();         // NOT OK --> func does not take 0 arguments 
}
```
/----------------------------------------------
/----------------------------------------------

- **Example** : Default arguments for reference parameters (call by reference) 
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

- **Example** : Default arguments for reference parameters (call by reference) 
```cpp
#include <iostream>

int g = 23;
// default argument in function declaration
void func(int& ref = g);

// no default argument in function definition
void func(int& ref) {
	std::cout << "ref : " << ref << "\n";
}

int main() {
	
	func(); // ref : 23 (like as func(g);)
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Default arguments for functions with pointer type parameters  
```cpp
#include <iostream>

void func(int* ptr = nullptr);
void func(int* ptr) {
	std::cout << "ptr : " << ptr << "\n";
}

int main() {
	
	int x = 10;
	func(&x);   // ptr : 00AFFA24
	func();     // ptr : 00000000 (like as func(nullptr);)
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Default arguments for functions with pointer type parameters  
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void time_func(time_t* ptr);
void time_func(time_t* ptr = nullptr); // redecleration
void time_func(int* ptr) {
	std::cout << "time_func() is called !!! " << "\n";
}

int main() {
	int value = 10;
	time_func(&value);   // OK 
	time_func();         // OK --> time_func(nullptr); 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Default arguments for const char pointer type parameters
```cpp
#include <iostream>

void func(const char* error = "Exception Handling");
void func(const char* error) {
	std::cout << "error : " << error << "\n";
}

int main() {
	func("Error !!!"); // error : Error !!!
	func();            // error : Exception Handling
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Default arguments for functions with string parameters (const char*) 
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

- **Example** : Default argument definition for the middle parameter with wrapper function
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
	wrapperFunc(10,20,30);  // OK --> func(10,20,30);
	wrapperFunc(10,20);     // OK --> func(10,10,20);
	wrapperFunc(10);        // NOT OK !!! 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Default argument for the last parameter of a function
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <chrono>
#include <ctime>

// Checking if the last parameter is sent or not !!!
void process_date(int day, int month, int year = -1);
void process_date(int day, int month, int year) {
	if (year == -1) {
		auto start = std::chrono::system_clock::now();
		std::time_t end_time = std::chrono::system_clock::to_time_t(start);
		auto date = std::ctime(&end_time);
		std::cout << "date : " << date << "\n";
	}
	else {
		std::cout << "day: " << day << " month : " << month << " year : " << year << "\n";
	}
}

int main() {
	process_date(11,11,2020); // day: 11 month : 11 year : 2020
	process_date(11,11);      // date : Thu Nov 12 22 : 29 : 13 2020
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :
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

