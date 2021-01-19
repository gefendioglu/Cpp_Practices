#pragma once

#ifdef CREATIONAL_ABSTRACT_FACTORY_PROBLEM

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Point {
public:
    virtual ~Point() {
        std::cout << "Point::~Point()\n";
    }
};

class Point2D :public Point {
public:
    ~Point2D() {
        std::cout << "Point::~Point2D()\n";
    }
};

class Point3D : public Point {
public:
    ~Point3D() {
        std::cout << "Point::~Point3D()\n";
    }
};

void create_point() {
    // Not sure which object class would be passed here ("Point2D" or "Point3D")
    // Point3D* ptr3d = new Point3D();
    // Point2D* ptr2d = new Point2D();
    Point* point = new Point();
    delete point;
}

int main() {

    create_point();

    return EXIT_SUCCESS;
    /*
        Point::~Point()
    */
}

#endif // CREATIONAL_ABSTRACT_FACTORY_PROBLEM


#ifdef CREATIONAL_ABSTRACT_FACTORY

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<memory>

// pure virtual - abstract class (can not be instantiated)
class Point {
public:
    Point(int x, int y) : m_x{ x }, m_y{ y } {}
    virtual ~Point() = default;

    // like as virtual constructor
    virtual std::unique_ptr<Point> create() = 0;

    // like as virtual copy constructor
    virtual std::unique_ptr<Point> clone() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
private:
    int m_x;
    int m_y;
};

class Point2D : public Point {
public:
    // Derived --> Base (upcasting)
    // Point2D --> Point
    // std::unique_ptr<Point> point2d = std::make_unique<Point2D>();
    std::unique_ptr<Point> create() override {
        return std::make_unique<Point2D>();
    }
    // std::unique_ptr<Point> point2d = std::make_unique<Point2D>(*this);
    std::unique_ptr<Point> clone() override {
        return std::make_unique<Point2D>(*this);
    }
};

class Point3D : public Point {
public:
    // Derived --> Base (upcasting)
    // Point3D --> Point
    // std::unique_ptr<Point> point3d = std::make_unique<Point3D>();
    std::unique_ptr<Point> create() override {
        return std::make_unique<Point3D>();
    }

    // std::unique_ptr<Point> point3d = std::make_unique<Point3D>(*this);
    std::unique_ptr<Point> clone() override {
        return std::make_unique<Point3D>(*this);
    }
};

void point_func(std::unique_ptr<Point> point) {

    // "create" the object of same type pointed by ?
    auto new_point = point->create();

    // "copy" the object of same type pointed by ?
    auto duplicate_point = point->clone();
}

int main() {
    // TO BE IMPLEMENTED
    //std::unique_ptr<Point> point2d = std::make_unique<Point2D>();
    //point_func(point2d); // NOT OK!
    return EXIT_SUCCESS;
}

#endif // CREATIONAL_ABSTRACT_FACTORY_I

#ifdef CREATIONAL_FUNCTIONAL_FACTORY

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<memory>
#include<map>
#include<functional>

enum class PointType { Point2D, Point3D };

class Point {
public:
    Point() = default;
    Point(int x, int y) : m_x{ x }, m_y{ y } {}
    virtual ~Point() = default;

    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
private:
    int m_x;
    int m_y;
};

class Point2D : public Point {/* . . . */ };
class Point3D : public Point {/* . . . */ };

class PointFunctionalFactory {
public:
    PointFunctionalFactory() {
        m_factories[PointType::Point2D] = [] { 
            return std::make_unique<Point2D>(); 
        };
        m_factories[PointType::Point3D] = [] { 
            return std::make_unique<Point3D>(); 
        };
    }
    std::unique_ptr<Point> create(PointType type) { 
        return m_factories[type](); 
    }
private:
    std::map<PointType, std::function<std::unique_ptr<Point>() >> m_factories;
};

int main() {

    PointFunctionalFactory pf;
    auto point2D = pf.create(PointType::Point2D);
    std::cout << point2D << "\n"; // The address of point2D
    
    return EXIT_SUCCESS;
}

#endif // CREATIONAL_FUNCTIONAL_FACTORY






