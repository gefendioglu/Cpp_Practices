#pragma once

/* Virtual Functions & Inline Functions */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_INLINE_FUNCTIONS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Base{
public:
	virtual void who()	{
		std::cout << "I am Base" <<"\n";
	}
};

class Derived : public Base{
public:
	void who() override	{
		std::cout << "I am Derived" << "\n";
	}
};

int main()
{
	// virtual function who() is called through object of the class
	// it will be resolved at compile time
	// so it can be inlined
	Base base;
	base.who();

	// Virtual function is called through pointer, 
	// so it cannot be inlined 
	Base* ptr = new Derived();
	ptr->who();

	return 0;
}

#endif // VIRTUAL_INLINE_FUNCTIONS


/* When a virtual function is called inside a non-virtual function? */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_NONVIRTUAL_FUNCTIONS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Base{
public:
	virtual void print()	{
		std::cout << "Base class print function \n";
	}
	void invoke(){
		std::cout << "Base class invoke function \n";
		this->print();
	}
};

class Derived : public Base{
public:
	void print() override{
		std::cout << "Derived class print function \n";
	}
	void invoke(){
		std::cout << "Derived class invoke function \n";
		this->print(); // called under non - virtual function 
	}
};

int main()
{
	Base* b = new Derived;
	b->invoke();
	return 0;
	
	/*
		Base class invoke function
		Derived class print function
	*/
}

#endif // VIRTUAL_NONVIRTUAL_FUNCTIONS


/*  Concept of Virtual Functions */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_FUNCTIONS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class base {
public:
	virtual void print()	{
		std::cout << "print base class" << "\n";
	}

	void show(){
		std::cout << "show base class" << "\n";
	}
};

class derived : public base {
public:
	void print()	{
		std::cout << "print derived class" << "\n";
	}

	void show()	{
		std::cout << "show derived class" << "\n";
	}
};

int main()
{
	base* bptr;
	derived d;
	bptr = &d;

	// virtual function, binded at runtime 
	bptr->print();

	// Non-virtual function, binded at compile time 
	bptr->show();

	/*
		print derived class
		show base class
	*/
	
}

#endif // VIRTUAL_FUNCTIONS


/* Virtual Pointers (VPTR) - Virtual Table (VTABLE) */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_POINTERS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

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

#endif // VIRTUAL_POINTERS


/* Default Arguments and Virtual Function  */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_FUNCTIONS_DEFAULT_ARG

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Base{
public:
	virtual void fun(int x = 0)	{
		std::cout << "Base::fun(), x = " << x << "\n";
	}
};

class Derived : public Base{
public:
	virtual void fun(int x=10)	{
		std::cout << "Derived::fun(), x = " << x << "\n";
	}
};

int main()
{
	Derived d1;
	Base* bp = &d1;
	bp->fun();

	return 0;
	
	// Derived::fun(), x = 0
}

#endif // VIRTUAL_FUNCTIONS_DEFAULT_ARG

 
/* Calling virtual methods in Constructor/Destructor  */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_FUNCTIONS_CONSTRUCTORS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class dog{
public:
	dog()	{
		std::cout << "Constructor called" << "\n";
		bark();
	}

	~dog(){
		bark();
	}

	virtual void bark(){
		std::cout << "Virtual method called" << "\n";
	}

	void seeCat(){
		bark();
	}
};

class Yellowdog : public dog{
public:
	Yellowdog(){
		std::cout << "Derived class Constructor called" << "\n";
	}

	void bark()	override{
		std::cout << "Derived class Virtual method called" << "\n";
	}
};

int main()
{
	Yellowdog d;
	d.seeCat();

	/*
		Constructor called
		Virtual method called
		Derived class Constructor called
		Derived class Virtual method called
		Virtual method called
	*/
}

#endif // VIRTUAL_FUNCTIONS_CONSTRUCTORS
 
/* Can virtual functions be private in C++ ?  */
// --------------------------------------------
// --------------------------------------------

#ifdef PRIVATE_VIRTUAL_FUNCTIONS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Base Class
class base{
public:
	base() { std::cout << "base class constructor\n"; }
    
	// If this class is inherited --> use virtual base destructor
	virtual ~base()	{
		std::cout << "base class destructor\n";
	}

	void show()	{
		std::cout << "show() called on base class\n";
	}

	virtual void print(){
		std::cout << "print() called on base class\n";
	}
};

// Derived Class from Base Class
class derived : public base {
public:

	derived(): base()	{
		std::cout << "derived class constructor\n";
	}

	 /*if this class inherits from a base class --> always use virtual destructors */
	virtual ~derived()	{
		std::cout << "derived class destructor\n";
	}

private:
	 /*private virtual function in derived class overwrites
	 base class virtual method contents of this function
	 are printed when called with base class pointer or
	 when called with derived class object*/
	virtual void print(){
		std::cout << "print() called on derived class\n";
	}
};

int main()
{
	std::cout << "printing with base class pointer\n";

	// construct base class pointer with derived class memory
	base* b_ptr = new derived();

	// call base class show()
	b_ptr->show();

	/* call virtual print in base class but it is overridden
	 in derived class. print() is private member in derived class, still the contents of derived class are printed. because base class defines a public interface and drived class overrides it in its implementation*/
	b_ptr->print();

	delete b_ptr;

	/*
		printing with base class pointer
		base class constructor
		derived class constructor
		show() called on base class
		print() called on derived class
		derived class destructor
		base class destructor
	*/
}

#endif // PRIVATE_VIRTUAL_FUNCTIONS

 
/* Virtual functions in derived classes */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_FUNCTIONS_DERIVED_CLASSES

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class A {
public:
	virtual void fun()	{
		std::cout << "\n A::fun() called ";
	}
};

class B : public A {
public:
	void fun() override	{
		std::cout << "\n B::fun() called ";
	}
};

class C : public B {
public:
	void fun()	override {
		std::cout << "\n C::fun() called ";
	}
};

int main() {

	C c; 
	B* b = &c; // Derived --> Base (upcasting)
	b->fun(); 
	getchar();

	return 0;
	// C::fun() called
}

#endif // VIRTUAL_FUNCTIONS_DERIVED_CLASSES

