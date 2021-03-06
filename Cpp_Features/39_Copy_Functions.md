
## COPY CONSTRUCTORS & COPY ASSIGNMENT 

## Copy Constructors

- Aynı türden başka bir sınıf nesnesinden kopyalanarak hayata gelen bir nesne için copy ctor çağrılmaktadır.

- The copy ctor written by compiler:
  - public, non-static member function
  - inline member function
  - The declaration of copy ctor --> Data(const Data &ref) = default; 

  - When do we need a copy ctor special member function in a class?
  - T is a class type, x and y are T objects:
    T x = y; --> copy ctor
  - While calling by-value functions 
  - When the return value of a function is a class type, compiler needs to have a temporary object to hold this return value temporarily. In that case, copy ctor is called for this temporary object. 

- Copy constructors are generally written by compiler, not by users. In some specific situations, copy constructors can be coded bu users. 

- If one of copy operations is written by user, move operations are not declared by compiler implicitly. Actually if one of the big three member is written by user, move operations are not declared by compiler implicitly.  

/----------------------------------------------
/----------------------------------------------

- **Example** : When copy constructors shall be written by user?
  - If a class has a pointer type and the copy ctor of this class has been written by compiler, then the pointer types belongs to two different objects Member the same object.
  - If this object is destructed in some way, then the other pointer would be dangling pointer (Members the objects which are no longer exists).

```cpp
class Member {
public:
	// Membering the same object
	Member(const Member& other) : ptr{other.ptr} {}
private:
	int* ptr;
};
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Copy ctor and dangling pointer problem 
  - **dangling pointer** is a kind of runtime error
  -**deep copy**--> Instead of copying pointer, it is the copying of the object itself pointed by the copied pointer to a new allocated memory block. 
  - with deep copying, all pointer have their own memory blocks. 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>

class String {
public:
	String(const char* pstr) : mlenght{ std::strlen(pstr) } {
		mptr = static_cast<char*>(malloc(mlenght + 1));
		if (!mptr)
		{
			std::cerr << "not enough memory...\n";
			std::exit(EXIT_FAILURE);
		}
		std::cout << "ctor is called...this : " << this << "\n";
		std::cout << "the address of allocated block : " << (void*)mptr << "\n";
		std::strcpy(mptr, pstr);
	}
  
	~String() {
		std::cout << "destructor is called...this : " << this << "\n";
		if (mptr)
		{
			std::free(mptr);
		}
		std::cout << "the address of freed block : " << (void*)mptr << "\n";
	}
  
	size_t length()const {
		return mlenght;
	}
  
	void print()const {
		std::cout << "[" << mptr << "]" << "\n";
	}

private:
	size_t mlenght;
	char* mptr;
};

void func(String str) {
	std::cout << "func is called...\n";
	str.print();
	std::cout << "func is ended...\n";
}

int main() {

	String s = "Gamze Efendioglu";
	std::cout << "length : " << s.length() << "\n";
	s.print();

	func(s);   
	_getch(); 
	s.print(); // dangling pointer - runtime error
			   // when func is ended, the the temporary object is destroyed
	           // copy ctor is written by compiler
			   // not a deep copy, Membering the same object 

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Calling of copy constructor

```cpp
class Data {
public:
	Data() : data{ 0 } {}
	Data(const Data& mdata) {}
private:
	int data; 
};

