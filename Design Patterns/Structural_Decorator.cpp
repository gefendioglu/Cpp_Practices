#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<algorithm> 
#include<string>

class Coffee {

public:
	// TODO: To Be Controlled for the wrong results
	virtual int getCost() { return 0; };
	virtual std::string getDescription() { return "No coffee";};
};

// Concrete Component : SimpleCoffee
class SimpleCoffee : public Coffee {
public:
	int getCost()
	{
		return 10;
	}

	std::string getDescription()
	{
		return "Simple Coffee";
	}
};

// Concrete Component : MilkCoffee
class MilkCoffee : public Coffee {

public:
	
	MilkCoffee(Coffee coffee)
	{
		this->coffee = coffee;
	}

	int getCost() 
	{
		return this->coffee.getCost() + 2;
	}

	std::string getDescription() 
	{
		return this->coffee.getDescription() + ", milk";
	}

protected:
	Coffee coffee;

};

class WhipCoffee : public Coffee {

public:
	WhipCoffee(Coffee coffee)
	{
		this->coffee = coffee;
	}

	int getCost() 
	{
		return this->coffee.getCost() + 5;
	}

	std::string getDescription()
	{
		return this->coffee.getDescription() + ", whip";
	}

protected:
	Coffee coffee;

};

class VanillaCoffee : public Coffee {
public:
	VanillaCoffee(Coffee coffee)
	{
		this->coffee = coffee;
	}

	int getCost()
	{
		return this->coffee.getCost() + 3;
	}

	std::string getDescription()
	{
		return this->coffee.getDescription() + ", vanilla";
	}
protected:
	Coffee coffee;
};


//int main()
//{
//	// Lets make a coffee now
//	Coffee* someCoffee = new SimpleCoffee();
//	std::cout << "Simple Coffee cost : " << someCoffee->getCost() << "\n"; // 10
//	std::cout << "Simple Coffee Description : " << someCoffee->getDescription() << "\n"; // Simple Coffee
//	 
//	someCoffee = new MilkCoffee(*someCoffee);
//	std::cout << "Milk Coffee cost : " << someCoffee->getCost() << "\n"; // 12
//	std::cout << "Milk Coffee Description : " << someCoffee->getDescription() << "\n"; // Simple Coffee, milk
//
//	someCoffee = new WhipCoffee(*someCoffee);
//	std::cout << "Whip Coffee cost : " << someCoffee->getCost() << "\n"; // 17
//	std::cout << "Whip Coffee Description : " << someCoffee->getDescription() << "\n"; // Simple Coffee, milk, whip
//
//	someCoffee = new VanillaCoffee(*someCoffee);
//	std::cout << "Vanilla Coffee cost : " << someCoffee->getCost() << "\n"; // 20
//	std::cout << "Vanilla Coffee Description : " << someCoffee->getDescription() << "\n"; //  Simple Coffee, milk, whip, vanilla
//
//}
