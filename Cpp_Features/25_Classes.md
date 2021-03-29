
## CLASS TYPES

- **Data Abstraction** is the most important phenomenon.

- **Class Definition** & **Class Declaration** are different mechanism. 

- Both "struct" and "class", they are assumed as classes in C++ environment.

- **data members** (for the data in a class):
  - non-static data members
  - static data members

- **class member functions** (for the functions in a class):
  - non-static member functions
    - non-const member functions
    - const member functions
  - static member functions

- **nested types** (member types, type members)
  
/----------------------------------------------
/----------------------------------------------

- **Example** : Data member and class member functions in C++

```cpp
struct MyClass {
	int mx, my;         // non-static data member
	static double dval; // static data member
	void func(int);     // non-static member function
	static int foo();   // static member function 
	typedef int Word;
	enum class Color{Red, Green};
};
```
/----------------------------------------------
/----------------------------------------------

## Name Lookup

- The results of name lookup in C++:
  - syntax error 
    - compiler can not find any definitions related to the name)
	  - compiler can find more than one definitions related to the name (ambiguity error)
    - compiler can understand what the name is

- Name lookup rules in C+:
  - name lookup is ended after finding the name, not started again
  - name hiding (name masking, name shadowing)
  - The order of controls in C++: 
    - name lookup
	  - context control (R-Value, L-Value expression assignment error)
	  - access control (using access specifiers: public, private, protected)

/----------------------------------------------
/----------------------------------------------

- **Example** : Name Lookup Sample (name hiding)

```cpp
int main() {

	int printf = 0;
	printf("gamze"); // name lookup error, cause printf name is found in the same function scope

}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name Lookup Sample (name hiding)
- 
```cpp
int func(int);

int main() {
	int func = 0;
	func(12); // name lookup error, func name is found
	func++;   // not a syntax error
}
```

/----------------------------------------------
/----------------------------------------------

### When is a name searched in Class Scope?
- The name is in the right operand wrt. dot operator (member selection operator)
- The name is in the right operand wrt. arrow operator (member selection operator)
- The name is in the right operand wrt. scope resolution operator (::)
  - Namespace::right_operand OR ClassName::right_operand

/----------------------------------------------
/----------------------------------------------

## Access Control
- Access specifiers : public, private, protected 

- default access specifier : private for class, public for struct

- public --> public interface (this interface is open for client code)
  - public functions and global functions are in the same scope
  
- private --> private interface (is only open for class code)

- protected --> protected interface (is only used for inheritance, is open for derived class code, not for client code)

- access specifiers don't specify any scope definition, all data members and class member functions are in the same class scope. 
The same names can not be used twice or more regardless of its access specifier. 

/----------------------------------------------
/----------------------------------------------

- **Example** : All data members and class member functions are in the same class scope

```cpp
class MyClass {
public:
	int x;
private:
	int x();
};

int main() {
	MyClass myclass;
	myclass.x; // syntax error
} 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : A class member is the hidden parameter in the class member functions. 

```cpp
class MyClass {
public:
	void func(int); // like as : void func(MyClass *ptr, int);
};

int main(){
	MyClass::func(10); // syntax error, it is necessary to have a class object to send as a parameter for this class member function
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Dereferencing a pointer (pointed to nullptr address), it is an undefined behaviour 

```cpp
class MyClass {
public:
	void func();
private:
	int mx, my, mz;
};

