## Undefined Behaviour :
- Always avoid undefined behaviour (ub)
- The reason samples for undefined behaviour 
  - Dereferencing null pointers
  - Changing string literals (read only)
  - Changing variables which assigned as const
  - Overflowing for signed variables
  - No returning value for a function
  - Using uninitialized auto variables 

## Unspecified Behaviour :
- do not rely on unspecified behaviour
- It depends on compiler type
- It depends on the implementation (compiler here), implementation is not required to document which behaviour occurs; range of possible behaviours usually specified in standard
  
* Implementation Defined Behaviour: 
	- try not to rely on implemetation defined behaviour
	- this behaviour should be documented

* Unspecified Behaviour

/----------------------------------------------
/----------------------------------------------

#### Example: Unspecified Behaviour

```cpp

#include <iostream>

int main() {

	int x = 10, y = 20;
	bool flag = &x > & y; // flag = true OR flag = false

	std::cout << "flag : " << flag << "\n";
}
```

/----------------------------------------------
/----------------------------------------------


```cpp
#include <iostream>

int func1();
int func2();

int main() {

	int x = func1()*5 + func2();
	// which function is called first ? Not clear!
}
```
/----------------------------------------------
/----------------------------------------------

```cpp
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
```
/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>
#include <cstdint>

int main() {

	int firstNumber;
	int32_t secondNumber; // guaranteed that secondNumber -->  32 bits 
}
```

## R VALUE REFERENCES - L VALUE REFERENCES :

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

```cpp
#include <iostream>

int main() {

	int array[5]{ 0,1,2,3,4 };
	int (&refArray)[5] = array;
	auto &referansArray = array;
	// if auto is used  --> auto  = int* referansArray
	// if auto& is used --> auto = int (&referansArray)[5]

	std::cout << "(&refArray) : " << (&refArray) << "\n"; // (&refArray) = 006FF7F4
	std::cout << "(&refArray) address: " << refArray << "\n";     // refArray = 006FF7F4
	std::cout << "referansArray address: " << referansArray << "\n"; // referansArray = 006FF7F4
}
```

/----------------------------------------------
/----------------------------------------------

* Pointers can be referenced for other pointers

```cpp
#include <iostream>

int main() {

	int number = 10;
	int* ptr = &number;   // (*ptr) --> number = 10
	int** ptrptr = &ptr;  // ptrptr --> &ptr
	int**& ref = ptrptr;  // ref --> ptrptr 
	
	std::cout << "(*ptr) : " << *ptr << "\n";     // *ptr  = 10
	std::cout << "(ptrptr) : " << ptrptr << "\n"; // ptrptr = 005BFB4C
	std::cout << "(**ref) : " << **ref << "\n";   // **ref = 10
	std::cout << "(++**ref) : " << ++**ref << "\n";   // ++**ref = 11
	std::cout << "(&ref) : " << &ref << "\n";     // &ref = 005BFB40
}
```

/----------------------------------------------
/----------------------------------------------

* L-Value References for functions : 

*  void  func(Type x);          --> call by value
/----------------------------------------------
*  void  func(Type *ptr);       --> call by reference (nesneyi hem okur hem de yazar)
*  void  func(Type &ref);       --> call by reference (nesneyi hem okur hem de yazar)
/----------------------------------------------
*  void  func(const Type *ptr); --> call by reference (nesneden sadece okuma yapar)
*  void  func(const Type &ref); --> call by reference (nesneden sadece okuma yapar)
/----------------------------------------------
*  Type  *func();       --> return value geri dönülen nesnenin adresi
*  Type  &func();       --> return value geri dönülen nesnenin referansý
/----------------------------------------------
*  const Type  *func(); --> return value geri dönülen nesnenin adresi
*  const Type  &func(); --> return value geri dönülen nesnenin referansý

/----------------------------------------------
/----------------------------------------------

* Type func(); 
  func(); --> R-Value expression
  Type &ref = func();       // NOT OK
  const Type &ref = func(); // OK --> R-Value expression

* Type &func(); 
  func(); --> L-Value expression
  Type &ref = func(); // OK --> L-Value expression

/----------------------------------------------
/---------------------------------------------

