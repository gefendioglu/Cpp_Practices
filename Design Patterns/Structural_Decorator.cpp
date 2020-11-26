#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<algorithm> 
#include<string>

class Coffee {

public:
    virtual int getCost() const;
    virtual std::string getDescription()const;
};

class SimpleCoffee : public Coffee {
public:
    int getCost()const
    {
        return 10;
    }

    std::string getDescription()const
    {
        return "Simple coffee";
    }
};

class MilkCoffee implements Coffee
{
    protected $coffee;

    public function __construct(Coffee $coffee)
    {
        $this->coffee = $coffee;
    }

    public function getCost()
    {
        return $this->coffee->getCost() + 2;
    }

    public function getDescription()
    {
        return $this->coffee->getDescription() . ', milk';
    }
}

class WhipCoffee implements Coffee
{
    protected $coffee;

    public function __construct(Coffee $coffee)
    {
        $this->coffee = $coffee;
    }

    public function getCost()
    {
        return $this->coffee->getCost() + 5;
    }

    public function getDescription()
    {
        return $this->coffee->getDescription() . ', whip';
    }
}

class VanillaCoffee implements Coffee
{
    protected $coffee;

    public function __construct(Coffee $coffee)
    {
        $this->coffee = $coffee;
    }

    public function getCost()
    {
        return $this->coffee->getCost() + 3;
    }

    public function getDescription()
    {
        return $this->coffee->getDescription() . ', vanilla';
    }
}


int main() 
{
       // Lets make a coffee now


    $someCoffee = new SimpleCoffee();
    echo $someCoffee->getCost(); // 10
    echo $someCoffee->getDescription(); // Simple Coffee

    $someCoffee = new MilkCoffee($someCoffee);
    echo $someCoffee->getCost(); // 12
    echo $someCoffee->getDescription(); // Simple Coffee, milk

    $someCoffee = new WhipCoffee($someCoffee);
    echo $someCoffee->getCost(); // 17
    echo $someCoffee->getDescription(); // Simple Coffee, milk, whip

    $someCoffee = new VanillaCoffee($someCoffee);
    echo $someCoffee->getCost(); // 20
    echo $someCoffee->getDescription(); // Simple Coffee, milk, whip, vanilla
}

