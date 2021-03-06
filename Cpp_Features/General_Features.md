
## 1- TYPE ALIASES 

- type aliases are easier to read 
- type aliase are compatible with C++ templates types

```cpp
template <typename T>
using dyn_arr = std::vector<T>;
dyn_arr<int> nums; // equivalent to std::vector<int>

using func_ptr = int (*)(int);
```

/----------------------------------------------
/----------------------------------------------

## 2- USER DEFINED LITERALS 

-**Example**: User Defined Literals
 - Adding constexpr will serve zero cost run-time performance impact
 
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

using ull = unsigned long long;
constexpr ull operator"" _KB(ull no){ return no * 1024;}
constexpr ull operator"" _MB(ull no){ return no * (1024_KB); }

int main() {
    std::cout << 1_KB << "\n";
    std::cout << 5_MB << "\n";
}
```

/----------------------------------------------
/----------------------------------------------

## 3- INITIALIZER LIST (std::initializer_list) 

-**Example**: Initializer List

```cpp
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
```

/----------------------------------------------
/----------------------------------------------

## 4- INLINE FUNCTIONS 

- Inline functions and inlined functions are different terms

- Implicitly inline functions can be defined in class definition directly. If the function is defined in source file as always, then it is not an inline function. 

- ODR idiom is not violated by the use of inline specifier 

- Constexpr functions are implicitly inlined functions. 

- Both non-static const member functions and non-static non-const member functions can be defined as inlined functions.

- Static member functions can also be defined as inlined function.

- Inline functions should be preferred to use for the small and frequently called functions.

- Inline functions are very useful in terms of code optimization. The settings shall be use to set the using level of inline functions.  

- Static Initialization Fiasco: It is not clear that the order of coming to life for an object in different source files. 

- Before C++17, inline keyword was only used with functions. After C ++ 17, this keyword has also been used for static members and also global variables (inline variables). All compilers are compatible with this kind of important feature. This feature does not violate ODR (one definition rule) either. 

- Header Only Library : These are files that consist only of header files and do not have source files dependent on to it. In these kinds of files, inline keyword provides static data members to define inside class without the needs of having a source file. 
  - If inline keyword is not used and there is also no source file in the environment, undefined behaviour can be came out in linker phase. This is not a preferred situation.  

/----------------------------------------------
/----------------------------------------------

- **Example** : inline keyword with static data members (C++17)

```cpp
#include <iostream>

// like static local variables
inline int globalVal = 15;

// member.h
//----------------------------------------------
class Member {
public:
	static int smx;
	inline static int smy = 10;
};

//member.cpp
//----------------------------------------------
int Member::smx = 10;