int main() {
	
    Data data1;
    Data data2 = data1; // copy ctor is called 
    Data data3(data1);  // copy ctor is called 
    Data data4{data1};  // copy ctor is called  
	
	  return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Copy ctor with temporary objects   

```cpp
class Data {
public:
	Data() : data{ 0 } {}
	Data(const Data& mdata) {}
	void func(Data mdata);
	~Data() = default;
private:
	int data; 
};

Data gdata;
Data foo() {
	//...
	return gdata; // Temporary object is created here
				        // Copy ctor is called !!!
}

int main() {
	Data kdata;
	kdata.func(kdata);   // copy ctor is called here!!!
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The implementation of copy ctor

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class T {};
class U {};
class X {};

class Data {
public:
	Data() = default;
	// copy ctor 
	Data(const Data& other) :mt{ other.mt }, mu{ other.mu }, mx{ other.mx } {}
private:
	T mt;
	U mu;
	X mx;
};


int main() {

	Data data1;
	Data data2 = data1; // copy ctor is called!

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The implementation of copy ctor 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Member {
public:
	Member() = default;
	Member(const Member& other) :mx{ other.mx }, md{other.md} {
		std::cout << "Member copy ctor is called..." << "\n";
	} 
  
	void print() const {
		std::cout << "mx : " << mx << "\n";
		std::cout << "md : " << md << "\n";
	}
  
	void set(const int ival, const double dval) {
		std::cout << "Setting the object data members..." << "\n";
		this->mx = ival;
		this->md = dval;
	}
private:
	int mx = 10;
	double md = 5.4;
};

int main() {

	Member member1;
	member1.print();
	member1.set(20,6.3);
	member1.print();

	Member member2 = member1; // copy ctor is called!
	member2.print();
	member1.set(30, 10.2);
	member2.print();

	return EXIT_SUCCESS;

	/*
		mx : 10
		md : 5.4
		Setting the object data members...
		mx : 20
		md : 6.3
		Member copy ctor is called...
		mx : 20
		md : 6.3
		Setting the object data members...
		mx : 20
		md : 6.3
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Default and Copy Constructors

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>

class Member {
public:
	Member() {
		std::cout << "Member() default ctor is called...this : " << this << "\n";
	}
	~Member() {
		std::cout << "~Member() dtor is called...this : " << this << "\n";
	}
	Member(const Member& other){
		std::cout << "Member(const Member& other) copy ctor is called...this : " << this << "\n";
		std::cout << "&other : " << &other << "\n";
	}
};

void funcVal(Member mem) {
	std::cout << "funcVal(Member mem) is called...this : " << &funcVal << "\n";
}

void funcRef(Member &mem) {
	std::cout << "funcRef(Member &mem) is called...this : " << &funcRef << "\n";
}

int main() {
	
	Member m1; // Default ctor
	std::cout << "&m1 : " << &m1 << "\n";

	Member m2 = m1; // Copy ctor is called here !!!
		              // m1 is sent as an argument to copy ctor for m2 object
	std::cout << "&m2 : " << &m2 << "\n";

	funcVal(m2); // Copy ctor is called here !!!
		           // m2 is sent as an argument to copy ctor for func(m2) function

	funcRef(m2); // copy ctor is NOT called !!!
				       // three objects: m1, m2, funcVal temp. object 
				 
	return EXIT_SUCCESS;

	/*
		Member() default ctor is called...this : 0135F82B
		&m1 : 0135F82B
		Member(const Member& other) copy ctor is called...this : 0135F81F
		&other : 0135F82B
		&m2 : 0135F81F
		Member(const Member& other) copy ctor is called...this : 0135F72C
		&other : 0135F81F
		funcVal(Member mem) is called...this : 002D1451
		~Member() dtor is called...this : 0135F72C
		funcRef(Member &mem) is called...this : 002D1456
		~Member() dtor is called...this : 0135F81F
		~Member() dtor is called...this : 0135F82B
	*/
}
```

/----------------------------------------------
/----------------------------------------------

## Copy Assignment Function:

- Its another name is **Assignment Operator Function**
- non-static, public, inline class member function

- T is a class type:
  ```cpp
  T mx;
  T my;
  mx = my; --> copy assign. 
  mx.operator=(my);
  ```
  
- The implementation of copy assignment function is like the following (Assuming that Data is a class):
  - Data& operator=(const Data &other){}
  - using **copy & swap** idiom (especially for exception handling)

- When do we need to write copy assignment function manually?
  - Whenever it is a necessity to make a deep copy (compilers make a memberwise copy --> the address of objects are copied, instead of objects themselves).

/----------------------------------------------
/----------------------------------------------

- **Example** : The implementation of copy assignment function

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class T{};
class U{};
class X{};

class Data {
public:
	//copy assignment function (with operator overloading)
	Data &operator=(const Data &other){
		mt = other.mt;
		mu = other.mu;
		mx = other.mx;

		return *this;
	}
	void func() {
		std::cout << "Data::func() is called...this : " << this << "\n";
	}

private:
	T mt;
	U mu;
	X mx;
};

int main() {

	Data data1;
	Data data2;
	data2 = data1; // data2.operator=(data1);
	data2.operator=(data1).func();
	
	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The implementation of copy assignment function

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Counter {
public:
	Counter() = default;
	Counter(int x) : mx{ x } {}
	Counter& operator=(const Counter& other){
		std::cout << "Copy assignment is called...this : " << this << "\n";
		std::cout << "&other : " << &other << "\n";
		this->mx = other.mx;
		return *this;
	}
  
	void func() {
		std::cout << "Counter::func() is called...this : " << this << "\n";
	}
  
	void print()const {
		std::cout << "mx : " << mx << "\n";
	}
  
	void set(const int val) {
		this->mx = val;
	}
private:
	int mx;
};

int main() {

	Counter cnt1{10};
	Counter cnt2{20};

	cnt1.print(); // 10
	cnt2.print(); // 20

	cnt2.operator=(cnt1); // cnt2 = cnt1, copy assign. called
	cnt1.print(); // 10
	cnt2.print(); // 10

	(cnt1 = cnt2).print(); // 10
	// copy assign. is called 
	//--> cnt1.operator=(cnt2).print();
	
	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The implementation of copy assignment function

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Counter {
public:
	Counter() = default;
	Counter(int x) : mx{ x } {}
	Counter& operator=(const Counter& other){
		std::cout << "Copy assignment is called...this : " << this << "\n";
		std::cout << "&other : " << &other << "\n";
		this->mx = other.mx;
		return *this;
	}
private:
	int mx;
};

int main() {

	Counter cnt1{343};
	Counter cnt2{522};
	
	std::cout << "&cnt1 : " << &cnt1 << "\n";
	std::cout << "&cnt2 : " << &cnt2 << "\n";
	cnt2 = cnt1; // cnt2.operator=(cnt1); 
	
	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The implementation of copy assignment
  - The assignment operator returns the object reference, that's why it is a L-Value expression 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Counter {
public:
	Counter() = default;
	Counter(int x) : mx{ x } {}
	Counter& operator=(const Counter& other){
		std::cout << "Copy assignment is called...this : " << this << "\n";
		this->mx = other.mx;
		return *this;
	}
  
	void print()const {
		std::cout << "mx : " << mx << "\n";
	}
private:
	int mx;
};

int main() {

	Counter cnt1, cnt2, cnt3, cnt4;
	Counter cnt5{ 115 };

	//cnt1 = cnt2 = cnt3 = cnt4 = cnt5;
	cnt1.operator=(cnt2.operator=( cnt3.operator=( cnt4.operator=(cnt5))));

	cnt1.print();
	cnt2.print();
	cnt3.print();
	cnt4.print();
	cnt5.print();
	
	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Self assignment (unconsciously)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>

class String {
public:
	String(const char* pstr) : mlenght{ std::strlen(pstr) } {
		mptr = static_cast<char*>(malloc(mlenght + 1));
		if (!mptr) {
			std::cerr << "not enough memory...\n";
			std::exit(EXIT_FAILURE);
		}
		std::cout << "ctor is called...this : " << this << "\n";
		std::strcpy(mptr, pstr);
	}

	~String() {
		std::cout << "destructor is called...this : " << this << "\n";
		if (mptr)
			std::free(mptr);
	}

	// user declared copy contructor
	String(const String& other) : mlenght{ other.mlenght } {
		std::cout << "Copy ctor is called...this : " << this << "\n";
		
    // deep copying 
		mptr = static_cast<char*>(malloc(mlenght + 1));
		if (!mptr) {
			std::cerr << "not enough memory...\n";
			std::exit(EXIT_FAILURE);
		}
		std::strcpy(mptr, other.mptr);
	}

	// user declared copy assignment
	String& operator=(const String& other) {
		// control block for self-assignment 
		if (this == &other)
			return *this; // function is ended directly

    std::cout << "Copy assignment is called...this : " << this << "\n";
		// The assigned object must first return its own resource. 
		free(mptr);

		this->mlenght = other.mlenght;

		// deep copying 
		mptr = static_cast<char*>(malloc(mlenght + 1));
		if (!mptr) {
			std::cerr << "not enough memory...\n";
			std::exit(EXIT_FAILURE);
		}
    
		std::strcpy(mptr, other.mptr);
		return *this;
	}

	void print()const {
		std::cout << "[" << mptr << "]" << "\n";
	}
private:
	size_t mlenght;
	char* mptr;
};

void func(String &str1, String& str2) {
	//...
	str1 = str2;
}

int main() {

	String s2{"Gamze Efendioglu"};
	func(s2, s2); // self-assignment
			          // not a run-time error, because of control blocks in copy assignment function 
	return EXIT_SUCCESS;

	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

## BIG THREE

- The following special member functions consist of big three: 
  - Destructor (related to RAII idiom)
  - Copy Ctor
  - Copy Assignment 

- If you need to write destructor to deallocate the allocated memory block for an object (RAII rule) and if copy ctor and copy assignment functions are written by compiler, then memberwise copy is realized. 
  - For deep copying, it is mandatory to write them by user manually (to allocate different memory blocks for copied objects). 
  - Instead of deep copying, sometimes it is required to delete copy ctor and copy assignment functions (using delete keyword).
    - If these functions are in the private access specifier, they can not be assumed that they are deleted. Because, the other members of the same class can reach end use these functions, has the capability of copying. 

- RAII Idiom (to prevent resource leak): 
  - Resource Acquisition Is Initialization or RAII, is a C++ programming technique which binds the life cycle of a resource that must be acquired before use to the lifetime of an object (resource allocation examples: allocated heap memory, thread of execution, open socket, open file, locked mutex, disk space, database connection—anything that exists in limited supply, etc.).
  - RAII guarantees that all resources are released when the lifetime of their controlling object ends, in reverse order of acquisition.

- If one of the big three member is written by user, move operations are not declared by compiler implicitly.  

/----------------------------------------------
/----------------------------------------------

## BIG FIVE 

- Using instead of Big Three with modern Cpp - C++11

- The following special member functions consist of big five: 
  - Destructor (related to RAII idiom)
  - Copy Ctor
  - Copy Assignment 
  - Move Ctor
  - Move Assignment

/----------------------------------------------
/----------------------------------------------

- **Example** : Not copyable class object

```cpp
class Data {
public:
	Data() = default;
	// not copyable
	Data(const Data&) = delete;
	Data& operator=(const Data&) = delete;
};

int main() {

	Data data1, data2;
	Data data3 = data1; // ERROR, copy ctor is deleted func. 
	data1 = data2; // ERROR, copy assign. is a deleted func.  
	
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------


