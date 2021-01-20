#pragma once


#ifdef CREATIONAL_BUILDER

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

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
};

class WindowBuilder {
public:
	WindowBuilder() :visible{ false },modal{ false }, dialog{ false } {}

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
	bool modal;
	bool visible;
	bool dialog;
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
	BurgerBuilder(int size)	{
		this->size = size;
	}

	BurgerBuilder addPepperoni(bool flag) {
		this->pepperoni = flag;
		return *this;
	}

	BurgerBuilder addLettuce(bool flag)	{
		this->lettuce = flag;
		return *this;
	}

	BurgerBuilder addCheese(bool flag) {
		this->cheese = flag;
		return *this;
	}

	BurgerBuilder addTomato(bool flag) {
		this->tomato = flag;
		return *this;
	}

	Burger build() {
		return *new Burger(cheese, pepperoni, lettuce, tomato);
	}
private:
	int size;
	bool cheese = false;
	bool pepperoni = false;
	bool lettuce = false;
	bool tomato = false;
};

int main() {

	// creating object in a classic way
	Window* w = new Window(false, true, true);
	
	// creating object using builder class (WindowBuilder)
	WindowBuilder* window = new WindowBuilder();
	Window wbuilder = window->setVisible(false).setModal(true).setDialog(true).build();

	// creating object using builder class (BurgerBuilder)
	BurgerBuilder *burger = new BurgerBuilder(14);
	Burger bbuilder = burger->addPepperoni(true).addLettuce(false).addTomato(false).build();

	return 0;
}

#endif // CREATIONAL_BUILDER

#ifdef CREATIONAL_BUILDER_I

// Person.h
// ----------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class PersonBuilder;

class Person {
public:
	friend class PersonBuilder;
	friend std::ostream& operator<<(std::ostream& os, const Person& obj);
	static PersonBuilder create(std::string name);
private:
	// Personel Data
	std::string m_name, m_street_address, m_city; 
	// Employment Data
	std::string m_company_name, m_position, m_annual_income;
	// Private Constructor
	Person(std::string name) : m_name{ name } {}
};

// Person_Builder.h
// ----------------------------------------------
//#include "Person.h"

class PersonBuilder {

public:
	PersonBuilder(std::string name) : person{ name } {}
	operator Person() const { 
		return std::move(person); 
}

	PersonBuilder& lives();
	PersonBuilder& at(std::string street_address);
	PersonBuilder& in(std::string city);
	PersonBuilder& works();
	PersonBuilder& with(std::string company_name);
	PersonBuilder& as_a(std::string position);
	PersonBuilder& earning(std::string annual_income);

private:
	Person person;
};

// Person.cpp
// ----------------------------------------------
//#include "Person.h"
//#include "Person_Builder.h"

PersonBuilder Person::create(std::string name) { 
	return PersonBuilder{ name }; // temporary object
}
std::ostream& operator<<(std::ostream& os, const Person& obj)
{
	return os << obj.m_name
		<< std::endl
		<< "lives : " << std::endl
		<< "at " << obj.m_street_address
		<< " in " << obj.m_city
		<< std::endl
		<< "works : " << std::endl
		<< "with " << obj.m_company_name
		<< " as a " << obj.m_position
		<< " earning " << obj.m_annual_income;
}

// Person_Builder.cpp
// ----------------------------------------------
//#include "Person_Builder.h"

PersonBuilder& PersonBuilder::lives() { return *this; }
PersonBuilder& PersonBuilder::works() { return *this; }

PersonBuilder& PersonBuilder::with(std::string company_name) {
	person.m_company_name = company_name;
	return *this;
}

PersonBuilder& PersonBuilder::as_a(std::string position) {
	person.m_position = position;
	return *this;
}

PersonBuilder& PersonBuilder::earning(std::string annual_income) {
	person.m_annual_income = annual_income;
	return *this;
}

PersonBuilder& PersonBuilder::at(std::string street_address) {
	person.m_street_address = street_address;
	return *this;
}

PersonBuilder& PersonBuilder::in(std::string city) {
	person.m_city = city;
	return *this;
}

// main.cpp
// ----------------------------------------------
//#include "Person.h"
//#include "Person_Builder.h"

int main()
{
	Person p = Person::create("John")
		.lives()
		.at("123 London Road")
		.in("London")
		.works()
		.with("PragmaSoft")
		.as_a("Consultant")
		.earning("1000000");

	std::cout << p << "\n";

	return EXIT_SUCCESS;
}

#endif // CREATIONAL_BUILDER
