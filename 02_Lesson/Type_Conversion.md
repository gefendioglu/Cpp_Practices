
## TYPE CONVERSION 
- C++ data conversion (casting) types:
	- static_cast
	- const_cast
	- reinterpret_cast
	- dynamic_cast
  
/----------------------------------------------
/----------------------------------------------

- **Example** : CPP --> No automatically conversion from arithmetic types to enum types 
```cpp
#include <iostream>

enum Color{White, Gray, Black};

int main() {
	enum Color mycolor = Gray;
	mycolor = (Color)2;
	// mycolor = 2; --> is OK in main.c

	std::cout << "mycolor: " << mycolor << "\n"; // mycolor: 2
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :  CPP --> No automatically conversion between different enum types  
```cpp
#include <iostream>

enum Color{White, Gray, Black};
enum Position{OFF, ON};

int main() {
	enum Color myColor = Gray;     // --> Gray : 1
	enum Position myPosition = ON; // --> ON : 0

	myColor = (Color)myPosition;
	// mycolor = myPosition; --> is OK in main.c

	std::cout << "myPosition: " << myPosition << "\n"; // myPosition: 1
	std::cout << "myColor: " << myColor << "\n";       // myColor: 1
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The conversion from enum types to the other types is OK (For example: enum --> int)
```cpp
#include <iostream>

enum Color{White, Gray, Black};
enum Position{OFF, ON};

int main() {
	enum Color myColor = Black;// --> Gray : 2
	enum Position myPosition = OFF; // --> OFF : 0

	int number1 = myColor;
	int number2 = myPosition;
	std::cout << "number1: " << number1 << "\n"; // number1: 2 --> myColor
	std::cout << "number2: " << number2 << "\n"; // number2: 0 --> myPosition
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :
  - The conversion from pointer types to arithmetic types is OK (C) 
  - No automatically conversion from pointer types to arithmetic types (C++)
```cpp
#include <iostream>

int main() {
	int x = 0;
	int* ptr = &x; // int* ptr = x;     --> OK, warning in main.c 
				         // int number = ptr; --> OK, warning in main.c 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - The type conversion between different address types:
	  - The data type and pointer type shall be compatible to each other, C++ --> error
	  - The data type and pointer type shall be compatible to each other, C   --> warning
```cpp
#include <iostream>

int main() {
	int x = 10;
	// double* ptr = &x; --> C++ a value of type cannot be used to initialize an entity of type
	// double* ptr = &x; --> C warning C4133 : incompatible types from 'int*' to 'double*'
	double* ptr = (double*)&x;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - No type conversion between pointer types automatically (C++)
  - T* --> U* (T and U are two different data type)
```cpp
#include <iostream>

int main() {
	int x = 10;
	int* ptr = &x;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The data types for addresses 
```cpp
#include <iostream>

int main() {
	int x = 10;
	// &x --> the data type of x : int*

	int primes[10] = {};
	// &primes --> the data type of primes array : int* (array decay)

	const int cx = 10;
	// &cx --> the data type of cx : const int*

	int const icx = 10;
	// &icx --> the data type of cx : const int* (like the previous one)

	const int cprimes[10] = {};
	// &cprimes --> the data type of cprimes array : const int* 
	
	char name[6] = "gamze";	
	// string literals in C
	// &name --> the data type of name : char* in C

	const char cname[6] = "gamze";	
	// string literals in C++ 
	// &cname --> the data type of cname : const char* in C++ 
}
```	

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - The type conversion rules for const address types (const int *):
    - The type conversion from const address data types to non-const address data types is OK (C)
    - No type conversion from const address data types to non-const address data types (C++)
      - const T* --> T* (NOT OK)
    - The type conversion from non-const address data types to const address data types is OK (C)
    - The type conversion from non-const address data types to const address data types is OK (C++)
      - T* --> const T* (OK)
```cpp
#include <iostream>

int main() {
	int x = 10;
	const int *cptr = &x; // T* --> const T* (OK)

	const char* name = "Gamze Efendioglu";
	// char* name = "Gamze Efendioglu"; --> Error in main.cpp, not Error in main.c
	// Error C2440 'initializing': cannot convert from 'const int *' to 'int *'	
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :
  - The type conversion for void pointers:
    - (C++) : void T* (OK) 
    - (C++) : void T* --> T* (OK) 
    - (C)   : void T* --> T* (NOT OK) 
```cpp
#include <iostream>

int main() {
	int ival = 10;
	unsigned int uval = 20;
	double dval = 5;
	char str[] = "gamze";

	// T* --> void T* (OK) in main.cpp
	void* vptr = &ival; // void pointer 
	vptr = &uval;
	vptr = &dval;
	vptr = str;

	// void T* --> T* (NOT OK) in main.cpp
	// int* iptr = vptr;
	// Error E0144: a value of type "void *" cannot be used to initialize an entity of type "int *
}
```	

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>
#include <stdlib.h>

int main() {
	size_t n;
	// int* iptr = malloc(n * sizeof(int)); // NOT OK --> 
	int* iptr = (int*)malloc(n * sizeof(int));
}
```

/----------------------------------------------
/----------------------------------------------