int main() {
	Member mem;
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Inline functions in class definition

```cpp
class MyClass {
public:
	//Inline function without "inline" specifier
	int func(int val) {
		return val * val;
	}
  
	int foo(int val);
  
	//Inline static member function
	static int sfunc(int num1, int num2) {
		return num1 + num2;
	}
  
	//Inline friend function
	friend int ffunc(int x) {
		//...
		return 1;
	}
}

//Implicitly inlined function 
constexpr int factorial(int n) { return n < 2 ? 1 : factorial(n - 1) * n; }
```

/----------------------------------------------
/----------------------------------------------

## 5- DELETE FUNCTIONS  

- The following function types can be deleted using "delete" keyword:
  - global functions
  - class member functions
  - special member functions
    - default constructor
    - copy constructor
    - copy assignment function 
    - move constructor  (added with C++11)
    - move assignment function  (added with C++11)
    - destructor

- Calling a deleted function results in a syntax error.

/----------------------------------------------
/----------------------------------------------

- **Example** : Delete Functions & Function Overloading

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// all the following functions are overloaded
void func(int x, int y);
void func(int);
void func(double) = delete; // func(double) still exists
void func(int*);
void func(long double);

int main() {

	func(12, 24); // OK, func(int x, int y) is called
	func(2.43);   // NOT OK, func(double) is a deleted function
				        // attempting to reference a deleted func. error
	
	/*
		To be executed to add here !!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : How can we provide to call func() function with only int parameter? 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void func(int);

template<typename T>
void func(T x) = delete;

int main() {
	func(12);	// OK, func(int x) is not deleted
	func(2.43); // NOT OK, for the other types, is deleted 
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : "default" keyword

```cpp
class Data {
public:
	// compiler writes the default constructor
	Data() = default; 
	Data(const Data &) = default; 
	~Data() = default; 
	Data(int x) {std::cout << "Data(int x)\n";}
private:
	std::string ms;
};
```

/----------------------------------------------
/----------------------------------------------

- **Example** : "mutable" keyword

```cpp
class Data {
public:
	Data() = default;
	~Data() = default; 
	void func()const {
		++counter; // OK, thanks to "mutable" 
		           // normally, it is NOT OK, const func.
	}
	void foo() { ++counter; }
private:
	mutable int counter = 0; 
};
```

/----------------------------------------------
/----------------------------------------------

## 6- SCOPE LEAKAGE

- Before C++17, another scope can be defined to restrict the usage of variable 
- After C++17, "if with initializer" is used instead of adding another scope in these  cases. 

/----------------------------------------------
/----------------------------------------------

```cpp
int x = foo(2,5);
if( x > 10 ){
	//...
	g(x);
}
// x is also accessed here !!!
```

/----------------------------------------------
/----------------------------------------------

```cpp
if( int x = foo(2,5); x > 10 ){
	//...
	g(x);
}
// x is not accessed here !!!
```

/----------------------------------------------
/----------------------------------------------

```cpp
int *foo(int);
int func(int, int);

int main(){
	if(int *ptr = foo(10); ptr != nullptr){
		//...
	}
	// if(int *ptr = foo(20)){} --> in this case, if(true) or if(false) 
}
```

/----------------------------------------------
/----------------------------------------------

## 7- RANGE BASED LOOP 

- If container is assumed as any kind of container, range based for loops can be one of the followings: 
  - for(T x : container)   -->  for(auto x : container)
  - for(T &x : container)  -->  for(auto &x : container)
  - for(T &&x : container) -->  for(auto &&x : container)

- Each type of "for loops" are interpreted differently by compilers. 
- You traverse all elements of containers with for range loops, not a part of it. 

/----------------------------------------------
/----------------------------------------------

- **Example**: For range loop --> for(auto x : container)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {

	int arr[]{ 1,4,5,6,8,12,98,23 };

	// array elements are copied to x value 
	// x is not a reference for array elements
	for (auto x : arr) {
		std::cout << x << " ";
		x++; // not effect the array elements
	}

	std::cout << "\n";

	// The array elements are not changed.
	for (auto x : arr) {
		std::cout << x << " ";
	}

	return EXIT_SUCCESS;

	/*
		1 4 5 6 8 12 98 23
		1 4 5 6 8 12 98 23
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: For range loop --> for(auto &x : container)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {

	int arr[]{ 1,4,5,6,8,12,98,23 };

	// x is a reference for array elements
	for (auto &x : arr) { 
		std::cout << x << " ";
		x++; // effects the array elements
	}

	std::cout << "\n";

	// The array elements must have changed.
	for (auto x : arr) {
		std::cout << x << " ";
	}

	return EXIT_SUCCESS;
	
	/*	
		1 4 5 6 8 12 98 23
		2 4 6 7 8 13 99 24
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Constant for range loops --> for( const auto &x : container)
  - Whenever you want to access the array elements, but not intend to change their values, const keyword shall be used in "for range" loops. 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {

	int arr[]{ 1,4,5,6,8,12,98,23 };

	// array elements are copied to x value 
	// x is not a reference for array elements
	for (const auto &x : arr) {
		std::cout << x << " ";
		x++; // SYNTAX ERROR, x is a const reference
	}
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: For range loop with forwarding ref. --> for(auto &&x : container)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int main() {

	std::vector<int> ivec{1, 4, 5, 6, 8, 12, 98, 23};

	// x is a forwarding reference (universal ref.)
	for (auto&& x : ivec) {
		std::cout << x << " ";
		x++; // effects the array elements
	}

	std::cout << "\n";

	// The array elements must have changed.
	for (auto x : ivec) {
		std::cout << x << " ";
	}

	return EXIT_SUCCESS;

	/*
		1 4 5 6 8 12 98 23
		2 4 6 7 8 13 99 24
	*/
}
```

/----------------------------------------------
/----------------------------------------------

## 8- FRIEND FUNCTION DECLARATION  

- "friend" specifier is used to access the private part of a class by a function which is not a member of the same class. 

- There are 3 different types of friend declaration by supporting a friendship for:
  - global functions
  - class member functions
  - classes

- In friend declaration, the class does not need to have the function definition.  

- It does not matter where to define a friend declaration. It might be under public or private part of a class.

- It is not possible (and not sensible either) to give friendship to class member functions for the same class.

- The class taking friendship from another class, it does not mean that this class have to give friendship too. 

- It is not possible to give friendship for a specific private function to a class. A class taking the friendship can access all private members of another class giving the friendship to this class. (If we want to access a specific private member of a class, then we use attorney client idiom) 

- If a base class gives friendship to another class (supposed to be called as "Member" class), it does not mean that the derived class which is inherited from this base class can access the private members of Member class. 

```cpp
class Base {
public:
	friend class Member;
};

class Derived : public Base {
public:
	void derFunc();
private:
	int derVal;
};

class Member {
public:
	void memFunc(Derived der) {
		der.derFunc(); // OK,it is a public func 
		der.derVal;    // NOT OK, not a friend of Derived class
	}
};
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Friend Function Declaration 

```cpp
class Data {
public:
	void dfunc();
};

class Member {
public:
	friend void gfunc(Member mem);

	// Data class definition must be done before this friend declaration, incomplete declaration can not be accepted, neither!!!  
	friend void Data::dfunc();
private:
	void pfunc();
};

void gfunc(Member mem) {
	//...
	mem.pfunc(); // OK, thanks to friend declaration !!!
}

void Data::dfunc() {
	//...
	Member mem;
	mem.pfunc();  // OK, thanks to friend declaration !!!
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Giving friendship to all class members
  - In this case, the class giving friendship is not obliged to see the definition/declaration of the class taking this friendship.

```cpp
class Member {
public:
	// To give friendship for all members of Data class, not need to Data class declaration/definition!!!
	friend class Data;
private:
	void pfunc();
};

class Data {
public:
	void dfunc();

	// All members of Data class can access to all members of Member class
	void func1(Member mem) {
		//...
		mem.pfunc(); 
	}
	void func2() {
		//...
		Member mem;
		mem.pfunc();
	}
};
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Global operator function inline definition with friend declaration. 
  - Normally binary operators take two parameters, if they are defined in global space. If they are defined in class, they can continue to have this feature, because of using friend declaration. 
 
```cpp
class Member {
public:
	// global operator function - inline definition thanks to friend declaration
	friend bool operator<(Member mem1, Member mem2) {
		return mem1.mx < mem2.mx;
	}
	int getVal()const {
		return mx;
	}
private:
	int mx;
};
```

/----------------------------------------------
/----------------------------------------------
