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
	void setData(int mdata)	{
		mx = mdata;
	}

	// Forward declaration is required for the parameters of sum func. 
	friend int sum(const A&, const B&);
private:
	int mx;
};

class A {
public:
	void setData(int mdata)	{
		my = mdata;
	}
	friend int sum(const A&, const B&);
private: 
	int my;
};

int sum(const A& m, const B& n){
	return (m.my + n.mx);
}

int main(){

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
	std::stack<int> istack = {1, 2, 3, 4, 5}; // NOT OK
	std::queue<int> iqueue = {1, 2, 3, 4, 5}; // NOT OK
	std::priority_queue<int> ipq = {1, 2, 3, 4, 5}; // NOT OK
}

#endif // INITIALIZER_LIST


// Constructor Initalizer List 
// --------------------------------------------
// --------------------------------------------

#ifdef CONSTRUCTOR_INIT_LIST

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int func(){ 
	//...
	return 1;
}

class Data {
public:
	// constructor initializer list
	Data(int x, int y, int z, const int cm, double ref) :mx{ x }, my{ y }, mz{ z }, ptr{nullptr}, cm{ cm }, ref{ ref }{
		std::cout << "Data ctor is called...\n";
	}

	Data(const int cm, double ref) : mz{ func() }, vptr{std::malloc(1000)}, cm{ cm }, ref{ ref }{
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

	Data mdata{3,4};
	mdata.print();

	/*
		To be executed to add here !!!
	*/
}

#endif // CONSTRUCTOR_INIT_LIST


// The implementation of Copy Constructors 
// --------------------------------------------
// --------------------------------------------

#ifdef COPY_CTOR

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

#endif // COPY_CTOR_ADDRESS

// Copy Ctor withput Dangling Pointer Problem 
// Whenever a need comes out to allocate memory block (if there is an in-class pointer), the copy ctor of this class shall be declared by user.
// --------------------------------------------
// --------------------------------------------

#ifdef USER_DECLARED_COPY_CTOR

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

	// user declared copy contructor
	String(const String& other) : mlenght{other.mlenght} {
		std::cout << "Copy ctor is called...this : " << this << "\n";
		
		mptr = static_cast<char*>(malloc(mlenght + 1));
		if (!mptr)
		{
			std::cerr << "not enough memory...\n";
			std::exit(EXIT_FAILURE);
		}
		std::cout << "the address of allocated block : " << (void*)mptr << "\n";
		std::cout << "other.mptr : " << (void*)other.mptr << "\n";
		std::strcpy(mptr, other.mptr);
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
	s.print(); 

	return EXIT_SUCCESS;

	/*
		ctor is called...this : 00D2F840
		the address of allocated block : 01190578
		length : 16
		[Gamze Efendioglu]
		Copy ctor is called...this : 00D2F74C
		the address of allocated block : 01195A88
		other.mptr : 01190578
		func is called...
		[Gamze Efendioglu]
		func is ended...
		destructor is called...this : 00D2F74C
		the address of freed block : 01195A88
		[Gamze Efendioglu]
		destructor is called...this : 00D2F840
		the address of freed block : 01190578
	*/
}

#endif // USER_DECLARED_COPY_CTOR


// Features 
// --------------------------------------------
// --------------------------------------------

#ifdef FEATURE

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

private:
	T mt;
	U mu;
	X mx;
};

int main() {

	Data data1;
	Data data2;
	data2 = data1; // data2.operator=(data1);
}

#endif // FEATURE

