## AUTO TYPE DEDUCTION

* The tools in Cpp using the specifications of type deduction: 
	- auto specifier 
	- decltype specifier
	- templates 

- "auto" specifier : 
	- the meaning of auto specifier is different in C and C++
	- AAA : Almost Always Auto
	- The advantages of using auto specifier:
		- to force all variables to be initialized
		- the common usage of auto:  
			generic programming
			while assigning a function result/address to a variable/pointer

 - "auto" type deduction with reference semantics: 
	-  The rules are different for each shown in the following: 
	   auto x = expr;
	   auto &ref = expr; 
	   auto &&refref = expr; 

/----------------------------------------------
/----------------------------------------------

- **Example** : 
```cpp
#include <iostream>
#include <cstring>

int main() {
	int number = 10;
	auto inum = number; // inum --> int
	auto dnum = number + 2.4; // dnum --> double 
	// auto x; --> auto variable must be initialized !!!

    // the data type of strcmp --> int *(fp)(const char *, const char *)
	auto functionPointer = strcmp;

	int foo();
	auto x = foo(); // --> instead of int x = foo();
	// If the return type of foo(), then it is necessary to change the assigned variable

	int func(int);
	auto y = func(10); // the data type of y --> int 

	int funct(int, int);
	auto fptr = &funct; // the data type of fptr --> int(*fptr)(int, int)
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Rules for "auto x = expr;" 
```cpp
#include <iostream>

int main() {
	auto x = 10; // x --> int

	const int firstNumber = 10;
	auto y = firstNumber; // y --> int / not const int 

	// Reference / Const Reference :
	// ----------------------------------------------
	int secondNumber = 20;
	int& firstRef = secondNumber;
	auto z = firstRef; // z --> int

	const int& secondRef = secondNumber;
	auto k = secondRef; // k --> int / not const int&

	// Arrays / Const Arrays : 
	// ----------------------------------------------
	int a[10] = {};
	auto firstArray = a; // firstArray --> int*, like as --> auto firstArray = &a[0]

	int const array[10] = {0};
	auto secondArray = a; // secondArray --> int*

	// String Literals :
	// ----------------------------------------------
	auto name = "gamze"; // name --> const char* (array to pointer conversion)

	// Function Pointers :
	// ----------------------------------------------
	int func(int);
	auto function = func; // function --> int(*)(int)
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Rules for "auto &ref = expr;" 
```cpp
#include <iostream>

int main() {
	// Reference / Const Reference :
	// ----------------------------------------------
	int firstNumber = 10;

	auto &x = firstNumber; // OK 
	auto &x = 10;          // NOT OK 

	int*** ptr;
	auto& ref = ptr; // ref --> int***& 
		
	const int constNumber = 10;
	auto& refConst = constNumber; // refConst --> const int &
	refConst = 20; // NOT OK --> refConst is a L-Value

	// Arrays / Const Arrays : 
	// ----------------------------------------------
	int array[5] = { 0 };
	auto& refArray = array; // refArray --> int(&refArray)[5] 

	const int constArray[5] = { 0 };
	auto& refConstArray = constArray; // refConstArray --> const int (&refConstArray)[5]

	// String Literals :
	// ----------------------------------------------
	auto& stringLiteral = "gamze"; // stringLiteral --> const char (&stringLiteral)[6]


	// Function Pointers / Function Reference:
	// ----------------------------------------------
	int(*fptr)(int, int);
	auto& refFunction = fptr; // refFunction --> int(*&)(int,int)
	
	int foo(int, int);
	int (*ptrFunction)(int, int) = &foo; // pointer function
	int (&refFunction)(int, int) = foo;  // reference function
	auto& refFunctionAuto = foo;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Rules for "auto &&ref = expr;"  --> LATER !!!!
  - Script to be added here !!!

/----------------------------------------------
/----------------------------------------------

- **Example** : "auto" with "const" keyword 
```cpp
#include <iostream>

int main() {

	// Const Auto --> const is a type specifier
	// ----------------------------------------------
	int firstNumber = 10;
	const auto x = firstNumber; // y --> const int y
	auto const y = firstNumber; // z --> const int z
	auto ptr = &firstNumber;    // ptr --> int* ptr 
	auto* p = &firstNumber;     // p --> int* p
  
	// ----------------------------------------------
	int* intPtr;
	auto p = &intPtr;  // p --> int** p
  
	// ----------------------------------------------
	int* const constPtr = &firstNumber;
	auto p = &constPtr; // p --> int* const* p

	// Const Auto Ref : 
	// ----------------------------------------------
	auto& refAuto = firstNumber;        // refAuto -->  int& refAuto
	const auto &refConstAuto = refAuto; // refConstAuto --> const int& refConstAuto --> very common usage
	
	// Static Auto -->  static is not a type specifier
	// ----------------------------------------------
	static int staticNumber = 10;
	auto staticNum = staticNumber; // staticNum --> int staticNum
	
}
```

/----------------------------------------------
/----------------------------------------------

