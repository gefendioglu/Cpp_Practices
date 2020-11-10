## POINTER TYPES: 

- Invalid Pointer: 
  - If the automatically defined pointer types are not initialized --> invalid pointer 
  - If a pointer type is assigned/initialized with an address of dynamic object and then this pointed objects are deleted before deleting the pointer type --> invalid pointer 
  
- Valid Pointer: 
  - If a pointer points the address of the last array element and its value is incremented, then this pointer holds the address of the ending place of the same array.  
 
- Null Pointer (nullptr):
  - Null pointers point to anything. There is nothing in this address. That's why, it must not be dereferenced.  
  - There is no "null reference" concept in Cpp.

/----------------------------------------------
/----------------------------------------------

- Example: 
```cpp
#include <iostream>

int main() {
	int* ptr = nullptr;
	std::cout << "(*ptr) : " << *ptr << "\n"; 
	// Exception thrown : read access violation.
}
```

/----------------------------------------------	
/----------------------------------------------

### The Comparisons for References and Pointers:
- Referanslara ilk değer vermek zorunlu, ilk değer vermeden referans oluşturulamaz ! 
- Pointer değişkenlere ilk değer vermek zorunlu değildir. 
- "Reference to reference" kavramı yoktur; ancak "pointer to pointer" kavramı mecvuttur. 

/----------------------------------------------	
/----------------------------------------------

- Example: 
  - Non-const pointer types can point the addresses of different objects   
  - Const pointer types can not point the addresses of different objects. It must point the same object.  
```cpp
#include <iostream>

int main() {
	int firstNumber = 10;
	int secondNumber = 99;

	int *ptr = &firstNumber;
	ptr = &secondNumber; // OK
	//...
	int* const ptr2 = &secondNumber; // const pointer
	ptr2 = &firstNumber; // NOT OK
}
```

/----------------------------------------------
/----------------------------------------------

- Example: There is no definition for reference arrays.
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

- Example: Initialization of pointer and reference arrays
```cpp
#include <iostream>

int main() {
	int a[10] = {0}; 
	int(*ptrArray)[10] = &a;
	int(&refArray)[10] = a;
}
```

/----------------------------------------------
/----------------------------------------------
