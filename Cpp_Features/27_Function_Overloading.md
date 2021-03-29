
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

## Function Overload Resolution

- If there is function overloading, then which function is called?
  - **invalid** --> syntax error
    - no match  --> there is no function matching with the given function call
    - ambiguity --> there are more than one valid function matching with the given function call
  - **valid** --> it is known that which function is called !!! 
	
- For the first time, the candidate functions create the overload set.  
  - **Viable Function** : If the function placed in the overloaded set can be called whenever it is alone.
    - If the parameter number is the same with the calling function (default arguments are also in this situation)
    - If there is a legal conversion between arguments of the calling function and parameters of the called function. 
    - If there are two viable functions, the ambiguity error is taken (compilers generally show the functions that cause this situation )
      - The priority in this case (from the worst to the best): 
        - variadic conversion (coming from C)
	- user-defined conversion (it is only in C++)
	- standard conversion (whether there is data loss or not)
	  - int --> double
	  - int --> char
	  - int --> long double 
	  - long double -> char 
	  - int * --> void* (the opposite is not valid)
	  - enum --> int (the opposite is not valid)
    - If there are two viable functions and both of them are applicable for standard conversion 
      - Standard conversions (from the best to worst):
	- exact match
	  - L-Value to R-Value transformation
	  - const conversion
	  - array to pointer conversion (array decay)
	  - function o pointer conversion
	- promotion
	- conversion (If there is two conversion --> ambiguity error)

- Standard Conversion - Promotion 
  - Integral Promotion: If the arithmetic operations are applied on the types under int, then integral promotion shows up. 
    - The types under integers are the following: 
      - short, unsigned short, signed short
	    - char, unsigned char, signed char
	    - bool
  - Reel Number Promotion : 
    - The real number types: float, double, long double
      - float --> double (promotion)
      - float --> long double (not a promotion)
      - double --> long double (not a promotion)
      - double --> float (not a promotion)
      
/----------------------------------------------
/----------------------------------------------

- **Example** : Standard Conversion - Exact Match - L-Value to R-Value transformation

```cpp
void func(int x);
func(10);   --> direct calling 
func(ival); --> L-Value to R-Value transformation 
```

/----------------------------------------------
/----------------------------------------------

```cpp
void func(int);
void func(int&);

int main() {

	int x = 10;
	func(x);  // calling with L-Value --> syntax error
		  // both are viable --> ambiguity 
	func(20); // calling with R-Value --> not syntax error
	          // void func(int); is called (the other is not viable function)
} 
```

/----------------------------------------------
/----------------------------------------------

```cpp
void func(const int &ref); // const L-Value reference
void func(int &&ref);      // R-Value reference

int main() {

	int x = 10;
	func(10); // both functions are viable !!
		  // R-Value ref. --> const L-Value ref. is OK !
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : R-Value Reference

```cpp
void func(int &ref);
void func(int &&ref);

