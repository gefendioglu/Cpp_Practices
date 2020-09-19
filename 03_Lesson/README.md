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

