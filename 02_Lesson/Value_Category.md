
## VALUE CATEGORY:

 - What is the difference between "expression" and "statement"?
   - expression --> 10, x, x+10, a*a + b*b > 10. etc (operators, objects, constants, etc.)
   - statement  --> all expressions which have ; at the end. 
     - x = 10  --> expression
     - x = 10; --> statement (expression statement)
     
- "const" keyword doesnt effect the value category 

- What is the data type?
  - int, int*, int&, int [], int (*)(int), etc.

/----------------------------------------------
/----------------------------------------------

## R-VALUE REFERENCES & L-VALUE REFERENCES :
- References does not allocate memory, the memory allocation is for objects !!! 
- Adding to C++ standard with C++11 
- The value category types in Cpp:
  - L Value (Left Value):
    - the values that point objects
    - they have a place in the memory 
    
  - X Value (Expiring Value):
    - not defined in C language
    - the values that point objects
    - it is not named in a code (no identity for this type of value category)
	  
   - PR Value (Pure Right Value):
     - the values that not point any objects
     - they dont have any place in the memory 
   
   - L Value + X Value = GL Value 
   - PR Value + X Value = R Value 

- A value belongs to only one of the above value categories !!!

- The differences of value categories between C and CPP ?
  - **++x**, **--x**  --> R-Value (C), L-Value (C++)
  - **a**,**b**       --> R-Value (C), L-Value (C++) (even if right operand is an object)
  - **x++**, **x--**  --> R-Value (C), PR-Value (C++)
  - **x>0 ? y:z**     --> R-Value (C), L-Value (C++) (for operands)

/----------------------------------------------
/----------------------------------------------

## R Value References:
- Adding for move semantics and perfect forwarding reference 

- Forwarding reference, if there is type deduction using with && specifier.
  - auto &&ref = expr; --> this is not R value reference, it is forwarding reference !!! 
  
- R value reference must be initialized with R Value expression 
  - T &&ref = 10; // OK --> R value reference 
    - ref is a L value expression 
    - T &&ref is a R value expression (the data type of ref is a R value expression)
    - void func(T &&ref); --> move semantic
    - T&& func(); --> return value is R value reference 

/----------------------------------------------
/----------------------------------------------

- **Example** :R value references and R value expressions
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int foo();
int &func();

