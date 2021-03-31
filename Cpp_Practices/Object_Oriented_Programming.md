
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
int MyClass::ival; 
float MyClass::fval; 
MyClass::_vptr;    

// data segment:
//----------------------------------------------
static int MyClass::count; 

// text segment:
//----------------------------------------------
MyClass::MyClass();     
MyClass::~MyClass();
MyClass::printAll();
MyClass::printInt();
MyClass::printFloat();
static MyClass::printCount();
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
int Base::x;  
string Base::str; // (? --> const char*)
Base::_vptr;      //--> Members type_info Derived, the address of Derived::~Derived(), the address of Derived::printAll()
int Derived::y;

// text segment:
//----------------------------------------------
Base::Base();  
Base::~Base(); 
Base::printAll();
Derived::Derived();  
Derived::~Derived();
Derived::printAll();
string::string();
string::~string(); 
string::length();
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
int BaseX::x;
BaseX::_vptr; // --> Members type_info Derived, the address of Derived::~Derived(), Derived::printX()
int BaseY::y;
BaseY::_vptr; // --> Members type_info Derived, the address of Derived::~Derived(), Derived::printY()
int Derived::z;

// text segment:
//----------------------------------------------
BaseX::~BaseX();
BaseX::printX();
BaseY::~BaseY(); 
BaseY::printY();
Derived::~Derived();
Derived::printX();
Derived::printY();
Derived::printZ();
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
