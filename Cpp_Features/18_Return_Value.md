## RETURN VALUE 

/----------------------------------------------
/----------------------------------------------

-**Example**: Return value is a pointer 

```cpp
int* ptrFunc() {
	static int number = 10;
	//....
	return &number;
}
```

-**Example**:  return value is reference 

```cpp
int& refFunc() {
	static int number = 10;
	//....
	return number;
}
```

/----------------------------------------------
/----------------------------------------------

-**Example**: When function return value is reference, then the function is a L-Value 

```cpp
#include <iostream>
int command = 45;

int& refFunc() {	return command; }

int main() {

	refFunc() = 100; // refFunc() is a L-Value
	std::cout << "command: " << command << "\n"; // command = 100
  
  int& ref = refFunc();
	ref = 500;
	std::cout << "command : " << command << "\n"; // command : 500
  
}
```
/----------------------------------------------
/----------------------------------------------

-**Example**: When function return value is reference or address --> undefined behaviour

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

### Trailing Return Type (-> return-type)

-**Example**: Trailing Return Type (with auto and decltype keywords)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

template <typename X, typename Y>
auto add(X x, Y y) -> decltype(x + y){
	return x + y;
}

int main() {

	std::cout << "add(1, 2)     : " << add(1, 2)     << "\n";  // 
	std::cout << "add(1, 2.0)   : " << add(1, 2.0)   << "\n";  // 
	std::cout << "add(1.5, 1.5) : " << add(1.5, 1.5) << "\n";  // 

	/*
		add(1, 2)     : 3
		add(1, 2.0)   : 3
		add(1.5, 1.5) : 3
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- Whichever object is taken as a parameter, it can be returned with its address.

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

- The object itself is taken as a parameter and the return value is itself. 

```cpp
struct Data& reffunc(struct Data &ref) { 
	//...
	return ref;
}
```

/----------------------------------------------
/----------------------------------------------
