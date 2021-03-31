## Dynamic Objects

- The objects are created dynamically and it is not limited ant kind of scope. They can be defined in a specified time range. 

- There are 4 different types of "new" operators in Cpp: 
  - new T   --> delete val  
  - new T[] --> delete val[]
  - new (expr) T
  - new (nothrow)

- It is not common to use "new" operators directly to create an object. Instead, the classes which are using these operators directly such as smart pointer classes (unique_ptr, shared_ptr) are preffered to use. 

- In the cases whenever static or automatic objects do not meet the requirements, in these cases we need dynamic objects.
  - In the case that the number of instances are specified in run-time.
  - In the case that the data type of an instance is specified in run-time. 
  - In the case that a community of different numbers of objects sharing the same resource.

- If there is no need to create a dynamic objects, then it should not be done. Handling dynamic objects is difficult and they are very error-prone. 

- void *operator new(size_t n) --> like as malloc in C

- If an error come out during memory allocation for dynamic objects, then exception handling mechanism kicks in and turns "bad allocation" error.  

- There is no garbage collector mechanism (no related thread doing this). User is responsible to manage dynamic objects, when a dynamic object completes its task, then the user shall delete it and provide to de-allocate the memory. 

- When a dynamic object is created with operator new :  
  - new Member(12, 10, 20); --> It calls two functions, firstly it calls memory allocation function, then calls class contructor 
  (Member*)(operator new (sizeof(Member))); 
  - delete ptr; --> It calls destructor, firstly it calls destructor, then calls operator delete function for memory deallocation. 
    - void operator delete(void *vp)
	- operator new    --> like as malloc function
    - operator delete --> like as free function

- If the object is not deleted, in this case resource leak comes out because of the following reasons: 
  - Destructor is not called
  - operator delete function is not called
  - Dangling pointer or double deletion errors might be came out. 
  
- Resource leak and memory leak are different mechanisms. Resource leak includes memory leak too. The reason of resource leak might be for example not de-allocated memory for dynamic objects.

/----------------------------------------------
/----------------------------------------------

- **Example**: Dangling Pointer (Continuing to use a deleted object)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "point.h"

int main() {

	Point *ptr = new Point(10,20,30);
	Point* ptr2 = ptr;
	ptr->print();

	delete ptr;
	ptr2->print(); // dangling pointer 

	return EXIT_SUCCESS;

	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Double deletion error
  - Usually caused by deleting the copied pointer and then deleting the copied pointer again.

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "point.h"

int main() {

	Point *ptr = new Point(10,20,30);
	Point* ptr2 = ptr;
	ptr->print();

	delete ptr;
	delete ptr2; // double deletion problem

	return EXIT_SUCCESS;

	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Creating Dynamic Objects

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory>

void* operator new(size_t n) {
	std::cout << "operator new called n : " << n << "\n";
	void* vptr = std::malloc(n);
	if (!vptr)
		throw std::bad_alloc{};
	std::cout << "address of allocated block : " << vptr << "\n";
	return vptr;
}

void operator delete(void *vptr) {
	std::cout << "operator delete called vptr : " << vptr << "\n";
	if (vptr)
		std::free(vptr);
}

// point.h
/*--------------------------------------------------------*/
class Point {
public:
	Point() : mx{}, my{}, mz{}{ std::cout << "Point() ctor is called...this : " << this << "\n";}
	Point(int x, int y, int z) :mx{ x }, my{ y }, mz{ z } {
		std::cout << "Point(int x, int y, int z) is called...this : " << this << "\n";
	}
	~Point() { std::cout << "~Point() dtor is called...this : " << this << "\n"; }
	void print()const { std::cout << "[" << mx << ", " << my << ", " << mz << "]\n";}
	void set(const int x, const int y, const int z) {
		this->mx = x;
		this->my = y;
		this->mz = z;
	}
private:
	int mx, my, mz;
};

int main() {

	Point *ptr = new Point(10,20,30);
	// auto *ptr = new Point(10,20,30);
	// Point* ptr = new Point{ 10, 20, 30 };
	// Point* ptr(new Point(10, 20, 30));
	// Point* ptr{ new Point(10, 20, 30) };

	std::cout << "ptr : " << ptr << "\n";
	ptr->print();
	delete ptr;
	
	return EXIT_SUCCESS;
	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**:  delete[] operator

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "point.h"

int main() {

	int n;
	std::cout << "How many elements are there in the array :  ";
	std::cin >> n;
	Point* ptr = new Point[n];

	// delete ptr; --> undefined behaviour
	delete[] ptr;

	return EXIT_SUCCESS;

	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Creating dynamic objects using smart pointers (adding <memory> library)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "point.h"

int main() {

	std::unique_ptr<Point>ptr(new Point(10,20,30));
	return EXIT_SUCCESS;
	/*
		Executed again !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Fighter class based on object oriented design

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string> 
#include<vector> 
#include<algorithm> 

// fighter.h
/*-------------------------------------------------*/
class Fighter {
public:
	Fighter() { msvec.push_back(this); }
	Fighter(const std::string &name, int age) : mname{ std::move(name) }, mage{ age }{
		// the address of instance is stored in a vector 
		msvec.push_back(this);
	}
	~Fighter() {
		// iter type --> std::vector<Fighter>::iterator
		// if iter is found in the vector, if with initializer
		if (auto iter = std::find(msvec.begin(), msvec.end(), this); iter != msvec.end())
			msvec.erase(iter);
		else
			std::cerr << "Not found!!!\n";
	}
	Fighter(const Fighter& ref) = delete;
	Fighter& operator=(const Fighter& ref) = delete;
	int getAge() const { return mage; }
	std::string getName() const { return mname; }
	void kill();
	void run();
	void ask_help();
private:
	std::string mname = "noname";
	int mage = 0;
	inline static std::vector<Fighter*> msvec{};
};

// fighter.cpp
void Fighter::ask_help() {
	// range based for loop
	for (auto ftr: msvec) {
		if(ftr != this) // it is not the object itself
		std::cout << ftr->mname << " ";
	}
	std::cout << "Help!!!\n";
}

// client code
/*-------------------------------------------------*/
int main() {

	// Static objects
	Fighter f1{ "Mehmet", 25 };
	Fighter f2{ "Ayse", 26 };
	Fighter f3{ "Ece", 27 };
	Fighter f4{ "Utku", 30 };

	// Dynamic objects
	auto pf1 = new Fighter{"Selin", 32};
	auto pf2 = new Fighter{"Özge", 33};
	auto pf3 = new Fighter{"Sinem", 34};
	
	delete pf2;
	delete pf3;

	// asking help for the other live fighters
	f2.ask_help();
	return EXIT_SUCCESS;

	/*
		Mehmet Ece Utku Selin Help!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------
