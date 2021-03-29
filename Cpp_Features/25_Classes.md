
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
