#pragma once

#ifdef CREATIONAL_ABSTRACT_FACTORY_PROBLEM

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Member {
public:
    virtual ~Member() {
        std::cout << "Member::~Member()\n";
    }
};

class Member2D :public Member {
public:
    ~Member2D() {
        std::cout << "Member::~Member2D()\n";
    }
};

class Member3D : public Member {
public:
    ~Member3D() {
        std::cout << "Member::~Member3D()\n";
    }
};

void create_Member() {
    // Not sure which object class would be passed here ("Member2D" or "Member3D")
    // Member3D* ptr3d = new Member3D();
    // Member2D* ptr2d = new Member2D();
    Member* Member = new Member();
    delete Member;
}

int main() {

    create_Member();

    return EXIT_SUCCESS;
    /*
        Member::~Member()
    */
}

#endif // CREATIONAL_ABSTRACT_FACTORY_PROBLEM


#ifdef CREATIONAL_ABSTRACT_FACTORY

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<memory>

// pure virtual - abstract class (can not be instantiated)
class Member {
public:
    Member(int x, int y) : m_x{ x }, m_y{ y } {}
    virtual ~Member() = default;

    // like as virtual constructor
    virtual std::unique_ptr<Member> create() = 0;

    // like as virtual copy constructor
    virtual std::unique_ptr<Member> clone() = 0;

    friend std::ostream& operator<<(std::ostream& os, const Member& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
private:
    int m_x;
    int m_y;
};

class Member2D : public Member {
public:
    // Derived --> Base (upcasting)
    // Member2D --> Member
    // std::unique_ptr<Member> Member2d = std::make_unique<Member2D>();
    std::unique_ptr<Member> create() override {
        return std::make_unique<Member2D>();
    }
    // std::unique_ptr<Member> Member2d = std::make_unique<Member2D>(*this);
    std::unique_ptr<Member> clone() override {
        return std::make_unique<Member2D>(*this);
    }
};

class Member3D : public Member {
public:
    // Derived --> Base (upcasting)
    // Member3D --> Member
    // std::unique_ptr<Member> Member3d = std::make_unique<Member3D>();
    std::unique_ptr<Member> create() override {
        return std::make_unique<Member3D>();
    }

    // std::unique_ptr<Member> Member3d = std::make_unique<Member3D>(*this);
    std::unique_ptr<Member> clone() override {
        return std::make_unique<Member3D>(*this);
    }
};

void Member_func(std::unique_ptr<Member> Member) {

    // "create" the object of same type pointed by ?
    auto new_Member = Member->create();

    // "copy" the object of same type pointed by ?
    auto duplicate_Member = Member->clone();
}

int main() {
    // TO BE IMPLEMENTED
    //std::unique_ptr<Member> Member2d = std::make_unique<Member2D>();
    //Member_func(Member2d); // NOT OK!
    return EXIT_SUCCESS;
}

#endif // CREATIONAL_ABSTRACT_FACTORY_I

#ifdef CREATIONAL_FUNCTIONAL_FACTORY

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<memory>
#include<map>
#include<functional>

enum class MemberType { Member2D, Member3D };

class Member {
public:
    Member() = default;
    Member(int x, int y) : m_x{ x }, m_y{ y } {}
    virtual ~Member() = default;

    friend std::ostream& operator<<(std::ostream& os, const Member& obj) {
        return os << "x: " << obj.m_x << " y: " << obj.m_y;
    }
private:
    int m_x;
    int m_y;
};

class Member2D : public Member {/* . . . */ };
class Member3D : public Member {/* . . . */ };

class MemberFunctionalFactory {
public:
    MemberFunctionalFactory() {
        m_factories[MemberType::Member2D] = [] { 
            return std::make_unique<Member2D>(); 
        };
        m_factories[MemberType::Member3D] = [] { 
            return std::make_unique<Member3D>(); 
        };
    }
    std::unique_ptr<Member> create(MemberType type) { 
        return m_factories[type](); 
    }
private:
    std::map<MemberType, std::function<std::unique_ptr<Member>() >> m_factories;
};

int main() {

    MemberFunctionalFactory pf;
    auto Member2D = pf.create(MemberType::Member2D);
    std::cout << Member2D << "\n"; // The address of Member2D
    
    return EXIT_SUCCESS;
}

#endif // CREATIONAL_FUNCTIONAL_FACTORY






