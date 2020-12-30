#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Base Class
class Point {
public:
    virtual void draw() { std::cout << "Point\n"; }

private:
    int32_t m_x;
};

// Template Definition for a generic adapter
template<class T>
class GenericLineAdapter : public Point {
public:
    GenericLineAdapter(T& line) : m_line(line) {}
    void draw() { m_line.draw(); }

private:
    T& m_line;
};

// Derived Class (from Point base class)
class Point2D : public Point {
public:
    void draw() override { std::cout << "Point2D\n"; }
private:
    int32_t m_y;
};

// Global Function Definition
void draw_point(Point& p) {
    p.draw();
}

// "Line" class is composed of "Point2D" derived class
class Line {
public:
    void draw() { std::cout << "Line\n"; }

private:
    Point2D m_start;
    Point2D m_end;
};

// Adapter class for "Line" class
class LineAdapter : public Point {
public:
    LineAdapter(Line& line) : m_line(line) {}
    void draw() override { m_line.draw(); }

private:
    Line& m_line;
};

//int main() {
//
//    Line line;
//    LineAdapter lineAdapter(line);
//    draw_point(lineAdapter);
//
//    return EXIT_SUCCESS;
//}