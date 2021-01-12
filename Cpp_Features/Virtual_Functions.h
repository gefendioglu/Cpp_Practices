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
		std::cout << "Base::who() function is called" <<"\n";
	}
};

class Derived : public Base{
public:
	void who() override	{
		std::cout << "Derived::who() function is called" << "\n";
	}
};

int main()
{
	// Base::who() is called through object of the class, it will be resolved at compile time, so it can be inlined
	Base base;
	base.who(); 

	// Virtual function who() is called through pointer, it will be resolved at run rime (dynamic memory allocation), so it can not be inlined 
	Base* ptr = new Derived();
	ptr->who();

	return EXIT_SUCCESS;
	
	/*
	Base::who() function is called
	Derived::who() function is called
	*/
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
	virtual void print() {
		std::cout << "virtual Base::print() is called" << "\n";
	}

	void invoke(){
		std::cout << "non-virtual Base::invoke() is called" << "\n";
		// calling a virtual func. from a non-virtual func. in Base class
		this->print(); 
	}
};

class Derived : public Base {
public:
	void print() override {
		std::cout << "overrided Derived::print() is called" << "\n";
	}
	void invoke() {
		std::cout << "Derived::invoke() is called" << "\n";
		// calling a virtual func. from a non-virtual func. in Derived class
		this->print();  
	}
}; 

int main(){

	Base* base = new Derived; //Derived -> Base (upcasting)
	base->invoke();
	return EXIT_SUCCESS;
	
	/*
		non-virtual Base::invoke() is called
		overrided Derived::print() is called
	*/
}

#endif // VIRTUAL_NONVIRTUAL_FUNCTIONS
  

/*  Concept of Virtual Functions */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_FUNCTIONS_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class base {
public:
	virtual void print()	{
		std::cout << "virtual Base::print() is called" << "\n";
	}

	void show(){
		std::cout << "non-virtual Base::show() is called" << "\n";
	}
};

class derived : public base {
public:
	void print() override {
		std::cout << "overrided derived::print() is called" << "\n";
	}

	void show()	{
		std::cout << "derived::show() is called" << "\n";
	}
};

int main() {

	base* bptr;
	derived derived;
	bptr = &derived;

	// Virtual function, binded at runtime 
	bptr->print();

	// Non-virtual function, binded at compile time 
	bptr->show();

	/*
		overrided derived::print() is called		
		non-virtual Base::show() is called
	*/
	
}

#endif // VIRTUAL_FUNCTIONS_I


/* Virtual Pointers (VPTR) - Virtual Table (VTABLE) */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_POINTERS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class base {
public:
	void fun_1() { std::cout << "base::fun_1()" << "\n"; }
	virtual void fun_2() { std::cout << "base::fun_2()" << "\n";}
	virtual void fun_3() { std::cout << "base::fun_3()" << "\n";}
	virtual void fun_4() { std::cout << "base::fun_4()" << "\n";}
};

class derived : public base {
public:
	void fun_1() { std::cout << "derived::fun_1()" << "\n";}
	void fun_2() override { std::cout << "overrided derived::fun_2()" << "\n";}
	void fun_4(int x) { std::cout << "derived::fun_4(int x)" << "\n";}
};

int main() {

	base* bptr;
	derived derived; // derived -> bptr (upcasting)
	bptr = &derived;

	// Early binding, fun_1() is non-virtual in base 
	bptr->fun_1();

	// Late binding (Run Time Polymorphism) 
	bptr->fun_2();

	// Late binding (Run Time Polymorphism)
	bptr->fun_3();

	// Late binding (Run Time Polymorphism)
	bptr->fun_4();

	// Early binding, but this function call is illegal
	// because pointer is of base type and function is of derived class 
	// bptr->fun_4(5); // NOT OK! - too many arguments error

	/*
		base::fun_1()
		overrided derived::fun_2()
		base::fun_3()
		base::fun_4()
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
		std::cout << "Base::fun(int x = 0), x = " << x << "\n";
	}
};
class Derived : public Base{
public:
	virtual void fun(int x = 10) {
		std::cout << "Derived::fun(int x = 10), x = " << x << "\n";
	}
};

int main() {

	Derived d1;
	Base* bp = &d1;
	bp->fun();

	return EXIT_SUCCESS;

	/* Derived::fun(int x = 10), x = 0 */
}

#endif // VIRTUAL_FUNCTIONS_DEFAULT_ARG

 
/* Calling Virtual Functions in Constructor/Destructor */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_FUNCTIONS_CONSTRUCTORS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Dog{
public:
	Dog() {
		std::cout << "Dog() Constructor" << "\n";
		bark();
	}

	~Dog() {
		bark();
	}

	virtual void bark(){
		std::cout << "virtual Dog::bark()" << "\n";
	}

	void seeCat(){
		bark();
	}
};

