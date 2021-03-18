#pragma once

// User Defined Literals
// --------------------------------------------
// --------------------------------------------
#ifdef USER_DEFINED_LITERALS 

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

using ull = unsigned long long;
constexpr ull operator"" _KB(ull no) {
	return no * 1024;
}
constexpr ull operator"" _MB(ull no) {
	return no * (1024_KB);
}

int main() {

	std::cout << 1_KB << "\n";
	std::cout << 5_MB << "\n";
}
#endif // USER_DEFINED_LITERALS 

// Uniform Initialization
// Non-static Member Initialization
// --------------------------------------------
// --------------------------------------------

#ifdef NON_STATIC_MEMBER_INIT

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class demo {
public:
	demo(uint32_t ival, bool bval, std::string sval, float fval) : m_ival{ ival }, m_bval{ bval }, m_sval{ sval },
		m_fval{ m_fval } {}
private:
	// non-static member initialization
	uint32_t m_ival = 0;
	bool m_bval = false;
	std::string m_sval = "";
	float m_fval = 0.0;
};

int main() {
	// uniform initialization
	demo obj{ 123, true, "lol", 1.1 };
	return EXIT_SUCCESS;
}

#endif // NON_STATIC_MEMBER_INIT

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Forward Declaration
// --------------------------------------------
// --------------------------------------------

#ifdef FORWARD_DECLARATION

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Forward Declaration for class A
class A;

class B {
public:
	void setData(int mdata) {
		mx = mdata;
	}

	// Forward declaration is required for the parameters of sum func. 
	friend int sum(const A&, const B&);
private:
	int mx;
};

class A {
public:
	void setData(int mdata) {
		my = mdata;
	}
	friend int sum(const A&, const B&);
private:
	int my;
};

int sum(const A& m, const B& n) {
	return (m.my + n.mx);
}

int main() {

	B b;
	A a;

	a.setData(5);
	b.setData(4);
	std::cout << "The sum is : " << sum(a, b);
	// The sum is : 9

	return EXIT_SUCCESS;
}

#endif // FORWARD_DECLARATION

// std::initializer_list
// --------------------------------------------
// --------------------------------------------

#ifdef INITIALIZER_LIST

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<vector>
#include<tuple> 
#include<set> 
#include<list> 
#include<deque> 
#include<array> 
#include<stack> 
#include<queue> 

int main() {

	std::pair<int, int> ipair = { 1, 2 };
	std::tuple<int, int> ituple = { 1, 2 };
	std::vector<int> ivec = { 1, 2, 3, 4, 5 };
	std::set<int> iset = { 1, 2, 3, 4, 5 };
	std::list<int> ilist = { 1, 2, 3, 4, 5 };
	std::deque<int> ideque = { 1, 2, 3, 4, 5 };
	std::array<int, 5> iarray = { 1, 2, 3, 4, 5 };

	// Initializer list is not available for adapters
	std::stack<int> istack = { 1, 2, 3, 4, 5 }; // NOT OK
	std::queue<int> iqueue = { 1, 2, 3, 4, 5 }; // NOT OK
	std::priority_queue<int> ipq = { 1, 2, 3, 4, 5 }; // NOT OK
}

#endif // INITIALIZER_LIST


// Constructor Initalizer List 
// --------------------------------------------
// --------------------------------------------

#ifdef CONSTRUCTOR_INIT_LIST

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int func() {
	//...
	return 1;
}

class Data {
public:
	// constructor initializer list
	Data(int x, int y, int z, const int cm, double ref) :mx{ x }, my{ y }, mz{ z }, ptr{ nullptr }, cm{ cm }, ref{ ref }{
		std::cout << "Data ctor is called...\n";
	}

	Data(const int cm, double ref) : mz{ func() }, vptr{ std::malloc(1000) }, cm{ cm }, ref{ ref }{
		std::cout << "Data(const int cm, double ref) ctor is called...\n";
	}

	~Data() {
		std::cout << "Data destructor is called...\n";
	}

	void print()const {

		std::cout << " mx : " << mx << "\n";
		std::cout << " my : " << my << "\n";
		std::cout << " mz : " << mz << "\n";
		std::cout << " ptr : " << ptr << "\n";
		std::cout << " vptr : " << vptr << "\n";
		std::cout << " cm : " << cm << "\n";
		std::cout << " ref : " << ref << "\n";
	}

private:
	int mx, my, mz;
	int* ptr;
	void* vptr;
	const int cm; // const data members must be initilalized
	double& ref;  // references must be initilalized
};

int main() {

	Data data{ 1,2,3,4,5 };
	data.print();

	Data mdata{ 3,4 };
	mdata.print();

	/*
		To be executed to add here !!!
	*/
}

#endif // CONSTRUCTOR_INIT_LIST


// Temporary Objects
// --------------------------------------------
// --------------------------------------------