int main() {

	int x = 10;
	func(x); // calling the function with L-Value --> not sytnax error
	         // void func(int &ref); --> the parameter is L-Value; is called
	         // void func(int &&ref); --> R-Value reference; not called
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Standard Conversion - Exact Match -  const conversion

```cpp
void func(const int* ptr);

int main() {
	int x = 10;
	func(&x);  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Standard Conversion - Exact Match -  array decay 

```cpp
void func(int* ptr);

int main() {
	int arr[10] = {0};
	func(arr);  // --> func(&arr[0]) --> the address of first element of an array
}
```

- **Example** : There is an exception for array decay (sizeof(arr) --> no array decay here)

```cpp
int main() {
	int arr[10];
	std::cout << sizeof(arr) << "\n";     // 40 (bytes)
	std::cout << sizeof(&arr[0]) << "\n"; // 4 (bytes)
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Standard Conversion - Exact Match - function o pointer conversion

```cpp
void func(void(*fp)(int));
void f1(int);
void f2(int);

int main() {
	func(&f1); 
	func(f2);  // --> function to pointer conversion implicitly
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function Overloading - Standard Conversion - Promotion 

```cpp
void func(int);
void func(double);

int main() {
	func(1.2f); // void func(double); is called 
	            // because of promotion : float --> double 
		    // float --> int (conversion has the least priority)
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
void func(double);
void func(char);

int main() {
	float f = 12.5;
	func(f); // void func(double); is called
	         // because of promotion : float --> double 
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function Overloading  - Standard Conversion - Exact Match 

```cpp
void func(int);
void func(bool);

int main() {
	func(10>5); // void func(bool); is called - exact match 
	            // integral promotion : bool --> int (but it has lower priority comparing to exact match)
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
void func(int);
void func(char);

int main() {

	func('A'); // void func(char); is called --> exact match 
	           // integral promotion : char --> int (but it has lower priority comparing to exact match )
	           // C   : 'A' --> int type
	           // C++ : 'A' --> char type 
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function Overloading  - Standard Conversion

```cpp
void func(void*);

int main() {
	int ival = 10;
	func(&ival); // not syntax error --> void func(void*); is called
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function Overloading  - Standard Conversion

```cpp
void func(bool);

int main() {

	int ival = 10;
	func(&ival); // not syntax error  --> void func(bool); is called
	             // the address type  --> bool (true)
		     // null address type --> bool (false)
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Exception on Function Overloading  - Standard Conversion

```cpp
void func(bool);
void func(void *);

int main() {
	int ival = 10;
	func(&ival); // not syntax error --> void func(void *); is called
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Exception on Function Overloading  - Standard Conversion

```cpp
void func(int);
void func(int *ptr);

int main() {
	func(nullptr); // not syntax error --> void func(int *ptr); is called
	func(0);       // not syntax error --> void func(int); is called
	               // if there is void func(double); instead of void func(int);, then ambiguity error is received !!!
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function Overloading  - Standard Conversion

```cpp
void func(double *ptr);
void func(int *ptr);

int main() {
	func(nullptr); // syntax error --> both functions are viable
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function Overloading - Two viable function and both are applicable for conversion (ambiguity)

```cpp
void func(int);
void func(double);

int main() {
	unsigned int uval = 25;
	func(uval); // syntax error - ambiguity
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
void func(long double);
void func(char);

int main() {
	func(2.3); // syntax error - both are viable function - conversion 
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
void func(long double);
void func(char);

int main() {
	float f = 12.5;
	func(f); // syntax error - both are viable function - conversion 
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
void func(int);
void func(int, int = 10);

int main() {
	func(10); // syntax error --> ambiguity
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Integral Promotion (C Interviews)

```cpp
int main() {

	char c1 = 10;
	char c2 = 5;

	short s1 = 100;
	short s2 = 40;

	std::cout << typeid(c1 + c2).name() << "\n"; // int
	std::cout << typeid(s1 + s2).name() << "\n"; // int 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Function Overloading Resolution Problem --> syntax error (no match)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void func(int);
void func(int, int);
void func(int, double);

int main(){
	func(nullptr); // syntax error - no match
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Function Overloading Resolution Problem --> syntax error (ambiguity)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void func(char c);
void func(long double dval);

int main(){

	double dval = 3.4;
	func(dval); // syntax error
	// more than one instance of overloaded function
	// double --> char and double --> long double conversion are same priority
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Function Overloading Resolution --> viable function

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class MyClass {  };

void func(int *);    // --> not viable function
void func(int, int); // --> not viable function
void func(double);   // --> viable function
void func(MyClass);  // --> not viable function

int main(){
	func(12);
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Function Overloading Resolution Problem --> syntax error (ambiguity, because of more than one viable functions)
  - They are all candidate functions
  - Three of them are viable functions

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

enum Color { Red, Green, White };

void func(int);      // --> viable function (double --> int)
void func(bool);     // --> viable function (double --> bool)
void func(int, int); // --> not viable function
void func(int*);     // --> not viable function
void func(int, int = 1, double = 3.4); // --> viable function (double --> int) with default arguments
void func(Color);    // --> not viable function (no conversion double --> enum)

int main() {
	func(4.5);     // syntax error - ambiguity
	func(nullptr); // exact match (void func(int*);)
}
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
