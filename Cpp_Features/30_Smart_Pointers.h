#pragma once

// Smart Pointers
// --------------------------------------------
// --------------------------------------------

#ifdef SMART_POINTERS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <memory> 

class SmartPtr {
public:
	explicit SmartPtr(int* p = nullptr) { ptr = p; }
	~SmartPtr() { delete (ptr); }

	// Overloading dereferencing operator 
	int& operator*() { return *ptr; }

private:
	int* ptr;
};

// A generic smart pointer class 
template <class T>
class SmartPtrTemp {
public:
    explicit SmartPtrTemp(T* p = nullptr) { ptr = p; }

    // Destructor 
    ~SmartPtrTemp() { delete (ptr); }

    // Overloading dereferncing operator - return object
    T& operator*() { return *ptr; }

    // Overloading arrow operator - return pointer
    T* operator->() { return ptr; }

private:
    T* ptr; 
};

int main()
{
	SmartPtr ptr(new int());
	*ptr = 20;
	std::cout << *ptr; // 20

    SmartPtrTemp<int> ptr(new int());
    *ptr = 20;
    std::cout << *ptr; // 20

	return EXIT_SUCCESS;
}

#endif // SMART_POINTERS

// Smart Pointers --> std::unique_ptr<>
// --------------------------------------------
// --------------------------------------------

#ifdef SMART_POINTERS_UNIQUE

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <memory> 

class Rectangle {
public:
	Rectangle(int l, int b){
		length = l;
		breadth = b;
	}

	int area()	{
		return length * breadth;
	}
private:
	int length;
	int breadth;
};

int main(){

	std::unique_ptr<Rectangle> P1(new Rectangle(10, 5));
	std::cout << P1->area() << "\n"; // 50 

	//std::unique_ptr<Rectangle> P2(P1); // not copyable
	std::unique_ptr<Rectangle> P2;       // but movable
	P2 = std::move(P1);              // Transferring ownership
	std::cout << P2->area() << "\n"; // 50

	// std::cout<<P1->area()<<"\n"; // not reachable
	return EXIT_SUCCESS;
}

#endif // SMART_POINTERS_UNIQUE

// Smart Pointers --> std::shared_ptr<>
// --------------------------------------------
// --------------------------------------------

#ifdef SMART_POINTERS_SHARED

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <memory> 

class Rectangle {
public:
	Rectangle(int l, int b){
		length = l;
		breadth = b;
	}

	int area()	{
		return length * breadth;
	}
private:
	int length;
	int breadth;
};

int main(){

	std::shared_ptr<Rectangle> P1(new Rectangle(10, 5));
	std::cout << P1->area() << "\n"; // 50 

	std::shared_ptr<Rectangle> P2;
	P2 = P1; // copy assignment function is called
	std::cout << P2->area() << "\n"; // 50 
	std::cout << P1->area() << "\n"; // 50 - not give an error

	// print 2 as Reference Counter is 2 
	std::cout << P1.use_count() << "\n"; // 2

	return EXIT_SUCCESS;
}

#endif // SMART_POINTERS_SHARED


// Smart Pointers --> std::weak_ptr<> 
// --------------------------------------------
// --------------------------------------------

#ifdef SMART_POINTERS_WEAK

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <memory> 

int main() {

	std::shared_ptr<int> p1 = std::make_shared<int>(5);
	std::weak_ptr<int> wp1{ p1 };  // p1 owns the memory
	std::shared_ptr<int> p3 = wp1.lock();

	return EXIT_SUCCESS;
}


#endif // SMART_POINTERS_WEAK








