#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Virtual Destructor
// --------------------------------------------
// --------------------------------------------

class base {
public:
	base() {
		std::cout << "Constructing base \n";
	}

	// without virtual destructor causing undefined behavior
	// if this class is used for inheritance
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
//
//int main(void)
//{
//	derived* d = new derived();
//	base* b = d;
//
//	// Deleting a derived class object using a pointer of base class type that has a non-virtual destructor results in undefined behavior.
//	// The object of derived class is not destructed properly
//	delete b;
//
//	return 0;
//
//	/*
//		Constructing base
//		Constructing derived
//		Destructing derived
//		Destructing base
//	*/
//}


// Virtual Constructor
// --------------------------------------------
// --------------------------------------------

//// Starting a Library 
//class Base {
//public:
//
//	// The "Virtual Constructor" 
//	static Base* Create(int id);
//
//	Base() { }
//
//	// Ensures to invoke actual object destructor 
//	virtual ~Base() { }
//
//	// A pure virtual function to provide an interface 
//	virtual void DisplayAction() = 0;
//};
//
//class Derived1 : public Base {
//public:
//	Derived1() {
//		std::cout << "Derived1 created" << "\n";
//	}
//
//	~Derived1() {
//		std::cout << "Derived1 destroyed" << "\n";
//	}
//
//	void DisplayAction() override {
//		std::cout << "Action from Derived1" << "\n";
//	}
//};
//
//class Derived2 : public Base
//{
//public:
//	Derived2() {
//		std::cout << "Derived2 created" << "\n";
//	}
//
//	~Derived2() {
//		std::cout << "Derived2 destroyed" << "\n";
//	}
//
//	void DisplayAction() override {
//		std::cout << "Action from Derived2" << "\n";
//	}
//};
//
//class Derived3 : public Base
//{
//public:
//	Derived3() {
//		std::cout << "Derived3 created" << "\n";
//	}
//
//	~Derived3() {
//		std::cout << "Derived3 destroyed" << "\n";
//	}
//
//	void DisplayAction() override {
//		std::cout << "Action from Derived3" << "\n";
//	}
//};
//
//Base* Base::Create(int id)
//{
//	// User code need not be recompiled to create newly added class objects 
//	if (id == 1)
//		return new Derived1;
//	else if (id == 2)
//		return new Derived2;
//	else
//		return new Derived3;
//}
//// Ending a Library 
//
//
////  User is utility class trying to make use of the hierarchy. 
//class User {
//public:
//
//	User() : pBase(nullptr)
//	{
//		// Receives an object of Base hierarchy at runtime 
//		int input;
//
//		std::cout << "Enter ID (1, 2 or 3): ";
//		std::cin >> input;
//
//		while ((input != 1) && (input != 2) && (input != 3))
//		{
//			std::cout << "Enter ID (1, 2 or 3 only): ";
//			std::cin >> input;
//		}
//
//		// Get object from the "Virtual Constructor" 
//		pBase = Base::Create(input);
//	}
//
//	~User() {
//		if (pBase){
//			delete pBase;
//			pBase = nullptr;
//		}
//	}
//
//	// Delegates to actual object 
//	void Action() {
//		pBase->DisplayAction();
//	}
//
//private:
//	Base* pBase;
//};

//int main()
//{
//	User* user = new User();
//
//	user->Action();
//
//	delete user;
//
//	/*
//		Enter ID (1, 2 or 3): 1
//		Derived1 created
//		Action from Derived1
//		Derived1 destroyed
//	*/
//
//	/*
//		Enter ID (1, 2 or 3): 2
//		Derived2 created
//		Action from Derived2
//		Derived2 destroyed
//	*/
//
//	/*
//		Enter ID (1, 2 or 3): 3
//		Derived3 created
//		Action from Derived3
//		Derived3 destroyed
//	*/
//}


// Pure virtual destructor
// --------------------------------------------
// --------------------------------------------

//class Base{
//public:
//	// Pure virtual destructor 
//	virtual ~Base() = 0; 
//};
//
//Base::~Base(){
//	std::cout << "Pure virtual destructor is called" << "\n";
//}
//
//class Derived : public Base{
//public:
//	~Derived()	{
//		std::cout << "~Derived() is executed" << "\n";
//	}
//};
//
//int main()
//{
//	Base* b = new Derived();
//	delete b;
//	return 0;
//
//	/*
//		~Derived() is executed
//		Pure virtual destructor is called
//	*/
//}