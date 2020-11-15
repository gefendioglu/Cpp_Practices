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
private:
	int mx{ 0 }, my{ 0 };

};

class Rectangle;
class Graphics {};

class Shape {
public:

	Point getCenter() const { return center; }
	virtual Rectangle getBounds();
	virtual void draw(Graphics g);
protected:
	Point center;
	Shape() {
		this->center.setX(0);
		this->center.setY(0);
	}
	Shape(Point center) { this->center = center; }

};

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
	void draw(Graphics g) override {
		// code to paint rectangle
	}
	int getHeight() const { return height; }
	int getWidth() const { return width; }

private:
	int height{ 0 };
	int width{ 0 };
};

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
	void draw(Graphics g) override {
		// code to paint ellipse
	}

	int getHorizontalAxis()const { return horizontalAxis; }
	int getVerticalAxis() const { return verticalAxis; }

private:
	int horizontalAxis{ 0 };
	int verticalAxis{ 0 };
};

int main()
{
	Shape* shape;
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
