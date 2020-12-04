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
    void draw() override { std::cout << "Circle" << "\n"; }
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

// ----------------------------------------------------
// ----------------------------------------------------

class Neuron {
public:
    Neuron() {
        static int id = 1;
        this->id = id++;
    }

    void connect_to(Neuron& other) {
        out.push_back(&other);
        other.in.push_back(this);
    }

    friend std::ostream& operator<<(std::ostream& os, const Neuron& obj) {
        for (Neuron* n : obj.in)
            os << n->id << "\t-->\t[" << obj.id << "]" << "\n";

        for (Neuron* n : obj.out)
            os << "[" << obj.id << "]\t-->\t" << n->id << "\n";

        return os;
    }

private:
    std::vector<Neuron*> in, out;
    uint32_t id;
};

//  Making a neuron layer and it is basically like a collection.
class NeuronLayer : public std::vector<Neuron> {
public:
    NeuronLayer(int count) {
        while (count-- > 0)
            emplace_back(Neuron{});
    }

    friend std::ostream& operator<<(std::ostream& os, NeuronLayer& obj) {
        for (auto& n : obj)
            os << n;
        return os;
    }
};

int main() {

    NeuronLayer l1{ 1 }, l2{ 2 };
    Neuron n1, n2;
    n1.connect_to(l1);  // Neuron connects to Layer
    l2.connect_to(n2);  // Layer connects to Neuron
    l1.connect_to(l2);  // Layer connects to Layer
    n1.connect_to(n2);  // Neuron connects to Neuron

    return EXIT_SUCCESS;
}

