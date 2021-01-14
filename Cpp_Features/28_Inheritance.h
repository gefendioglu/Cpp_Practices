#pragma once

// Basic Inheritance
// --------------------------------------------
// --------------------------------------------

#ifdef INHERITANCE_I

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//Base class 
class Parent{
public:
	int id_p;
};

// Sub class inheriting from Base Class(Parent) 
class Child : public Parent{
public:
	int id_c;
};

int main(){

	Child obj1;

	// An object of class child has all data members 
	// and member functions of class parent 
	obj1.id_c = 7;
	obj1.id_p = 91;
	std::cout << "Child id is " << obj1.id_c << "\n";
	std::cout << "Parent id is " << obj1.id_p << "\n";

	return 0;

	/*
		Child id is 7
		Parent id is 91
	*/
}

#endif // INHERITANCE_I


// Types of Inheritance in C++
// --------------------------------------------
// --------------------------------------------

#ifdef MULTIPLE_INHERITANCE_I

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// First Base Class 
class Vehicle {
public:
	Vehicle() {
		std::cout << "This is a Vehicle" << "\n";
	}
};

// Second Base Class 
class FourWheeler {
public:
	FourWheeler() {
		std::cout << "This is a 4 wheeler Vehicle" << "\n";
	}
};

// Multiple Inheritance
// sub class derived from two base classes 
class Car : public Vehicle, public FourWheeler {
	//...
};

int main() {

	//creating object of sub class will invoke the constructor of base classes 
	Car obj;
	return 0;

	/*
		This is a Vehicle
		This is a 4 wheeler Vehicle
	*/
}
#endif // MULTIPLE_INHERITANCE_I


// Multiple Inheritance in C++
// --------------------------------------------
// --------------------------------------------

#ifdef MULTIPLE_INHERITANCE_II

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class A{
public:
	A() { std::cout << "A's constructor called" << "\n";}
	~A() { std::cout << "A's destructor called" << "\n"; }
};

class B{
public:
	B() { std::cout << "B's constructor called" << "\n"; }
	~B() { std::cout << "B's destructor called" << "\n"; }
};

// Multiple Inheritance
class C : public A, public B
{
public:
	C() { std::cout << "C's constructor called" << "\n"; }
	~C() { std::cout << "C's destructor called" << "\n"; }
};

int main()
{
	C c;
	return 0;

	/*
		A's constructor called
		B's constructor called
		C's constructor called
		C's destructor called
		B's destructor called
		A's destructor called
	*/
}

#endif // MULTIPLE_INHERITANCE_II


// The Diamond Problem
// --------------------------------------------
// --------------------------------------------

#ifdef DIAMOND_PROBLEM

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Person {
public:
	Person() { 
		std::cout << "Person::Person() called" << "\n";
	}
	Person(int x) { 
		std::cout << "Person::Person(int ) called" << "\n"; 
	}
};

class Faculty : virtual public Person {
public:
	Faculty(int x) :Person(x) {
		std::cout << "Faculty::Faculty(int ) called" << "\n";
	}
};

class Student : virtual public Person {
public:
	Student(int x) :Person(x) {
		std::cout << "Student::Student(int ) called" << "\n";
	}
};

class TA : public Faculty, public Student {
public:
	// Delegating Constructor
	TA(int x) :Student(x), Faculty(x), Person(x) {
		std::cout << "TA::TA(int ) called" << "\n";
	}
};

int main() {

	TA ta1(30);

	// Person object is created twice.
	/*
		Person::Person() called
		Faculty::Faculty(int ) called
		Student::Student(int ) called
		TA::TA(int ) called
	
	*/
}

#endif // DIAMOND_PROBLEM

// TODO: Devam edilecek !!!
// http://www.vishalchovatiya.com/part-2-all-about-virtual-keyword-in-cpp-how-virtual-class-works-internally/

#ifdef DIAMOND_PROBLEM_II

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Top { 
public: 
	int t; 
};

class Left : virtual public Top { 
public: 
	int l; 
};

class Right : virtual public Top { 
public: 
	int r; 
};

class Bottom : public Left, public Right { 
public: 
	int b; 
};

int main() {

	Top* t_ptr1 = new Left;
	Top* t_ptr2 = new Right;
	
	Left* left = new Bottom;
	Right* right = new Bottom;
	
	// There is only one Top instance included in the hierarchy
	Top* Top = new Bottom; // OK !
	
	Bottom* bot = new Bottom;
	bot->t; // OK !
}
#endif // DIAMOND_PROBLEM_II

// Multilevel Inheritance 
// --------------------------------------------
// --------------------------------------------

#ifdef MULTILEVEL_INHERITANCE

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Base Class
class Vehicle{
public:
	Vehicle()	{
		std::cout << "This is a Vehicle" << "\n";
	}
};

//Derived Class --> fourWheeler
class fourWheeler : public Vehicle{
public:
	fourWheeler()	{
		std:: cout << "Objects with 4 wheels are vehicles" << "\n";
	}
};

// Derived from two base classes 
class Car : public fourWheeler {
public:
	Car()	{
		std::cout << "Car has 4 Wheels" << "\n";
	}
};

int main(){

	//creating object of Car invokes the constructor of base classes 
	Car obj;
	return 0;

	/*
		This is a Vehicle
		Objects with 4 wheels are vehicles
		Car has 4 Wheels
	*/
}

#endif // MULTILEVEL_INHERITANCE

// Inheritance and Friendship
// --------------------------------------------
// --------------------------------------------

#ifdef INHERITANCE_FRIENDSHIP

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class A{
public:
	A() { x = 0; }
	friend void show();
protected:
	int x;
};

class B : public A{
public:
	B() : y(0) {}
private:
	int y;
};

void show(){
	B b;
	std::cout << "The default value of A::x = " << b.x;

	// Can't access private member declared in class 'B' 
	std::cout << "The default value of B::y = " << b.y;
}

int main(){

	show();
	return 0;
}

#endif // INHERITANCE_FRIENDSHIP


// Question : Inheritance Example
// --------------------------------------------
// --------------------------------------------

#ifdef INHERITANCE_EXAMPLE_I

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class A{
public:
	void setX(int i) { x = i; }
	void print() { std::cout << x; }
private: 
	int x;
};

class B : public A{
public:
	B() { setX(10); }
};

class C : public A{
public:
	C() { setX(20); }
};

class D : public B, public C {
};

int main()
{
	D d;
	d.print(); // ambiguous
	return 0;
}
#endif // INHERITANCE_EXAMPLE_I


// Question : Inheritance Example
// --------------------------------------------
// --------------------------------------------

#ifdef INHERITANCE_EXAMPLE_II

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class A{
	int x;
public:
	A(int i) { x = i; }
	void print() { std::cout << x; }
};

class B : virtual public A{
public:
	B() :A(10) { }
};

class C : virtual public A{
public:
	C() :A(10) { }
};

// attempting to reference a deleted function for public B
// no default constructor exists for class "A"	
class D : public B, public C {
};

int main()
{
	D d;
	d.print();
	return 0;
}

#endif // INHERITANCE_EXAMPLE_II



