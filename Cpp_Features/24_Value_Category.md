## VALUE CATEGORY:

- What is the difference between "expression" and "statement"?
  - expression --> 10, x, x+10, a*a + b*b > 10. etc (operators, objects, constants, etc.)
  - statement  --> all expressions which have ; at the end. 
    - x = 10  --> expression
    - x = 10; --> statement (expression statement)
  - "const" keyword does not effect the value category 

- What is the data type?
  - int, int*, int&, int [], int (*)(int), etc.

- The value category types in Cpp:
  - L Value (Left Value):
    - The values that point objects
    - They have a place in the memory 

  - X Value (Expiring Value):
    - Not defined in C language
    - The values that point objects
    - It does not appear as a direct name in the code (it does not have an ID.)
	  
  - PR Value (Pure Right Value):
    - The values that not point any objects
    - They do not have any place in the memory 
    
   - L Value + X Value = GL Value 
   - PR Value + X Value = R Value 

/----------------------------------------------
/----------------------------------------------

### L-VALUE REFERENCES for functions : 
  
| Function Type                | Call Value                                           | 
| ---------------------------- |:---------------------------------------------------- |
| void  func(Type x);          | call by value                                        |
| void  func(Type *ptr);       | call by value                                        |
| void  func(Type &ref);       | call by reference (both reads and writes the object) |
| void  func(const Type *ptr); | call by reference (reads only from the object)       |
| void  func(const Type &ref); | call by reference (reads only from the object)       |
| Type  *func();               | return value is the address of the returned object   |
| Type  &func();               | return value is the reference of the returned object |
| const Type  *func();         | return value is the address of the returned object   |
| const Type  &func();         | return value is the reference of the returned object |
    
/----------------------------------------------
/----------------------------------------------

- Type func(); 
  - func(); --> R-Value expression
  - Type &ref = func();       // NOT OK
  - const Type &ref = func(); // OK --> R-Value expression

- Type &func(); 
  - func(); --> L-Value expression
  - Type &ref = func(); // OK --> L-Value expression

/----------------------------------------------
/----------------------------------------------

### R-VALUE REFERENCES 
- References does not allocate memory, the memory allocation is for objects 
- Adding to C++ standard with C++11 
- Adding for move semantics and perfect forwarding reference 
  - R value reference must be initialized with R Value expression 
  - T &&ref = 10; // OK --> R value reference 
    - ref is a L value expression 
  - T &&ref is a R value expression (the data type of ref is a R value expression)
     - void func(T &&ref); --> move semantic
     - T&& func(); --> return value is R value reference 
  - auto &&ref = expr; --> this is not R value reference, it is forwarding reference !!! (forwarding reference, if there is type deduction using with && specifier.)

/----------------------------------------------
/----------------------------------------------

- The differences of value categories between C and CPP ? 

|           |  C      | C++                                          |
| --------- |:-------:|:-------------------------------------------- |
| ++x       | R-Value | L-Value                                      |
| --x       | R-Value | L-Value                                      | 
| a,b       | R-Value | L-Value (even if right operand is an object) |  
| x++       | R-Value | PR-Value                                     |
| x--       | R-Value | PR-Value                                     |
| x>0 ? y:z | R-Value | L-Value (for operands)                       | 


/----------------------------------------------
/----------------------------------------------

```cpp
void func(int &ref);
void func(const int &ref);
int& func(void); --> return value is L value
func() = 10; not an error !!!
```

- L value Reference
  - void func(T *ptr);       --> void func(T &ref);
  - void func(const T *ptr); --> void func(const T &ref);
  - T* func();               --> T& func();
  - const T* func();         --> const T& func();

- R Value / L Value Functions
  - T foo();   --> R value expression --> T &ref = foo();  // ERROR --> const T &ref 
  - T& func(); --> L value expression --> T &ref = func(); // NOT ERROR

/----------------------------------------------
/----------------------------------------------

- **Example**:  A value belongs to only one of the above value categories !!!

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

- **Example**: Finding value category

```cpp
// ValueCategory.h --> 
//----------------------------------------------

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


// main.cpp -->
//----------------------------------------------
#include <iostream>
#include "ValueCategory.h"

int foo();
int& func();
int&& xfunc();

int main() {
	
	int number = 10;	   // number --> L Value
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

- **Example**: What is unevaluated context? --> for array[3] in the following example

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

- **Example**: 

```cpp
#include <iostream>

