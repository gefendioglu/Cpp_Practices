## MOVE CONSTRUCTORS & MOVE ASSIGNMENTS

## Move Constructors (with C++11): 

- **Persistent Object**: If an object is a L-Value expression, then it is persistent object. In that case, the resources of these kind of objects shall not be stolen.
  - **copy ctor** is called for persistent objects 

- **Non-Persistent Object**: If an object is a R-Value expression (PR-Value or X-Value), then it is non-persistent object. In that case, the resources of these kind of objects can be stolen. Cause, these objects are not going to be used in the remaining part of the program. 
  - **move ctor** is called for non-persistent objects 
 
/----------------------------------------------
/----------------------------------------------

## Move Assignment (with C++11): 

- The implementation of move assignment (non-static, public, inline): 
  - Data& operator=(Data&&); 

- std::move() function is not moving an object, it is casting the object's type to R-Value reference type 

- The important section of the following book: 
  - Scott Meyers - Effective Modern C++
    - Item 23: Understand std::move and std::forward.
	- Item 17: Understand special member function generation.
	- " Generated special member functions are implicitly public and inline, and they’re non-virtual unless the function is a destructor in a derived class inheriting from a base class with a virtual destructor. In that case, the compiler-generated destructor for the derived class is also virtual. "

- "Move operations are generated only for classes lacking explicitly declared **move operations**, **copy operations**, and a **destructor**." - Scott Meyers

- If one of move operations is written by user, copy operations are deleted implicitly. 

/----------------------------------------------
/----------------------------------------------

- **Example** : R-Value and L-Value References with functions  
  - R Value References were added to the language to allow the objects to be moved to other objects. 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() = default;
};

// const L-Value Reference
// viable for both R-Value and L-Value calling 
void func(const Data&) {
	std::cout << "func(const Data &) is called...\n";
}

// R-Value Reference
// viable only R-Value calling
// when calling with R-Value, this function is called according to function overload resolution rules
void func(Data&&) {
	std::cout << "func(Data&&) is called...\n";
}

int main() {

	Data data;
	func(data);   // func(const Data &) is called...
	func(Data{}); // func(Data&&) is called...
		      // Data{} --> temp. object, PR-Value Expr.

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : R-Value and L-Value References with functions 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() = default;
	Data(const Data&); // copy ctor 
	Data(Data&&);      // move ctor 
private:
};

// L-Value Reference Parameter
void func(const Data& ref) {
	std::cout << "func(const Data& ref) is called...\n";
}

// R-Value Reference Parameter
void func(Data&& ref) {
	std::cout << "func(Data&& ref) is called...\n";
}

