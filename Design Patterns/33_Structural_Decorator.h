#pragma once

// ----------------------------------------------------
// ----------------------------------------------------

#ifdef STRUCTURAL_DECORATOR_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string>

// Abstract Component : Coffee
class Coffee {
public:
	virtual int getCost() const = 0;
	virtual std::string getDescription() const = 0;
};

// Concrete Component : SimpleCoffee
class SimpleCoffee : public Coffee {
public:
	int getCost() const override {
		return 10; 
	}
	std::string getDescription() const override {
		return "Simple Coffee"; 
	}
};

// Decorator : CoffeeDecorator 
class CoffeeDecorator : public Coffee {
public:
	CoffeeDecorator(Coffee* coffee) : m_coffee{ coffee } {}
	
	// Wrapping the getCost() function with the same name
	int getCost() const override {
		return this->m_coffee->getCost();
	}

	// Wrapping the getDescription() function 
	std::string getDescription() const override {
		return this->m_coffee->getDescription();
	}
protected:
	Coffee* m_coffee;
};

// Concrete Decorator : MilkCoffee
class MilkCoffee : public CoffeeDecorator {

public:
	// Delegating Constructor
	MilkCoffee(Coffee* coffee) : CoffeeDecorator(coffee) {}

	int getCost() const override {
		return m_coffee->getCost() + 2;
	}

	std::string getDescription() const override {
		return m_coffee->getDescription() + ", milk";
	}
};

// Concrete Decorator : WhipCoffee
class WhipCoffee : public CoffeeDecorator {

public:
	// Delegating Constructor
	WhipCoffee(Coffee* coffee) : CoffeeDecorator(coffee) {}

	int getCost() const override {
		return m_coffee->getCost() + 5;
	}
	std::string getDescription() const override {
		return m_coffee->getDescription() + ", whip";
	}
};

// Concrete Decorator : VanillaCoffee
class VanillaCoffee : public CoffeeDecorator {
public:
	// Delegating Constructor
	VanillaCoffee(Coffee* coffee) : CoffeeDecorator(coffee) {}

	int getCost() const override {
		return m_coffee->getCost() + 3;
	}
	std::string getDescription() const override {
		return m_coffee->getDescription() + ", vanilla";
	}
};


int main()
{
	// Derived (SimpleCoffee) --> Base (Coffee)
	Coffee* baseCoffee = new SimpleCoffee();
	std::cout << "Simple Coffee cost : " << baseCoffee->getCost() << "\n"; // 10
	std::cout << "Simple Coffee Description : " << baseCoffee->getDescription() << "\n"; // Simple Coffee
	 
	baseCoffee = new MilkCoffee(baseCoffee);
	std::cout << "Milk Coffee cost : " << baseCoffee->getCost() << "\n"; // 12
	std::cout << "Milk Coffee Description : " << baseCoffee->getDescription() << "\n"; // Simple Coffee, milk

	baseCoffee = new WhipCoffee(baseCoffee);
	std::cout << "Whip Coffee cost : " << baseCoffee->getCost() << "\n"; // 17
	std::cout << "Whip Coffee Description : " << baseCoffee->getDescription() << "\n"; // Simple Coffee, milk, whip

	baseCoffee = new VanillaCoffee(baseCoffee);
	std::cout << "Vanilla Coffee cost : " << baseCoffee->getCost() << "\n"; // 20
	std::cout << "Vanilla Coffee Description : " << baseCoffee->getDescription() << "\n"; //  Simple Coffee, milk, whip, vanilla

	delete baseCoffee;
	return 0;
}

#endif // STRUCTURAL_DECORATOR_I

// ----------------------------------------------------
// ----------------------------------------------------

#ifdef STRUCTURAL_DECORATOR_II

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Abstract Component : MilkShake 
class MilkShake {
public:
	virtual std::string getServe() const = 0;
	virtual double getPrice() const = 0;
};

// Concrete Component : BaseMilkShake
class BaseMilkShake : public MilkShake {
public:
	std::string getServe()const override { 
		return "MilkShake"; 
	}
	double getPrice()const override { 
		return 30; 
	}
};

// Decorator : MilkShakeDecorator
class MilkShakeDecorator : public MilkShake {
public:
	MilkShakeDecorator(MilkShake* baseMilkShake) : m_MilkShake{ baseMilkShake } {}

	std::string getServe()const override { 
		return m_MilkShake->getServe(); 
	}
	double getPrice()const override { 
		return m_MilkShake->getPrice(); 
	}
protected:
	MilkShake* m_MilkShake;
};

// Concrete Decorator : MangoMilkShake
class MangoMilkShake : public MilkShakeDecorator {
public:
	// Delegating Constructor
	MangoMilkShake(MilkShake* baseMilkShake) : MilkShakeDecorator(baseMilkShake) {}

	std::string getServe()const override { 
		return m_MilkShake->getServe() + " decorated with Mango "; 
	}
	double getPrice()const override { 
		return m_MilkShake->getPrice() + 40; 
	}
};

// Concrete Decorator : VanillaMilkShake
class VanillaMilkShake : public MilkShakeDecorator {
public:
	// Delegating Constructor
	VanillaMilkShake(MilkShake* baseMilkShake) : MilkShakeDecorator{ baseMilkShake } {}

	std::string getServe()const override { 
		return m_MilkShake->getServe() + " decorated with Vanilla "; 
	}
	double getPrice()const override { 
		return m_MilkShake->getPrice() + 80; 
	}
};

int main()
{
	MilkShake* baseMilkShake = new BaseMilkShake();
	std::cout << "Basic Milk shake \n";
	std::cout << baseMilkShake->getServe() << "\n";
	std::cout << baseMilkShake->getPrice() << "\n";

	MilkShake* decoratedMilkShake = new MangoMilkShake(baseMilkShake);
	std::cout << "Mango decorated Milk shake \n";
	std::cout << decoratedMilkShake->getServe() << "\n";
	std::cout << decoratedMilkShake->getPrice() << "\n";

	decoratedMilkShake = new VanillaMilkShake(baseMilkShake);
	std::cout << "Vanilla decorated Milk shake \n";
	std::cout << decoratedMilkShake->getServe() << "\n";
	std::cout << decoratedMilkShake->getPrice() << "\n";

	delete decoratedMilkShake;
	delete baseMilkShake;
	return 0;

	/*
		Basic Milk shake
		MilkShake
		30
		Mango decorated Milk shake
		MilkShake decorated with Mango
		70
		Vanilla decorated Milk shake
		MilkShake decorated with Vanilla
		110
	*/
}

#endif // STRUCTURAL_DECORATOR_II
// ----------------------------------------------------
// ----------------------------------------------------
