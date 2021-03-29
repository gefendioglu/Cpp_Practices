
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
