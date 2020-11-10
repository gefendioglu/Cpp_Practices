## R VALUE REFERENCES - L VALUE REFERENCES :
/----------------------------------------------
/----------------------------------------------

- Example:

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

	std::cout << "(&refArray) : " << (&refArray) << "\n"; // (&refArray) = 006FF7F4
	std::cout << "(&refArray) address: " << refArray << "\n";     // refArray = 006FF7F4
	std::cout << "referansArray address: " << referansArray << "\n"; // referansArray = 006FF7F4
}
```

/----------------------------------------------
/----------------------------------------------

- Example: Pointers can be referenced for other pointers

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

- Example: L-Value References for functions : 

```cpp
void  func(Type x); //  call by value
```

/----------------------------------------------

```cpp
void  func(Type *ptr); // call by reference (nesneyi hem okur hem de yazar)
void  func(Type &ref); // call by reference (nesneyi hem okur hem de yazar)
```

/----------------------------------------------

```cpp
void  func(const Type *ptr); // call by reference (nesneden sadece okuma yapar)
void  func(const Type &ref); // call by reference (nesneden sadece okuma yapar)
```

/----------------------------------------------

```cpp
Type  *func();  // return value is the address of object
Type  &func();  // return value is the reference of object 
```

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
