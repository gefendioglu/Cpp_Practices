#pragma once

/* Virtual Destructor */ 
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_DESTRUCTOR

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class base {
public:
	base() {
		std::cout << "Constructing base \n";
	}

	// if this class is used for inheritance
	// without virtual destructor --> undefined behavior
	virtual ~base() {
		std::cout << "Destructing base \n";
	}
};

class derived : public base {
public:
	derived() {
		std::cout << "Constructing derived \n";
	}
	~derived() {
		std::cout << "Destructing derived \n";
	}
};

int main(void){
	
	derived* d = new derived();
	base* b = d; // derived -> base (upcasting)

	// Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior.
	// The object of derived class is not destructed properly
	delete b;

	return 0;

	/*
		Constructing base
		Constructing derived
		Destructing derived
		Destructing base
	*/
}

#endif // VIRTUAL_DESTRUCTOR


/* Virtual Constructor */
// --------------------------------------------
// --------------------------------------------

#ifdef VIRTUAL_CONSTRUCTOR

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Base {
public:

	// The "Virtual Constructor" 
	static Base* Create(int id);

	Base() { }

	// Ensures to invoke actual object destructor 
	virtual ~Base() { }

	// A pure virtual function to provide an interface 
	virtual void DisplayAction() = 0;
};

class Derived1 : public Base {
public:
	Derived1() {
		std::cout << "Derived1 created" << "\n";
	}

	~Derived1() {
		std::cout << "Derived1 destroyed" << "\n";
	}

	void DisplayAction() override {
		std::cout << "Action from Derived1" << "\n";
	}
};

class Derived2 : public Base
{
public:
	Derived2() {
		std::cout << "Derived2 created" << "\n";
	}

	~Derived2() {
		std::cout << "Derived2 destroyed" << "\n";
	}

	void DisplayAction() override {
		std::cout << "Action from Derived2" << "\n";
	}
};

class Derived3 : public Base
{
public:
	Derived3() {
		std::cout << "Derived3 created" << "\n";
	}

	~Derived3() {
		std::cout << "Derived3 destroyed" << "\n";
	}

	void DisplayAction() override {
		std::cout << "Action from Derived3" << "\n";
	}
};

Base* Base::Create(int id)
{
	// User code need not be recompiled to create newly added class objects 
	if (id == 1)
		return new Derived1;
	else if (id == 2)
		return new Derived2;
	else
		return new Derived3;
}

class User {
public:

	User() : pBase(nullptr)
	{
		// Receives an object of Base hierarchy at runtime 
		int input;

		std::cout << "Enter ID (1, 2 or 3): ";
		std::cin >> input;

		while ((input != 1) && (input != 2) && (input != 3))
		{
			std::cout << "Enter ID (1, 2 or 3 only): ";
			std::cin >> input;
		}

		// Get object from the "Virtual Constructor" 
		pBase = Base::Create(input);
	}

	~User() {
		if (pBase){
			delete pBase;
			pBase = nullptr;
		}
	}

	// Delegates to actual object 
	void Action() {
		pBase->DisplayAction();
	}

private:
	Base* pBase;
};

int main()
{
	User* user = new User();

	user->Action();

	delete user;

	/*
		Enter ID (1, 2 or 3): 1
		Derived1 created
		Action from Derived1
		Derived1 destroyed
	*/

	/*
		Enter ID (1, 2 or 3): 2
		Derived2 created
		Action from Derived2
		Derived2 destroyed
	*/

	/*
		Enter ID (1, 2 or 3): 3
		Derived3 created
		Action from Derived3
		Derived3 destroyed
	*/
}

#endif // VIRTUAL_CONSTRUCTOR


/* Pure Virtual Destructor */
// --------------------------------------------
// --------------------------------------------

#ifdef PURE_VIRTUAL_DESTRUCTOR

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
 
class Base{
public:
	// Pure virtual destructor 
	virtual ~Base() = 0; 
};

Base::~Base(){
	std::cout << "Pure virtual destructor is called" << "\n";
}

class Derived : public Base{
public:
	~Derived()	{
		std::cout << "~Derived() is executed" << "\n";
	}
};

int main(){
	
	Base* b = new Derived(); // Derived --> Base (Upcasting)
	delete b;
	return 0;

	/*
		~Derived() is executed
		Pure virtual destructor is called
	*/
}

#endif // PURE_VIRTUAL_DESTRUCTOR



/* Constructors of Virtual Bases */
// --------------------------------------------
// --------------------------------------------

#ifdef CONSTRUCTORS_VIRTUAL_BASES

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Top{
public:
	Top() { 
		top_val = -1; 
		std::cout << "Top::Top()\n";
	}
	Top(int top_val) { 
		this->top_val = top_val; 
		std::cout << "Top::Top(int)\n";
	}
	int top_val;
};

class Left : virtual public Top{
public:
	Left() { 
		left_val = -2;
		std::cout << "Left::Left()\n";
	}
	Left(int top_val, int left_val) : Top(top_val) { 
		this->left_val = left_val;
		std::cout << "Left::Left(int, int)\n";
	}
	int left_val;
};

class Right : virtual public Top {
public:
	Right() { 
		right_val = -3; 
		std::cout << "Right::Right()\n";
	}
	Right(int top_val, int right_val) : Top(top_val) {
		this->right_val = right_val; 
		std::cout << "Right::Right(int, int)\n";
	}
	int right_val;
};

class Bottom : public Left, public Right{
public:
	Bottom() { 
		bottom_val = -4;
		std::cout << "Bottom::Bottom()\n";
	}
	Bottom(int top_val, int left_val, int right_val, int bottom_val) :  Top(top_val), Left(top_val, left_val), Right(top_val, right_val)	{
		this->bottom_val = bottom_val;
		std::cout << "Bottom::Bottom(int, int, int, int)\n";
	}

	int bottom_val;
};

int main() {

	Bottom* bptr = new Bottom();
	Right* rptr = bptr;
	if (rptr == bptr)
		printf("Equal!\n");

	return 0;

	/*
		Top::Top()
		Left::Left()
		Right::Right()
		Bottom::Bottom()
		Equal!
	*/
}

#endif // COMSTRUCTORS_VIRTUAL_BASES
