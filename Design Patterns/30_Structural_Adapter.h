#pragma once

#ifdef STRUCTURAL_ADAPTER_CLASSICAL

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Base Class
class Member {
public:
    virtual void draw() { 
		std::cout << "Member::draw()\n";
	}
private:
    int32_t m_x;
};

// Template Definition for a generic adapter
template<class T>
class GenericLineAdapter : public Member {
public:
	GenericLineAdapter(T& line) : m_line{ line } {}
    void draw() { m_line.draw(); }
private:
    T& m_line;
};

// Derived Class (from Member base class)
class Member2D : public Member {
public:
    void draw() override { 
		std::cout << "Member2D::draw()\n"; 
	}
private:
    int32_t m_Member2d;
};

// Global Function Definition
void draw_Member(Member& p) {
    p.draw();
}

// "Line" class is composed of "Member2D" derived class
class Line {
public:
    void draw() {
		std::cout << "Line::draw()\n"; 
	}
private:
    Member2D m_start;
    Member2D m_end;
};

// Adapter class for "Line" class
class LineAdapter : public Member {
public:
	LineAdapter(Line& line) : m_line{ line } {}
    void draw() override { 
		m_line.draw(); 
	}
private:
    Line& m_line;
};

int main() {

    Line line;
    LineAdapter lineAdapter(line);
    draw_Member(lineAdapter);

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
	void Brew() { 
		std::cout << "brewing coffee" << "\n"; 
	}
	void getBeverage() override { Brew(); }
};

void make_drink(Beverage& drink) {
	drink.getBeverage();
}
/* ---------------------------------------------- */

class JuiceMaker {
public:
	void Squeeze() { 
		std::cout << "making Juice" << "\n"; 
	}
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

// Pure Virtual Base Class 
class Bird {
public:
	virtual void fly() = 0;
	virtual void makeSound() = 0;
};

// Derived class (Sparrow) from virtual base class (Bird)
class Sparrow : public Bird {
public:
	void fly() override {
		std::cout << "Sparrow::fly()" << "\n";
	}

	void makeSound() override {
		std::cout << "Sparrow::makeSound() - Chirp Chirp" << "\n";
	}
};

// Pure Virtual Base Class 
class ToyDuck {
public:
	//toyducks don't fly, they only make squeaking sound 
	virtual void squeak() = 0;
};

// Derived class (PlasticToyDuck) from base class (ToyDuck)
class PlasticToyDuck : public ToyDuck {
public:
	void squeak() override {
		std::cout << "PlasticToyDuck::squeak()" << "\n";
	}
};

// Adapter class (inherited from base class)
class BirdAdapter : public ToyDuck {
public:
	BirdAdapter(Bird* bird) {
		this->bird = bird;
	}

	void squeak() override {
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
