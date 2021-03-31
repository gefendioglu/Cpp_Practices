
## FUNCTION OVERLOADING 

- It is much more applicable for client code in terms of function usage

- It is in compiler time (early binding)

- Early Binding (Static Binding) : Compiler can understand which function is called. 

-  Dynamic Binding (Late Binding) : Compiler does know which function is called in run-time (for ex. if you are calling a function pointer in run-time, or virtual functions are resolved in run time too)

- The Rules About Function Overloading:  
  - Function should have the same function name and they should be defined/declared in the same scope
  - Functions with the same name must have different signatures.
    - int func(int, int);
      - the function signature --> func(int, int)
      - return value --> int 

/----------------------------------------------
/----------------------------------------------

- "char", "signed char", "unsigned char" --> They are distinct types 

```cpp
void func(char);
void func(signed char); // function overloading 
```
/----------------------------------------------
/----------------------------------------------

```cpp
int foo(int x, int y);
int foo(int, int, int );  // function overloading
int foo(double);          // function overloading
int foo(bool);            // function overloading
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <cstdint>

void func(int);
void func(int32_t); 
// int32_t --> implementation dependent (compiler dependent)
// so, the second expression can be function overloading or not
```

/----------------------------------------------
/----------------------------------------------

```cpp
void foo(int x, int y, int z = 10);
void foo(int x, int y); // function overloading
```

/----------------------------------------------
/----------------------------------------------

```cpp
void foo(int);
void foo(int&); // function overloading
```

/----------------------------------------------
/----------------------------------------------

```cpp
void foo(int&&);
void foo(int&); // function overloading
```

/----------------------------------------------
/----------------------------------------------

- Variadic conversion (coming from C syntax)
- For variadic functions, it is necessary to pass arguments for each parameter preceding the variadic parameter.

- The variadic functions: 
  int func(int, ...);
  int printf(const char*, ...);
  int sprintf(char* pbuf, const char *, ...);

/----------------------------------------------
/----------------------------------------------

- **Example**: Calling a variadic function 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void func(int, int, ...); // --> variadic function

int main() {

	func(1,2); 
	func(1,2,3); 
	func(1,2,3,4); 
	func(1,2,3,4,5); // and so on...
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Calling an user-defined conversion (with syntax error)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Data {
	Data myData;
};

int main() {
	mydata = 10; // syntax error (no conversion int --> struct )
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Calling an user-defined conversion (with no syntax error)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Data {
	Data();
	Data(int); // thanks to this function
};

int main() {
	Data mydata;
	mydata = 10; // no syntax error 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Function Overloading (Interview)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void func(double);
void func(int* ptr);

int main() {

	int x = 10;
	func(x); // void func(double); is called
	func(0); // syntax error - ambiguity - both functions are viable 
	         // 0 --> nullptr (conversion)
	         // 0 --> double (conversion)
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Function Overloading (Interview)
  - Be careful when calling a function with an argument of 0.

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void func(int);
void func(int* ptr);

int main() {

	int x = 10;
	func(x); // void func(double); is called
	func(0); // void func(int); is called - exact match 
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function Overloading with multiple parameters (Interview)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// at least one of the parameters should have exact matching 
void func(int, double, long);
void func(double, int, int);
void func(float, float, float);

int main() {

	func(12, 6u, 3.4);   // void func(int, double, long); is called
			     // for the first parameter, the first function has the highest priority 
			     // for the other functions, second parameters have the same priority 
	func(3.4, 4u, 3.4);  // void func(double, int, int); is called
	func(12u, 34, 2.3);  // void func(double, int, int); is called
	func(12u, 34, 2.3f); // ambiguity --> the last parameter of third function has the highest priority, but the second parameter of second function has the highest priority,

}
```
/----------------------------------------------
/----------------------------------------------
