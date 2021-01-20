#pragma once

// Creational - Prototype Desing Pattern - Example 1
// ----------------------------------------------
// ----------------------------------------------

#ifdef CREATIONAL_PROTOTYPE_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Office {
public:
    Office(std::string street, std::string city, int32_t cubical)
        :m_street{ street }, m_city{ city }, m_cubical{ cubical } {}
private:
    std::string m_street;
    std::string m_city;
    int32_t m_cubical;
};

class Employee {
public:
    Employee(std::string name, Office office) :m_name{ name }, m_office{ office } {}
private:
    std::string m_name;
    Office m_office;
};

static Office LondonOffice{ "123 East Dr", "London", 123 };
static Office BangaluruOffice{ "RMZ Ecoworld ORR", "London", 123 };

int main() {

    Employee john{ "John Doe", LondonOffice };
    Employee jane{ "Jane Doe", LondonOffice };
    Employee jack{ "jack Doe", BangaluruOffice };

    return EXIT_SUCCESS;
}

#endif // CREATIONAL_PROTOTYPE_I

// Creational - Prototype Design Pattern - Example 2
// ----------------------------------------------
// ----------------------------------------------

#ifdef CREATIONAL_PROTOTYPE_II

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<memory> 

// pure virtual functions - abstract class
class animal {
public:
    virtual ~animal() = default;
    virtual std::unique_ptr<animal> create() = 0;
    virtual std::unique_ptr<animal> clone() = 0;
};

class dog :public animal {
public:
    std::unique_ptr<animal> create() override {
        std::cout << "creating dog object" << "\n";
        return std::make_unique<dog>();
    }

    std::unique_ptr<animal> clone() override {
        std::cout << "cloning dog object" << "\n";
        return std::make_unique<dog>(*this);
    }
};

class cat : public animal {
public:
    std::unique_ptr<animal> create() {
        std::cout << "creating cat object" << "\n";
        return std::make_unique<cat>();
    }

    std::unique_ptr<animal> clone() {
        std::cout << "cloning cat object" << "\n";
        return std::make_unique<cat>(*this);
    }
};

void create_animal(animal* animal) {
    auto new_animal = animal->create();
    auto clone_animal = animal->clone();
    delete animal;
}

int main() {

    // Derived (dog) --> Base (animal) - upcasting
    animal* animal_dog = new dog();

    // Derived (cat) --> Base (animal) - upcasting
    animal* animal_cat = new cat();

    create_animal(animal_dog);
    create_animal(animal_cat);

    /*
        creating dog object
        cloning dog object
        creating cat object
        cloning cat object
    */

    return 0;
}

#endif // CREATIONAL_PROTOTYPE_II


