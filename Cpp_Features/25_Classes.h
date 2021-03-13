#pragma once

#ifdef CLASSES

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// data.h
class Data {
public:
	Data() {
		std::cout << "Data ctor is called..this : " << this << "\n";
	}
	~Data() {
		std::cout << "Data destructor is called..this : " << this << "\n";
	}
private:
	int mx, my;
};

// global class objects
Data globalData1;
Data globalData2;
Data globalData3;

int main() {
	std::cout << "main() function is called...\n";
	std::cout << "&globalData : " << &globalData1 << "\n";
	std::cout << "main() function is ended...\n";

	/*
		Data ctor is called..this : 00AEE138
		main() function is called
		&globalData : 00AEE138
		main() function is ended
		Data destructor is called..this : 00AEE138
	*/


}

#endif // CLASSES


// Static Data Members & Static Member Functions
// --------------------------------------------
// --------------------------------------------

#ifdef STATIC_MEMBERS

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string> 
#include<vector> 
#include<algorithm> 

// fighter.h
/*-------------------------------------------------*/
class Fighter {
public:
	Fighter() {
		msvec.push_back(this);
	}
	Fighter(const std::string &name, int age) : mname{ std::move(name) }, mage{ age }{
		// the address of instance is stored in a vector 
		msvec.push_back(this);
	}
	~Fighter() {
		// iter type --> std::vector<Fighter>::iterator
		// if iter is found in the vector, if with initializer
		if (auto iter = std::find(msvec.begin(), msvec.end(), this); iter != msvec.end())
			msvec.erase(iter);
		else
			std::cerr << "Not found!!!\n";
	}

	Fighter(const Fighter& ref) = delete;
	Fighter& operator=(const Fighter& ref) = delete;
	
	int getAge() const { return mage; }
	std::string getName() const { return mname; }
	void kill();
	void run();
	void ask_help();
private:
	std::string mname = "noname";
	int mage = 0;
	inline static std::vector<Fighter*> msvec{};
};

// fighter.cpp
void Fighter::ask_help() {
	// range based for loop
	for (auto ftr: msvec) {
		if(ftr != this) // it is not the object itself
		std::cout << ftr->mname << " ";
	}
	std::cout << "Help!!!\n";
}

// client code
/*-------------------------------------------------*/
int main() {

	// Static objects
	Fighter f1{ "Mehmet", 25 };
	Fighter f2{ "Ayse", 26 };
	Fighter f3{ "Ece", 27 };
	Fighter f4{ "Utku", 30 };

	// Dynamic objects
	auto pf1 = new Fighter{"Selin", 32};
	auto pf2 = new Fighter{"Özge", 33};
	auto pf3 = new Fighter{"Sinem", 34};
	
	delete pf2;
	delete pf3;

	// asking help for the other live fighters
	f2.ask_help();


	return EXIT_SUCCESS;

	/*
		Mehmet Ece Utku Selin Help!!
	*/
}

#endif // STATIC_MEMBERS