#ifdef TEMPORARY_OBJECTS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() : mx{ 0 }, my{ 0 } {
		std::cout << "Data() default ctor is called...\n";
	};
	Data(int x) : mx{ x }, my{ 0 }{
		std::cout << "Data(int x) ctor is called...\n";
	}
	Data(int x, int y) : mx{ x }, my{ y }{
		std::cout << "Data(int x, int y) ctor is called...\n";
	}
	~Data() {
		std::cout << "~Data() destructor is called...\n";
	}
	void print()const {
		std::cout << "mx : " << mx << " my : " << my << "\n";
	}
private:
	int mx, my;
};

void func(const Data& ref) {
	std::cout << "func(const Data& ref) is called...\n";
}

void func(Data&& ref) {
	std::cout << "func(Data&& ref) is called...\n";
}

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

	return EXIT_SUCCESS;
}

#endif // TEMPORARY_OBJECTS


// Conversion Constructors
// --------------------------------------------
// --------------------------------------------

#ifdef CONVERSION_CTOR

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() : mx{ 0 } {
		std::cout << "Data() default ctor is called...this : " << this << "\n";
	}

	Data(int x) : mx{ x } {
		std::cout << "Data(int x) is called...this : " << this << "\n";
		std::cout << "x: " << x << "\n\n";
	};

	Data& operator=(const Data& other) {
		std::cout << "copy assignment is called...this : " << this << "\n";
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

#endif // CONVERSION_CTOR


// Copy Elimination (with RVO and NRVO)
// --------------------------------------------
// --------------------------------------------

#ifdef COPY_ELISION

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data() : mx{ 0 } {
		std::cout << "Data() default ctor is called...this : " << this << "\n";
	}
	Data(int x) : mx{ x } {
		std::cout << "Data(int x) is called...this : " << this << "\n";
	}
	Data(const Data& other) : mx{ other.mx } {
		std::cout << "Data(const Data&) copy ctor is called...this : " << this << "\n";
	}

	~Data() {
		std::cout << "~Data() destructor is called...this : " << this << "\n";
	}
	void set(const int x) {
		this->mx = x;
	}
private:
	int mx;
};

void func(Data data) {
	std::cout << "func(Data data) is called...\n";
}

// RVO - Return Value Optimization
// Mandatory Copy Elision (C++17)
// When foo() is called, copy ctor is not called for return value 
Data foo() {
	//...
	return Data{ 20 };
}

// NRVO - Named Return Value Optimization
// Not Mandatory Copy Elision (C++17)
Data foo2() {
	Data d{ 36 };
	d.set(35);
	//..
	return d;
}

int main() {

	std::cout << "main() is started...\n";
	func(Data{});
	// First destructor is called here for Data{}
	std::cout << "main() is still going on...\n\n";

	func(Data{ 10 });  // copy elimination is applied by compiler
					  // not calling copy ctor for Data{10}
					  // calling Data(int x) directly 

	// Second destructor is called here for Data{ 10 }
	std::cout << "main() is still going on...\n\n";

	Data data = foo();
	std::cout << "main() is ended...\n";
	// Third destructor is called here for "data" object

	return EXIT_SUCCESS;
	/*
		To be executed again!!!
	*/
}

#endif // COPY_ELISION


// Dynamic Memory Allocation - Creating dynamic objects
// --------------------------------------------
// --------------------------------------------

#ifdef DYNAMIC_OBJECTS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <memory>

void* operator new(size_t n) {
	std::cout << "operator new called n : " << n << "\n";
	void* vptr = std::malloc(n);
	if (!vptr){
		throw std::bad_alloc{};
	}
	std::cout << "address of allocated block : " << vptr << "\n";
	return vptr;
}

void operator delete(void *vptr) {
	std::cout << "operator delete called vptr : " << vptr << "\n";
	if (vptr)
	{
		std::free(vptr);
	}

}
// point.h
/*--------------------------------------------------------*/
class Point {
public:
	Point() : mx{}, my{}, mz{}{
		std::cout << "Point() ctor is called...this : " << this << "\n";
	}
	Point(int x, int y, int z) :mx{ x }, my{ y }, mz{ z } {
		std::cout << "Point(int x, int y, int z) is called...this : " << this << "\n";
	}
	~Point() {
		std::cout << "~Point() dtor is called...this : " << this << "\n";
	}
	void print()const {
		std::cout << "[" << mx << ", " << my << ", " << mz << "]\n";
	}
	void set(const int x, const int y, const int z) {
		this->mx = x;
		this->my = y;
		this->mz = z;
	}
private:
	int mx, my, mz;
};

int main() {

	Point* ptr = new Point(10, 20, 30);
	//auto *ptr = new Point(10,20,30);
	//Point* ptr = new Point{ 10, 20, 30 };
	//Point* ptr(new Point(10, 20, 30));
	//Point* ptr{ new Point(10, 20, 30) };

	std::cout << "ptr : " << ptr << "\n";
	ptr->print();

	delete ptr;

	return EXIT_SUCCESS;

	/*
		Executed again !!!
	*/
}

#endif // DYNAMIC_OBJECTS


// Features
// --------------------------------------------
// --------------------------------------------

#ifdef FEATURE

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class Member {
public:


};

int main() {

	Member mem;
	!mem; // overloading for operator! function

	return EXIT_SUCCESS;
}

#endif // DYNAMIC_OBJECTS