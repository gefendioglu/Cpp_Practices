#pragma once

#ifdef STRUCTURAL_ADAPTER_CLASSICAL

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Base Class
class Point {
public:
    virtual void draw() { std::cout << "Point\n"; }

private:
    int32_t m_x;
};

// Template Definition for a generic adapter
template<class T>
class GenericLineAdapter : public Point {
public:
    GenericLineAdapter(T& line) : m_line(line) {}
    void draw() { m_line.draw(); }

private:
    T& m_line;
};

// Derived Class (from Point base class)
class Point2D : public Point {
public:
    void draw() override { std::cout << "Point2D\n"; }
private:
    int32_t m_y;
};

// Global Function Definition
void draw_point(Point& p) {
    p.draw();
}

// "Line" class is composed of "Point2D" derived class
class Line {
public:
    void draw() { std::cout << "Line\n"; }

private:
    Point2D m_start;
    Point2D m_end;
};

// Adapter class for "Line" class
class LineAdapter : public Point {
public:
    LineAdapter(Line& line) : m_line(line) {}
    void draw() override { m_line.draw(); }

private:
    Line& m_line;
};

int main() {

    Line line;
    LineAdapter lineAdapter(line);
    draw_point(lineAdapter);

    return EXIT_SUCCESS;
}

#endif // STRUCTURAL_ADAPTER_CLASSICAL


// ----------------------------------------------
// ----------------------------------------------

#ifdef STRUCTURAL_ADAPTER_PLUGGIN_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<functional> 

/* Legacy code */
/* ---------------------------------------------- */
class Beverage {
public:
	virtual void getBeverage() = 0;
};

class CoffeeMaker : public Beverage {
public:
	void Brew() { std::cout << "brewing coffee" << "\n"; }
	void getBeverage() override { Brew(); }
};

void make_drink(Beverage& drink) {
	drink.getBeverage();
}
/* ---------------------------------------------- */

class JuiceMaker {
public:
	void Squeeze() { std::cout << "making Juice" << "\n"; }
};

// Adapter class for "Beverage" base class 
class Adapter : public Beverage {
public:
	Adapter(CoffeeMaker* cm) { m_request = [cm]() { cm->Brew(); }; }
	Adapter(JuiceMaker* jm) { m_request = [jm]() { jm->Squeeze(); }; }
	void getBeverage() override { m_request(); }

private:
	std::function<void()> m_request;
};

int main() {

	Adapter adp1 = new CoffeeMaker();
	make_drink(adp1); // brewing coffee 

	Adapter adp2 = new JuiceMaker();
	make_drink(adp2); // making Juice

	return EXIT_SUCCESS;
}

#endif // STRUCTURAL_ADAPTER_PLUGGIN

// ---------------------------------------------
// ---------------------------------------------


#ifdef STRUCTURAL_ADAPTER_PLUGGIN_II

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Virtual Base Class 
class Bird {
public:
	// birds implement Bird interface that allows them to fly and make sounds adaptee interface 
	virtual void fly() = 0;
	virtual void makeSound() = 0;

};

// Derived class (Sparrow) from virtual base class (Bird)
class Sparrow : public Bird {
public:
	// overriding fly() virtual class 
	void fly() override {
		std::cout << "Flying" << "\n";
	}

	void makeSound() override {
		std::cout << "Chirp Chirp" << "\n";
	}
};

// Virtual Base Class 
class ToyDuck {
public:
	// target interface toyducks dont fly they make squeaking sound 
	virtual void squeak() = 0;
};

// Derived class (PlasticToyDuck) from base class (ToyDuck)
class PlasticToyDuck : public ToyDuck {
public:
	void squeak() override {
		std::cout << "Squeak" << "\n";
	}
};

// Adapter class (inherited from base class)
class BirdAdapter : public ToyDuck {
public:
	BirdAdapter(Bird* b) {
		// Referencing to the object we are adapting 
		bird = b;
	}

	void squeak() override {
		// translate the methods appropriately 
		bird->makeSound();
	}

private:
	Bird* bird;
};

int main() {

	Sparrow* sparrow = new Sparrow();
	ToyDuck* toyDuck = new PlasticToyDuck();

	// Wrap a bird in a birdAdapter so that it behaves like toy duck 
	ToyDuck* birdAdapter = new BirdAdapter(sparrow);

	std::cout << "Sparrow...";
	sparrow->fly();
	sparrow->makeSound();

	std::cout << "ToyDuck...";
	toyDuck->squeak();

	// toy duck behaving like a bird 
	std::cout << "BirdAdapter...";
	birdAdapter->squeak();

	return 0;

	/*
		Sparrow...Flying
		Chirp Chirp
		ToyDuck...Squeak
		BirdAdapter...Chirp Chirp
	*/
}

#endif // STRUCTURAL_ADAPTER_PLUGGIN_II

// ---------------------------------------------
// ---------------------------------------------
