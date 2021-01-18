#pragma once

// User Defined Literals
// --------------------------------------------
// --------------------------------------------
#ifdef USER_DEFINED_LITERALS 

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

using ull = unsigned long long;
constexpr ull operator"" _KB(ull no) {
    return no * 1024;
}
constexpr ull operator"" _MB(ull no) {
    return no * (1024_KB);
}

int main() {

    std::cout << 1_KB << "\n";
    std::cout << 5_MB << "\n";
}
#endif // USER_DEFINED_LITERALS 

// Uniform Initialization
// Non-static Member Initialization
// --------------------------------------------
// --------------------------------------------

#ifdef NON_STATIC_MEMBER_INIT

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class demo {
public:
    demo(uint32_t ival, bool bval, std::string sval, float fval) : m_ival{ ival }, m_bval{ bval }, m_sval{ sval },
        m_fval{ m_fval } {}
private:
    // non-static member initialization
    uint32_t m_ival = 0;
    bool m_bval = false;
    std::string m_sval = "";
    float m_fval = 0.0;
};

int main() {
    // uniform initialization
    demo obj{ 123, true, "lol", 1.1 };
    return EXIT_SUCCESS;
}

#endif // NON_STATIC_MEMBER_INIT

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Forward Declaration
// --------------------------------------------
// --------------------------------------------

#ifdef FORWARD_DECLARATION

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Forward Declaration for class A
class A;

class B {
public:
	void setData(int mdata)	{
		mx = mdata;
	}

	// Forward declaration is required for the parameters of sum func. 
	friend int sum(const A&, const B&);
private:
	int mx;
};

class A {
public:
	void setData(int mdata)	{
		my = mdata;
	}
	friend int sum(const A&, const B&);
private: 
	int my;
};

int sum(const A& m, const B& n){
	return (m.my + n.mx);
}

int main(){

	B b;
	A a;
	
	a.setData(5);
	b.setData(4);
	std::cout << "The sum is : " << sum(a, b);
	// The sum is : 9
	
	return EXIT_SUCCESS;
}

#endif // FORWARD_DECLARATION

// std::initializer_list
// --------------------------------------------
// --------------------------------------------

#ifdef INITIALIZER_LIST

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<vector>
#include<tuple> 
#include<set> 
#include<list> 
#include<deque> 
#include<array> 
#include<stack> 
#include<queue> 

int main() {

	std::pair<int, int> ipair = { 1, 2 };
	std::tuple<int, int> ituple = { 1, 2 };
	std::vector<int> ivec = { 1, 2, 3, 4, 5 };
	std::set<int> iset = { 1, 2, 3, 4, 5 };
	std::list<int> ilist = { 1, 2, 3, 4, 5 };
	std::deque<int> ideque = { 1, 2, 3, 4, 5 };
	std::array<int, 5> iarray = { 1, 2, 3, 4, 5 };

	// Initializer list is not available for adapters
	std::stack<int> istack = {1, 2, 3, 4, 5}; // NOT OK
	std::queue<int> iqueue = {1, 2, 3, 4, 5}; // NOT OK
	std::priority_queue<int> ipq = {1, 2, 3, 4, 5}; // NOT OK
}

#endif // INITIALIZER_LIST


// This section is to test dummy features
// --------------------------------------------
// --------------------------------------------

#ifdef FEATURE

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 


int main() {


}

#endif // FEATURE
