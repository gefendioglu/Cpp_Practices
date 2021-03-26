
## AUTO TYPE DEDUCTION  

- The tools in Cpp using the specifications of type deduction: 
	- auto specifier 
	- decltype specifier (TBD)
	- templates (TBD)

- "auto" Specifier : 
	- The meaning of auto specifier is different in C and C++
	- AAA : Almost Always Auto
	- The advantage of using auto specifier is to force all variables to be initialized
	- The common usage of auto specifier:  
		- generic programming
		- while assigning a function result/address to a variable/pointer

- "auto" type deduction with reference semantics: 
  - The rules are different for the following statements using with auto specifier:
    - auto x = expr;
	  - auto &ref = expr; 
	  - auto &&refref = expr; 
	
/----------------------------------------------
/----------------------------------------------

- **Example**: "auto" specifier

```cpp
#include <iostream>
#include <cstring>

int main() {

	int number = 10;
	auto inum = number; // inum --> int
	auto dnum = number + 2.4; // dnum --> double 
	// auto x; --> auto variable must be initialized !!!

  // the data type of strcmp --> int *(fp)(const char *, const char *)
	auto functionpointer = strcmp; // function to pointer conversion

	int foo();
	auto x = foo();    // --> instead of int x = foo();

	int func(int);
	auto y = func(10); // the data type of y --> int 

	int funct(int, int);
	auto fptr = &funct; // the data type of fptr --> int(*fptr)(int, int)
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Rules for "auto x = expr;" 

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
    // firstArray --> int*, auto firstArray = &a[0];
    auto firstArray = a; 

    int const array[10] = { 0 };
    // secondArray --> int*, auto secondArray = &array[0];
    auto secondArray = array; 

    // String Literals :
    // ----------------------------------------------
    auto name = "gamze"; // name --> const char* (array to pointer conversion)

    // Function pointer :
    // ----------------------------------------------
    int func(int);
    // function --> int(*)(int), function to pointer conversion, auto function = &func(10);
    auto function = func; 
    
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Rules for "auto &ref = expr;" 

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

	// Function pointer / Function Reference:
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

- **Example**: "auto" with const keyword

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
	const auto &refConstAuto = refAuto; // refConstAuto --> const int& refConstAuto --> 
					    // very common usage
	
	// Static Auto -->  static is not a type specifier
	// ----------------------------------------------
	static int staticNumber = 10;
	auto staticNum = staticNumber; // staticNum --> int staticNum
	
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: A sample for the usage of auto keyword with a const value 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(){

	int x = 10;
	const int& cr = x;
	auto& r = cr; // r is a const int here 
	++r;          // NOT OK --> not modifiable 
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: A sample for the usage of auto type specifier with a const value 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(){

	const int x = 20;
	auto y = x; // --> y is not const value, y = int type value 
	++y;

	std::cout << "y : " << y << "\n"; // y : 21
	std::cout << "x : " << x << "\n"; // x : 20

}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: A sample for the usage of auto keyword with arrays

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {

	int a[] = { 0, 1, 2, 3, 4, 5 };
	auto r1 = a;  // int *r1 = a 
	auto& r2 = a; // int (&r2)[6] = a --> r2 ref for a 

	++r2[3];      // r2 is int& and r2[3]=a[3]= 3 --> ++r2[3] = a[3]= 4

	std::cout << "r1[3] : " << r1[3] << "\n";                       // r1[3] : 4
	std::cout << "r2[3] : " << r2[3] << "\n";                       // r2[3] : 4
	std::cout << "(r1[3] == r2[3]) : " << (r1[3] == r2[3]) << "\n"; // (r1[3] == r2[3]) : 1
}
```

/----------------------------------------------
/----------------------------------------------
