## TYPE CONVERSION

- C++ Data Conversion Types:
	- static_cast
	  - int ival; --> static_cast<double>(ival);
	- const_cast
	- reinterpret_cast
	- dynamic_cast

- The type conversion between different address types:
	- The data type and pointer type shall be compatible to each other, C++ --> error
	- The data type and pointer type shall be compatible to each other, C   --> warning
	
- No type conversion between pointer types automatically in C++
	- T* --> U* (T and U are two different data type)
       
- The type conversion rules for const address types (const int *):
  -  C   --> The type conversion from const address data types to non-const address data types is OK.
  -  C++ --> No type conversion from const address data types to non-const address data types. 
		 - const T* --> T* (NOT OK)

   -  C   --> The type conversion from non-const address data types to const address data types is OK.
   -  C++ --> The type conversion from non-const address data types to const address data types is OK.
		  - T* --> const T* (OK)
 
- The type conversion for void pointer:
	- C++ --> T* --> void T* (OK) 
	- C++ --> void T* --> T* (OK)
	- C   --> void T* --> T* (NOT OK)
    
/----------------------------------------------
/----------------------------------------------

- **Example** : CPP --> No conversion from arithmetic types to enum types automatically

```cpp
#include <iostream>

enum Color{White, Gray, Black};

int main() {
	enum Color mycolor = Gray;
	mycolor = (Color)2;	// mycolor = 2; --> is OK in main.c
	std::cout << "mycolor: " << mycolor << "\n"; // mycolor: 2
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : CPP --> No conversion between different enum types automatically 

```cpp
#include <iostream>

enum Color{White, Gray, Black};
enum Position{OFF, ON};

