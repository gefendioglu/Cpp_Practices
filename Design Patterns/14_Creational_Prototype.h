#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<map> 

class Office {
public:
    Office(std::string street, std::string city, int32_t cubical)
        :m_street(street), m_city(city), m_cubical(cubical) {}

private:
    std::string m_street;
    std::string m_city;
    int32_t m_cubical;
};

class Employee {
public:
    Employee(std::string name, Office office) :m_name(name), m_office(office) {}

private:
    std::string m_name;
    Office m_office;
};

static Office LondonOffice{ "123 East Dr", "London", 123 };
static Office BangaluruOffice{ "RMZ Ecoworld ORR", "London", 123 };

//int main() {
//
//    Employee john{ "John Doe", LondonOffice };
//    Employee jane{ "Jane Doe", LondonOffice };
//    Employee jack{ "jack Doe", BangaluruOffice };
//
//    return EXIT_SUCCESS;
//}


// ----------------------------------------------
// ----------------------------------------------

//class animal {
//public:
//    virtual ~animal() = default;
//    virtual std::unique_ptr<animal> create() = 0;
//    virtual std::unique_ptr<animal> clone() = 0;
// };
//
//class dog :public animal {
//public:
//    // Derived (dog) --> Base (animal) - upcasting
//    std::unique_ptr<animal> create() { 
//        std::cout << "creating dog object" << "\n";
//        return std::make_unique<dog>(); 
//        
//    }
//
//    std::unique_ptr<animal> clone() { 
//        std::cout << "cloning dog object" << "\n";
//        return std::make_unique<dog>(*this); 
//    }
//};
//
//class cat : public animal {
//public:
//    // Derived (cat) --> Base (animal) - upcasting
//    std::unique_ptr<animal> create() {
//        std::cout << "creating cat object" << "\n";
//        return std::make_unique<cat>(); 
//    }
//
//    std::unique_ptr<animal> clone() { 
//        std::cout << "cloning cat object" << "\n";
//        return std::make_unique<cat>(*this); 
//    }
//};
//
//void who_am_i(animal* who) { 
//    auto new_who = who->create(); 
//    auto duplicate_who = who->clone(); 
//    delete who; 
//}
//
//int main() {
//    
//    animal* animal_dog = new dog();
//    animal* animal_cat = new cat();
//    
//    who_am_i(animal_dog); 
//    who_am_i(animal_cat); 
//
//    /*
//        creating dog object
//        cloning dog object
//        creating cat object
//        cloning cat object
//    */
//
//    return 0;
//}