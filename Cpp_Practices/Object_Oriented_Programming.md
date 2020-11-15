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

int main()
{
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

int main()
{
	Point* point_ptr = new Point(10, 20);
	Ellipse* ellipse_ptr = new Ellipse(*point_ptr, 30, 40);
	Rectangle* rectangle_ptr = new Rectangle(*point_ptr, 50, 60);

	std::cout << "rectangle : " << rectangle_ptr->getHeight() << " " << rectangle_ptr->getWidth() << "\n";
	std::cout << "ellipse : " << ellipse_ptr->getHorizontalAxis() << " " << ellipse_ptr->getVerticalAxis() << "\n";
}

// Error	LNK2001	unresolved external symbol "public: virtual class Rectangle __thiscall Shape::getBounds(void)" 
// Error	LNK2001	unresolved external symbol "public: virtual void __thiscall Shape::draw(class Graphics)" 
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

## Virtual Functions 

- In OOP, child classes can override (redefine) methods defined by base classes. 
- Functions declared final cannot be overridden.
- In C++, functions are only virtual when declared with the virtual keyword—nonvirtual methods are the default.
- If the functon is not virtual, the function definition invoked is determined at compile time based on the type of the reference (or pointer).
- Virtual functions are used for polymorphism.
- One special type of virtual function in C++ is a pure virtual method: a function declared but explicitly not defined.
- Any class that contains a pure virtual function or inherits one without redefining it is an abstract class.
- It almost always takes longer to invoke a virtual function because the address of the appropriate function definition must be looked up in a table before it is invoked. This table also requires a small amount of extra memory. In most applications, the overhead associated with virtual functions is so small as to be negligible. 


- **Example** : In the case of using non-virtual member functions 
```cpp
#include <iostream>
#include <string>

class A {
public:
	void print() { std::cout << "A"; }
};

class B : A {
public:
	void print() { std::cout << "B"; }
};

class C : B {
public:
	void print() { std::cout << "C"; }
};

int main()
{
	A* aptr = new A();
	B* bptr = new B();
	C* cptr = new C();

	aptr->print(); // A
	bptr->print(); // B
	cptr->print(); // c

	// Because print is not virtual, the method invoked depends on the type used at compile time :
	((B*)cptr)->print(); // B
	((A*)cptr)->print(); // A
	((A*)bptr)->print(); // A
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : In the case of using virtual member functions 
```cpp
#include <iostream>
#include <string>

class A {
public:
	virtual void print() { std::cout << "A"; }
};

class B : A {
public:
	virtual void print() { std::cout << "B"; }
};

class C : B {
public:
	virtual void print() { std::cout << "C"; }
};

int main()
{
	A* aptr = new A();
	B* bptr = new B();
	C* cptr = new C();

	aptr->print(); // A
	bptr->print(); // B
	cptr->print(); // c

	// The runtime type of the object determines which function definition is invoked : 
	((B*)cptr)->print(); // C
	((A*)cptr)->print(); // C
	((A*)bptr)->print(); // B
}
```

/----------------------------------------------
/----------------------------------------------

## Multiple Inheritance  
- In C++ a class can inherit (directly or indirectly) from more than one class, which is referred to as multiple inheritance. In C# and Java limit classes to single inheritance—each class inherits from a single parent class.
- Multiple inheritance is a useful way to create classes that combine aspects of two disparate class hierarchies.  If two frameworks define their own base classes for exceptions, you can use multiple inheritance to create exception classes that can be used with either framework.
- The complexities exist with multiple inheritance:
  - The problem with multiple inheritance is that it can lead to "ambiguity". 
  - The order in which the base classes are initialized when a derived object is constructed
  - The way members can be inadvertently hidden from derived classes.

- **Example** : The example is when a class inherits from two other classes, each of which inherits from the same class
```cpp
class A {
protected:
	bool flag;
};
class B : public A {};
class C : public A {};
class D : public B, public C {
public:
	void setFlag(bool nflag) {
		flag = nflag; // Error: D::flag is ambiguous
		// The flag data member is defined by class A. 
		// But class D descends from class B and class C, which both derive from A. 
		// So in essence two copies of flag are available because two instances of A are in D’s class hierarchy.
		// Which one do you want to set ?
	}
};
```

- **Solution-1** : To specify which class data member is used with scope resolution operator --> B::flag = nflag; 
- **Solution-2** : To specify class A as virtual base classes to have only one A class object 
```cpp
class A {
protected:
	bool flag;
};
class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {
public:
	void setFlag(bool nflag) {
		flag = nflag; 
	}
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