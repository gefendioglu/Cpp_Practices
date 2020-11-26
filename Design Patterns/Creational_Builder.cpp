#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<algorithm> 

// ----------------------------------------------------
// ----------------------------------------------------

class Window {
public:
	Window(bool visible, bool modal, bool dialog) {
		this->visible = visible;
		this->modal = modal;
		this->dialog = dialog;
	}
private:
	bool visible;
	bool modal;
	bool dialog;
	// rest of class omitted
};

class WindowBuilder {
public:
	WindowBuilder() :dialog{ false }, modal{ false }, visible{ false }{}

	WindowBuilder setDialog(bool flag) {
		dialog = flag;
		return *this;
	}

	WindowBuilder setModal(bool flag) {
		modal = flag;
		return *this;
	}

	WindowBuilder setVisible(bool flag) {
		visible = flag;
		return *this;
	}

	Window build() {
		return *new Window(visible, modal, dialog);
	}

private:
	bool dialog;
	bool modal;
	bool visible;
};

// ----------------------------------------------------
// ----------------------------------------------------

class Burger {
public:
	Burger(bool cheese, bool pepperoni, bool lettuce, bool tomato) {
		this->cheese = cheese;
		this->pepperoni = pepperoni;
		this->lettuce = lettuce;
		this->tomato = tomato;
	}

private:
	bool cheese = false;
	bool pepperoni = false;
	bool lettuce = false;
	bool tomato = false;
};

class BurgerBuilder {
public:
	BurgerBuilder(int size)
	{
		this->size = size;
	}

	BurgerBuilder addPepperoni(bool flag)
	{
		this->pepperoni = flag;
		return *this;
	}

	BurgerBuilder addLettuce(bool flag)
	{
		this->lettuce = flag;
		return *this;
	}

	BurgerBuilder addCheese(bool flag)
	{
		this->cheese = flag;
		return *this;
	}

	BurgerBuilder addTomato(bool flag)
	{
		this->tomato = flag;
		return *this;
	}

	Burger build()
	{
		return *new Burger(cheese, pepperoni, lettuce, tomato);
	}

private:
	int size;
	bool cheese = false;
	bool pepperoni = false;
	bool lettuce = false;
	bool tomato = false;
};

//int main()
//{
//	Window* w = new Window(false, true, true);
//	
//	WindowBuilder* window = new WindowBuilder();
//	Window wbuilder = window->setVisible(false).setModal(true).setDialog(true).build();
//
//	Burger bbuilder = (new BurgerBuilder(14))->addPepperoni(true).addLettuce(false).addTomato(false).build();
//}