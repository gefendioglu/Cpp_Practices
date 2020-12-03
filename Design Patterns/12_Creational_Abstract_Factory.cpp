#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<memory>
#include<map>
#include<functional>

enum class PointType{ Point2D, Point3D };

class Point {
public:
    Point(int x, int y) : m_x(x), m_y(y) {}
    Point() = default;
    virtual ~Point() = default;

    friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
private:
    int   m_x;
    int   m_y;
    
};

class Point2D : public Point {/* . . . */ };
class Point3D : public Point {/* . . . */ };

class PointFunctionalFactory {
public:
    PointFunctionalFactory() {
        m_factories[PointType::Point2D] = [] { return std::make_unique<Point2D>(); };
        m_factories[PointType::Point3D] = [] { return std::make_unique<Point3D>(); };
    }
    std::unique_ptr<Point> create(PointType type) { return m_factories[type](); }
private:
    std::map<PointType, std::function<std::unique_ptr<Point>() >> m_factories;
};

//int main() {
//
//    PointFunctionalFactory pf;
//    auto p2D = pf.create(PointType::Point2D);
//    std::cout << p2D << "\n"; // The address of object will print
//    return EXIT_SUCCESS;
//}