int main() {

	Data data1;
	func(data1); // L-Value ref.
		     // func(const Data& ref) is called...
	func(static_cast<Data&&>(data1)); // R-Value ref.
					  // func(Data&& ref) is called...
	func(std::move(data1)); // R-Value ref.
				// func(Data&& ref) is called...
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : R-Value and L-Value References with functions called in other functions

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data{
public:
	Data() = default;
};

void func(Data&& ref) {
	std::cout << "func(Data&& ref) is called...\n";
}

void func(const Data& ref) {
	std::cout << "func(const Data& ref) is called...\n";
}

void foo(const Data& ref){
	func(ref);
}

void foo(Data&& ref) {
	func(std::move(ref));
}

int main(){

	Data data;
	foo(data);   // func(const Data& ref) is called... 
	foo(Data{}); // func(Data&& ref) is called...

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Move operations (move ctor, move assignment) 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class T {};
class U {};
class X {};

class Data {
public:
	Data() = default;

	// copy constructor
	Data(const Data& other): mt{ other.mt }, 
				 mu{other.mu }, 
				 mx{ other.mx } {
		std::cout << "copy ctor is called...\n";
	}

	// move constructor
	Data(Data&& other) : mt{ std::move(other.mt) }, 
			     mu{ std::move(other.mu) }, 
			     mx{std::move(other.mx)} {
		std::cout << "move ctor is called...\n";
	}

	// move assignment 
	Data& operator=(Data&& other){

		std::cout << "move assignment is called...\n";
		this->mt = std::move(other.mt);
		this->mu = std::move(other.mu);
		this->mx = std::move(other.mx);

		return *this;
	}
private:
	T mt;
	U mu;
	X mx;
};

int main() {

	Data data1;
	Data data2{ data1 }; // data1 is a L-Value expr.
			     // copy ctor is called...

	Data data3{ std::move(data1) }; //std::move(data1) is a R-Value expr.
					// move ctor is called...
					// data1 resource is stolen!!
	Data data4;
	data4 = std::move(data2); // move assignment is called...
	
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Move and copy operations in a user defined String class
  - Copy ctor and copy assignment implementations without dangling pointer problem by the help of user declared copy constructor.
  - Whenever a need comes out to allocate memory block (if there is an in-class pointer), the copy ctor of this class shall be declared by user.

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>

class String {
public:
	// there is no default constructor 
	String(const char* pstr) : mlength{ std::strlen(pstr) } {
		mptr = static_cast<char*>(malloc(mlength + 1));
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

	// user declared copy contructor
	String(const String& other) : mlength{other.mlength } {
		std::cout << "Copy ctor is called...this : " << this << "\n";
		
		// deep copying 
		mptr = static_cast<char*>(malloc(mlength + 1));
		if (!mptr)
		{
			std::cerr << "not enough memory...\n";
			std::exit(EXIT_FAILURE);
		}
		std::cout << "the address of allocated block : " << (void*)mptr << "\n";
		std::cout << "other.mptr : " << (void*)other.mptr << "\n";
		std::strcpy(mptr, other.mptr);
	}

	// user declared copy assignment
	String& operator=(const String& other) {
		// if the object is assigned to itself
		// if the argument address and the address of object calling this function 
		if (this == &other)
		{
			return *this; // function is ended directly
		}

		std::cout << "Copy assignment is called...this : " << this << "\n";
		// The assigned object must first return its own resource. 
		free(mptr);

		this->mlength = other.mlength;
		
		// deep copying 
		mptr = static_cast<char*>(malloc(mlength + 1));
		if (!mptr)
		{
			std::cerr << "not enough memory...\n";
			std::exit(EXIT_FAILURE);
		}
		std::cout << "the address of allocated block : " << (void*)mptr << "\n";
		std::cout << "other.mptr : " << (void*)other.mptr << "\n";
		std::strcpy(mptr, other.mptr);

		return *this;
	}

	// user declared move constructor
	String(String&& other) : mlength{ std::move(other.mlength) }, mptr{std::move(other.mptr)} {
		std::cout << "Move ctor is called...this : " << this << "\n";
		other.mptr = nullptr;
	}

	// user declared move assignment 
	String& operator=(String&& other) {
		
		// controlling the self-assginment, like in copy assign. func.  
		if (this == &other) 
			return *this;
		
		std::cout << "Move assignment is called...this : " << this << "\n";
		this->mlength = std::move(other.mlength);
		 
		// firstly the source of mptr is given 
		std::free(mptr);
		
		// then, the source of other object is stolen
		this->mptr = std::move(other.mptr);
		other.mptr = nullptr;
		
		return *this;
	}

	size_t length()const {
		return mlength;
	}

	void print()const {
		std::cout << "[" << mptr << "]" << "\n";
	}
private:
	size_t mlength;
	char* mptr;
};

void func(String str) {
	std::cout << "func is called...\n";
	str.print();
	std::cout << "func is ended...\n";
}

int main() {

	String s1 = "Gamze Efendioglu";
	s1.print();
	std::cout << "\n\n";
	
	func(s1);  // copy ctor is called !!!
	s1.print(); 
	std::cout << "\n\n";
	
	String s2 = "Mehmet Efendioglu";
	s2.print();
	std::cout << "\n\n";

	s2 = s1;   // copy assignment is called here !!!
	s2.print();
	std::cout << "\n\n";

	s2 = s2; // self-assignment --> results in run-time error
		 // there should be a control in copy assignment
	std::cout << "\n\n";

	String s3{ "Hakan" }, s4{ "Sema"};
	String s5 = std::move(s3); // move ctor
	s4 = std::move(s5);        // move assignm.
	std::cout << "\n\n";

	return EXIT_SUCCESS;

	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------