int main() {

	int value = 10;
	int&& ref = value;    // NOT OK --> value is a L value expression
	int&& ref1 = 10;      // OK --> 10 is a R value expression
	int&& ref2 = foo();   // OK --> foo() is a R value expression
	int&& ref = func();   // NOT OK --> func() is a L value expression
	int& r = ref1;        // OK --> ref is a L value expression
	r = 10;		      // OK --> assignment for L-value expression

	value + 5;	      // --> R value expression
	++value;	      // --> L value expression
	--value;	      // --> L value expression
	value > 10;	      // --> R value expression 
	value && 10;	      // --> R value expression
	!value ;	      // --> R value expression
	value & 10;	      // --> R value expression
	value++;	      // --> R value expression
	value--;	      // --> R value expression
	value > 10 ? 1 : 0;   // --> R value expression
	foo();		      // --> R value expression

	int x = 10, y = 20;
	(x = 10) = y;         // (x = 10) --> L value expression
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :
```cpp
#include <iostream>

int main() {

	int firstNumber = 10;
	int& ref = firstNumber; // ref --> L value ref. ref = firstNumber
	int* const ptr = &firstNumber; // (*ptr) = firstNumber

	std::cout << "ref : " << ref << "\n";     // ref = 10
	std::cout << "(*ptr) : " << *ptr << "\n"; // (*ptr) = 10 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :
```cpp
#include <iostream>

int main() {

	int firstNumber = 10;
	int& ref = firstNumber; // ref --> L value ref. ref = firstNumber

	// int& referans = 10;
	// referans --> L Value , 10 --> R-Value
	// Error: 'initializing': cannot convert from 'int' to 'int &'

	int* const ptr = &firstNumber;            // (*ptr) = firstNumber

	std::cout << "ref : " << ref << "\n";     // ref = 10
	std::cout << "(*ptr) : " << *ptr << "\n"; // (*ptr) = 10
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :
```cpp
#include <iostream>

int main() {

	int array[5]{ 0,1,2,3,4 };
	int (&refArray)[5] = array;
	auto &referansArray = array;
	// if auto is used  --> auto  = int* referansArray
	// if auto& is used --> auto = int (&referansArray)[5]

	std::cout << "(&refArray) : " << (&refArray) << "\n";            // (&refArray) = 006FF7F4
	std::cout << "(&refArray) address: " << refArray << "\n";        // refArray = 006FF7F4
	std::cout << "referansArray address: " << referansArray << "\n"; // referansArray = 006FF7F4
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Pointers can be referenced for other pointers
```cpp
#include <iostream>

int main() {

	int number = 10;
	int* ptr = &number;   // (*ptr) --> number = 10
	int** ptrptr = &ptr;  // ptrptr --> &ptr
	int**& ref = ptrptr;  // ref --> ptrptr 
	
	std::cout << "(*ptr) : " << *ptr << "\n";       // *ptr  = 10
	std::cout << "(ptrptr) : " << ptrptr << "\n";   // ptrptr = 005BFB4C
	std::cout << "(**ref) : " << **ref << "\n";     // **ref = 10
	std::cout << "(++**ref) : " << ++**ref << "\n"; // ++**ref = 11
	std::cout << "(&ref) : " << &ref << "\n";       // &ref = 005BFB40
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : L-Value References for functions : 

```cpp
void  func(Type x); //  call by value
```

/----------------------------------------------
/----------------------------------------------

```cpp
void  func(Type *ptr); // call by reference (nesneyi hem okur hem de yazar)
void  func(Type &ref); // call by reference (nesneyi hem okur hem de yazar)
```

/----------------------------------------------
/----------------------------------------------

```cpp
void  func(const Type *ptr); // call by reference (nesneden sadece okuma yapar)
void  func(const Type &ref); // call by reference (nesneden sadece okuma yapar)
```

/----------------------------------------------
/----------------------------------------------

```cpp
Type  *func();  // return value is the address of object
Type  &func();  // return value is the reference of object 
```

/----------------------------------------------
/----------------------------------------------

```cpp
const Type  *func(); --> return value is the address of object
const Type  &func(); --> return value is the reference of object 
```

/----------------------------------------------
/----------------------------------------------

- **Example** :

```cpp
Type func(); 
func();                   // R-Value expression
Type &ref = func();       // NOT OK
const Type &ref = func(); // OK --> R-Value expression
```

```cpp
Type &func(); 
func(); 	    // L-Value expression
Type &ref = func(); // OK --> L-Value expression
```

/----------------------------------------------
/---------------------------------------------

- **Example** :
```cpp
#include <iostream>

struct Data{
	int x, y;
};

int main() {
	
	int number = 10;    // number --> L Value
	
	Data myData;        // myData --> L Value 
	myData.x;           // myData.x --> L Value 

	int* ptr = &number; // (*ptr) --> L Value
	int array[5]{};     // array[2] --> L Value
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :
```cpp
// ValueCategory.h ------------------------------------------------
#pragma once
#include <iostream>

template <typename T>
struct ValueCategory {
	constexpr static const char* ptrstr{ "PR Value" };
};

template <typename T>
struct ValueCategory<T &> {
	constexpr static const char* ptrstr{ "L Value" };
};

template <typename T>
struct ValueCategory<T &&> {
	constexpr static const char* ptrstr{ "X Value" };
};

#define valuecategory(exp) (std::cout << "Value category of \"" #exp"\" is : " << ValueCategory<decltype((exp))>::ptrstr << "\n");

// main.cpp ------------------------------------------------
#include <iostream>
#include "ValueCategory.h"

int foo();
int& func();
int&& xfunc();

int main() {
	
	int number = 10;           // number --> L Value
	const int realNumber = 0;  // realNumber --> L Value 
	int& refNumber = ++number; // ++number is L Value and  &refNumber is L Value
	// int& refNumber = number++;  --> Error : number++ is R Value, &refNumber is L Value 

	int firstNumber = 10;
	int secondNumber = 20;
	int& ref = (firstNumber, secondNumber);
	int array[10]{};

	valuecategory(number);      // Value category of "number" is : L Value
	valuecategory(realNumber);  // Value category of "realNumber" is : L Value
	valuecategory(number++);    // Value category of "number++" is : PR Value
	valuecategory(number--);    // Value category of "number--" is : PR Value
	valuecategory(++number);    // Value category of "++number" is : L Value
	valuecategory(--number);    // Value category of "--number" is : L Value

	valuecategory(refNumber);   // Value category of "refNumber" is : L Value
	valuecategory(ref);         // Value category of "ref" is : L Value
	valuecategory(array);       // Value category of "array" is : L Value
		
	valuecategory(foo());       // Value category of "foo()" is : PR Value
	valuecategory(func());      // Value category of "func()" is : L Value
	valuecategory(xfunc());     // Value category of "xfunc()" is : X Value
}
```
/----------------------------------------------
/----------------------------------------------

- **Example** : What is unevaluated context? --> for array[3] in the following example
```cpp
#include <iostream>
#include "ValueCategory.h"

int main() {
	
	int array[2] = {0,1};
	sizeof(array[3]);
	
	valuecategory(sizeof(array[3])); // Value category of "sizeof(array[3])" is : PR Value

	std::cout << "sizeof(array[3]) :  " << sizeof(array[3]) << "\n"; 
	// sizeof(array[3]) :  4
}
```

/----------------------------------------------
/----------------------------------------------
