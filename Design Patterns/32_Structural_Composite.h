#pragma once

#ifdef STRUCTURAL_COMPOSITE_I

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

// Abstract Base Class
class Shape {
public:
    virtual void draw() = 0;
};

// Derived - Concrete Class (from base class)
class Circle : public Shape {
public:
    void draw() override { 
        std::cout << "Circle" << "\n"; 
    }
};

// Derived - Concrete Class (from base class)
class Group : public Shape {
public:
    std::string m_name;
    std::vector<Shape*> m_objects;
    Group(const std::string& name) : m_name{ name } {}
    
    void draw() override {
        std::cout << "Group " << m_name.c_str() << " contains:" << "\n";
        for (auto&& objects : m_objects)
            objects->draw();
    }
};

int main() {

    Group root("root");
    root.m_objects.push_back(new Circle);

    Group subgroup("sub");
    subgroup.m_objects.push_back(new Circle);

    root.m_objects.push_back(&subgroup);
    root.draw();

    return EXIT_SUCCESS;

    /*
        Group root contains:
        Circle
        Group sub contains:
        Circle
    */
}

#endif // STRUCTURAL_COMPOSITE_I

// ----------------------------------------------------
// ----------------------------------------------------

#ifdef STRUCTURAL_COMPOSITE_II

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

template <typename Self>
class SomeNeurons {
public:
    template <typename T>
    void connect_to(T& other);
};

template <typename Self>
template <typename T>
void SomeNeurons<Self>::connect_to(T& other) {
    for (Neuron& from : *static_cast<Self*>(this)) {
        for (Neuron& to : other) {
            from.out.push_back(&to);
            to.in.push_back(&from);
        }
    }
}

class Neuron : public SomeNeurons<Neuron> {
public:
    std::vector<Neuron*> in, out;
    uint32_t id;

    Neuron() {
        static int id = 1;
        this->id = id++;
    }
    Neuron* begin() { return this; }
    Neuron* end() { return this + 1; }
};

struct NeuronLayer : public std::vector<Neuron>, SomeNeurons<NeuronLayer> {
public:
    NeuronLayer(int count) {
        while (count-- > 0)
            emplace_back(Neuron{}); // temporary object
    }
};

template <typename Self>
std::ostream& operator<<(std::ostream& os, SomeNeurons<Self>& object) {
    for (Neuron& obj : *static_cast<Self*>(&object)) {
        for (Neuron* n : obj.in)
            os << n->id << "\t-->\t[" << obj.id << "]" << "\n";

        for (Neuron* n : obj.out)
            os << "[" << obj.id << "]\t-->\t" << n->id << "\n";
    }
    return os;
}

int main() {

    Neuron n1, n2;
    NeuronLayer l1{ 1 }, l2{ 2 };

    n1.connect_to(l1); // Scenario 1: Neuron connects to Layer
    l2.connect_to(n2); // Scenario 2: Layer connects to Neuron
    l1.connect_to(l2); // Scenario 3: Layer connects to Layer
    n1.connect_to(n2); // Scenario 4: Neuron connects to Neuron

    std::cout << "Neuron " << n1.id << "\n" << n1 << "\n";
    std::cout << "Neuron " << n2.id << "\n" << n2 << "\n";

    std::cout << "Layer " << "\n" << l1 << "\n";
    std::cout << "Layer " << "\n" << l2 << "\n";

    return EXIT_SUCCESS;

    /* Output
        Neuron 1
        [1]    -->    3
        [1]    -->    2

        Neuron 2
        4    -->    [2]
        5    -->    [2]
        1    -->    [2]

        Layer
        1      -->    [3]
        [3]    -->    4
        [3]    -->    5

        Layer
        3      -->    [4]
        [4]    -->    2
        3      -->    [5]
        [5]    -->    2
    */
}

#endif // STRUCTURAL_COMPOSITE_II

// ----------------------------------------------------
// ----------------------------------------------------

#ifdef STRUCTURAL_COMPOSITE_III

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

// Abstract Base Class
class PageObject {
public:
    virtual void Add(PageObject a) {}
    virtual void Remove() {}
    virtual void Delete(PageObject a) {}
};

class Page : public PageObject {
public:
    void Add(PageObject a) override {
        std::cout << "something is added to the page" << "\n";
    }
    void Remove() override {
        std::cout << "something is removed from the page" << "\n";
    }
    void Delete(PageObject a) override {
        std::cout << "something is deleted from page " << "\n";
    }
};

class Copy : public PageObject {
public:
    void AddElement(PageObject a) {
        copyPages.push_back(a);
    }

    void Add(PageObject a) override {
        std::cout << "something is added to the copy" << "\n";
    }

    void Remove() override {
        std::cout << "something is removed from the copy" << "\n";
    }
    void Delete(PageObject a) override {
        std::cout << "something is deleted from the copy";
    }
private:
    // Both has-a and is-a relationships
    std::vector<PageObject> copyPages;
};

int main()
{
    Page a;
    Page b;
    Copy allcopy;

    allcopy.AddElement(a);
    allcopy.AddElement(b);

    allcopy.Add(a);   // something is added to the copy
    a.Add(b);         // something is added to the page
     
    allcopy.Remove(); // something is removed from the copy
    b.Remove();       // something is removed from the page

    return 0;
}

#endif // STRUCTURAL_COMPOSITE_III

// ----------------------------------------------------
// ----------------------------------------------------

