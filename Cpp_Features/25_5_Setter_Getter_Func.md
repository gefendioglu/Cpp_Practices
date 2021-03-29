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
