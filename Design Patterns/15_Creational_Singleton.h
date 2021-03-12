#pragma once

#ifdef CREATIONAL_SINGLETON

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<chrono> 

// Return a singleton as a pointer
// ----------------------------------------------------
// ----------------------------------------------------

class President {
public:

	static President* getInstance()	{
		if (!instance)
			instance = new President();
		return instance;
	}

	// deleted copy constructor
	President(President const& president) = delete;

	// deleted copy assignment
	President& operator=(President const& president) = delete;

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

// Return a singleton as a reference (lazy initialization)
// ----------------------------------------------------
// ----------------------------------------------------

class Ceo {
public:
	static Ceo& getInstance() {
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


#ifdef CREATIONAL_SINGLETON_II

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

//singleton.h
/*-----------------------------------------------------*/
class SingletonPtr {
public:
	// return value is a pointer
	static SingletonPtr* getInstance();
	SingletonPtr(const SingletonPtr& ref) = delete;
	SingletonPtr& operator=(const SingletonPtr& ref) = delete;
	int getter() const{ 
		return mx; 
	}
	void setter(const int x) {
		this->mx = x;
	}
private:
	static SingletonPtr* mptr;
	int mx;
	SingletonPtr() = default; // preventing to be accessed by other classes
};

class SingletonRef {
public:
	// return value is a reference
	static SingletonRef& getInstance() {
		static SingletonRef sref; 
		return sref;
	}
	SingletonRef(const SingletonRef& ref) = delete;
	SingletonRef& operator=(const SingletonRef& ref) = delete;
	int getter() const {
		return mx;
	}
	void setter(const int x) {
		this->mx = x;
	}
private:
	int mx;
	SingletonRef() = default;
};

//singleton.cpp
/*-----------------------------------------------------*/
SingletonPtr* SingletonPtr::mptr = nullptr;
// the same imp. --> Singleton Singleton::*mptr = nullptr;

SingletonPtr* SingletonPtr::getInstance() {
	if (!mptr)
		mptr = new SingletonPtr();
	return mptr;
}

int main() {

	//Singleton obj; // --> not possible to create instance directly 
	auto objPtr = SingletonPtr::getInstance();
	objPtr->setter(10);
	std::cout << "objPtr->mx : " << objPtr->getter() << "\n";
		
	auto& objRef = SingletonRef::getInstance();
	objRef.setter(20);
	std::cout << "objRef.mx  : " << objRef.getter() << "\n";

	/*
		objPtr->mx : 10
		objRef.mx  : 20
	*/

	return EXIT_SUCCESS;
}

#endif // CREATIONAL_SINGLETON_II


