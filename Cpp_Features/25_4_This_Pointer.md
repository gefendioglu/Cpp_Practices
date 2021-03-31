## This Pointer

- "this" keyword is only used in non-static class member functions

- this pointer is used as the address of the object for which it is called in C++. 

- *this represents represents the object itself in C++. 

- "this" keyword is not a pointer in C# and Java languages. In these languages, "this" keyword represents the object itself.

- "this" pointer is used to deal with the name shadowing problem caused by local data members which have the same names.

- *this --> L-Value && this --> R-Value

/----------------------------------------------
/----------------------------------------------

- **Example** : This pointer 

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo();
	void func()const;
private:
	int mx, my;
};

// myclass.cpp
void MyClass::func() {

	this->mx = 10; // mx = 10;
	this->my = 20; // my = 20;
	this->foo();   // foo();
	std::cout << "Myclass::func()\n";
  
}

void MyClass::foo() {

	int mx = 10; 
	mx = 20; // this is local data : mx

	this->mx = 30;    // this is class data member : mx
	(*this).mx = 40;  // this is class data member : mx
	MyClass::mx = 30; // this is also class data member : mx
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of this pointer in class member functions 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// myclass.h
class MyClass {
public:
	void func();
	void foo();
private:
	int mx, my;
};

// myclass.cpp
void MyClass::func() {
	std::cout << "Myclass::func() is called \n";
	std::cout << "this : " << this << "\n";
	foo();
}

void MyClass::foo() {
	std::cout << "Myclass::foo() is called \n";
	std::cout << "this : " << this << "\n";
}

int main() {
	
	MyClass myclass;
	std::cout << "&myclass : " << &myclass << "\n";
	myclass.func();
	
	// The address values should be the same for the same instance
	/*
		The address values should be the same for the same instance
		&myclass : 00CFFE10
		Myclass::func() is called
		this : 00CFFE10
		Myclass::foo() is called
		this : 00CFFE10
	*/	
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of this pointer (with global functions)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// myclass.h
class MyClass {
public:
	void func();
	void foo();
private:
	int mx, my;
};

void gf1(MyClass* ptr) {
	std::cout << "Global gf1() function is called \n";
	std::cout << "ptr : " << ptr << "\n";
}

void gf2(MyClass& ref) {
	std::cout << "Global gf2() function is called \n";
	std::cout << "ref : " << &ref << "\n";
}

// myclass.cpp
void MyClass::func() {

	std::cout << "Myclass::func() is called \n";
	std::cout << "this : " << this << "\n";
	gf1(this);  // gf1 func. takes this pointer as argument 
	gf2(*this); // gf2 func. takes the member instance as argument 
}

int main() {
	
	MyClass myclass;
	std::cout << "&myclass : " << &myclass << "\n";
	myclass.func();
	
	// The address values should be the same for the same instance
	/*
		&myclass : 008FFDD8
		Myclass::func() is called
		this : 008FFDD8
		Global gf1() function is called
		ptr : 008FFDD8
		Global gf2() function is called
		ref : 008FFDD8
	*/
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of this pointer 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// myclass.h
class MyClass {
public:
	void func();
	MyClass* foo_ptr(); 
	MyClass& foo_ref();
private:
	int mx, my;
};

// myclass.cpp
MyClass* MyClass::foo_ptr() {
	//...
	return this; // return the address of object
}

MyClass& MyClass::foo_ref() {
	//...
	return *this; // return the object
}

int main() {
	MyClass myclass;
	myclass.foo_ptr();
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of this pointer 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// myclass.h
class MyClass {
public:
	MyClass& foo_ref1();
	MyClass& foo_ref2();
	MyClass& foo_ref3();
	MyClass& foo_ref4();
private:
	int mx, my;
};

MyClass& MyClass::foo_ref1() {
	std::cout << "foo_ref1() is called\n";
	return *this;
}

MyClass& MyClass::foo_ref2() {
	std::cout << "foo_ref2() is called\n";
	return *this;
}

MyClass& MyClass::foo_ref3() {
	std::cout << "foo_ref3() is called\n";
	return *this;
}

MyClass& MyClass::foo_ref4() {
	std::cout << "foo_ref4() is called\n";
	return *this;
}


int main() {
	
	MyClass myclass;
	
	// Fluent API for C++
	myclass.foo_ref1().foo_ref2().foo_ref3().foo_ref4();
	/*
		foo_ref1() is called
		foo_ref2() is called
		foo_ref3() is called
		foo_ref4() is called
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of fluent API with operator overloading 
  - std::cout << ival << dval << flag;
  - std::cout.operator<<(ival).operator<<(dval).operator<<(flag);

```cpp
int main() {
	
	int ival = 10;
	double dval = 12.1;
	bool flag = true; 
	
	// The same expressions for fluent API in C++: 
	std::cout << ival << dval << flag;
	std::cout.operator<<(ival).operator<<(dval).operator<<(flag);

}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of this pointer and constantness

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo() const;
private:
	int mx, my;
};

MyClass global;

// myclass.cpp
void MyClass::foo() const {
	*this = global; // NOT OK, const MyClass object
	this->mx = 10;  // NOT OK, const MyClass object
}

void MyClass::func() { 
	*this = global; // OK, non-const MyClass object
	this->mx = 10;  // OK, non-const MyClass object
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of this pointer and const member functions

```cpp
// myclass.h
class MyClass {
public:
	MyClass* func1();
	MyClass& func2();
	
	MyClass* func3()const;
	MyClass& func4()const;

	const MyClass* func5()const;
	const MyClass& func6()const;

private:
	int mx, my;
};

// myclass.cpp
MyClass* MyClass::func1() {
	//...
	return this;
}

MyClass& MyClass::func2() {
	//...
	return *this;
}

MyClass* MyClass::func3()const {
	//...
	return this; // NOT OK, T* --> const T* is not allowed!!!
}

MyClass& MyClass::func4()const {
	//...
	return *this; // // NOT OK, T& --> const T& is not allowed!!!
}

const MyClass* MyClass::func5()const {
	//...
	return this; // OK
}

const MyClass& MyClass::func6()const {
	//...
	return *this; // OK
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : This pointer features 

```cpp
// myclass.h
class MyClass {
public:
	void func();      // --> void func(MyClass* const this);
	void foo() const; // --> (const MyClass* const this);
private:
	int mx, my;
};

MyClass global;

// myclass.cpp
void MyClass::func() {
	this = &global; // NOT OK, this pointer is R-Value expression
	                // this pointer is a const itself
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of const parameter and const pointer in a function
  - low level const --> The object pointed by the pointer cannot be changed.
  - top level const --> The pointer itself cannot be changed.
  - TO BO CHECKED !!!

```cpp
struct Data {
	int mx, my;
};

struct Data gstruct;

void func(const struct Data* const ptr) { // both top & low level const
	*ptr = gstruct; // NOT OK, because of first const
	ptr = &gstruct; // NOT OK, because of second const (const ptr)
}

void foo(const struct Data* ptr) { // low level const 
	*ptr = gstruct; // NOT OK, because of first const
	ptr = &gstruct; // OK, because of non-const ptr
}

void goo(struct Data* ptr) {
	*ptr = gstruct; // OK, because of non-const struct parameter 
	ptr = &gstruct; // OK, because of non-const ptr
}
```

/----------------------------------------------
/----------------------------------------------
