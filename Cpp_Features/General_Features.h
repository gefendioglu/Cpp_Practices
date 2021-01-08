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
