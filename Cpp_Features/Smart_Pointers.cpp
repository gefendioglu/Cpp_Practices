#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class SmartPtr {
public:
	explicit SmartPtr(int* p = NULL) { ptr = p; }
	~SmartPtr() { delete (ptr); }

	// Overloading dereferencing operator 
	int& operator*() { return *ptr; }

private:
	int* ptr; // Actual pointer 
};

// A generic smart pointer class 
template <class T>
class SmartPtrTemp {
public:
    explicit SmartPtrTemp(T* p = NULL) { ptr = p; }

    // Destructor 
    ~SmartPtrTemp() { delete (ptr); }

    // Overloading dereferncing operator 
    T& operator*() { return *ptr; }

    // Overloading arrow operator 
    T* operator->() { return ptr; }

private:
    T* ptr; 
};

int main()
{
	SmartPtr ptr(new int());
	*ptr = 20;
	std::cout << *ptr;

    SmartPtrTemp<int> ptr(new int());
    *ptr = 20;
    std::cout << *ptr;

	return 0;
}
