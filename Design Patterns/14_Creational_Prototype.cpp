#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Office {
    Office(std::string street, std::string city, int32_t cubical)
        :m_street(street), m_city(city), m_cubical(cubical) {}

private:
    std::string m_street;
    std::string m_city;
    int32_t m_cubical;
};

class Employee {
    Employee(std::string name, Office office) :m_name(name), m_office(office) {}

private:
    std::string m_name;
    Office m_office;
};

int main() {

    Employee john( "John Doe", Office("123 East Dr", "London", 123) );
    Employee jane( "Jane Doe", Office{"123 East Dr", "London", 124} );
    Employee jack{ "jack Doe", Office{"123 ORR", "Bangaluru", 300} };

    return EXIT_SUCCESS;
}