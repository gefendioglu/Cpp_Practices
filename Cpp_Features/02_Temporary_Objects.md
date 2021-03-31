### Temporary Objects:

- After using a temporary object (after evaluating the related row about it), its destructor is called to destroy the object. Each time its constructors are called, whenever a temporary object is created like as a normal object. 

- Sometimes compiler creates a temporary object implicitly, and sometimes user orients the compiler to create a temporary object. 

- Temporary objects are important in terms of efficiency.

- Temporary objects can be linked to  R-Value and const L-Value references. They are not linked to non-const L-Value expressions. 

- Temporary objects are not named, they only include their type names.

- const L-value references can be linked to temporary objects. In that case, the life of temporary objects extended till the end of reference scope (life extension)
  - const Data& ref = Data{ 12 };

- Temporary objects are also used as a return value of a function.

/----------------------------------------------
/----------------------------------------------

- **Example** : Temporary Class Objects 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data(): mx{ 0 }, my{ 0 } { std::cout << "Data() default ctor is called...\n"; };
	Data(int x) : mx{ x }, my{ 0 }{	std::cout << "Data(int x) ctor is called...\n";	}
	Data(int x, int y) : mx{ x }, my{ y }{ std::cout << "Data(int x, int y) ctor is called...\n"; }
	~Data() { std::cout << "~Data() destructor is called...\n"; }
	void print()const { std::cout << "mx : " << mx << " my : " << my << "\n"; }
private:
	int mx,my;
};

void func(const Data &ref) { std::cout << "func(const Data& ref) is called...\n"; }
void func(Data&& ref) {	std::cout << "func(Data&& ref) is called...\n"; }

int main() {

	// All the followings are temporary objects
	// They can call directly their class member functions
	Data{}.print();        // Data{} --> PR-Value expr.
	Data{ 12 }.print();    // Data{12} --> PR-Value expr.
	Data{ 12,25 }.print(); // Data{12,25} --> PR-Value expr.

	std::cout << "\n";
	const Data& ref = Data{ 12 };
	
	std::cout << "\n";
	Data data;
	func(data); // data is L-Value expr.
		    // func(const Data &ref) is called

	std::cout << "\n";
	func(Data(15)); // Data(15) is a  PR-Value expr. 
			// Data(15) can be linked to const L-Val.
			// Data(15) can be linked to R-Val.
			// both func() are viable (?)
	
	return EXIT_SUCCESS;
	
	/*
		Data() default ctor is called...
		mx : 0 my : 0
		Data(int x) ctor is called...
		mx : 12 my : 0
		Data(int x, int y) ctor is called...
		mx : 12 my : 25
		~Data() destructor is called...

		Data(int x) ctor is called...

		Data() default ctor is called...
		func(const Data& ref) is called...
		
		Data(int x) ctor is called...
		func(Data&& ref) is called...
		~Data() destructor is called...
		~Data() destructor is called...
		~Data() destructor is called...
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Temporary objects as function return value and as arguments sent to a function  

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

void func(const std::string& ref) { std::cout << "string : " << ref << "\n"; }

std::string func() {
	char c = 'B';
	//...
	return std::string(100, c); // temp. object 
}

int main() {

	// calling func(const std::string& ref) with temp. object
	func(std::string(100, 'A')); 
	
	std::cout << "\n";
	func();

	return EXIT_SUCCESS;
	/*
		Executed again!!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------