int main() {

	int firstNumber = 10;
	int& ref = firstNumber;        // ref --> L value ref. ref = firstNumber
	int* const ptr = &firstNumber; // (*ptr) = firstNumber

	std::cout << "ref : " << ref << "\n";     // ref = 10
	std::cout << "(*ptr) : " << *ptr << "\n"; // (*ptr) = 10 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: 

```cpp
#include <iostream>

int main() {

	int firstNumber = 10;
	int& ref = firstNumber; // ref --> L value ref. ref = firstNumber

	// int& referans = 10;
	// referans --> L Value , 10 --> R-Value
	// Error: 'initializing': cannot convert from 'int' to 'int &'

	int* const ptr = &firstNumber; // (*ptr) = firstNumber

	std::cout << "ref : " << ref << "\n";     // ref = 10
	std::cout << "(*ptr) : " << *ptr << "\n"; // (*ptr) = 10
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: 

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

- Example:

```cpp
#include <iostream>

int main() {

	int firstNumber = 10;
	int& ref = firstNumber;        // ref --> L value ref. ref = firstNumber
	int* const ptr = &firstNumber; // (*ptr) = firstNumber

	std::cout << "ref : " << ref << "\n";     // ref = 10
	std::cout << "(*ptr) : " << *ptr << "\n"; // (*ptr) = 10 
}
```

/----------------------------------------------
/----------------------------------------------

- Example:

```cpp
#include <iostream>

int main() {

	int firstNumber = 10;
	int& ref = firstNumber; // ref --> L value ref. ref = firstNumber

	// int& referans = 10;
	// referans --> L Value , 10 --> R-Value
	// Error: 'initializing': cannot convert from 'int' to 'int &'

	int* const ptr = &firstNumber; // (*ptr) = firstNumber

	std::cout << "ref : " << ref << "\n";     // ref = 10
	std::cout << "(*ptr) : " << *ptr << "\n"; // (*ptr) = 10
}
```

/----------------------------------------------
/----------------------------------------------

- Example:

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

- Example: pointer can be referenced for other pointer

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

- Example: L-Value References for functions 

```cpp
void  func(Type x); //  call by value
```

/----------------------------------------------
/----------------------------------------------

```cpp
void  func(Type *ptr); // call by reference (both reads and writes the object)
void  func(Type &ref); // call by reference (both reads and writes the object)
```

/----------------------------------------------
/----------------------------------------------

```cpp
void  func(const Type *ptr); // call by reference (reads only from the object)
void  func(const Type &ref); // call by reference (reads only from the object)
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

- Example:

```cpp
Type func(); 
func();                   //R-Value expression
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

	value + 5;		// --> R value expression
	++value;		// --> L value expression
	--value;		// --> L value expression
	value > 10;		// --> R value expression (comparisons)
	value && 10;		// --> R value expression
	!value ;		// --> R value expression
	value & 10;		// --> R value expression
	value++;		// --> R value expression
	value--;	        // --> R value expression
	value > 10 ? 1 : 0;     // --> R value expression
	foo();			// --> R value expression

	int x = 10, y = 20;
	(x = 10) = y;           // (x = 10) --> L value expression
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: R-Value, L-Value, X-Value samples

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct MyStruct {
	int a, b;
};

MyStruct   f1();
MyStruct&  f2();
MyStruct&& f3();

int main()
{
	int x = 10;
	const int y = 20;
	int& r = x;
	int&& rr = x + 5;
	MyStruct str;
	MyStruct* ptr = &str;
	MyStruct& nr{ str };
	int a[10];

	// x      	  --> L-Value 
	// x + 5  	  --> PR-Value
	// &x     	  --> PR-Value
	// &y     	  --> PR-Value (no dependency with const)
	// y      	  --> L-Value  (no dependency with const)
	// ++x    	  --> L-Value  (prefix --> L-Value)
	// x++    	  --> PR-Value (postfix --> PR-Value)
	// --x    	  --> L-Value  (prefix --> L-Value)
	// x--	  	  --> PR-Value (postfix --> PR-Value)
	// (x, y)	  --> L-Value (right operand --> y is L-Value)
	// x > 5 ? x : y  --> L-Value (both operands are L-Value)
	// x > 5 ? x : 7  --> PR-Value (right operand is R-Value)
	// x > y          --> PR-Value (comparison operators)
	// x && y         --> PR-Value (logic operators)
	// +x		  --> PR-Value (positive operators)
	// -x		  --> PR-Value (negative operators)
	// (double)x      --> PR-Value (type conversion operators)
	// f1()           --> PR-Value (return value is not reference)
	// f2()		  --> L-Value (return value is reference)
	// f3()		  --> X-Value (return value is R-reference)
	// r	          --> L-Value 
	// rr		  --> L-Value (interviews)
	// str		  --> L-Value (struct object)
	// str.x	  --> L-Value (struct object)
	// ptr		  --> L-Value (pointer Members an object)
	// *ptr		  --> L-Value (dereferencing)
	// &ptr		  --> R-Value (with address operator)
	// ptr->a         --> L-Value (struct object)
	// &ptr->a        --> PR-Value (&(ptr->a) address operator)
	// ptr + 1	  --> PR-Value (arithmetic operator)
	// a		  --> L-Value 
	// *a		  --> L-Value (dereferencing)
	// a + 3	  --> PR-Value (arithmetic operator)
	// a[4]		  --> L-Value
	// nr		  --> L-Value (reference)
	// nr.a		  --> L-Value 
	// int()	  --> PR-Value (temporary object)
	// int{}	  --> PR-Value (temporary object)
	// MyStruct()	  --> PR-Value (temporary object)
	// MyStruct{}     --> PR-Value (temporary object)
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : R-Value, L-Value, X-Value samples

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int& f1();
int f2();

int main()
{
	int x = 10;
	int y = 35;
	const int primes[]{ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	int a[]{ 1, 2, 4 };
	
	// int& r1;  NOT OK --> references must be initialized
	int& r2(++x); // ++x is L-Value 
	
	// int& r3{ 10 }; NOT OK --> 10 is a R-Value expression
	// temporary object R-Value and can be assigned to const ref.
	const int& r4{ int() };  
	const int& r5{ int{} };
	
	// int& r6 = +y; NOT OK --> +y PR value and can not be assigned to L-Value ref. 

	// (x, y) is L-Value expr. and can be assigned to L-value ref. r7
	int& r7 = (x, y); 

	// x > 10 ? x : y is L-value expr. here and can be assigned to L-value ref. r8
	int& r8 = x > 10 ? x : y; 

	// f1() is L-Value expr. and can be assigned to L-value ref. r9
	int& r9 = f1(); 

	// int& r10 = f2(); NOT OK --> f2() is R-Value expr. and can be assigned to L-value ref. r9

	// int& r11 = primes[5]; NOT OK --> primes is const 
	
	// *primes --> primes[0] --> const value
	int const& r12 = *primes;
	 
	// x is a L-Value expr. can be assigned to const ref. 
	const int& r13{ x };
	
	// int*& r14 = a; NOT OK 
	// int(&r15)[] = a; NOT OK --> the size should be defined as: int(&r15)[3] = a;
	int(&r16)[3] = a;
	auto& r17 = a; 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: R-Value, L-Value, X-Value samples

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	auto a; 	    	// NOT OK, must be initialized ! 
	int& b;             	// NOT OK, must be initialized ! 
	auto c = 10;        	// OK
	int& d = c;  	    	// OK
	const auto& e = 20; 	// OK
	int& f = ++c;       	// OK 
	int& g = c + 5;     	// NOT OK, c+5 --> R-Value is not assigned to L value ref. 
	int&& h = c % 2;    	// OK, c % 2 --> R-value is assigned to R-Value ref. 
	
	int func();         	// func() is R-Value
	int&& j = func();   	// func() is assigned to R-value ref. 
	
	int& foo();        	// foo() is L-Value 
	int&& m = foo();    	// foo() is not assigned to R-value ref.

	int ival = 10;          // ival --> L-Value
	int&& rval = ival + 10; // ival + 10--> R-value, is assigned to R-Value ref. 
	int& p = rval;          // rval--> L-value, is assigned to L-value ref.
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: R-Value, L-Value expression sample

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main()
{
	int ival = 1;

	// ival > 0 ? ival : 1 --> R-value expression
	// the result is assigned to a temporary reference not r here
	const int& ref1 = ival > 0 ? ival : 1;
	
	ival = 5;

	std::cout << "ival : "  << ival << "\n";   // ival : 5
	std::cout << "ref1 : "  << ref1 << "\n\n"; // ref1 : 1

	int x = 20; 
	// x is L-Value expr. and can be assigned to const L-value 
	const int& ref2 = ival > 0 ? ival : x;

	std::cout << "ival : " << ival << "\n";  // ival : 5
	std::cout << "ref2 : " << ref2 << "\n";  // ref2 : 5
}
```

/----------------------------------------------
/----------------------------------------------

### Forwarding Reference versus R-Value References 
- They are both represented by && operators
- Forwarding reference was added to the languagas as a new feature, because of existing move semantics and perfect forwarding. 

/----------------------------------------------
/----------------------------------------------

- **Example** : Forwarding Reference versus R-Value References 

```cpp
void func(Data&& ref); // func parameter is R-value ref.

template<typename T>
void foo(T&& ref); // foo parameter is not R-value ref.
		   // it is forwarding ref.(universal ref.)

for(auto &&x : data_vec){/**/} // range based for loop --> not R-value ref.
			       // it is forwarding ref.
```

/----------------------------------------------
/----------------------------------------------
