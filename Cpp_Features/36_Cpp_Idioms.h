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
    // Because of unary operator, there is no parameters when doing it in class definition
    T& operator*() const { 
        return *m_ptr; 
    }

    // Arrow operator overloading 
    // Because of unary operator, there is no parameters when doing it in class definition
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

// CRTP : Curiously Recurring Template Pattern Idiom 
// --------------------------------------------
// --------------------------------------------
#ifdef CRTP

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <string>

template <typename T>
class Pet {
public:
    void make_sound() {
        std::cout << thisObject().get_sound() << "\n";
    }
    // No virtual function definition/declaration
    // std::string T::get_sound() const; --> in Derived class
private:
    const T& thisObject() {
        return *static_cast<const T*>(this);
    }
};

class Dog : public Pet<Dog> { 
public:
    std::string get_sound() const {
        return{ "bark" };
    }
};

class Cat : public Pet<Cat> {
public:
    std::string get_sound() const {
        return{ "meow" };
    }
};

template<typename T>
void pet_game(Pet<T>& pet) {
    pet.make_sound();
}

int main() {

    Cat mycat;
    Dog mydog;
    pet_game(mycat);
    pet_game(mydog);

    return EXIT_SUCCESS;

    /*
        meow
        bark
    */
}

#endif

// CRTP : Curiously Recurring Template Pattern Idiom 
// --------------------------------------------
// --------------------------------------------

#ifdef CRTP_II

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

template <class T>
class compare {};

class value : public compare<value> {
public: 
    value(int x) : m_x{ x } {}
    bool operator<(const value& rhs) const { 
        return m_x < rhs.m_x; 
    }
private:
    int m_x;
};

// No need to write relational operators.
// Use only type dependent "operator <" & CRTP.
template <class T>
bool operator > (const compare<T>& lhs, const compare<T>& rhs) {
    return (static_cast<const T&>(rhs) < static_cast<const T&>(lhs));
}

/*  For the other operators: 
    == operator returns -->  !(lhs < rhs) && !(rhs < lhs)
    != operator returns -->  !(lhs == rhs)
    >= operator returns -->  (rhs < lhs) || (rhs == lhs)
    <= operator returns -->  (lhs < rhs) || (rhs == lhs)
*/

int main() {

    value v1{ 5 };
    value v2{ 10 };

    std::cout << std::boolalpha << "v1 > v2: " << (v1 > v2) << '\n';
    return EXIT_SUCCESS;
   
    /*
        v1 > v2: false
    */
}

 
#endif


// CRTP : Curiously Recurring Template Pattern Idiom 
// --------------------------------------------
// --------------------------------------------

#ifdef CRTP_III

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

template<typename T>
class animal {
public:
    void who() { 
        implementation().who(); 
    }
private:
    T& implementation() { 
        return *static_cast<T*>(this); 
    }
};

class dog : public animal<dog> {
public:
    void who() { 
        std::cout << "dog" << "\n"; 
    }
};

class cat : public animal<cat> {
public:
    void who() { 
        std::cout << "cat" << "\n"; }
};

template<typename T>
void get_animal(animal<T>& animal) {
    animal.who();
}

int main() {
    dog my_dog;
    cat my_cat;
   
    get_animal(my_dog);
    get_animal(my_cat);

    return EXIT_SUCCESS;

    /*
        dog
        cat
    */
}

#endif


