#if Liskov_Substitution

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <assert.h>     

//// Before applying Liskov Substitution Responsibility
//// ----------------------------------------------
//
//// Base Class : Rectangle
//class Rectangle {
//public:
//    Rectangle(const uint32_t width, const uint32_t height) : m_width{ width }, m_height{ height } {}
//
//    uint32_t get_width() const { return m_width; }
//    uint32_t get_height() const { return m_height; }
//    
//    virtual void set_width(const uint32_t width) 
//    { 
//        this->m_width = width; 
//    }
//    
//    virtual void set_height(const uint32_t height) 
//    { 
//        this->m_height = height; 
//    }
//
//    uint32_t area() const 
//    { 
//        return m_width * m_height; 
//    }
//
//protected:
//    uint32_t m_width, m_height;
//};
//
//// Derived Class : Square
//class Square : public Rectangle {
//public:
//    // Delegating constructor
//    Square(uint32_t size) : Rectangle(size, size) {}
//    
//    void set_width(const uint32_t width) override 
//    { 
//        this->m_width = m_height = width; 
//    }
//
//    void set_height(const uint32_t height) override 
//    { 
//        this->m_height = m_width = height; 
//    }
//};
//
//void process(Rectangle& r) {
//
//    uint32_t w = r.get_width();
//    r.set_height(10);
//    assert((w * 10) == r.area()); // Fails for Square 
//}
//
//int main() {
//
//    Rectangle r{ 5, 5 };
//    process(r);
//
//    Square s{ 5 };
//    process(s);
//   //  Assertion failed : (w * 10) == r.area()
//
//    return EXIT_SUCCESS;
//}


// After applying Liskov Substitution Responsibility
// Use proper inheritance hierarchy
// ----------------------------------------------

class Shape {
public:
    virtual uint32_t area() const = 0;
};

class Rectangle : public Shape {
public:
    Rectangle(const uint32_t width, const uint32_t height) : m_width{ width }, m_height{ height } {}

    uint32_t get_width() const { return m_width; }
    uint32_t get_height() const { return m_height; }

    virtual void set_width(const uint32_t width) { 
        this->m_width = width; 
    }

    virtual void set_height(const uint32_t height) { 
        this->m_height = height; 
    }

    uint32_t area() const override { 
        return m_width * m_height; 
    }

private:
    uint32_t m_width, m_height;
};

class Square : public Shape {
public:
    Square(uint32_t size) : m_size{ size } {}

    void set_size(const uint32_t size) { 
        this->m_size = size; 
    }

    uint32_t area() const override { 
        return m_size * m_size; 
    }

private:
    uint32_t m_size;
};

// Trying to use Virtual Constructor & Virtual Copy Constructor i.e. Factory Pattern.
struct ShapeFactory {
    static Shape CreateRectangle(uint32_t width, uint32_t height);
    static Shape CreateSquare(uint32_t size);
};

void process(Shape& s) {
    std::cout << s.area() << "\n";
}

int main() {

    Rectangle rec{ 5, 5 };
    // Derived --> Base (upcasting)
    process(rec); // 25

    Square square{ 5 };
    // Derived --> Base (upcasting)
    process(square); // 25

    return EXIT_SUCCESS;
}

#endif // Liskov_Substitution
