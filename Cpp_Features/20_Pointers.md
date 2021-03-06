## POINTER TYPES 

- **Invalid Pointer**: An invalid pointer becomes an invalid pointer if the address of a dynamic object is assigned to a pointer or if the initial value is given and the pointer variable's life ends while the life of the pointer variable continues. 
  When automatically defined pointers are not initialized, they become invalid pointers.
  
- **Valid Pointer**: A pointer will hold the address of the last element of an array, 
    while incrementing its value by one will be holding the address of where the array ends.
    
- **Null Pointer**: A pointer with the value nullptr does not point to any object. It should never be dereferenced. 
  In addition to this, the concept of "null reference" does not exist!
  
- **Dangling Pointer**: They are pointers that lose their validity when the life of the object it points to.
  
/----------------------------------------------
/----------------------------------------------

### Null Pointer :

- nullptr was added to the language with C++11:
  - What is null pointer?
  - When we need to use null pointer?
  - NULL is a macro defined in the libraries like as stdlib, stdio, time, string, etc. 
  - In our system   --> #define NULL 0 
  - In some systems --> #define NULL ((void*) 0) 

- What is null pointer conversion in C?
	- int *ptr = NULL;
	  int *ptr = 0; 

- The type of implicit pointer conversion:
  - array to pointer conversion (array decay) --> the address of first element 
  - function to pointer conversion --> func() --> &func()
  - NULL pointer conversion --> int *ptr = 0; --> int *ptr = NULL;

- nullptr 
  - --> is an address constant to eliminate the disadvantages of using 0 to represent null ,
  - --> data type is nullptr_t (in <cstddef> lib)
  - void func(nullptr_t) --> especially used for function overloading 
  - --> nullptr is only assigned to pointer (not taking consideration of data types)
  - --> nullptr doesnt Member any objects, and it can not be dereferenced. 

- The following if conditions are same: 
  - if (iptr == nullptr) {} 
  - if (!iptr) {}

- The following if conditions are same: 
  - if (iptr != nullptr) {} 
  - if (iptr) {}

- It is not suggested to use NULL macro in cpp 

/----------------------------------------------	
/----------------------------------------------

-**Example**:

```cpp
#include <stdlib.h>
#include <cstddef>

struct Data {};

int main() {
	
	// int x = nullptr; --> NOT OK in main.cpp 
	// Error : C++ a value of type "std::nullptr_t" cannot be used to initialize an entity of type "int"
	
	int* iptr = nullptr;
	double* dptr = nullptr;
	Data* sptr = nullptr; 

	bool flag;
	flag = 0;
	flag = NULL;
	flag = nullptr;
}
```

/----------------------------------------------	
/----------------------------------------------

- The usage of null pointers: 
  - In functions that return addresses (T* func(){...}), nullptr is returned as the failure value.
  
  - It can be used for searching in some functions:
	  - If the searched value is found -> returns the address of the value
	  - If the searched value is not found -> returns "nullptr""
	  
  - It is widely used in functions whose parameter is pointer. 
  The addresses of the objects or nullptr can be passed to these functions as arguments. 
  The function can be designed to do a different job when called with the object address, and a different job when called with nullptr.
	- void func(T *ptr){...} --> func(nullptr); 
	- fflush(nullptr); --> from standard lib. 

/----------------------------------------------
/----------------------------------------------

**Example** : It is common to use pointer variables as flags.

```cpp
	int *ptr = nullptr;
	if(expr){
		ptr = nesne adresi; 
	}
	if(ptr == nullptr) {...}
```

/----------------------------------------------
/----------------------------------------------

**Example** : Dangling pointers

```cpp
#include <iostream>
#include <cstdlib>

int main() {

	size_t n = 10;
	int* ptr = (int*)malloc(n* sizeof(int));
	// malloc() --> its return value can be nullptr 

	free(ptr);     // ptr --> a dangling pointer --> invalid pointer
	ptr = nullptr; // ptr --> is not a dangling pointer
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
int main() {
	int* ptr = nullptr;
	std::cout << "(*ptr) : " << *ptr << "\n"; 
	// Exception thrown : read access violation.
}
```

/----------------------------------------------	
/----------------------------------------------

- The differences between references and pointer:
  - It is mandatory to give an inital value yo references, they can not be created without initialization.
  - It is not mandatory to initialize pointers.
  - There is no concept of "reference to reference"; however, the concept of "pointer to pointer" is available.

**Example** : Pointers can point the addresses of different objects. It doesn't have to be const itself. 

```cpp
#include <iostream>

int main() {
	int firstNumber = 10;
	int secondNumber = 99;

	int *ptr = &firstNumber;
	ptr = &secondNumber;             // OK

	int* const ptr2 = &secondNumber; // const pointer
	ptr2 = &firstNumber;             // NOT OK
}
```

/----------------------------------------------
/----------------------------------------------

**Example** : An array constituting of references cannot be written.- 

```cpp
#include <iostream>
int x, y, z, t;

int main() {
	int* ptrArray[] = { &x, &y, &z, &t }; // OK
	int& refArray[] = { x, y, z, t };     // NOT OK
	// Error C2234 'refArray': arrays of references are illegal	
}
```

/----------------------------------------------
/----------------------------------------------

**Example** : Initialization of pointer and reference arrays

```cpp
int main() {
	int a[10] = {0}; 
	int(*ptrArray)[10] = &a;
	int(&refArray)[10] = a;
}
```

/----------------------------------------------
/----------------------------------------------

**Example** : Pointers can be referenced for other pointers

```cpp
#include <iostream>

int main() {
	int number = 10;
	int* ptr = &number;   // (*ptr) --> number = 10
	int** ptrptr = &ptr;  // ptrptr --> &ptr
	int**& ref = ptrptr;  // ref --> ptrptr 
	
	std::cout << "(*ptr) : " << *ptr << "\n";        // *ptr  = 10
	std::cout << "(ptrptr) : " << ptrptr << "\n";    // ptrptr = 005BFB4C
	std::cout << "(**ref) : " << **ref << "\n";      // **ref = 10
	std::cout << "(++**ref) : " << ++**ref << "\n";  // ++**ref = 11
	std::cout << "(&ref) : " << &ref << "\n";        // &ref = 005BFB40
}
```

/----------------------------------------------
/----------------------------------------------

 **Example** : Void pointers

```cpp
int main(){

	int x = 4;
	float y = 5.5;

	// A void pointer 
	void* ptr;

	// void pointer Members an address includes integer value
	ptr = &x; 

	// (int*)ptr - does type casting of void 
	// *((int*)ptr) dereferences the typecasted 
	std::cout << "Integer variable is = " << *((int*)ptr) << "\n";
	
	// void pointer Members an address includes integer value
	ptr = &y;
	std::cout << "Float variable is= = " << *((float*)ptr) << "\n";
	return 0;

	/*
		Integer variable is = 4
		Float variable is= = 5.5
	*/
}
```

// --------------------------------------------
// --------------------------------------------

**Example** : Null pointers

```cpp
int main(){
	// Null pointer 
	int* ptr = nullptr;
	std::cout << "The value of ptr is : " << ptr << "\n";
	return 0;

	// The value of ptr is : 00000000
}
```

// --------------------------------------------
// --------------------------------------------

**Example** : Wild pointers

```cpp
int main(){

	/* wild pointer - initialize with garbage value*/
   // Error C4700: uninitialized local variable 'p' used
	int* p; 

	int x = 10;
	p = &x; // p is not a wild pointer now 
	std::cout << "not wild pointer : " << p << "\n";

	return 0;
}
```

// --------------------------------------------
// --------------------------------------------
