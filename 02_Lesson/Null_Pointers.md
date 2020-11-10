
## NULL POINTER:

- nullptr was added to the language with C++11:
	- What is null pointer?
	- When we need to use null pointers?
	- NULL is a macro defined in the libraries like as <stdlib>, <stdio>, <time>, <string> 
	- In our system   --> #define NULL 0 
	  In some systems --> #define NULL ((void*) 0) 

- What is null pointer conversion in C?
	- int *ptr = NULL;
	  int *ptr = 0; 

- The type of implicit pointer conversion:
	- array to pointer conversion (array decay) --> the address of first element 
	- function to pointer conversion --> func() --> &func()
	- NULL pointer conversion --> int *ptr = 0; --> int *ptr = NULL;

- nullptr is an address constant to eliminate the disadvantages of using 0 to represent null 
	- data type is nullptr_t (in <cstddef> lib)
	- void func(nullptr_t) --> especially used for function overloading 
		- nullptr is only assigned to pointers (not taking consideration of data types)
		- nullptr doesnt point any objects, and it can not be dereferenced. 

- The following if conditions are same: 
	- if (iptr == nullptr) {} 
	- if (!iptr) {}

- The following if conditions are same: 
	- if (iptr != nullptr) {} 
	- if (iptr) {}

- It is not suggested to use NULL macro in cpp 

- The usage of null pointer: 
	- For the functions returned an address, in the case of insuccessful basarısızlık olarak --> return nullptr; T* func(){...}

	- For searching a value in some functions: 
	  - If the searched value is found --> return value is the address of founded value 
    - If the searched value is not found --> return value is nullptr

	- It is common for the functions which have pointer parameters: 
	  - The object address or nullptr can be sent to function parameters as an argument.
	  - In this case, this type of functions can behave differently depending on their calling style. 
	    - void func(T *ptr){...} --> func(nullptr); 
	    - fflush(nullptr); --> from standard lib. 

	- It is common that pointer types are used as a flag variable.
	
/----------------------------------------------
/----------------------------------------------

```cpp
int *ptr = nullptr;
if(expr){
	ptr = nesne adresi; 
}
if(ptr == nullptr) {...}
```

/----------------------------------------------
/----------------------------------------------

- **Example* :
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

- **Example* :
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
