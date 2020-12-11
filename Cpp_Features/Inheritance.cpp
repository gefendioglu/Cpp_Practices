#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// --------------------------------------------
// --------------------------------------------

////Base class 
//class Parent{
//public:
//	int id_p;
//};
//
//// Sub class inheriting from Base Class(Parent) 
//class Child : public Parent{
//public:
//	int id_c;
//};
//
//int main(){
//
//	Child obj1;
//
//	// An object of class child has all data members 
//	// and member functions of class parent 
//	obj1.id_c = 7;
//	obj1.id_p = 91;
//	std::cout << "Child id is " << obj1.id_c << "\n";
//	std::cout << "Parent id is " << obj1.id_p << "\n";
//
//	return 0;
//
//	/*
//		Child id is 7
//		Parent id is 91
//	*/
//}
//
//// Modes of Inheritance
//// --------------------------------------------
//// --------------------------------------------
//
//// a derived class doesn’t inherit access to private data members. 
//class A{
//public:
//	int x;
//protected:
//	int y;
//private:
//	int z;
//};
//
//class B : public A {
//	// x is public 
//	// y is protected 
//	// z is not accessible from B 
//};
//
//class C : protected A {
//	// x is protected 
//	// y is protected 
//	// z is not accessible from C 
//};
//
//// 'private' is default for classes 
//class D : private A {
//	// x is private 
//	// y is private 
//	// z is not accessible from D 
//};


//// Types of Inheritance in C++
//// --------------------------------------------
//// --------------------------------------------
//
//// first base class 
//class Vehicle {
//public:
//	Vehicle() {
//		std::cout << "This is a Vehicle" << "\n";
//	}
//};
//
//// second base class 
//class FourWheeler {
//public:
//	FourWheeler() {
//		std::cout << "This is a 4 wheeler Vehicle" << "\n";
//	}
//};
//
//// Multiple Inheritance
//// sub class derived from two base classes 
//class Car : public Vehicle, public FourWheeler {
//	//...
//};
//
//int main()
//{
//	// creating object of sub class will invoke the constructor of base classes 
//	Car obj;
//	return 0;
//	/*
//		This is a Vehicle
//		This is a 4 wheeler Vehicle
//	*/
//}



//// Types of Inheritance in C++
//// --------------------------------------------
//// --------------------------------------------
//
//class A{
//public:
//	A() { std::cout << "A's constructor called" << "\n";}
//	~A() { std::cout << "A's destructor called" << "\n"; }
//};
//
//class B{
//public:
//	B() { std::cout << "B's constructor called" << "\n"; }
//	~B() { std::cout << "B's destructor called" << "\n"; }
//};
//
//// Multiple Inheritance
//class C : public A, public B
//{
//public:
//	C() { std::cout << "C's constructor called" << "\n"; }
//	~C() { std::cout << "C's destructor called" << "\n"; }
//};
//
//int main()
//{
//	C c;
//	return 0;
//
//	/*
//		A's constructor called
//		B's constructor called
//		C's constructor called
//		C's destructor called
//		B's destructor called
//		A's destructor called
//	*/
//}


//// The diamond problem
//// --------------------------------------------
//// --------------------------------------------
//
//class Person {
//public:
//	Person() { 
//		std::cout << "Person::Person() called" << "\n";
//	}
//	Person(int x) { 
//		std::cout << "Person::Person(int ) called" << "\n"; 
//	}
//};
//
//class Faculty : virtual public Person {
//public:
//	Faculty(int x) :Person(x) {
//		std::cout << "Faculty::Faculty(int ) called" << "\n";
//	}
//};
//
//class Student : virtual public Person {
//public:
//	Student(int x) :Person(x) {
//		std::cout << "Student::Student(int ) called" << "\n";
//	}
//};
//
//class TA : public Faculty, public Student {
//public:
//	// Delegating Constructor
//	TA(int x) :Student(x), Faculty(x), Person(x) {
//		std::cout << "TA::TA(int ) called" << "\n";
//	}
//};
//
//int main() {
//
//	TA ta1(30);
//
//	// Person object is created twice.
//	/*
//		Person::Person() called
//		Faculty::Faculty(int ) called
//		Student::Student(int ) called
//		TA::TA(int ) called
//	
//	*/
//}


//// Question-1
//// --------------------------------------------
//// --------------------------------------------
//
//class A{
//public:
//	void setX(int i) { x = i; }
//	void print() { std::cout << x; }
//private: 
//	int x;
//};
//
//class B : public A{
//public:
//	B() { setX(10); }
//};
//
//class C : public A{
//public:
//	C() { setX(20); }
//};
//
//class D : public B, public C {
//};
//
//int main()
//{
//	D d;
//	d.print(); // ambiguous
//	return 0;
//}


//// Question-2
//// --------------------------------------------
//// --------------------------------------------
//
//class A{
//	int x;
//public:
//	A(int i) { x = i; }
//	void print() { std::cout << x; }
//};
//
//class B : virtual public A{
//public:
//	B() :A(10) { }
//};
//
//class C : virtual public A{
//public:
//	C() :A(10) { }
//};
//
////attempting to reference a deleted function for public B	
//// no default constructor exists for class "A"	
//class D : public B, public C {
//};
//
//int main()
//{
//	D d;
//	d.print();
//	return 0;
//}


//// Multilevel Inheritance 
//// --------------------------------------------
//// --------------------------------------------
//
//// Base Class
//class Vehicle{
//public:
//	Vehicle()	{
//		std::cout << "This is a Vehicle" << "\n";
//	}
//};
//
//class fourWheeler : public Vehicle{
//public:
//	fourWheeler()	{
//		std:: cout << "Objects with 4 wheels are vehicles" << "\n";
//	}
//};
//
//// sub class derived from two base classes 
//class Car : public fourWheeler {
//public:
//	Car()	{
//		std::cout << "Car has 4 Wheels" << "\n";
//	}
//};
//
//int main()
//{
//	//creating object of Car invokes the constructor of base classes 
//	Car obj;
//	return 0;
//
//	/*
//		This is a Vehicle
//		Objects with 4 wheels are vehicles
//		Car has 4 Wheels
//	*/
//}


//// Inheritance and Friendship
//// --------------------------------------------
//// --------------------------------------------
//
//class A{
//public:
//	A() { x = 0; }
//	friend void show();
//protected:
//	int x;
//};
//
//class B : public A{
//public:
//	B() : y(0) {}
//private:
//	int y;
//};
//
//void show(){
//	B b;
//	std::cout << "The default value of A::x = " << b.x;
//
//	// Can't access private member declared in class 'B' 
//	std::cout << "The default value of B::y = " << b.y;
//}
//
//int main(){
//
//	show();
//	return 0;
//}


