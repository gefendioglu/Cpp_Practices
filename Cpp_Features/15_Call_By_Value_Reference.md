
## CALL BY VALUE - CALL BY REFERENCE 

- C   --> always call-by-value
- C++ --> depends on function definition
  - func(int);   --> call-by-value OR 
  - func(int &); --> call-by-reference

- C --> 
  - setfunc(T *ptr); --> set function, setter, mutator
  - getfunc(const T *ptr);  
    - --> get function, getter, accessor
    - --> copy only pointer size, not all data
    - --> applicable especially for arrays
  - func(T value); --> copy all amount of data

- C --> 
  - setfunc(T *ptr);        --> output parameters
  - getfunc(const T *ptr);  --> input parameters

- C++ --> class Data{};
  - void setter(Data &ref);       --> the parameter will be changed
  - void getter(const Data& ref); --> the parameter will only be read

/----------------------------------------------
/----------------------------------------------

-**Example**: Swap Function with pointer - call by value & call by reference

```cpp
#include <iostream>

void swapPtr(int *ptr1, int *ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

void swapRef(int &ref1, int &ref2) {
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main() {

	int firstNumber = 35;
	int secondNumber = 43;

	swapPtr(&firstNumber, &secondNumber);

	std::cout << "firstNumber : " << firstNumber << "\n";     // firstNumber = 43 
	std::cout << "secondNumber : " << secondNumber << "\n";   // secondNumber = 35
  
  	swapRef(firstNumber, secondNumber);

	std::cout << "firstNumber : " << firstNumber << "\n";     // firstNumber = 35 
	std::cout << "secondNumber : " << secondNumber << "\n";   // secondNumber = 43
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int main() {

	int firstNumber = 35;
	const int& ref1 = firstNumber;
	int const& ref2 = firstNumber;
	int& const ref3 = firstNumber;

	// ref1 = 30; --> Error: expression must be a modifiable lvalue
	// ++ref1; --> Error: expression must be a modifiable lvalue
}
```

/----------------------------------------------
/----------------------------------------------

-**Example**: Getter function (with const parameters)

```cpp
#include <iostream>

int getter(const int& ref) { return ref; }

int main() {

	int firstNumber = 35;
	const int secondNumber = 43;
	
	std::cout << "getter(firstNumber): " << getter(firstNumber)<<"\n";
	std::cout << "getter(secondNumber): " << getter(secondNumber)<<"\n";
}
```

/----------------------------------------------
/----------------------------------------------

-**Example**: Setter function, no conversion from const --> non-const

```cpp
#include <iostream>

int setter(int& ref) {
	ref = 15;
	return ref;
}

int main() {

	int firstNumber = 35;
	const int secondNumber = 43;
	
	std::cout << "getter(firstNumber): " << setter(firstNumber)<<"\n";
	//std::cout << "getter(secondNumber): " << setter(secondNumber)<<"\n";
	// Error: qualifiers dropped in binding reference of type "int &" to initializer of type "const int"
	// Error : 'int setter(int &)' : cannot convert argument 1 from 'const int' to 'int &'
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int main() {

	int firstNumber = 35;
	const int& ref = firstNumber; // firstNumber --> L-Value  
	const int& ref = 10;          // 10 --> R Value 
	
	// A temporary object was defined for R Value 
	// int temp_object{10};
	// const int &ref = temp_object;
}
```

/----------------------------------------------
/----------------------------------------------

-**Example**: No conversion from const ref --> non-const ref

```cpp
#include <iostream>

int main() {

	int firstNumber = 35;
	const int& ref1 = firstNumber; // firstNumber --> L-Value  
	const int& ref2 = 10; // 10 --> R Value 
	// A temporary object was defined for R Value 
	// int temp_object{10};
	// const int &ref = temp_object;

	// int& reference = ref2;
	// Error: 'initializing' cannot convert from 'const int' to 'int &'	
}
```

/----------------------------------------------
/----------------------------------------------

-**Example**: No reference to reference definition

```cpp
#include <iostream>

int main() {

	int number = 35;
	int& ref1 = number;
	int& ref2 = ref1; // ref2 = number
	int& ref3 = ref2; // ref3 = number

	std::cout << "number: " << number << "\n"; // number = 35
	std::cout << "ref1: " << ref1 << "\n"; // ref1 = 35
	std::cout << "ref2: " << ref2 << "\n"; // ref2 = 35
	std::cout << "ref3: " << ref3 << "\n"; // ref3 = 35

	++ref1;
	++ref2;
	++ref3;

	std::cout << "number: " << number << "\n"; // number = 38
	std::cout << "ref1: " << ref1 << "\n"; // ref1 = 38
	std::cout << "ref2: " << ref2 << "\n"; // ref2 = 38
	std::cout << "ref3: " << ref3 << "\n"; // ref3 = 38
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Call by value, call by reference samples

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// call by-reference, return value is also ref. 
int& f2(int& r1, int& r2) {
	r1 += r2;
	return r1;
}

// call by-reference, return value is not ref. 
void f1(int& r1, int& r2) {
	r1 *= r2;     // x = x*y; --> x = 2*5 = 10; y = 5
	++f2(r1, r2); // f2(10,5); --> x = 10+5 = 15; y = 5 --> x=16
	++f2(r2, r1); // f2(5,15); --> y= 5+16 = 21; x = 16 --> y=22
}

int main() {

	int x = 2, y = 5;
	f1(x, y); // r1 --> x, r2 --> y

	std::cout << "x : "<< x << "\n"; // x : 16
	std::cout << "y : "<< y << "\n"; // y : 22
}
```

/----------------------------------------------
/----------------------------------------------
