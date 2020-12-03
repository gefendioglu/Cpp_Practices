#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

struct Office {
    std::string m_street;
    std::string  m_city;
    int32_t m_cubical;
};

class Employee {
public:

    // Copy constructor
    Employee(const Employee& employee) : m_name{ employee.m_name }, m_office{ new Office{*employee.m_office} }
    { }

    // Copy assignment
    Employee& operator=(const Employee& rhs) {
        if (this == &rhs) return *this;
        m_name = rhs.m_name;
        m_office = new Office{ *rhs.m_office };
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        return os << employee.m_name
            << " works at " << employee.m_office->m_street
            << " " << employee.m_office->m_city
            << " seats @" << employee.m_office->m_cubical;
    }

private:
    std::string m_name;
    Office* m_office;

    // Private constructor
    // Direct instance can not be created except for "class EmployeeFactory"
    Employee(std::string name, Office* office) : m_name(name), m_office(office) {}
    friend class EmployeeFactory;
};

class EmployeeFactory {
public:

    static std::unique_ptr<Employee> NewMainOfficeEmployee(std::string name, int32_t cubical) {
        return NewEmployee(name, cubical, main);
    }
    static std::unique_ptr<Employee> NewAuxOfficeEmployee(std::string name, int32_t cubical) {
        return NewEmployee(name, cubical, aux);
    }

private:

    static Employee main;
    static Employee aux;
    static std::unique_ptr<Employee> NewEmployee(std::string name, int32_t cubical, Employee& proto) {
        auto employee = std::make_unique<Employee>(proto);
        employee->m_name = name;
        employee->m_office->m_cubical = cubical;
        return employee;
    }
};

// Static Member Initialization 
Employee EmployeeFactory::main{ "", new Office{"123 East Dr", "London", 123} };
Employee EmployeeFactory::aux{ "", new Office{"RMZ Ecoworld ORR", "London", 123} };

//int main() {
//
//    auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);
//    auto jack = EmployeeFactory::NewAuxOfficeEmployee("Jack Doe", 123);
//    std::cout << *jane << "\n" << *jack << "\n";
//
//    return EXIT_SUCCESS;
//
//    /*
//        Jane Doe works at 123 East Dr London seats @125
//        Jack Doe works at RMZ Ecoworld ORR London seats @123
//    */
//}
