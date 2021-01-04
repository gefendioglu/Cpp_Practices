#pragma once

#ifdef CREATIONAL_SINGLETON

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<chrono> 

// ----------------------------------------------------
// ----------------------------------------------------
// Return a singleton as a pointer
// This guarantees that it is created and destroyed only once. 
// Stop the compiler generating methods of copy the object with copy constructor

class President {
public:

	static President* getInstance()
	{
		if (!instance)
			instance = new President();
		return instance;
	}

	// deleted copy constructor
	President(President const& pre) = delete;

	// deleted copy assignment
	President& operator=(President const& pre) = delete;

	// getter - setter functions
	int getData()const { return this->data; }
	void setData(const int& data) { this->data = data; }

private:
	static President* instance;
	int data;
	President() : data{ 0 } {	} // private ctor
};

//Initialize pointer to zero so that it can be initialized in first call to getInstance
President* President::instance = 0;

// ----------------------------------------------------
// ----------------------------------------------------

// Return a singleton as a reference
// Use the static in a function method.
// It also gives you "lazy initialization". 

class Ceo {
public:
	static Ceo& getInstance()
	{
		static Ceo instance;
		return instance;
	}

	int getData()const { return this->data; }
	void setData(const int& data) { this->data = data; }

private:
	int data;
	Ceo() {}						// private ctor 
	Ceo(Ceo const& ceo);			// copy constructor
	Ceo& operator=(Ceo const& ceo); // copy assignment

};

int main() {

	President* president = president->getInstance();
	std::cout << president->getData() << "\n"; // 0 
	president->setData(100);
	std::cout << president->getData() << "\n"; // 100


	Ceo &ceo = ceo.getInstance();
	std::cout << ceo.getData() << "\n"; // 0 
	ceo.setData(200);
	std::cout << ceo.getData() << "\n"; // 200

	return 0;
}

#endif // CREATIONAL_SINGLETON