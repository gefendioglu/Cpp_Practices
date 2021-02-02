#pragma once

// RAII : Resource Acquisition Is Initialization idiom 
// --------------------------------------------
// --------------------------------------------
#ifdef RAII

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class resource {
public:
    resource(int x, int y) {
        std::cout << "Resource is acquired!!!" << "\n";
    }
    ~resource() {
        std::cout << "Resource is destroyed!!!" << "\n";
    }
};

template<class T>
class smart_ptr{
public:
    template<typename... Args>
    
    smart_ptr(Args&&... args) : m_ptr(new T(std::forward<Args>(args)...)) {}
    
    //Deleting --> if this class has private address value
    ~smart_ptr() { 
        delete m_ptr; 
    }

    // Deleting copy constructor
    smart_ptr(const smart_ptr& rhs) = delete;
   
    // Deleting copy assignment
    smart_ptr& operator=(const smart_ptr& rhs) = delete;

    // Defining move ctor - forwarding reference
    smart_ptr(smart_ptr&& rhs) : m_ptr(exchange(rhs.m_ptr, nullptr)) {}

    // Defining move assignment
    smart_ptr& operator=(smart_ptr&& rhs) {
        if (&rhs == this) 
            return *this;
        delete m_ptr;
        m_ptr = exchange(rhs.m_ptr, nullptr);
        return *this;
    }

    // Dereferencing operator overloading 
    // Because of unary operator, there is no parameters when doing in class definition
    T& operator*() const { 
        return *m_ptr; 
    }

    // Arrow operator overloading 
    // Because of unary operator, there is no parameters when doing in class definition
    T* operator->() const { 
        return m_ptr; 
    }

private:
    T* m_ptr;
};

int main(){

    // ptr guarantee the release of its resource
    auto ptr = smart_ptr<resource>(1, 2); 
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    if (x == 0)
        throw 0; 
    if (x < 0)
        return EXIT_SUCCESS;

    // ptr related codes...

    return EXIT_SUCCESS;

    /*
        Resource is acquired!!!
        Enter an integer: 41
        Resource is destroyed!!!
    */
}  


#endif