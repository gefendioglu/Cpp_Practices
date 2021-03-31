## Name Lookup Rules

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
