
## SMART POINTERS

- Smart pointers have a structure called "exclusive ownership".

- Smart pointer classes are not copyable, but movable. It means copy constructor and copy assginment functions are deleted. 

- The pointers created using smart pointer classes can not be copied to the other pointers (protected against double deletion error). 

// --------------------------------------------
// --------------------------------------------

- **Example**: Smart pointer class (with/without templates)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class SmartPtr {
public:
	explicit SmartPtr(int* p = NULL) { ptr = p; }
	~SmartPtr() { delete (ptr); }

	// Overloading dereferencing operator 
	int& operator*() { return *ptr; }

private:
	int* ptr; // Actual pointer 
};

// A generic smart pointer class 
template <class T>
class SmartPtrTemp {
public:
    explicit SmartPtrTemp(T* p = NULL) { ptr = p; }

    // Destructor 
    ~SmartPtrTemp() { delete (ptr); }

    // Overloading dereferencing operator 
    T& operator*() { return *ptr; }

    // Overloading arrow operator 
    T* operator->() { return ptr; }

private:
    T* ptr; 
};

int main(){

	SmartPtr ptr(new int());
	*ptr = 20;
	std::cout << *ptr;

    SmartPtrTemp<int> ptr(new int());
    *ptr = 20;
    std::cout << *ptr;

	return 0;
}
```

// --------------------------------------------
// --------------------------------------------

- **Example**: Smart Pointers with their deleted copy ctor and copy assignment functions

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include "point.h" 

int main() {

	std::unique_ptr<Point>ptr1(new Point(10,20,30));
	std::unique_ptr<Point>ptr2(new Point(10,20,30));

	// SYNTAX ERROR, copy assignment func is deleted for smart pointers
	ptr1 = ptr2; 

	// SYNTAX ERROR, copy ctor is deleted for smart pointers
	std::unique_ptr<Point>ptr3 = ptr1;

	// NOT ERROR, move ctor is defined for smart pointers 
	auto ptr4 = std::move(ptr1);

	// NOT ERROR, move assignment function is defined for smart pointers 
	ptr1 = std::move(ptr2);

	return EXIT_SUCCESS;
}
```

// --------------------------------------------
// --------------------------------------------

- **Example**: The effect of smart pointers on a class

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory>

// Member class is non-copyable, but movable
// due to the existence of smart pointer as a data member
class Member {
public:
	Member() = default;
	std::unique_ptr<std::string> uptr;
};

int main() {

	Member mem1, mem2;
	Member mem3 = mem2; // SYNTAX ERROR 
	mem3 = mem2;        // SYNTAX ERROR

	Member mem4 = std::move(mem2); // NOT ERROR
	mem4 = std::move(mem1);		     // NOT ERROR
	
	return EXIT_SUCCESS;
}
```

// --------------------------------------------
// --------------------------------------------

- **Example**: Function calling with smart pointers

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>
#include "point.h" 

// Member class is non-copyable, but movable
class Member {
public:
	Member() = default;
	std::unique_ptr<std::string> uptr;
};

void func(std::unique_ptr<Point> uptr);
void foo(Member mem);

int main() {

	Member mem;
	foo(std::move(mem)); // NOT ERROR
	foo(mem);            // SYNTAX ERROR

	std::unique_ptr<Point> uptr{ new Point{1,2,3} };
	func(std::move(uptr));  // NOT ERROR
	func(uptr);				// SYNTAX ERROR

	return EXIT_SUCCESS;
}
```

// --------------------------------------------
// --------------------------------------------

- **Example**: "unique_ptr" class 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <memory> 

class Rectangle {
public:
	Rectangle(int l, int b){
		length = l;
		breadth = b;
	}
	int area()	{	return length * breadth; }
  
private:
	int length;
	int breadth;
};

int main(){

	std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	std::cout << P1->area() << "\n"; // 50 

	//std::unique_ptr<Rectangle> P2(P1); // not copyable
	std::unique_ptr<Rectangle> P2;       // but movable
	P2 = std::move(P1);                  // Transferring ownership
	std::cout << P2->area() << "\n";     // 50

	// std::cout<<P1->area()<<"\n"; // not reachable
	return 0;
  
}
```

// --------------------------------------------
// --------------------------------------------

- **Example**: "shared_ptr" class

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <memory> 

class Rectangle {
public:
	Rectangle(int l, int b){
		length = l;
		breadth = b;
	}
	int area()	{	return length * breadth; }  
  
private:
	int length;
	int breadth;
};

int main(){

	std::shared_ptr<Rectangle> P1(new Rectangle(10, 5));
	std::cout << P1->area() << "\n"; // 50 

	std::shared_ptr<Rectangle> P2;
	P2 = P1; // copy assignment function is called
	std::cout << P2->area() << "\n"; // 50 
	std::cout << P1->area() << "\n"; // 50 - not give an error

	// print 2 as Reference Counter is 2 
	std::cout << P1.use_count() << "\n"; // 2

	return 0;
  
}
```

// --------------------------------------------
// --------------------------------------------

- **Example**: "weak_ptr" class

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <memory> 

std::shared_ptr<int> p1 = std::make_shared<int>(5);
std::weak_ptr<int> wp1{ p1 };  // p1 owns the memory
std::shared_ptr<int> p3 = wp1.lock();
```

// --------------------------------------------
// --------------------------------------------

- **Example**: De-allocation of memory

```cpp
int main() {

	int* ptr = (int*)malloc(sizeof(int));

	// Deallocating a memory pointed by ptr causes dangling pointer 
	free(ptr);

	// No more a dangling pointer 
	ptr = nullptr;
  
}
```

// --------------------------------------------
// --------------------------------------------

- **Example**: Function Call with smart pointers

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

int* fun(){

	// x is local variable and goes out of scope after an execution of fun() is over. 
	int x = 5;

	// warning:  returning address of local variable or temporary: x
	return &x; 
}

int main() {

	int* p = fun();
	fflush(stdin);

	// p points to something which is not valid anymore, but Cpp compiler wont give an error and prints 5 
	std::cout << *p << "\n";
	std::cout << p << "\n";

	return 0;
}
```

// --------------------------------------------
// --------------------------------------------

- **Example**: The above problem doesn’t appear (or p doesn’t become dangling) if x is a static variable.

```cpp
int* fun(){
	// x has scope throughout the program 
	static int x = 5;
	return &x; 
}

int main() {

	int* p = fun();
	fflush(stdin);

	// p Members to something which is not valid anymore 
	std::cout << *p << "\n";
	std::cout << p << "\n";

	return 0;
}
```

// --------------------------------------------
// --------------------------------------------

