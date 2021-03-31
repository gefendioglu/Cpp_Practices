
## OBJECT ORIENTED PROGRAMMING (OOP)

- **Class** : A class is an abstract definition of something that has data members and member class functions. 

- **Interface** : The public class member functions provide an interface that is the only access to the data structures contained in the class.

- **Constructor** : Creating an object is called constructing the object. Part of the process involves invoking a "constructor" in the class. The constructor initializes the state of the object. 

- **Destructor** :  In C++ a member function called the destructor is invoked to clean up an object’s state.

- **Inheritance** : It allows a class to be defined as a modified or more specialized version of another class.

- **Polymorphism** : A core concept of OOP, enabled by overriding, is runtime selection of which definition of a class member function should be executed based on the class of the object.

/----------------------------------------------
/----------------------------------------------

- **Example** : Class Implementation 
  - A class definition for Point, which is a pair of integers that represents the x and y values of a point in a Cartesian coordinate plane:
  
```cpp
#include <iostream>
#include <string>

class Point {
public:
	Point() = default;
	Point(int x, int y) :mx{ x }, my{ y } {}
	Point(const Point& other) {
		std::cout << "Copy constructor called " << "\n";
		mx = other.getX();
		my = other.getY();
	}
	Point& operator= (const Point& point) {
		std::cout << "Assignment operator called " << "\n";
		return *this;
	}
	
	// getter functions
	int getX() const { return mx; }
	int getY() const { return my; }

	//setter functions
	void setX(const int& x) { this->mx = x; }
	void setY(const int& y) { this->my = y; }

	// other functions
	Point* relativeTo(int dx, int dy) {
		return new Point(mx + dx, my + dy);
	}
	std::string toString() {
		std::string str;
		str.push_back('(');
		str.push_back(mx);
		str.push_back(',');
		str.push_back((char)my);
		str.push_back(')');
		return str;
	}
private:
	int mx, my;
};

int main() {

	Point cartesian(10, 20);
	std::cout << "mx : " << cartesian.getX() << "\n"; // mx : 10
	std::cout << "my : " << cartesian.getY() << "\n"; // my : 20

	Point* ptr = new Point(30, 40);
	std::cout << "mx : " << ptr->getX() << "\n"; // mx : 30
	std::cout << "my : " << ptr->getY() << "\n"; // my : 40

	Point* p1 = cartesian.relativeTo(5, -5);
	std::cout << "p1 : " << p1->toString() << "\n"; // NOT OK !!! To Be Controlled !!!
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : C++ Object Model

```cpp
class Thing {
public:
    Thing();                        // default constructor
    Thing(const Thing&);            // copy ctor
    Thing& operator=(const Thing&); // copy-assignment
    Thing(Thing&&);                 // move ctor
    Thing& operator=(Thing&&);      // move-assignment
    ~Thing();                       // dtor
};  
```

/----------------------------------------------
/----------------------------------------------

- **Example** : C++ Object Model 
  - All the functions in class/struct contain implicit this pointer as the first argument using to access all non-static data members
  - Static data members are not part of class/struct. Because it usually resides in a data segment of memory layout.
  - The size of the following struct is 4 (because of int type non-static data member). Because of using implicit this pointer as function parameter.

```cpp
struct foo{
	int m_var;
public:
	void print(){ std::cout << m_var << "\n"; }
};
```

- Interpreted as the following: 

```cpp
struct foo{ int m_var; };
void foo::print(foo *this){
    std::cout.operator<<(this->m_var).operator<<(std::endl);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Memory Layout of an Object With Virtual Function & Static Data Member
  - All non-static data members got the space into the stack with the same order of their declaration
  - Static data member got the space into the data segment of memory.
  - Static functions go into the text segment
  - For virtual keyword, the compiler automatically inserts pointer(vptr) to a virtual table into the object memory representation.


```cpp
class MyClass {
public:
    MyClass() {}
    virtual ~MyClass() {}
    virtual void printAll() {}
    void printInt() {}
    void printFloat() {}
    static void printCount() {}
private:
	int ival;
    	float fval;
    	static int count;
};

// stack :
//----------------------------------------------
int MyClass::ival 
float MyClass::fval 
MyClass::_vptr    

// data segment:
//----------------------------------------------
static int MyClass::count 

// text segment:
//----------------------------------------------
MyClass::MyClass()     
MyClass::~MyClass()
MyClass::printAll()
MyClass::printInt()
MyClass::printFloat()
static MyClass::printCount()
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Memory Layout of C++ Object With Inheritance

```cpp
class Base {
public:
	Base() {}
	virtual ~Base() {}
	virtual void printAll() {}
private:
	int x;
	std::string str;
};

class Derived : public Base {
public:
	Derived() {}
	~Derived() {}
	void printAll() {}
private:
	int y;
};

// stack :
//----------------------------------------------
int Base::x  
string Base::str; // (? --> const char*)
Base::_vptr       //--> Members type_info Derived, the address of Derived::~Derived(), the address of Derived::printAll()
int Derived::y

// text segment:
//----------------------------------------------
Base::Base()  
Base::~Base() 
Base::printAll()
Derived::Derived()  
Derived::~Derived()
Derived::printAll() 
string::string()
string::~string() 
string::length()
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Memory Layout of an Object With Multiple Inheritances & Virtual Function

```cpp
class BaseX {
public:
	virtual ~BaseX() {}
	virtual void printX() {}
private: 
	int x;
};

class BaseY {
public:
	virtual ~BaseY() {}
	virtual void printY() {}
private:
	int y;
};

class Derived : public BaseX, public BaseY {
public:
	~Derived() {}
	void printX() {}
	void printY() {}
	void printZ() {}
private:
	int z;
};

// stack :
//----------------------------------------------
```cpp
int BaseX::x 
BaseX::_vptr --> Members type_info Derived, the address of Derived::~Derived(), Derived::printX()
int BaseY::y
BaseY:: _vptr --> Members type_info Derived, the address of Derived::~Derived(), Derived::printY()
int Derived::z

// text segment:
//----------------------------------------------
BaseX::~BaseX()
BaseX::printX()
BaseY::~BaseY() 
BaseY::printY()
Derived::~Derived()
Derived::printX()
Derived::printY()
Derived::printZ()
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Memory Layout of Object Having Virtual Inheritance ???
  - In this case, memory is divided into two regions:
    - an invariant region
    - a shared region

```cpp
class X { int x; };
class Y : virtual public X { int y; };
class Z : virtual public X { int z; };
class A : public Y, public Z { int a; };
```

/----------------------------------------------
/----------------------------------------------

### Temporary Objects:

- After using a temporary object (after evaluating the related row about it), its destructor is called to destroy the object. Each time its constructors are called, whenever a temporary object is created like as a normal object. 

- Sometimes compiler creates a temporary object implicitly, and sometimes user orients the compiler to create a temporary object. 

- Temporary objects are important in terms of efficiency.

- Temporary objects can be linked to  R-Value and const L-Value references. They are not linked to non-const L-Value expressions. 

- Temporary objects are not named, they only include their type names.

- const L-value references can be linked to temporary objects. In that case, the life of temporary objects extended till the end of reference scope (life extension)
  - const Data& ref = Data{ 12 };

- Temporary objects are also used as a return value of a function.

/----------------------------------------------
/----------------------------------------------

- **Example** : Temporary Class Objects 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	Data(): mx{ 0 }, my{ 0 } { std::cout << "Data() default ctor is called...\n"; };
	Data(int x) : mx{ x }, my{ 0 }{	std::cout << "Data(int x) ctor is called...\n";	}
	Data(int x, int y) : mx{ x }, my{ y }{ std::cout << "Data(int x, int y) ctor is called...\n"; }
	~Data() { std::cout << "~Data() destructor is called...\n"; }
	void print()const { std::cout << "mx : " << mx << " my : " << my << "\n"; }
private:
	int mx,my;
};

