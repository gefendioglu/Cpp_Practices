#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Virtual Functions & Inline Functions
// --------------------------------------------
// --------------------------------------------

//class Base{
//public:
//	virtual void who()	{
//		std::cout << "I am Base" <<"\n";
//	}
//};
//
//class Derived : public Base{
//public:
//	void who() override	{
//		std::cout << "I am Derived" << "\n";
//	}
//};
//
//int main()
//{
//	// virtual function who() is called through object of the class
//	// it will be resolved at compile time
//	// so it can be inlined
//	Base base;
//	base.who();
//
//	// Virtual function is called through pointer, 
//	// so it cannot be inlined 
//	Base* ptr = new Derived();
//	ptr->who();
//
//	return 0;
//}


//when a virtual function is called inside a non-virtual function C++?
// --------------------------------------------
// --------------------------------------------


//class Base{
//public:
//	virtual void print()	{
//		std::cout << "Base class print function \n";
//	}
//	void invoke(){
//		std::cout << "Base class invoke function \n";
//		this->print();
//	}
//};
//
//class Derived : public Base{
//public:
//	void print() override{
//		std::cout << "Derived class print function \n";
//	}
//	void invoke(){
//		std::cout << "Derived class invoke function \n";
//		this->print(); // called under non - virtual function 
//	}
//};
//
//int main()
//{
//	Base* b = new Derived;
//	b->invoke();
//	return 0;
//	
//	/*
//		Base class invoke function
//		Derived class print function
//	*/
//}

// Concept of Virtual Functions 
// --------------------------------------------
// --------------------------------------------

//class base {
//public:
//	virtual void print()	{
//		std::cout << "print base class" << "\n";
//	}
//
//	void show(){
//		std::cout << "show base class" << "\n";
//	}
//};
//
//class derived : public base {
//public:
//	void print()	{
//		std::cout << "print derived class" << "\n";
//	}
//
//	void show()	{
//		std::cout << "show derived class" << "\n";
//	}
//};
//
//int main()
//{
//	base* bptr;
//	derived d;
//	bptr = &d;
//
//	// virtual function, binded at runtime 
//	bptr->print();
//
//	// Non-virtual function, binded at compile time 
//	bptr->show();
//
//	/*
//		print derived class
//		show base class
//	*/
//	
//}


// Virtual Pointers (VPTR) - Virtual Table (VTABLE) 
// --------------------------------------------
// --------------------------------------------

class base {
public:
	void fun_1() { std::cout << "base-1\n"; }
	virtual void fun_2() { std::cout << "base-2\n"; }
	virtual void fun_3() { std::cout << "base-3\n"; }
	virtual void fun_4() { std::cout << "base-4\n"; }
};

class derived : public base {
public:
	void fun_1() { std::cout << "derived-1\n"; }
	void fun_2() { std::cout << "derived-2\n"; }
	void fun_4(int x) { std::cout << "derived-4\n"; }
};

int main()
{
	base* p;
	derived obj1;
	p = &obj1;

	// Early binding because fun1() is non-virtual in base 
	p->fun_1();

	// Late binding (RTP) 
	p->fun_2();

	// Late binding (RTP) 
	p->fun_3();

	// Late binding (RTP) 
	p->fun_4();

	// Early binding but this function call is illegal(produces error)
	// becasue pointer is of base type and function is of derived class 
	// p->fun_4(5); // NOT OK! - too many arguments error

	/*
		base-1
		derived-2
		base-3
		base-4
	*/
}

