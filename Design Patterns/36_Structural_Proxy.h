#pragma once

// Proxy Design Pattern: 
//----------------------------------------------
//----------------------------------------------

#ifdef STRUCTURAL_PROXY_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string> 

// There is nothing more than a field plus a getter & setter methods for that field
template<typename T>
class Property {
public:
    Property(const T initialValue) { *this = initialValue; }
    operator T() { return m_value; }
    T operator = (T newValue) { return m_value = newValue; }

private:
    T   m_value;
};

struct Creature {
    Property<int32_t>   m_strength{ 10 };
    Property<int32_t>   m_agility{ 5 };
};

int main() {

    Creature creature;
    creature.m_agility = 20;
    std::cout << creature.m_agility << "\n"; // 20
    
    return EXIT_SUCCESS;
}

#endif // STRUCTURAL_PROXY_I

// Virtual Proxy Design Pattern: 
//----------------------------------------------
//----------------------------------------------

#ifdef STRUCTURAL_PROXY_VIRTUAL

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Abstract class
class Image {
    virtual void draw() = 0;
};

class Bitmap : public Image {
public:
    Bitmap(const std::string& filename) : m_filename(filename) {
        std::cout << "Loading image from " << m_filename << "\n";
        // Steps to load the image ...
    }

    // Polymorphic behaviour for draw() function
    void draw() override {
        std::cout << "Drawing image " << m_filename << "\n";
    }

private:
    std::string m_filename;
};

//This kind of technique is quite useful when you are working with a third-party library & wants to write a wrapper around it for some performance improvements.

class LazyBitmap : public Image {
public:
    LazyBitmap(const std::string& filename) : m_filename(filename) {}

    // Polymorphic behaviour for draw() function
    void draw() override {
        if (!m_bmp)
            m_bmp = std::make_unique<Bitmap>(m_filename);
        m_bmp->draw();
    }
private:
    std::unique_ptr<Bitmap>      m_bmp{ nullptr };
    std::string                  m_filename;
};

int main() {

    Bitmap img_1{ "image_1.png" };
    Bitmap img_2{ "image_2.png" };

    (rand() % 2) ? img_1.draw() : img_2.draw();

    // If an image is drawn, then to construct the other images are not necessary!!!
    LazyBitmap img_3{ "image_3.png" };
    LazyBitmap img_4{ "image_4.png" };

    (rand() % 2) ? img_3.draw() : img_4.draw();

    return EXIT_SUCCESS;

    /*
        Loading image from image_1.png
        Loading image from image_2.png
        Drawing image image_1.png

        Loading image from image_3.png
        Drawing image image_3.png

    */
}

#endif  // STRUCTURAL_PROXY_VIRTUAL


// Commnication Proxy Design Pattern: 
//----------------------------------------------
//----------------------------------------------

#ifdef STRUCTURAL_PROXY_COMMUNICATION

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

template <typename T>
class arr2D {
public:
    class proxy {
    public:
        proxy(T* arr) : m_arr_1D(arr) {}
        T& operator[](int32_t idx) {
            return m_arr_1D[idx];
        }
    private:
        T* m_arr_1D;
    };

    arr2D::proxy operator[](int32_t idx) {
        return arr2D::proxy(m_arr_2D[idx]);
    }

private:
    T   m_arr_2D[10][10];
};

int main() {

    arr2D<int32_t> arr;
    arr[0][0] = 1;  // Uses the proxy object

    return EXIT_SUCCESS;
}

#endif // STRUCTURAL_PROXY_COMMUNICATION

//----------------------------------------------
//----------------------------------------------