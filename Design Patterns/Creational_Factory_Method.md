
## Factory Design Pattern 

/----------------------------------------------
/----------------------------------------------

- **Example**: The Problem
  - This isn’t possible as you might know you can not create two constructors with the same type of arguments.

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

enum class PointType { cartesian, polar };

class Point {
   
public:
    // Polar coordinates
    Point(float a, float b, PointType type = PointType::cartesian)
    {
        if (type == PointType::cartesian) {
            Point(a, b);
        }
        else {
            Point(a * cos(b), a * sin(b));
        }
    }
};
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Factory Method 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include<iostream> 

enum class PointType { cartesian, polar };

class Point {

public:
    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }

    // Static class member function for cartesian coord.
    static Point NewCartesian(const float &x, const float &y) {
        return { x, y, PointType::cartesian };
    }

    // Static class member function for polar coord.
    static Point NewPolar(const float &a, const float &b) {
        return { a * cos(b), a * sin(b), PointType::polar };
    }

private:
    float         m_x;
    float         m_y;
    PointType     m_type;

    // Private constructor
    // The object can't be created directly
    Point(const float &x, const float &y, PointType t) : m_x{ x }, m_y{ y }, m_type{ t } {}
};

int main() {

    // Point p{ 1,2 };  // Not Work!!!
    auto p = Point::NewPolar(5, M_PI_4);
    std::cout << p << "\n";  // x: 3.53553 y: 3.53553

    return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Classical Factory Design Pattern (using a concrete class)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include<iostream> 

class Point {

public:
    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }

    // The violation of Open-Closed Principle(OCP) because of friend
    friend class PointFactory;

private:
    float         m_x;
    float         m_y;

    // Private constructor
    Point(const float &x, const float &y) : m_x{ x }, m_y{ y } {}
};

// Concrete Class
class PointFactory {
public:

    // Static class member function for cartesian coord.
    static Point NewCartesian(const float& x, const float& y) {
        return { x, y};
    }

    // Static class member function for polar coord.
    static Point NewPolar(const float& r, const float& theta) {
        return { r * cos(theta),  r* sin(theta)};
    }
};


int main() {

    // Point p{ 1,2 };  // Not Work!!!
    auto pp = PointFactory::NewPolar(5, M_PI_4);
    std::cout << pp << "\n";  // x: 3.53553 y: 3.53553

    auto pc = PointFactory::NewCartesian(5, M_PI_4);
    std::cout << pc << "\n";  // x: 5 y: 0.785398

    return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Inner Factory

```cpp
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include<iostream> 

class Point {
public:
    struct Factory {

        static Point NewCartesian(float x, float y) { 
            return { x,y }; 
        }

        static Point NewPolar(float r, float theta) { 
            return{ r * cos(theta), r * sin(theta) }; 
        }
    };

    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }

private:
    float   m_x;
    float   m_y;
    Point(float x, float y) : m_x(x), m_y(y) {}
};

int main() {

    // Point p{ 1,2 };  // Not Work!!!
    auto pp = Point::Factory::NewPolar(5, M_PI_4);
    std::cout << pp << "\n";  // x: 3.53553 y: 3.53553

    auto pc = Point::Factory::NewCartesian(5, M_PI_4);
    std::cout << pc << "\n";  // x: 5 y: 0.785398

    return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------
