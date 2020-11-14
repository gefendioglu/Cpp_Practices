## ASSIGNMENT 

/----------------------------------------------
/----------------------------------------------

- **Example**: Assigning a pointer and reference values 
```cpp
#include <iostream>

int main() {
	int firstNumber = 10;
	int secondNumber = 99;

	int* ptr = &firstNumber;
	int*& refPointer = ptr;

	std::cout << "ptr : " << ptr << "\n";	            // ptr : 00AFFAF8
	std::cout << "refPointer : " << refPointer << "\n"; // refPointer : 00AFFAF8

	*refPointer = 300; // *refPointer --> firstNumber
	std::cout << "firstNumber : " << firstNumber << "\n";  // firstNumber : 300
		
	refPointer = &secondNumber;
	*refPointer = 700; // *refPointer --> secondNumber
	std::cout << "secondNumber : " << secondNumber << "\n"; // secondNumber : 700
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Assigning references 
```cpp
#include <iostream>

int main() {
	int firstNumber = 10;
	int secondNumber = 99;

	int& ref1 = firstNumber;
	int& ref2 = ref1;
	++ref2; 
  
	std::cout << "ref1 : " << ref1 << "\n"; // ref1: 11
	std::cout << "ref2 : " << ref2 << "\n"; // ref2 : 11
}
```

/----------------------------------------------
/----------------------------------------------