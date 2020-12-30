#pragma once

#ifdef CREATIONAL_FACTORY

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

#endif // CREATIONAL_FACTORY