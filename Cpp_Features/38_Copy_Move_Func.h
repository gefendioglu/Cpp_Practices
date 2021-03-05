#pragma once

// The implementation of Copy Constructors 
// --------------------------------------------
// --------------------------------------------

#ifdef COPY_CTOR

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Member {
public:
	Member() = default;
	Member(const Member& other) :mx{ other.mx }, md{ other.md } {
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
	member1.set(20, 6.3);
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

#endif // COPY_CTOR


// Copy Ctor and The Address of Objects
// --------------------------------------------
// --------------------------------------------

#ifdef COPY_CTOR_ADDRESS

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
	Member(const Member& other) {
		std::cout << "Member(const Member& other) copy ctor is called...this : " << this << "\n";
		std::cout << "&other : " << &other << "\n";
	}
};

void funcVal(Member mem) {
	std::cout << "funcVal(Member mem) is called...this : " << &funcVal << "\n";

}

void funcRef(Member& mem) {
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

#endif // COPY_CTOR_ADDRESS

// Copy Ctor without Dangling Pointer Problem 
// Whenever a need comes out to allocate memory block (if there is an in-class pointer), the copy ctor of this class shall be declared by user.
// --------------------------------------------
// --------------------------------------------

#ifdef COPY_MOVE_OPERATIONS

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
	String(const String& other) : mlength{ other.mlength } {
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
	String(String&& other) : mlength{ std::move(other.mlength) }, mptr{ std::move(other.mptr) } {
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

	String s3{ "Hakan" }, s4{ "Sema" };
	String s5 = std::move(s3); // move ctor
	s4 = std::move(s5);        // move assignm.
	std::cout << "\n\n";

	return EXIT_SUCCESS;

	/*
		Executed again !!!
	*/
}

#endif // USER_DECLARED_COPY_CTOR_ASSIGNMENT


// The implementation of Copy Assignment  
// --------------------------------------------
// --------------------------------------------

#ifdef COPY_ASSIGNMENT

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Counter {
public:
	Counter() = default;
	Counter(int x) : mx{ x } {}
	Counter& operator=(const Counter& other) {
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
	cnt1.operator=(cnt2.operator=(cnt3.operator=(cnt4.operator=(cnt5))));

	cnt1.print();
	cnt2.print();
	cnt3.print();
	cnt4.print();
	cnt5.print();

	/*
		Executed again !!!
	*/
}

#endif // COPY_ASSIGNMENT


// The implementation of Move Operations 
// --------------------------------------------
// --------------------------------------------

#ifdef MOVE_CTOR_ASSIGNMENT

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class T {};
class U {};
class X {};

class Data {
public:
	Data() = default;

	// copy constructor
	Data(const Data& other) : mt{ other.mt }, mu{ other.mu }, mx{ other.mx } {
		std::cout << "copy ctor is called...\n";
	}

	// move constructor
	Data(Data&& other) : mt{ std::move(other.mt) }, mu{ std::move(other.mu) }, mx{ std::move(other.mx) } {
		std::cout << "move ctor is called...\n";
	}

	// move assignment 
	Data& operator=(Data&& other) {

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

#endif // MOVE_CTOR_ASSIGNMENT