#pragma once

#ifdef CREATIONAL_FACTORY

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream> 

class Point {
public:
    struct Factory {

        static Point NewCartesian(double x, double y) {
            return { x,y }; 
        }

        static Point NewPolar(double r, double theta) {
            return{ r * cos(theta), r * sin(theta) };
        }
    };

    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }

private:
    double   m_x;
    double   m_y;
    Point(double x, double y) : m_x{ x }, m_y{ y } {}
};

int main() {

    // Point p{ 1,2 };  // Not Work!!!
    auto polar = Point::Factory::NewPolar(5, M_PI_4);
    std::cout << polar << "\n";  // x: 3.53553 y: 3.53553

    auto cartesian = Point::Factory::NewCartesian(5, M_PI_4);
    std::cout << cartesian << "\n";  // x: 5 y: 0.785398

    return EXIT_SUCCESS;
}

#endif // CREATIONAL_FACTORY


#ifdef CREATIONAL_FACTORY_I

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream> 

enum class PointType { cartesian, polar };

class Point {
public:
    // Static class member function for cartesian coord.
    static Point NewCartesian(const double& x, const double& y) {
        return { x, y, PointType::cartesian };
    }

    // Static class member function for polar coord.
    static Point NewPolar(const double& x, const double& y) {
        return { x * cos(y), x * sin(y), PointType::polar };
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }

private:
    double m_x;
    double m_y;
    PointType m_type;

    // Private constructor
    // The object can't be created directly
    Point(const double& x, const double& y, PointType type) : m_x{ x }, m_y{ y }, m_type{ type } {}
};

int main() {

    // Point p{ 5, M_PI_4 };  // Not Work!!!
    auto p = Point::NewPolar(5, M_PI_4);
    std::cout << p << "\n";  // x: 3.53553 y: 3.53553

    return EXIT_SUCCESS;
}

#endif // CREATIONAL_FACTORY_I

#ifdef CREATIONAL_FACTORY_II

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream> 

class Point {
public:
    // The violation of Open-Closed Principle (OCP) here, because of using friendship 
    friend class PointFactory;
    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
private:
    double m_x;
    double m_y;

    // Private constructor
    Point(const double& x, const double& y) : m_x{ x }, m_y{ y } {}
};

// Concrete Class
class PointFactory {
public:
    // Static class member function for cartesian coord.
    static Point NewCartesian(const double& x, const double& y) {
        return { x, y };
    }
    // Static class member function for polar coord.
    static Point NewPolar(const double& r, const double& theta) {
        return { r * cos(theta),  r * sin(theta) };
    }
};

int main() {

    // Point p{ 1,2 };  // Not Work!!!
    auto polar = PointFactory::NewPolar(5, M_PI_4);
    std::cout << polar << "\n";  // x: 3.53553 y: 3.53553

    auto cartesian = PointFactory::NewCartesian(5, M_PI_4);
    std::cout << cartesian << "\n";  // x: 5 y: 0.785398

    return EXIT_SUCCESS;
}

#endif // CREATIONAL_FACTORY_II

