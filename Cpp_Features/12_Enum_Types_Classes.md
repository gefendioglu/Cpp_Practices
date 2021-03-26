
## ENUM TYPES 
- Underlying type : int (as a default in C language)
- The most important disadvantages are: 
  - Because the underlying type of enums depend on compiler types, it can not be used as incomplete type (while doing forward declaration) 
  - The problem about including multiple header files. If one of the header files needs to be compiled, the other header files containing these files must also be compiled. Therefore, this solution should be chosen if using "incomplete types" instead of including header files solves the problem.
  - Pimpl idiom (opaque pointer, handle body, cashire cat idiom) is a solution to handle this problem.

- String literals:
  - C   --> char[]
  - C++ --> const char[]

- The data type of character constant: 
  - C   --> int 
  - C++ --> char 

- User defined tipler için C++ typedef kullanımına ihtiyaç yoktur (Foe ex. : structs)
  - struct Data{int Data;}

/----------------------------------------------
/----------------------------------------------
```cpp
#include <iostream>
#include <assert.h>

enum Color{White, Gray, Black};

int main() {
	assert(sizeof(Color) == sizeof(int)); // true
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The problem about Enum Types && Type Conversions

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// underlying type : int (C)
enum Color { White, Gray, Black, Yellow };

int main(){

	Color myColor = Yellow;
	int ival = 10;
	myColor = ival; // syntax error : int --> enum (no conversion) 
	ival = myColor; // not syntax error : enum --> int (conversion)
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of incomplete types - I

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Incomplete type 
struct Data; 

// The possible definitions with an incomplete type
Data func(struct Data);
extern struct Data gData;
typedef struct Data Data;
struct Data arr[];

struct myData {
	int value;
	struct Data* ptr;
};

int main(){
	struct Data* ptr; 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of incomplete types and standard library style - II

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Data; // incomplete type 
typedef struct Data* DHandle;
DHandle createData(void);
void func1(DHandle);
void func2(DHandle);

int main(){

	DHandle handle = createData();
	func1(handle);
	func2(handle);
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of incomplete type and pointer 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Data; // incomplete type 

int main(){

	struct Data myData; // syntax error --> compiler doesnt know the memory need for incomplete types
	struct Data* ptr;   // not syntax error, a pointer can be defined
	*ptr ;              // but this pointer can not be dereferenced
	ptr + 15;           // this pointer can not be used in arithmetic operations
	ptr->a;             // this pointer can not be used to reach an object
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of incomplete types and structures  

```cpp
struct Port;
struct File;

struct Data {
	struct Port* port; // not syntax error
	struct File *file; // not syntax error
	struct Port port; // syntax error -> the memory needs not known
	struct File file; // syntax error -> the memory needs not known
};
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of enum types and scope problem 
  - Not allowed to use the same names for enum types

```cpp
// #include "screen.h"
enum ScreenColor{Red, Magenta, Gray, Blue};

// #include "traffic.h"
enum TrafficLight{Yellow, Green, Red};

// Compiler Error - Because of scope rules 
// here "Red" are the same names 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Specifying underlying type solves the forward declaration problem 
  - The enum underlying types shall be integral type 

```cpp
enum ScreenColor :int;
enum TrafficLight : unsigned char;
enum Menus : double; // syntax error  

class MyClass {
	ScreenColor color; 
	TrafficLight lights; 
};
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of enum types and arithmetic operators
    - Not allowed to use enum types in arithmetic operators without implementing operator overloading 

```cpp
enum Color {White, Yellow, Black, Blue, Gray};

int main(){

	Color myColor = White;
	++myColor; // syntax error --> operator overloading shall be implemented for increment operator ++ 
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of enum types and arithmetic operators

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

enum WeekDay {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday,Saturday};

int main(){

	WeekDay weekday{ Sunday };
	++weekday; // to reach the next element in enumeration
	           // necessary to implement operator overloading 
}
```

/----------------------------------------------
/----------------------------------------------

## Enum Class 
- Enum class (scoped enums) should be preffered in C++ 
- Enum classes are not a original class type !!! 

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of enum class (the solutions for the problems caused by using enum types)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

enum class Color: unsigned long {White, Yellow, Black};
enum class TrafficLights: unsigned long {White, Yellow, Black};

class MyClass {
	Color color;
};

int main(){

	Color myColor = White; // syntax error
	Color myColor = Color::White; // not syntax error

	TrafficLights myColor = White; // syntax error
	TrafficLights myColor = TrafficLights::White; // not syntax error

	int ival = 10;
	ival = myColor; // syntax error --> not allowed with enum class
	ival = static_cast<int>(myColor);
	myColor = ival; // syntax error --> no conversion int --> enum

}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of enum class with pointer arrays

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

enum class Color: unsigned long {White, Yellow, Black};
enum class TrafficLights: unsigned long {White, Yellow, Black};

class MyClass {
	Color color;
};

int main(){

	const char* const ptr[] = { "White", "Yellow", "Black" };
	ptr[Color::White]; // syntax error --> no conversion to int 
	ptr[static_cast<int>(Color::White)]; // no error

}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of bool flag with increement operator 

```cpp
int main(){

	bool flag = false;
	++flag; // not an error in C++14, but error in C++17
} 
```

/----------------------------------------------
/----------------------------------------------
