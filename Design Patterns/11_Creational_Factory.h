#pragma once

#ifdef CREATIONAL_FACTORY

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream> 

class Member {
public:
    struct Factory {

        static Member NewCartesian(double x, double y) {
            return { x,y }; 
        }

        static Member NewPolar(double r, double theta) {
            return{ r * cos(theta), r * sin(theta) };
        }
    };

    friend std::ostream& operator<<(std::ostream& os, const Member& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }

private:
    double   m_x;
    double   m_y;
    Member(double x, double y) : m_x{ x }, m_y{ y } {}
};

int main() {

    // Member p{ 1,2 };  // Not Work!!!
    auto polar = Member::Factory::NewPolar(5, M_PI_4);
    std::cout << polar << "\n";  // x: 3.53553 y: 3.53553

    auto cartesian = Member::Factory::NewCartesian(5, M_PI_4);
    std::cout << cartesian << "\n";  // x: 5 y: 0.785398

    return EXIT_SUCCESS;
}

#endif // CREATIONAL_FACTORY


#ifdef CREATIONAL_FACTORY_I

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream> 

enum class MemberType { cartesian, polar };

class Member {
public:
    // Static class member function for cartesian coord.
    static Member NewCartesian(const double& x, const double& y) {
        return { x, y, MemberType::cartesian };
    }

    // Static class member function for polar coord.
    static Member NewPolar(const double& x, const double& y) {
        return { x * cos(y), x * sin(y), MemberType::polar };
    }

    friend std::ostream& operator<<(std::ostream& os, const Member& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }

private:
    double m_x;
    double m_y;
    MemberType m_type;

    // Private constructor
    // The object can't be created directly
    Member(const double& x, const double& y, MemberType type) : m_x{ x }, m_y{ y }, m_type{ type } {}
};

int main() {

    // Member p{ 5, M_PI_4 };  // Not Work!!!
    auto p = Member::NewPolar(5, M_PI_4);
    std::cout << p << "\n";  // x: 3.53553 y: 3.53553

    return EXIT_SUCCESS;
}

#endif // CREATIONAL_FACTORY_I

#ifdef CREATIONAL_FACTORY_II

#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include<iostream> 

class Member {
public:
    // The violation of Open-Closed Principle (OCP) here, because of using friendship 
    friend class MemberFactory;
    friend std::ostream& operator<<(std::ostream& os, const Member& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
private:
    double m_x;
    double m_y;

    // Private constructor
    Member(const double& x, const double& y) : m_x{ x }, m_y{ y } {}
};

// Concrete Class
class MemberFactory {
public:
    // Static class member function for cartesian coord.
    static Member NewCartesian(const double& x, const double& y) {
        return { x, y };
    }
    // Static class member function for polar coord.
    static Member NewPolar(const double& r, const double& theta) {
        return { r * cos(theta),  r * sin(theta) };
    }
};

int main() {

    // Member p{ 1,2 };  // Not Work!!!
    auto polar = MemberFactory::NewPolar(5, M_PI_4);
    std::cout << polar << "\n";  // x: 3.53553 y: 3.53553

    auto cartesian = MemberFactory::NewCartesian(5, M_PI_4);
    std::cout << cartesian << "\n";  // x: 5 y: 0.785398

    return EXIT_SUCCESS;
}

#endif // CREATIONAL_FACTORY_II