int main() {

	MyClass* ptr = nullptr; // if it is dereferenced, ub
	ptr->func();
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function overloading with class member functions

```cpp
class MyClass {
public:
	void func();
	void func(int); // func. overloading, in the same scope
	void func(int, int, int);  // func. overloading, in the same scope
	void func(double); // func. overloading, in the same scope
private:
	int mx, my, mz;
}; 

void func(int); // not a function overloading
                // functions should be in the same scope

int main(){

	MyClass myclass;
	myclass.func();    // --> calls void func();
	myclass.func(12);  // --> calls void func(int);
	myclass.func(1.2); // --> calls void func(double); 
	myclass.func(1u);  // --> syntax error, ambiguity 
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : A sample for access specifier 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class MyClass {
public:
	void func(int);
private:
	void func(double); // func. overloading, in the same class scope 
	int mx, my, mz;
};

int main() {

	MyClass myclass;
	myclass.func(12.34); // syntax error, private member func., access control is done after name lookup  
	myclass.func(12); // not ayntax error
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function redecleration for class member functions

```cpp
void func(int);
void func(int); // func. redecleration is not an error here

class MyClass {
public:
	void func(int);
	void func(int); // syntax error,function redecleration is not allowed for class member function
private:
	int mx, my, mz;
};
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The size of class member functions
  - What if they are virtual class member functions?
    - In that case, virtual function pointer is added for each virtual class member functions (size of pointer is 8 bytes in this compiler)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "myclass.h"

// myclass.h
class MyClass {
public:
	void func1(double); // no effect on the storage
	void func2(double); // no effect on the storage
	void func3(double); // no effect on the storage
private:
	int mx, my, mz; // sizeof(int) : 4 bytes
};

// myclass.cpp
void MyClass::func1(double dval){ //...}
void MyClass::func2(double dval){ //...}
void MyClass::func3(double dval){ //...}
void func4(double dval){//...} // not a member func., it is global func.

// main.cpp
int main() {

	std::cout << "sizeof(MyClass) : " << sizeof(MyClass);
	// sizeof(MyClass) : 12 (int + int + int = 12 bytes)
	func4(14.2); // calling global func. 
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The class member function definition in .cpp file
  - In .cpp file, the access specifier type of a class member function is not understood.

```cpp
class MyClass {
public:
	void func(int x, int y); 
private:
	void foo();
	int mx, my, mz; // sizeof(int) : 4 bytes
};

// The access specifiers of member functions are not important for their definitions in .cpp files. 
void MyClass::func(int x, int y){
	// ....
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : One of the solution to understand the access specifier type of a class member function, 
to define its access modifier type as a macro

```cpp
// myclass.h
class MyClass {
public:
	void func(int x, int y); 
private:
	void foo();
	int mx, my, mz; // sizeof(int) : 4 bytes
};

// myclass.cpp
#define PUBLIC  // compiler will delete this macro definition
#define PRIVATE // compiler will delete this macro definition

PUBLIC void MyClass::func(int x, int y){
	//...
}

PRIVATE void MyClass::foo() {
	//...
}
```

/----------------------------------------------
/----------------------------------------------

## Name Lookup for Class Member Functions Definitions
- function scope --> class scope --> global scope

/----------------------------------------------
/----------------------------------------------

- **Example** : Name shadowing by local variables on global variables

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int x = 20;

int main() {

	int x = 10;
	std::cout << "x : " << x << "\n";   // x : 10
	std::cout << "x : " << ::x << "\n"; // x : 20
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name shadowing 

```cpp
int main() {
	double x = 10.2;
	if (true)
	{
		int x = 10;
		std::cout << "x : " << x << "\n";   // x : 10
		// no way to reach the double x variable
	}
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name lookup and class data members

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo();
private:
	int mx, my; // data member mx
};

int mx = 30; // global mx 

// myclass.cpp
void MyClass::func() {
	
	int mx = 10;   // local mx
	++mx;          // local mx 
	++::mx;        // global mx
	++MyClass::mx; // data member mx
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name lookup and global functions 

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo();
private:
	int mx, my; 
};

void g();

// myclass.cpp
void MyClass::func() {
	int g = 10;
	g(); // syntax error, not calling global g() func. 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name shadowing and class data members wrt. the class objects that call class member functions

```cpp
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
	
	mx = 12; // not syntax error, found from class scope
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name lookup and class member functions 

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo(int);
private:
	int mx, my; 
};

void foo();

// myclass.cpp
void MyClass::func() {
	foo(); // syntax error, no an appropriate class member func. in class scope
	::foo(); // not syntax error, calls global foo() func.
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name lookup and class member functions 

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo(int);
private:
	int mx, my; 
};

void func(int);

// myclass.cpp
void MyClass::func() {
	func(10); // syntax error, func name is found in the class scope, but no appropriate func function. 
	func(); // not syntax error, recursive function calling 
	::func(12); // not syntax error, global function calling
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name lookup and class member functions 

```cpp
// myclass.h
class MyClass {
public:
	void func(int);
private:
	void func(double);
	int mx, my; 
};

int main() {
	MyClass myclass;
	myclass.func(1.2); // syntax error, private access specifier
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name lookup and class member functions 

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo(int);
private:
	int mx, my; 
};

MyClass gm;

void MyClass::func() {
	gm.mx = 10;
}
```

/----------------------------------------------
/----------------------------------------------

## Setter && Getter Functions 

- void foo(struct MyClass* ptr); --> setter function

- void func(const struct MyClass* ptr); --> getter function
  - void func() const; --> const member function (in a class)
  - void func(); --> non-const member function (in a class)
  
- const member functions dont change the class objects (its specifications, etc.)

- const correctness is the most important semantic specification in C++ 

/----------------------------------------------
/----------------------------------------------

- **Example** :  const correctness

```cpp
class Counter {
public:
	void print() const; // a const member function, not change the class object spec.
};

class Account {
public:
	void deposit(double sum); // not const func., cause it changes the class object specs.
};
```

/----------------------------------------------
/----------------------------------------------

- **Example** : const overloading

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo();
 	void foo()const; // const overloading
private:
	int mx, my; 
};

void func() const{} // syntax error for global func. 

// myclass.cpp
void MyClass::foo() const { // const keyword shall be here
	//...
	mx = 10;    // syntax error, this func. can not change 
	
	int a = mx; // not syntax error, mx can be used here 
	MyClass myclass; 
	myclass.mx = 10; // not syntax error
				     // there is no control on the other class objects 
}

void MyClass::func() { 
	//...
	mx = 10; // not syntax error, this func. is not const
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : const overloading

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo(); 
 	void foo()const; // const overloading
   // like as :  void foo(const MyClass *ptr); 
private:
	int mx, my; 
};

int main() {
	MyClass myclass;
	const MyClass cmyclass;

  myclass.func();  // OK, not syntax error 
	myclass.foo();   // OK, not syntax error 
	cmyclass.foo();  // OK, not a syntax error
	cmyclass.func(); // NOT OK, syntax error, 
					         // const T* --> T* not possible,not allowed
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
// myclass.h
class MyClass {
public:
	void func();
	void foo()const; 
	void g()const;
private:
	int mx, my;
};

void MyClass::func() {
	foo(); // OK, not syntax error
	       // T* --> const T* is allowed !!!
}

void MyClass::foo() const {
	func(); // NOT OK, syntax error
	        // const T* --> T* is NOT allowed !!!
	g();    // OK, not syntax error, both are const func. 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Const overloading and class member functions

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// myclass.h
class MyClass {
public:
	void func();
	void func()const;
private:
	int mx, my;
};

// myclass.cpp
void MyClass::func() {
	std::cout << "Myclass::func()\n";
}

void MyClass::func() const {
	std::cout << "Myclass::func() const\n";
}

int main() {
	const MyClass cmyclass;
	cmyclass.func(); // viable function: void func()const; 
	// Myclass::func() const
	// const object --> calls const function

	MyClass myclass;
	myclass.func();
	// Myclass::func()
	// non-const object --> calls non-const function
}
```

/----------------------------------------------
/----------------------------------------------

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

## Inline Functions

- This functions are used for compiler optimization (as an inline expansion)

- Some compiler optimization techniques: loop unrolling, dead code elimination 

- Inline Optimization in terms of compilers: 
  - It is mandatory to see the inline function definition for inline optimization
  - It is not guaranteed that each inline functions is used for optimization, it is depend on compiler decision 
  - Compilers can have some switches to make an optimization 
  - If user is used "inline" keyword, in that case compiler is forced to make inline expansion. But, the compiler doesnt have to do apply this.  

/----------------------------------------------
/----------------------------------------------

- **Example** : Inline Optimization   

```cpp
inline int sum_square(int x, int y) {
	return x * x + y * y;
}

int main() {
	
	int number1 = 10, number2 = 20;
	int result = sum_square(number1, number2);
	// int result = number1 * number1 + number2 * number2; 
  
}
```

/----------------------------------------------
/----------------------------------------------

## ODR : One Definition Rule

- What is ODR Violation? 
  - If a function definition is made in a header file, then there will be an ODR violation whenever more than one source files including this header file. In this case, this function definition is repeated for each source files.  
  - If "inline" keyword is used with the function, this prevents to make an ODR violation. 
  
- The usage of inline functions can be verified by a profiler or a benchmarking tool.

- The inline function definitions for class member functions:
  - "constexpr" functions are implicitly inline functions
  - both const non-static member functions and non-const non-static member functions can be defined as inlined functions in a class
  - static member functions can be defined as inlined functions in a class
  - friend member functions can also be defined as inlined functions 
  
- Compiler can optimize much bigger code block at the same time by using inline functions. 

- The types of inline definitions:  
  - inline class definitions
  - inline function definitions
  - inline variable definition  

/----------------------------------------------
/----------------------------------------------

- **Example** : Inline Optimization   

```cpp
// myclass.h
class MyClass {
public:
	int func(int);
	// not common to use inline keyword in class. 
	inline int foo(int x) { 
		return x + x;
	}
private:
	int mx, my;
};

// ODR Violation 
int foo(int x, int y) {
	return x * y;
}

// inline keyword prevents ODR violation 
inline int foo(int x, int y, int z) {
	return x + y - z;
}

// myclass.cpp
inline int MyClass::func(int x){
	return x * x;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : "constexpr" functions are implicitly inline functions

```cpp
// myclass.h
class MyClass {
public:
	int func(int);
	
	// inline non-static member function with inline keyword
	inline int foo(int x) { 
		//...
		return x + x;
	}

	// inline static member function 
	static int foo(int a, int b) {
		//...
		return a + b;
	}

	// inline friend member function 
	friend int goo(int x) {
		//...
		return foo(x,x);
	}
private:
	int mx, my;
};

// recursive - constexpr functions  
// Even if there is no inline keyword, this constexpr function is an inline function
constexpr int factorial(int number) {
	return number < 2 ? 1 : factorial(number-1)*number;
}
```

/----------------------------------------------
/----------------------------------------------
