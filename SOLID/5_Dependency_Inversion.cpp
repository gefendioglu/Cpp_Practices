#define _CRT_SECURE_NO_WARNINGS

#include<iostream> 
#include<string>
#include<vector>

enum class Relationship { parent, child, sibling };
struct Person {
    std::string  m_name;
};

// Low-level <<<<<<<<<<<<-------------------------
class Relationships {     
public:

    void add_parent_and_child(const Person& parent, const Person& child) {
        m_relations.push_back({ parent, Relationship::parent, child });
        m_relations.push_back({ child, Relationship::child, parent });
    }
    std::vector<std::tuple<Person, Relationship, Person>> m_relations;
};

// High-level  <<<<<<<<<<<<------------------------
class Research {         
public:
    Research(const Relationships& relationships) {
        for (auto&& [first, rel, second] : relationships.m_relations) { // Need C++17 here
            if (first.m_name == "John" && rel == Relationship::parent)
                std::cout << "John has a child called " << second.m_name << "\n";
        }
    }
};
int main() {

    Person parent{ "John" };
    Person child1{ "Chris" };
    Person child2{ "Matt" };
    Relationships relationships;

    relationships.add_parent_and_child(parent, child1);
    relationships.add_parent_and_child(parent, child2);
    Research _(relationships);

    return EXIT_SUCCESS;

    /*
        John has a child called Chris
        John has a child called Matt
    */
}