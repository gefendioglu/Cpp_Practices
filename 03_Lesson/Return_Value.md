## RETURN VALUE
/----------------------------------------------
/----------------------------------------------

- **Example**: When return value is a pointer 
```cpp
int* ptrFunc() {
	static int number = 10;
	//....
	return &number;
}
```
/----------------------------------------------
/----------------------------------------------

- **Example**: When return value is a reference
```cpp
int& refFunc() {
	static int number = 10;
	//....
	return number;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: When function return value is reference, then the function is a L-Value (1)
```cpp
#include <iostream>

int command = 45;

int& refFunc() {
	return command;
}

int main() {

	refFunc() = 100; // refFunc() is a L-Value
	std::cout << "command: " << command << "\n"; // command = 100
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: When function return value is reference, then the function is a L-Value (2)
```cpp
#include <iostream>

int command = 45;

int& refFunc() {
	return command;
}

int main() {

	int& ref = refFunc();
	ref = 500;
	std::cout << "command : " << command << "\n"; // command : 500
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: When function return value is reference or address --> undefined behaviour
```cpp
#include <iostream>

int& refFunc() {
	int x = 10;
	return x; 
	// warning C4172: returning address of local variable or temporary: x
}

int* ptrFunc() {
	int x = 10;
	return &x; 
	// warning C4172: returning address of local variable or temporary: x
}

int main() {

	int& ref = refFunc();
	std::cout << "ref : " << ref << "\n"; // ref: 10

	int* ptr = ptrFunc();
	std::cout << "ptr : " << ptr << "\n"; // ptr : 008FF7A0
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: The return value is the same with the function parameter as an object address (pointer)
```cpp
struct Data {
	int x, y, z;
};

struct Data *func(struct Data *ptr){
	
	//...
	return ptr;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: The return value is the same with the function parameter as an object reference
```cpp
struct Data& reffunc(struct Data &ref) { 

	//...
	return ref;
}
```

/----------------------------------------------
/----------------------------------------------
