#pragma once

// std::optional
// --------------------------------------------
// --------------------------------------------

#ifdef STL_OPTIONAL

#define _CRT_SECURE_NO_WARNINGS
#include <optional>
#include <iostream>

template<size_t n>
class A {
    unsigned char buffer[n];
};

template<size_t n>
using optype = std::optional<A<n>>;

int main()
{
    std::cout << sizeof(optype<128>) << "\n";  //129
    std::cout << sizeof(optype<256>) << "\n";  //257
    std::cout << sizeof(optype<512>) << "\n";  //513
    std::cout << sizeof(optype<1024>) << "\n"; //1025
    std::cout << sizeof(optype<2048>) << "\n"; //2049

}

#endif // STL_OPTIONAL


#ifdef STL_OPTIONAL_I

#define _CRT_SECURE_NO_WARNINGS
#include <optional>
#include <complex>
#include <set>
#include <cctype>
#include <utility>

int main()
{
    //std::optional<std::complex<double>> op1{1, 2}; // NOT OK!
    std::optional<std::complex<double>> op2{ std::in_place, 1, 2 };

    auto f = [](char x, char y) {
        return std::toupper(x) > std::toupper(y);
    };

    std::optional<std::set<char, decltype(f)>> op3{ std::in_place, {'c', 'T', 'a', 'B'}, f };
}

#endif // STL_OPTIONAL_I

#ifdef STL_OPTIONAL_II

#define _CRT_SECURE_NO_WARNINGS
#include <optional>
#include <string>
#include <iostream>

int main()
{
    std::optional<std::string> op{ "gamze" };
    std::cout << *op << "\n";
    
    *op += " efendioglu";
    std::cout << *op << "\n";
    std::cout << "size : " << op->size() << "\n";
    
    op = std::nullopt;
    std::cout << *op << "\n"; // ub

    /*
        gamze
        gamze efendioglu
        size : 16
    */
}

#endif // STL_OPTIONAL_II


#ifdef STL_OPTIONAL_III

#define _CRT_SECURE_NO_WARNINGS
#include <optional>
#include <iostream>
#include <string>

class Name{
public:
    Name(std::string first, std::optional<std::string> middle,
        std::string last) : m_first{ std::move(first) }, m_middle{ std::move(middle) }, m_last{ std::move(last) } {
    }

    friend std::ostream& operator << (std::ostream& os, const Name& name)
    {
        os << name.m_first << ' ';

        if (name.m_middle) {
            os << *name.m_middle << ' ';
        }

        return os << name.m_last;
    }

private:
    std::string m_first;
    std::optional<std::string> m_middle;
    std::string m_last;
};


int main()
{
    Name myName{ "Gamze", std::nullopt, "Efendioglu" };
    std::cout << myName << "\n";

    Name hisName{ "Mehmet", "Kaan", "Efendioglu" };
    std::cout << hisName << "\n";
}


#endif // STL_OPTIONAL_III


#ifdef STL_OPTIONAL_Example

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class Base {
public:
    Base() { 
        std::cout << "Base::Base() is called" << "\n";
        test_func(); 
    }
    virtual void test_func() { 
        std::cout << "BASE" << "\n";
    }
};

class Derived : public Base {
public:
    Derived() { 
        std::cout << "Derived::Derived() is called" << "\n";
        test_func(); 
    };

    void test_func() override { 
        std::cout << "DERIVED" << "\n";
    }
};

int main() {

    Derived* b = new Derived(); 
    return 0;
    /*
        Base::Base() is called
        BASE
        Derived::Derived() is called
        DERIVED
    */
}


#endif // STL_OPTIONAL_Example