int main() {
	enum Color myColor = Gray;     // --> Gray : 1
	enum Position myPosition = ON; // --> ON : 0
	myColor = (Color)myPosition;   // mycolor = myPosition; --> is OK in main.c

	std::cout << "myPosition: " << myPosition << "\n"; // myPosition: 1
	std::cout << "myColor: " << myColor << "\n";       // myColor: 1
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : CPP --> The conversion from enum types to the other types is OK 
	- For example: enum --> int 

```cpp
#include <iostream>

enum Color{White, Gray, Black};
enum Position{OFF, ON};

int main() {
	enum Color myColor = Black;     // --> Gray : 2
	enum Position myPosition = OFF; // --> OFF : 0
	int number1 = myColor;
	int number2 = myPosition;
	
  std::cout << "number1: " << number1 << "\n"; // number1: 2 --> myColor
	std::cout << "number2: " << number2 << "\n"; // number2: 0 --> myPosition
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - C    --> The conversion from pointer types to arithmetic types is OK 
  - C ++ --> No conversion from pointer types to arithmetic types automatically
  
```cpp
#include <iostream>

int main() {
	int x = 0;
	int* ptr = &x; // int* ptr = x;     --> OK, warning in main.c 
				         // int number = ptr; --> OK, warning in main.c 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The type conversion between different address types

```cpp
#include <iostream>

int main() {
	int x = 10;
	// double* ptr = &x; --> C++ a value of type cannot be used to initialize an entity of type
	// double* ptr = &x; --> C warning C4133 : incompatible types from 'int*' to 'double*'
	double* ptr = (double*)&x;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The data types for addresses

```cpp
#include <iostream>

int main() {
	int x = 10;
	// &x --> the data type of x : int*

	int primes[10] = {};
	// &primes --> the data type of primes array : int* (array decay)

	const int cx = 10;
	// &cx --> the data type of cx : const int*

	int const icx = 10;
	// &icx --> the data type of cx : const int* (like the previous one)

	const int cprimes[10] = {};
	// &cprimes --> the data type of cprimes array : const int* 
	
	char name[6] = "gamze";	
	// string literals in C
	// &name --> the data type of name : char* in C

	const char cname[6] = "gamze";	
	// string literals in C++ 
	// &cname --> the data type of cname : const char* in C++ 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The type conversion rules for const address types 

```cpp
#include <iostream>

int main() {
	int x = 10;
	const int *cptr = &x; // T* --> const T* (OK)
	
  const char* name = "Gamze Efendioglu";
	// char* name = "Gamze Efendioglu"; --> Error in main.cpp, not Error in main.c
	// Error C2440 'initializing': cannot convert from 'const int *' to 'int *'	
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The type conversion for void pointer:

```cpp
#include <iostream>

int main() {
	int ival = 10;
	unsigned int uval = 20;
	double dval = 5;
	char str[] = "gamze";

	// T* --> void T* (OK) in main.cpp
	void* vptr = &ival; // void pointer 
	vptr = &uval;
	vptr = &dval;
	vptr = str;

	// void T* --> T* (NOT OK) in main.cpp
	// int* iptr = vptr;
	// Error E0144: a value of type "void *" cannot be used to initialize an entity of type "int *
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>
#include <stdlib.h>

int main() {
	size_t n;
	// int* iptr = malloc(n * sizeof(int)); // NOT OK --> 
	int* iptr = (int*)malloc(n * sizeof(int));
}
```
/----------------------------------------------
/----------------------------------------------

- **Example** : C++ Type Conversion

```cpp
#include <iostream>
#include <ctime>

int main(){
    int x, y;
    srand(static_cast<unsigned int>(time(nullptr)));
    std::cin >> x >> y;

    static_cast<double>(x) / y;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : C Type Conversion Problem

```cpp
#include <iostream>

int main(){
    int x = -1; 
    unsigned int y = 1;
    if (x > y)
        std::cout << "True\n"; // return True (why?)
    else
        std::cout << "False\n";
}
```

/----------------------------------------------
/----------------------------------------------
```cpp
#include <iostream>

int main(){
    char c = 178; 
    if (c ==178)
        std::cout << "True\n";
    else
        std::cout << "False\n"; // return False  (why?)
}
```
/----------------------------------------------
/----------------------------------------------

- **Example** : C Type Comversion Problem 

```cpp
#include <iostream>

char* StrChr(const char* p, int c) {
	while (*p) {
		if (*p == c)
			return const_cast<char*>(p);
	}
    ++p;
	// warning C4715: 'StrChr': not all control paths return a value
}

int main() {
	char c = 178;
	// warning C4309: 'initializing': truncation of constant value
	if (c == 178)
		std::cout << "True\n";
	else
		std::cout << "False\n"; // return False 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : If the other type conversion structure is used rather than reinterpret_cast, then it return a syntax error 
  - ++i --> prefix operator shall be preferred instead of postfix operator 

```cpp
#include <iostream>

int main(){
	double dval = 324.2354;
	unsigned char* p = reinterpret_cast<unsigned char*>(&dval); // OK!!!
	unsigned char* p = const_cast<unsigned char*>(&dval);  // NOT OK!!!
	unsigned char* p = static_cast<unsigned char*>(&dval); // NOT OK!!!
	
  for (size_t i = 0; i < sizeof(dval); ++i)
		std::cout << p[i] << " ";
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Type Conversion Problems

```cpp
#include <iostream>
enum Color{Black, White, Green};

int main(){
	Color mycolor{Green};
	mycolor = 3; // ERROR !!!
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>
enum Color{Black, White, Green};

int main(){
	Color mycolor{Green};
	int ival = 2;
	//mycolor = ival; // ERROR !!!
	mycolor = static_cast<Color>(ival); // NOT ERROR !!!
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>
#include <cstdlib>

int main(){
	size_t n = 10000;
	char* p = malloc(n); // ERROR
	char* p = static_cast<char*>(malloc(n)); // NOT ERROR
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Two different conversion can not be realized at the same time

```cpp
#include <iostream>

int main(){
	const double* ptr = nullptr;
	char* p = const_cast<char*>(ptr);       // ERROR
	char* p = reinterpret_cast<char*>(ptr); // ERROR
	
	// The source of error: 
	// 1 - non-const --> const conversion
	// 2 - double*   --> char* conversion 

	// The solution is to mix both these type conversions: 
	const_cast<char*>(reinterpret_cast<const char*>(ptr)); // OK
	reinterpret_cast<char*>(const_cast<double*>(ptr));     // OK
}
```

/----------------------------------------------
/----------------------------------------------

### CONVERSION CONSTRUCTOR

- Conversion constructors convert a non-class argument to a class type.
  - variadic conversion is the low level 
  - user defined conversion is the next level of variadic conversion
  - std::string str;
    std = "Gamze"; --> conversion ctor 

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of conversion constructor 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data{
public:
	Data() = default;
	Data(int) {};
};

int main(){
	Data data;
	data = 10; // data.operator=(Data{10});
			   // operator overloading and copying temp. object
			   // ERROR, without Data(int) ctor 
			   // creating Data{10} temp. object
			   // int --> Data type conversion 

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of conversion constructor 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() : mx{ 0 } {
		std::cout << "Data() default ctor is called...this : " << this << "\n";
	}

	Data(int x) : mx{ x } {
		std::cout << "Data(int x) is called...this : " << this  << "\n";
		std::cout << "x: " << x << "\n\n";
	};

	Data& operator=(const Data& other) {
		std::cout << "copy assginment is called...this : " << this << "\n";
		std::cout << "&other : " << &other << "\n\n";
		this->mx = other.mx;
		return *this;
	}

	~Data() {
		std::cout << "~Data() dtor is called...this : " << this << "\n";
	}

private:
	int mx;
};

int main() {
	Data data;
	data = 10; // data.operator=(Data{10});

	// first destructor is called for temp. object
	// the last destructor is called for data object

	return EXIT_SUCCESS;
	/*
		To be Executed again!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

### CONSECUTIVE TYPE CONVERSIONS (Conversion Sequence)

- The following conversion types are realized by compilers implicitly:
  - First: Standard conversion + Second: user defined conversion  
  - First: user defined  conversion + Second: Standard conversion 

- Consecutive user defined conversions  are not allowed by compilers 
  - First: user defined conversion + Second: user defined conversion

/----------------------------------------------
/----------------------------------------------

- **Example** : Consecutive Type Conversions

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() : mx{ 0 } {}
	Data(int x) : mx{ x } {};
	Data& operator=(const Data& other) {
		this->mx = other.mx;
		return *this;
	}
	~Data() {}
private:
	int mx;
};

void func(Data data);
void foo(const Data& ref);
void f(Data& ref);

Data gData() {
	return 10; // conversion ctor as a return value
}

int main() {
	Data data;
	data = 5.2; // First : double --> int conversion 
				// Second: int --> Data class type conversion
	
	int ival = 20.5;
	func(20.5); // First : double --> int conversion 
				// Second: int --> Data class type conversion
	
	foo(ival);  // NOT ERROR
	f(ival);    // ERROR, temporary object is a R-Value expr.
	            // Temp. object can not be linked to non-const L-Value ref.

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

### EXPLICIT CONSTRUCTORS 

- It prevents to make a conversion ctor implicitly. It forces to use casting operators  

- explicit ctor is created using **explicit** keyword

- If the definition of an explicit ctor is applied in .cpp file, the keyword of **explicit** shall not be used. In this case, this keyword exists as ctro declaration in class. 

- If the inline definition of an explicit ctor is applied, so **explicit** keyword has already been used in this definition.
 
- **explicit ctor** also prevents copy initialization for a class object. 

- The vector and smart pointer classes of standard library have explicit constructors. Copy initialization is not allowed for the values has these class types.

/----------------------------------------------
/----------------------------------------------

- **Example** : Before applying explicit constructor

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class Data {
public:
	Data() : mx{ 0 } {}
	explicit Data(int x) : mx{ x } {};
	Data& operator=(const Data& other) {
		this->mx = other.mx;
		return *this;
	}
	~Data() {}
private:
	int mx;
};

void func(Data data);
void foo(const Data& ref);
void f(Data& ref);

Data gData() {
	return 10; // ERROR --> explicit ctor
}

int main() {
	Data data;
	data = 10;   // ERROR --> explicit ctor
	
	int ival = 20;
	func(ival);  // ERROR --> explicit ctor
	foo(ival);   // ERROR --> explicit ctor
	f(ival);     // ERROR --> explicit ctor

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : After applying explicit constructor

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() : mx{ 0 } {}
	explicit Data(int x) : mx{ x } {};
	Data& operator=(const Data& other) {
		this->mx = other.mx;
		return *this;
	}
	~Data() {}
private:
	int mx;
};

void func(Data data);
void foo(const Data& ref);

Data gData() {
	return 10; // ERROR --> explicit ctor
	return static_cast<Data>(10); // NOT ERROR
}

int main() {
	Data d;
	Data data = 20; // ERROR --> copy init is not allowed
	func(20);       // ERROR --> copy init is not allowed
	
	data = 10;   // ERROR --> explicit ctor
	data = static_cast<Data>(10);   // NOT ERROR
	
	int ival = 20;
	func(ival);  // ERROR --> explicit ctor
	func(static_cast<Data>(ival));  // NOT ERROR 
	
	foo(ival);   // ERROR --> explicit ctor
	foo(static_cast<Data>(ival));   // NOT ERROR 
	
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Before applying explicit constructor

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() = default;
	Data(int x, int y) : mx{ x }, my{ y } {};
	Data& operator=(const Data& other) {
		this->mx = other.mx;
		this->my = other.my;
		return *this;
	}
	~Data() {}
	void print()const {
		std::cout << "mx : " << mx << " my : " << my << "\n";
	}
private:
	int mx = 0, my = 0; // default member init. 
};

int main() {
	Data data;
	data = { 12, 42 }; // data = Data{ 12, 42 };
	data.print();

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : After applying explicit constructor

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() = default;
	explicit Data(int x, int y) : mx{ x }, my{ y } {};
	Data& operator=(const Data& other) {
		this->mx = other.mx;
		this->my = other.my;
		return *this;
	}
	~Data() {}
	void print()const {
		std::cout << "mx : " << mx << " my : " << my << "\n";
	}
private:
	int mx = 0, my = 0; // default member init. 
};

Data func() {
	//...
	return {}; // return temp. object calling default ctor 
}

int main() {
	Data data;
	data = { 12, 42 }; // ERROR --> explicit ctor

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The classes of standard library that have explicit ctor (For example: std::vector and std::unique_ptr) 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <memory>

int main() {
	std::vector<int> ivec(100); // size_t type
	std::cout << "ivec.size() : " << ivec.size() << "\n";
	std::vector<int> myVec = 20; // explicit ctor --> ERROR

	std::unique_ptr<int> uptr(new int);
	std::unique_ptr<int> myPtr = new int; // explicit ctor --> ERROR

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Explicit default ctor 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	explicit Data() = default;
	explicit Data(int x, int y) : mx{ x }, my{ y } {};
	Data& operator=(const Data& other) {
		this->mx = other.mx;
		this->my = other.my;
		return *this;
	}
	~Data() {}
private:
	int mx = 0, my = 0; // default member init. 
};

int main() {
	Data data = {};
	// 'Data': no appropriate default constructor available

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Explicit ctor and viable functions

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() = default;
	explicit Data(int x) : mx{ x }{
		std::cout << "Data(int x) is called...\n";
	}
	Data(double d) : md{ d }{
		std::cout << "Data(double x) is called...\n";
	}
private:
	int mx = 0;
	double md = 0.0;
};

int main() {
	int ival = 10;
	Data data(ival);    // Data(int x) is called...
	Data myData = ival; // Data(double x) is called...
						// Data(int x) is not viable, because of explicit ctor 

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Consecutive class type assignment

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class A {
public:
	A() = default;
};

class B {
public:
	B() = default;
	B(A a) : ma{ a } {}
private:
	A ma;
};

class C {
public:
	C() = default;
	C(B b) : mb{ b } {}
private:
	B mb;
};

int main() {
	A myAdata;
	B myBdata;
	C myCdata;

	myBdata = myAdata;
	myCdata = myBdata;

	myCdata = myAdata; // ERROR
	// binary '=': no operator found which takes a right-hand operand of type 'A' (or there is no acceptable conversion)
	myCdata = static_cast<C>(static_cast<B>(myAdata)); // NOT ERROR

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------
