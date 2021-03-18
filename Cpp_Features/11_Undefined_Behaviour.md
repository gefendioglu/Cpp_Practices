
## UNDEFINED BEHAVIOUR 
   - Always avoid undefined behaviour (ub)
     - Dereferencing null pointer
     - Changing string literals (read only)
     - Changing variables which assigned as const
     - Overflowing for signed variables
     - No returning value for a function
     - Using uninitialized auto variables 

## UNSPECIFIED BEHAVIOUR 
   - Do not rely on unspecified behaviour
   - It depends on compiler type
   - It depends on the implementation (compiler here), implementation is not required to document which behaviour occurs; range of possible behaviours usually specified in standard.
	
## Implementation Defined Behaviour: 
   - Try not to rely on implemetation defined behaviour
   - This behaviour should be documented

/----------------------------------------------
/----------------------------------------------

- **Example**: Unspecified Behaviour

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

- **Example**: Unspecified Behaviour

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

- **Example**: Unspecified Behaviour

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

- **Example**: Unspecified Behaviour

```cpp
#include <iostream>
#include <cstdint>

int main() {

	int firstNumber;
	int32_t secondNumber; // guaranteed that secondNumber -->  32 bits 
}
```
/----------------------------------------------
/----------------------------------------------

- **Example**: A sample for undefined behaviour 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// undefined behaviour --> int x has automatic scope value  
// return value shall not be L-value ref. in this case
int& func(int x)
{
	return x;
}

int main()
{
	int y = 20;
	func(y) = 50;
}
```

/----------------------------------------------
/----------------------------------------------
