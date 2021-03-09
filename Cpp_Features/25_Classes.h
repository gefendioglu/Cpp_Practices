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


// Static Class Data Members & Class Member Functions
// --------------------------------------------
// --------------------------------------------

#ifdef STATIC_MEMBERS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// member.h
class Member {
public:
	static int mx;
	static int smx;
	static const int x = 10;
	static constexpr int y = 10;
	static const bool flag = true;
	static const double dx = 1.0; // ERROR, double is not an integral type
	constexpr static double dy = 1.0; // NOT ERROR, because of using constexpr instead of const
private:
};

// member.cpp
int mx = 10;
int Member::mx = 65;
int Member::smx = mx; // Member::mx, because of class scope

int main() {

	std::cout << "Member::smx : " << Member::smx << "\n";
	/*
		Member::smx : 65
	*/
}

#endif // STATIC_MEMBERS