void func(const Data &ref) { std::cout << "func(const Data& ref) is called...\n"; }
void func(Data&& ref) {	std::cout << "func(Data&& ref) is called...\n"; }

int main() {

	// All the followings are temporary objects
	// They can call directly their class member functions
	Data{}.print();        // Data{} --> PR-Value expr.
	Data{ 12 }.print();    // Data{12} --> PR-Value expr.
	Data{ 12,25 }.print(); // Data{12,25} --> PR-Value expr.

	std::cout << "\n";
	const Data& ref = Data{ 12 };
	
	std::cout << "\n";
	Data data;
	func(data); // data is L-Value expr.
		    // func(const Data &ref) is called

	std::cout << "\n";
	func(Data(15)); // Data(15) is a  PR-Value expr. 
			// Data(15) can be linked to const L-Val.
			// Data(15) can be linked to R-Val.
			// both func() are viable (?)
	
	return EXIT_SUCCESS;
	
	/*
		Data() default ctor is called...
		mx : 0 my : 0
		Data(int x) ctor is called...
		mx : 12 my : 0
		Data(int x, int y) ctor is called...
		mx : 12 my : 25
		~Data() destructor is called...

		Data(int x) ctor is called...

		Data() default ctor is called...
		func(const Data& ref) is called...
		
		Data(int x) ctor is called...
		func(Data&& ref) is called...
		~Data() destructor is called...
		~Data() destructor is called...
		~Data() destructor is called...
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Temporary objects as function return value and as arguments sent to a function  

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

void func(const std::string& ref) { std::cout << "string : " << ref << "\n"; }

std::string func() {
	char c = 'B';
	//...
	return std::string(100, c); // temp. object 
}

int main() {

	// calling func(const std::string& ref) with temp. object
	func(std::string(100, 'A')); 
	
	std::cout << "\n";
	func();

	return EXIT_SUCCESS;
	/*
		Executed again!!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Object Oriented Programming (Inheritance, Virtual Functions) TO BE CONTROLLED !!!
  - A shapes library representing the different shapes in a vector-based drawing application.
  - At the top of the hierarchy is the "Shape" class, which defines the things that all shapes have in common
  - You can then specialize the shapes into "Rectangle" and "Ellipse" subclasses.
  - The Rectangle and Ellipse classes could be further specialized into "Square" and "Circle" subclasses.
  - Adding a new shape to the library shall be just a matter of subclassing one of the existing classes and implementing the things that are different.
  
```cpp
#include <iostream>

class Point {
public:
	Point() = default;
	Point(int x, int y) :mx{ x }, my{ y } {}
	Point(const Point& other) {
		std::cout << "Copy constructor called " << "\n";
		mx = other.getX();
		my = other.getY();
	}

	Point& operator= (const Point& point) {
		std::cout << "Assignment operator called " << "\n";
		return *this;
	}
	int getX() const { return mx; }
	int getY() const { return my; }
	void setX(const int& x) { this->mx = x; }
	void setY(const int& y) { this->my = y; }
	Point* relativeTo(int dx, int dy) { return new Point(mx + dx, my + dy);	}
private:
	int mx{ 0 }, my{ 0 };

};

class Rectangle;

// Base Class
class Shape {
public:
	Point getCenter() const { return center; }
	virtual Rectangle getBounds();
protected:
	Point center;
	Shape() {
		this->center.setX(0);
		this->center.setY(0);
	}
	Shape(Point center) { this->center = center; }
};

// Derived Class inherited from Shape class
class Rectangle : public Shape {
public:
	Rectangle() :height{ 0 }, width{ 0 } {}
	Rectangle(Point center, int h, int w) {
		this->center = center;
		height = h;
		width = w;
	}
	Rectangle getBounds() override {
		return *this;
	}
	int getHeight() const { return height; }
	int getWidth() const { return width; }

private:
	int height{ 0 };
	int width{ 0 };
};

// Derived Class inherited from Shape class
class Ellipse : public Shape {
public:
	Ellipse() :horizontalAxis{ 0 }, verticalAxis{ 0 }{}
	Ellipse(Point center, int h, int v) {
		this->center = center;
		horizontalAxis = h;
		verticalAxis = v;
	}

	Rectangle getBounds() override {
		Rectangle* ptr = new Rectangle(center, horizontalAxis * 2, verticalAxis * 2);
		return (*ptr);
	}
	int getHorizontalAxis()const { return horizontalAxis; }
	int getVerticalAxis() const { return verticalAxis; }

private:
	int horizontalAxis{ 0 };
	int verticalAxis{ 0 };
};

int main() {

	Point* point_ptr = new Point(10, 20);
	Ellipse* ellipse_ptr = new Ellipse(*point_ptr, 30, 40);
	Rectangle* rectangle_ptr = new Rectangle(*point_ptr, 50, 60);

	std::cout << "rectangle : " << rectangle_ptr->getHeight() << " " << rectangle_ptr->getWidth() << "\n";
	std::cout << "ellipse : " << ellipse_ptr->getHorizontalAxis() << " " << ellipse_ptr->getVerticalAxis() << "\n";
}

// Error LNK2001 unresolved external symbol "public: virtual class Rectangle __thiscall Shape::getBounds(void)" 
// Error LNK2001 unresolved external symbol "public: virtual void __thiscall Shape::draw(class Graphics)" 
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Interfaces && Abstract Classes 
  - An interface declares a set of related member functions, outside of any class.
    - An interface is equivalent to an abstract class with no data members and no method definitions.
	- In C++ an interface is defined by declaring a class with no data members and only pure virtual functions.
	- Supporting both interfaces and abstract classes are the provision of a default implementation of an interface via an abstract class.
  - An abstract class is an incomplete class definition that declares but does not define all its methods.
  - Abstract classes cannot be instantiated. Only the instances of concrete subclasses can be created.
  - In general, abstract classes are useful when the classes derived from them are more specific types of the base class (is-a relationship), particularly when there’s some shared functionality in the abstract base class that derived classes can use.
  
```cpp
class StatusCallback {
public:
	virtual void updateStatus(int oState, int nState) = 0;
};

class MyClass : StatusCallback {
public:
	void updateStatus(int oState, int nState) override {
		if (nState > oState) {
			// code...
		}
	}
	// remainder of class
};
```
/----------------------------------------------
/----------------------------------------------

## Resource Management 

- In C++, whenever you exit a function, whether by a return statement or because of an exception, all of the automatic (local) objects that pass out of scope are destroyed. How might you use this to ensure that you avoid leaking resources?

- You can create a class to wrap the resource. If you call openResource in the constructor and closeResource in the destructor, you can use the life cycle of the object to manage the resource. All you have to do is remember to declare the object as a local object on the stack so that it will be automatically destroyed (static objects?).

- A violation of this case: If an instance of the wrapper class were copied, then both objects would wrap the same resource handle, and each object would try to release the handle when the object was destroyed. One way to guard against this is to declare private copy constructor and assignment operators to prevent the object from being duplicated.

- The C++ approach represents all of the necessary logic in one place in the wrapper class, so there’s no duplication and the code that uses the resource is simple and clean.

- The pattern embodied by this C++ approach is commonly called Resource Acquisition Is Initialization (RAII), and is the preferred way to manage resources in C++. RAII relies on deterministic, immediate destruction of automatic objects when they go out of scope, which ensures that resources are released as soon as they’re no longer accessible through their wrapper objects.

- C# and Java provides try/finally functionality for resource management, but lacks the ability to do true RAII because it does not have deterministic destruction of automatic objects. (Java 1.7 added try-with-resources that is more limited than RAII in C++)

/----------------------------------------------
/----------------------------------------------

- **Example** : Resource Management (Pseudo Code)
  - Suppose you have a function that needs to access a limited system resource. 
  - The code must call an API function openResource to obtain a handle to the resource, and must pass this handle to a function closeResource when it’s done. 
  - How can you ensure that closeResource will be called in all cases and the resource will never be leaked?

```cpp
class Resource {
public:
	Resource() { handle = openResource(); } // memory is allocated in constructor 
	~Resource() { closeResource(handle); }  // memory is deallocated in ddestructor by destroying object 
	ResourceHandle getHandle() { return handle; }
private:
	ResourceHandle handle;
	Resource(Resource const&);             // private copy constructor as a guard (why isnt it deleted?) 
	Resource& operator= (Resource const&); // private assignment operator as a guard (why isnt it deleted?)
};

void useResource() {
	Resource r; 
	/* Use resource here */
}
```

/----------------------------------------------
/----------------------------------------------