class YellowDog : public Dog {
public:
	YellowDog(){
		std::cout << "YellowDog() Constructor" << "\n";
	}

	void bark()	override{
		std::cout << "YellowDog::bark()" << "\n";
	}
};

int main()
{
	YellowDog dog;
	dog.seeCat();

	/*
		Dog() Constructor
		virtual Dog::bark()
		YellowDog() Constructor
		YellowDog::bark()
		virtual Dog::bark()
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
	base() { std::cout << "base::base() constructor" << "\n"; }
    
	virtual ~base()	{
		std::cout << "base::~base() destructor"<< "\n";
	}

	void show()	{
		std::cout << "base::show()" << "\n";
	}

	virtual void print(){
		std::cout << "virtual base::print()" << "\n";
	}
};

// Derived Class from Base Class
class derived : public base {
public:
	derived(): base() {
		std::cout << "derived::derived() constructor" << "\n";
	}

	 /* if this class inherits from a base class --> always use virtual destructors */
	virtual ~derived()	{
		std::cout << "derived::~derived() destructor" << "\n";
	}

private:
	 /* private virtual function in derived class overwrites base class virtual function, function is called with base class pointer or derived class object */
	virtual void print(){
		std::cout << "private derived::print()" << "\n";
	}
};

int main() {

	// construct base class pointer with derived class memory
	base* b_ptr = new derived();
	b_ptr->show();

	/* print() is private member in derived class, still the contents of derived class are printed. because base class defines a public interface and drived class overrides it in its implementation*/
	b_ptr->print();

	delete b_ptr;

	/*
		base::base() constructor
		derived::derived() constructor
		base::show()
		private derived::print()
		derived::~derived() destructor
		base::~base() destructor
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
		std::cout << "A::fun() called" << "\n";
	}
};

class B : public A {
public:
	void fun() override	{
		std::cout << "B::fun() called" << "\n";
	}
};

class C : public B {
public:
	void fun()	override {
		std::cout << "C::fun() called" << "\n";
	}
};

int main() {

	C c; 
	B* b = &c; // Derived --> Base (upcasting)
	b->fun(); 

	return EXIT_SUCCESS;
	/* C::fun() called */
}

#endif // VIRTUAL_FUNCTIONS_DERIVED_CLASSES


/* Virtual Functions */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_FUNCTIONS_II

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class protocol_t {
public:
	virtual void authenticate() {
		std::cout << "protocol_t::authenticate()" << "\n";
	}
	virtual void connect() {
		std::cout << "protocol_t::connect()" << "\n";
	}
private:
	uint8_t type;
};

/* When wifi_t class is inherited from protocol_t class, a new virtual table will be created by the compiler.*/
class wifi_t : public protocol_t {
public:
	void authenticate() {
		std::cout << "wifi_t::authenticate()" << "\n";
	}

	void connect() {
		std::cout << "wifi_t::connect()" << "\n";
	}
private:
	char pass[15];
};

/* When bluetooth_t class is inherited from protocol_t class, a new virtual table will be created by the compiler.*/
class bluetooth_t : public protocol_t {
public:
	void authenticate() {
		std::cout << "bluetooth_t::authenticate()" << "\n";
	}
	void connect() {
		std::cout << "bluetooth_t::connect()" << "\n";
	}
private:
	char pass[15];
};

void makeConnection(protocol_t* protocol) {
	protocol->authenticate();
	protocol->connect();
}

int main() {

	protocol_t *pt = new wifi_t();
	makeConnection(pt);
	
	std::cout << "\n";

	bluetooth_t bluetooth;
	pt = &bluetooth;
	makeConnection(pt);

	return EXIT_SUCCESS;

	/*
		wifi_t::authenticate()
		wifi_t::connect()
		
		bluetooth_t::authenticate()
		bluetooth_t::connect()
	*/
}

#endif // VIRTUAL_FUNCTIONS_II

/* Virtual Functions with Composition */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_FUNCTIONS_COMPOSITION

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Foo{
public:
	Foo() { std::cout << "Foo ctor" << "\n"; }
	~Foo() { std::cout << "~Foo dtor" << "\n"; }
};

class base {
public:
	base() { std::cout << "base ctor" << "\n";}
	~base() { std::cout << "~base dtor" << "\n";}
};

class Bar : public base{
public:
	Bar(){
		std::cout << "Bar ctor" << "\n";
		str = 0;
	}
	~Bar() { std::cout << "~Bar dtor" << "\n";}

private:
	Foo foo;
	char* str;
};

int main() {

	base* bptr;
	Bar bar;
	bptr = &bar;

	return EXIT_SUCCESS;
	/*
		base ctor
		Foo ctor
		Bar ctor
		~Bar dtor
		~Foo dtor
		~base dtor
	*/
}

#endif // VIRTUAL_FUNCTIONS_COMPOSITION


