 
 ## OPERATOR OVERLOADING 

 - If operator < exists, the other operators can be overloaded on the basis of i. Other operators can be made type independent for reusability purpose.

 - In string class, the operator overloading mechanism is used intensively for example to sum a string and a string literal. 

 - There are two types of operator functions:  
   - global operator function (definition in global space)
   - member operator function (definition in class)
     - this type of function shall be defined as non-static 
	 - it is not possible to define a static member operator function in a class

- Overloading mechanism can be defined for only operators which are in the operator set in Cpp. 
  - For ex: Not possible to overload @ operator such as --> x @ y

- One of the operands shall be a class type for any kind of operator functions. 
  - For ex: assumed that for i1, i2 their types are integer
    - Operator overloading is not applied for --> i1 + i2, !i1, etc. 

- Some operators can not be overloaded. For example:
  - dot operator (.)
  - sizeof() operator
  - scope resolution operator(::)
  - .* operator
  - ternary operator (? : )
  - typeid() operator 

- The following operators can be overloaded:
  - reference operator (*)
  - arrow operator (->)
  - address operator (&)
  - parantheses operator ([])
  - function call operator ()
  - type conversion operators (??)

- Some operators can be overloaded, but only as member functions, not in the global scope:
  - special member function assignment operator (=), not all assignment operators 
  - parantheses operator ([])
  - function call operator ()
  - arrow operator (->)
  - type conversion operators (??)
  
- Naming for operator functions: 
  - "operator" keyword must be used in the function definition
  - For ex: operator!, operator<, etc.

- Operator functions can not take default arguments, except function call operator. 

- Operator Arity: It defines of whether the operator is binary operator or unary operator. This feature can not be changed with overloading mechanism. If an operator is a binary operator, it will remain as a binary operator, even after operator overloading mechanism is applied to it. 

- In global space:
  - Binary operators --> have 2 parameters 
  - Unary operators  --> have 1 parameter

- In class space (as a member function and generally const function):
  - Binary operators --> have 1 parameter 
  - Unary operators  --> do not have any parameters
 
- What is the common feature for the following operators?
  - +, -, &, * --> they are both unary and binary operators 

- Operator precedence and associativity level can not be changed with overloading mechanism.

- Operator overloading mechanism includes function overloading mechanism too. 

- Why do we need global operator functions? 
  - Especially for calling operator functions with parameters in a different order.

- How can we decide whether to write global operator function or class member operator function? Cpp standard library obeys the rules defined in the following: 
  - It is commonly suggested that symmetric binary operators which has no side effects on their parameters shall be written as global operator function.
    - symmetric operators --> (a operator b) = (b operator a)
    - non-symmetric operators --> (number - date) is not sensible 
  - If an operator has side effect on class objects, then its overloaded function shall be written as class member function. 
  - For binary operators with both have side effects on class objects or have not side effects on class objects, their operator overloading functions should be written in class. 
   
- What should be the return value of operator functions? 
  - The return value of a < b is equal to the return value of a.operator<(b) 
  - How can we choose the correct return value for the following examples? Should it be a reference? It depends on the value category (L-Value, R-Value, X-Value). Assuming that T is any kind of data type here:
    - R-Value exp. --> T operator() 
	- L-Value exp. --> T& operator() 

- Not suggested that both member operator functions and global operator functions are available for the same operator in a file. 

- How can we choose the correct parameter type for operator functions? Should it be a constant reference?
  - Member operator+(const Member& mem1, const Member& mem2);
  - Member operator+(Member mem1, Member mem2);
    - If the copy cost is not so much or if copying will be already applied in the function, then the functions with const reference parameters shall be chosen! Otherwise, the the functions with class type is much safer. 
    - If operator function has no side effect on its parameters, then the parameters shall be chosen as const reference.
  - The following parameter type should not be defined in any case: 
    - Member operator+(Member& mem1, Member& mem2);
	
/----------------------------------------------
/----------------------------------------------

**Example** : The operator "+=" changes the first value of oeprator function:
  - First argument is changed after applying += operator (non-const)
  - Second argument is not changed after applying += operator (const)

```cpp
class Member {};
Member& operator+=(Member& mem1, const Member& mem2);

int main() {

	Member mem1, mem2;
	mem1 += mem2; // calling --> operator+=(mem1, mem2);
				  // mem1 will be changed after calling operator+= func.
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

**Example** : Overloading operator functions with different parameter types

```cpp
class Member {
public:
	Member& operator!();
};

// Both are applicable, ambiquity error !!
Member operator+(const Member& mem1, const Member& mem2);
Member operator+(Member mem1, Member mem2);

int main() {

	Member mem1, mem2;
	mem1 + mem2;  // calling --> operator+(mem1, mem2);
	!mem1;        // calling --> operator!(mem1);
	
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Operator overloading in global space and in class space

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Member {
public:
	// unary operator overloading in class space
	// bool operator!() const;
	// binary operator overloading in class space
	// bool operator<(Member) const;
};

// unary operator overloading in global space
bool operator!(Member mem1);

// binary operator overloading in global space
bool operator<(Member mem1, Member mem2);

int main() {

	Member mem1, mem2;	
	
  // calling for "operator!(Member)" func.
	bool val1 = !mem1; 
	
	// calling "operator<(Member, Member)" func.
	bool val2 = mem1 < mem2; 

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The operators which are both unary and binary 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class SmartPtr {
public:
	// it should be an unary operator
	// therefore, it is dereferencing operator
	// int& operator*(); 
};

// dereferencing operator overloading in global space 
int& operator*(SmartPtr);

class Matrix {
public:
	// it should be an unary operator
	// therefore, it is product operator
	// Matrix operator*(const Matrix&);
};

// product operator overloading in global space 
Matrix operator*(const Matrix&, const Matrix&);

int main() {

	SmartPtr smrtPtr;
	Matrix mtrx1, mtrx2;

	// calls dereferencing operator overloading func.
	auto val1 = *smrtPtr; 

	// calls product operator overloading func.
	auto val2 = mtrx1 * mtrx2;

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

**Example** : Operator overloading for sum operation 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Complex {
public:
	Complex(int r = 0, int i = 0) { real = r; imag = i; }

	// This function is called when '+' is used with 
	// between two Complex objects 
	Complex& operator + (Complex const& obj) {
		Complex res;
		res.real = real + obj.real;
		res.imag = imag + obj.imag;
		return res;
	}
	void print() { std::cout << real << " + i" << imag << "\n"; }
private:
	int real, imag;
};


int main() {

  Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2; // An example call to "operator+" 
	c3.print();

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Operator overloading in "string" class 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int main() {

	std::string str1{ "ahmet" };
	std::string str2{ "mehmet" };
	std::string str3{ "gamze" };
	std::cout << str3[2] << " ";
	
	// calls member operator overloading functions
	std::cout << str3.operator[](1) << "\n";
	str1.operator+=(str2);
	str1.operator=(str2);

	// calls global operator< overloading func.
	if (operator<(str1, str2))	{
		//...
	}

	// calls global operator+ overloading func.
	auto str4 = operator+(str1, str2);

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Operator overloading in "iostream" class 

```cpp
#include <iostream>

int main() {

	int ival = 10;
	std::cout.operator<<(ival);
	// operator(std::cout, ival); --> NOT OK 

	if (std::cin.operator bool()) {
		//...
	}
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : In the case that overloading functions are in class space as member functions

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Member {
public:
	Member operator*(Member) const;
	Member operator+(Member) const;
	bool operator<(Member) const;

};

int main() {

	Member mem1, mem2, mem3, mem4;

	// operator precedence and asociativity is important to have an expected result
	auto val1 = mem1 * mem2 + mem3 < mem4;

	// The same definitions as above
	auto val2 = ((mem1 * mem2) + mem3) < mem4;
	auto val3 = mem1.operator*(mem2).operator+(mem3).operator<(mem4);
	
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : In the case that the above overloading functions are in global space

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Member {
public:
};

Member operator*(Member, Member);
Member operator+(Member, Member);
bool operator<(Member, Member);

int main() {

	Member mem1, mem2, mem3, mem4;

	// operator precedence and associativity is important to have an expected result
	auto val1 = mem1 * mem2 + mem3 < mem4;

	// The same definitions as above
	auto val2 = ((mem1 * mem2) + mem3) < mem4;
	auto val3 = operator<(operator+(operator*(mem1,mem2), mem3), mem4);

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The result of having different types of parameters for operator<< functions.
  - member overloading operator<< function --> it has void* parameter, so if any string literals are sent as argument to this operator function, then this function returns the argument's address, instead of its value. 
  - global overloading operator<< function --> it has char* [] parameter, so if any string literals are sent as argument to this operator function, then this function returns the argument's value. 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {

	int ival = 10;
	double dval = 10.5;

	std::cout << ival << " " << dval;
	std::cout << "\n\n";

	//The following does not return the same output
	std::cout.operator<<(ival).operator<<(" ").operator<<(dval);
	std::cout << "\n\n";

	//The following returns the same output
	//by calling global operator<< func. for string literal --> " "
	operator<<(std::cout.operator<<(ival), " ").operator<<(dval);

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Operator overloading with function overloading

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Ostream {
public:
	Ostream& operator<<(int);
	Ostream& operator<<(double);
};

std::ostream& operator<<(std::ostream& os, const std::string& str);

int main() {

	Ostream ostr;
	ostr.operator<<(10);
	ostr.operator<<(10.5);

	std::string str;
	operator<<(std::cout, str);

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Operator overloading with global operator function

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Date {};

std::ostream& operator<<(std::ostream&, Date date);

int main() {

	Date myDate;
	std::cout << myDate;		       // OK
	operator<<(std::cout, myDate); // OK

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Operator overloading when there is only operator member function

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Counter {
public:
	Counter operator+(int) const;
};
	
int main() {

	Counter cnt;
	auto acnt = cnt + 5;          // OK 
	auto acnt = cnt.operator+(5); // OK
	auto acnt = 5 + cnt;          // NOT OK 

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Calling operator functions with parameters in a different order ( and using function overloading in global space)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Counter {
public:
	//...
};

Counter operator+(Counter, int);
Counter operator+(int, Counter);

int main() {

	Counter cnt;
	auto acnt = cnt + 5; // OK 
	auto acnt = 5 + cnt; // OK 

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Operator overloading for "operator<" as a member function

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Member {
public:
	bool operator<(const Member& other) const {
		std::cout << "Member::operator<(const Member&)\n";
		std::cout << "this : " << this << "\n";
		std::cout << "&other : " << &other << "\n";
		return true;
	}
};

int main() {

	Member mem1, mem2;
	
	std::cout << "&mem1 : " << &mem1 << "\n";
	std::cout << "&mem2 : " << &mem2 << "\n";
	
	bool bval = mem1 < mem2; // --> mem1.operator<(mem2);
	// mem1 is an object
	// mem2 is an argument to call operator< func. here!!

	std::cout << "bool value : " << bval << "\n";

	return EXIT_SUCCESS;

	/*
	 	& mem1 : 00000000001FFAE4
		& mem2 : 00000000001FFB04
		Member::operator<(const Member&)
		this : 00000000001FFAE4
		& other : 00000000001FFB04
		bool value : 
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Operator overloading for "operator<" as global function

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Member {
public:
	//...
};

bool operator<(const Member& mem1, const Member& mem2) {
	std::cout << "Global operator< func. is called...\n";
	std::cout << "&mem1 : " << &mem1 << "\n";
	std::cout << "&mem2 : " << &mem2 << "\n";
	return true;
}

int main() {

	Member mem1, mem2;
	
	std::cout << "&mem1 : " << &mem1 << "\n";
	std::cout << "&mem2 : " << &mem2 << "\n";
	
	bool b = mem1 < mem2; // --> operator<(mem1, mem2);
	// both mem1 and mem2 are arguments to call operator< func. here!!

	return EXIT_SUCCESS;

	/*
	 	Executed again!!!
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : What should be the return value of operator functions? 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class SmartPtr {
public:
	int& operator*()const;
};

class Array {
public:
	int& operator[](int index)const;
};

class Data {};

// The argument is not changed after applying ! operator
bool operator!(const Data& data);

int main() {

	SmartPtr ptr;
	*ptr = 10;    // *ptr L-Value expr.

	Array arr;
	arr[5] = 10;  // arr[5] L-Value expr.

	Data data;
	!data;        // calling --> operator!(data);

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Operator overlading as member functions and global functions by taking care of constant correctness

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	/*Class member functions*/
	Data operator*(const Data& data) const;
	bool operator!()const; 
	Data& operator+=(const Data& data); //*this will be changed, so this func is not const
};

/* Global functions*/
// Data operator*(const Data& data1, const Data& data2);
// bool operator!(const Data& data);
// Data& operator+=(Data& data1, const Data& data2);

int main() {

	Data data1, data2; 
	Data data3 = data1* data2; // --> data1.operator*(data2);
	
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Inserter / extractor functions 
  - inserter func.  --> for output stream (std::cout)
  - extractor func. --> for input stream (std::cin)
  
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

int main() {

	int ival = 10;
	std::cout << ival; 
	// class member func. --> std::cout.operator<<(ival);
	
	std::cin >> ival;
	// class member func --> std::cin.operator>>(ival);

	/*------------------------------------------------------*/

	std::string name = "Gamze";
	std::cout << name;
	// global func. for string class --> operator<<(std::cout, name);

	std::cin >> name;
	// global func. for string class --> operator>>(std::cin, name);
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Counter class example 
  - If incomplete type is enough for the current file, then all header file which includes its complete type version should not be added to the file.  
  - "iosfwd" standard library includes the forward declaration of input/output stream classes. 
  - inserter operator functions shall be declared as global operator functions (operator<<)

```cpp
#ifndef COUNTER_INCLUDED
#define COUNTER_INCLUDED
#include <iostream>
#include <iosfwd>

class Counter {
public:
	Counter() = default; // default member init. 
	explicit Counter(int);

	// operator<< function can access the private members  
	friend std::ostream& operator<<(std::ostream& os, const Counter& cnt) {
		// inline operator function definition can de done here
	}
private:
};

//std::ostream&  operator<<(std::ostream& os, const Counter& cnt); 

int main() {

	Counter cnt1;
	Counter cnt2{100};
	std::cout << cnt1 << " " << cnt2 << " ";
	operator<<(std::cout, cnt1);

	return EXIT_SUCCESS;
}

#endif
```
 
/----------------------------------------------
/----------------------------------------------

- **Example** : Comparison Operator Function Example
  - Implementing a wrapper class which uses int type in the backend (defining different features thanks to operator overloading mechanism)
  - **operator<** and **operator==** are more important than the other operator functions. Because the other operator can be defined by using these two operator functions. 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<conio.h> 
#include "utility.h" 

// myint.h
// --------------------------------------------
class MyInt {
public:
	MyInt() = default;
	explicit MyInt(int val) : mval{ val } {}

	// operator< and operator== functions as inline functions 
	friend bool operator<(const MyInt& ref1, const MyInt& ref2) {
		return ref1.mval < ref2.mval;
	}
	friend bool operator==(const MyInt& ref1, const MyInt& ref2) {
		return ref1.mval == ref2.mval;
	}

	// inserter - extractor operator functions
	friend std::ostream& operator<<(std::ostream& os, const MyInt& ref);
	friend std::istream& operator>>(std::istream& is, MyInt& ref);

	static MyInt random();
private:
	int mval{};

};

// myint.cpp
// --------------------------------------------
inline bool operator>(const MyInt& ref1, const MyInt& ref2) {
	return ref2 < ref1;
}

inline bool operator>=(const MyInt& ref1, const MyInt& ref2) {
	return !(ref1 < ref2);
}

inline bool operator<=(const MyInt& ref1, const MyInt& ref2) {
	return !(ref2 < ref1);
}

inline bool operator!=(const MyInt& ref1, const MyInt& ref2) {
	return !(ref1 == ref2);
}

std::ostream& operator<<(std::ostream& os, const MyInt& ref) {
	return os << "[ " << ref.mval << " ]";
}

std::istream& operator>>(std::istream& is, MyInt& ref) {
	return is >> ref.mval;
}

MyInt MyInt::random() {
	// Irand is a user-defined class to generate random numbers between 0-1000
	return MyInt{ Irand{ 0, 1000 }() };
}


// test code for comparison operator functions 
// --------------------------------------------
int main() {

	MyInt mval1, mval2{ 20 };
	std::cout << mval1 << " " << mval2 << "\n";

	std::cout << "Enter two values: ";
	std::cin >> mval1 >> mval2;
	std::cout << mval1 << " " << mval2 << "\n";

	// operator<(mval1, mval2);
	if (mval1 < mval2)
		std::cout << "mval1 is smaller than mval2. " << "\n";
	// operator==(mval1, mval2);
	if (mval1 == mval2)
		std::cout << "mval1 is equal to mval2. " << "\n";

	std::cout << std::boolalpha;
	std::cout << mval1 << " <  " << mval2 << " = " << (mval1 < mval2) << "\n"; 
	std::cout << mval1 << " <= " << mval2 << " = " << (mval1 <= mval2) << "\n";
	std::cout << mval1 << " >  " << mval2 << " = " << (mval1 > mval2) << "\n";
	std::cout << mval1 << " >= " << mval2 << " = " << (mval1 >= mval2) << "\n";
	std::cout << mval1 << " == " << mval2 << " = " << (mval1 == mval2) << "\n";
	std::cout << mval1 << " != " << mval2 << " = " << (mval1 != mval2) << "\n";
	
	std::cout << std::boolalpha;

	for (;;) {

		auto mval1{ MyInt::random() };
		auto mval2{ MyInt::random() };

		std::cout << mval1 << " <  " << mval2 << " = " << (mval1 < mval2) << "\n";
		std::cout << mval1 << " <= " << mval2 << " = " << (mval1 <= mval2) << "\n";
		std::cout << mval1 << " >  " << mval2 << " = " << (mval1 > mval2) << "\n";
		std::cout << mval1 << " >= " << mval2 << " = " << (mval1 >= mval2) << "\n";
		std::cout << mval1 << " == " << mval2 << " = " << (mval1 == mval2) << "\n";
		std::cout << mval1 << " != " << mval2 << " = " << (mval1 != mval2) << "\n";
		_getch();
		system("cls");

		/*
			For Example:
			[ 538 ] <  [ 973 ] = true
			[ 538 ] <= [ 973 ] = true
			[ 538 ] >  [ 973 ] = false
			[ 538 ] >= [ 973 ] = false
			[ 538 ] == [ 973 ] = false
			[ 538 ] != [ 973 ] = true
		
		*/
	}

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Arithmetic Operator Functions Examples
  - Exception handling shall be applied for the followig operator functions (operator+=, operator-=, operator*=, operator/=) 
  - operator+ is written by using --> operator+=
  - operator- is written by using --> operator-=
  - operator* is written by using --> operator*=
  - operator/ is written by using --> operator/=

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<conio.h> 
#include "utility.h" 

// myint.h
// --------------------------------------------
class MyInt {
public:
	MyInt() = default;
	explicit MyInt(int val) : mval{ val } {}

	MyInt& operator+=(MyInt other) {
		this->mval += other.mval;
		return *this;
	}

	MyInt& operator-=(MyInt other) {
		this->mval -= other.mval;
		return *this;
	}

	MyInt& operator*=(MyInt other) {
		this->mval *= other.mval;
		return *this;
	}

	MyInt& operator/=(MyInt other) {
		this->mval /= other.mval;
		return *this;
	}

	// inserter - extractor operator functions
	friend std::ostream& operator<<(std::ostream& os, const MyInt& ref);
	friend std::istream& operator>>(std::istream& is, MyInt& ref);
	static MyInt random();
private:
	int mval{};

};

// myint.cpp
// --------------------------------------------
inline MyInt operator+(MyInt mval1, MyInt mval2) {
	return mval1 += mval2;
}

inline MyInt operator-(MyInt mval1, MyInt mval2) {
	return mval1 -= mval2;
}

inline MyInt operator*(MyInt mval1, MyInt mval2) {
	return mval1 *= mval2;
}

inline MyInt operator/(MyInt mval1, MyInt mval2) {
	return mval1 /= mval2;
}

std::ostream& operator<<(std::ostream& os, const MyInt& ref) {
	return os << "[ " << ref.mval << " ]";
}

std::istream& operator>>(std::istream& is, MyInt& ref) {
	return is >> ref.mval;
}

MyInt MyInt::random() {

	return MyInt{ Irand{ 0, 1000 }() };
}


// test code for arithmetic operator functions
// --------------------------------------------
int main() {

	std::cout << std::boolalpha;

	for (;;) {

		auto mval1{ MyInt::random() };
		auto mval2{ MyInt::random() };

		std::cout << mval1 << " +  " << mval2 << " = " << (mval1 + mval2) << "\n";
		std::cout << mval1 << " -  " << mval2 << " = " << (mval1 - mval2) << "\n";
		std::cout << mval1 << " *  " << mval2 << " = " << (mval1 * mval2) << "\n";
		std::cout << mval1 << " /  " << mval2 << " = " << (mval1 / mval2) << "\n";
		_getch();
		system("cls");

		/*
			For Example:
			[ 794 ] +  [ 485 ] = [ 1279 ]
			[ 794 ] -  [ 485 ] = [ 309 ]
			[ 794 ] *  [ 485 ] = [ 385090 ]
			[ 794 ] /  [ 485 ] = [ 1 ]
		
		*/
	}

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Prefix and postfix operator functions examples
  - If "value" is a L-Value expression --> "+value" is a R-Value expression
  - sign operators (+,-) do not have a side effect on typed values
  - prefix  --> ++x --> returns --> x + 1 (L-Value expr. in C++)
  - postfix --> x++ --> returns --> x (R-Value expr. in C++)
  - prefix and postfix oeprators are unary operators, so in order to differentiate the operator functions, then a parameter can be added as a dummy parameter to postfix operator function (for the reason of function overload resolution). This dummy parameter should not be named, it has only its type name. 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<conio.h> 
#include "utility.h" 

// myint.h
// --------------------------------------------
class MyInt {
public:
	MyInt() = default;
	explicit MyInt(int val) : mval{ val } {}
	int getVal()const { return mval; }
	void setVal(const int val) { this->mval = val; }

	// prefix operator++ --> ++val 
	MyInt& operator++() {
		++mval;
		return *this;
	}

	// prefix operator-- --> --val
	MyInt& operator--() {
		--mval;
		return *this;
	}

	// postfix operator++ --> val++
	MyInt operator++(int) {
		MyInt retval{ *this };
		++(*this);
		return retval;
	}

	// postfix operator-- --> val--
	MyInt operator--(int) {
		MyInt retval{ *this };
		--(*this);
		return retval;
	}

	// operator+ and operator- as class member funcs
	MyInt operator+() const {
		return *this;
	}

	MyInt operator-() const {
		return MyInt{ -mval };
	}
 
	MyInt& operator+=(MyInt other) {
		this->mval += other.mval;
		return *this;
	}

	MyInt& operator-=(MyInt other) {
		this->mval -= other.mval;
		return *this;
	}

	MyInt& operator*=(MyInt other) {
		this->mval *= other.mval;
		return *this;
	}

	MyInt& operator/=(MyInt other) {
		this->mval /= other.mval;
		return *this;
	}

	// inserter - extractor operator functions
	friend std::ostream& operator<<(std::ostream& os, const MyInt& ref);
	friend std::istream& operator>>(std::istream& is, MyInt& ref);
	static MyInt random();

private:
	int mval{};

};

// myint.cpp
// --------------------------------------------
std::ostream& operator<<(std::ostream& os, const MyInt& ref) {
	return os << "[ " << ref.mval << " ]";
}

std::istream& operator>>(std::istream& is, MyInt& ref) {
	return is >> ref.mval;
}

MyInt MyInt::random() {

	return MyInt{ Irand{ 0, 1000 }() };
}

// --------------------------------------------

// In global space, how to write prefix and postfix operator funcs.
// inline MyInt& operator++(MyInt);     // prefix ++
// inline MyInt operator++(MyInt, int); // postfix ++ 

// --------------------------------------------

// Test code for prefix/postfix operator functions
// --------------------------------------------
int main() {

	std::cout << std::boolalpha;

	for (;;) {

		auto mval1{ MyInt::random() };
		auto mval2{ MyInt::random() };
		
		std::cout << "mval1 : " << mval1 << "\n";
		std::cout << "++mval1 : " << ++mval1 << "\n";
		std::cout << "mval1++ : " << mval1++ << "\n\n";
		
		std::cout << "mval2 : " << mval2 << "\n";
		std::cout << "--mval2 : " << --mval2 << "\n";
		std::cout << "mval2-- : " << mval2-- << "\n";
		_getch();
		system("cls");
	}

	return EXIT_SUCCESS;

	/*
		mval1 : [ 169 ]
		++mval1 : [ 170 ]
		mval1++ : [ 170 ]

		mval2 : [ 478 ]
		--mval2 : [ 477 ]
		mval2-- : [ 477 ]
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- Operator overloading is different for the following special operators:
  - Index operator : []
  - Dereferencing operator : * 
  - Member selection (arrow) operator : ->
  - Function call operator : ()
  - Type conversion operator : <> 

/----------------------------------------------
/----------------------------------------------

- **Example** : Index operator [] overloading
  - <vector>, <deque>, <array>, <string> classes overloads index operator 

```cpp
#include <iostream>
#include <string>

int main() {

	std::string name{ "gamze" };
	auto c = name[0]; // OK, get the value of name[0]
	name[0] = 'k';    // OK, set the value of name[0]
	name.operator[](2) = 't'; 

	std::cout << "name : " << name << "\n"; // name : katze

	const std::string cname{ "mehmet" };
	auto cn = cname[0];   // OK, get the value of cname[0]
	//cname[0] = 'n';     // NOT OK, no possible to set the value of cname[0], return value const& (because of const overloading)

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : User defined array class example for operator overloading 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// myarray.h
// --------------------------------------------
class MyArray {
public:
	MyArray(size_t size, int val = 0);
	~MyArray();
	MyArray(const MyArray&) = delete;
	MyArray& operator=(const MyArray&) = delete;
	size_t size()const { return msize; }
	int& operator[](size_t index);
	const int& operator[](size_t index)const;
	friend std::ostream& operator<<(std::ostream &os, const MyArray& arr);
private:
	int* mptr;
	size_t msize;
};

// myarray.cpp
// --------------------------------------------
MyArray::MyArray(size_t size, int val) :msize{ size }, mptr{ new int[msize] }{
	for (size_t i = 0; i < msize; ++i)
		mptr[i] = val;
}

MyArray::~MyArray() {
	delete[]mptr;
}

int& MyArray::operator[](size_t index) {
	return mptr[index];
}

const int& MyArray::operator[](size_t index)const {
	std::cout << "const overloading of operator[] is called...\n";
	return mptr[index];
}

std::ostream& operator<<(std::ostream& os, const MyArray& arr) {
	
	os << "[ ";

	for (size_t i = 0; i < arr.msize - 1; ++i)
		os << arr.mptr[i] << ", ";

	os << arr.mptr[arr.msize - 1] << " ]";

	return os;
}


// Test code for user defined array class
// --------------------------------------------
int main() {

	MyArray arr(10, 5);
	std::cout << arr << "\n";

	for (size_t i = 0; i < arr.size(); ++i)
		arr[i] = i;
	std::cout << arr << "\n";

	auto val = arr[4]; // auto val = arr.operator[](4);
	arr[4] = 20;

	std::cout << "After setting array values...\n";
	std::cout << arr << "\n";

	// Defining const array 
	const MyArray carr{ 10, 10 };
	std::cout << carr << "\n";

	auto cval = carr[4];  // OK, thanks to const overloading
	//carr[4] = 20;       // NOT OK, thanks to const overloading  

	return EXIT_SUCCESS;

	/*
		[ 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 ]
		[ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 ]
		After setting array values...
		[ 0, 1, 2, 3, 20, 5, 6, 7, 8, 9 ]
		[ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 ]
		const overloading of operator[] is called...
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Containers and const operator function overloading 

```cpp
#include <iostream>
#include <vector>

int main() {

	std::vector<int> vec{ 0,2,4,6,8,10 };

	++vec.front(); // OK, vec.front() --> 0 
	--vec.back();  // OK, vec.back() --> 10
	std::cout << "vec.front() : " << vec.front() << "\n"; 
	// vec.front() : 1
	std::cout << "vec.back()  : " << vec.back() << "\n";  
	// vec.back()  : 9

	const std::vector<double> cvec{ 0.1, 2.1, 4.1, 6.1, 8.1, 10.1 };
	++cvec.front(); // NOT OK, cvec.front() --> 0.1 (const value) 
	--cvec.back();  // NOT OK, cvec.back() --> 10.1 (const value)

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Dereferencing operator* and member selection operator-> overloading
  - pointer like classes like as smart pointers overlaods these two operators
  - smart pointers are important to manage a dynamic objects in terms of deleting it after its life is finalized!!!
  - Exception: ptr->func(); --> ptr.operator->()->func(); --> therefore, arrow operator function is overloaded as class member function and assumed as unary operator (it can not be global operator function)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include "myint.h"

// myintptr.h --> like as smart pointer typed class, 
// movable, but not copyable
// --------------------------------------------
class MyIntPtr {
public:
	explicit MyIntPtr(MyInt* ptr) : myptr{ ptr } {}
	MyIntPtr(const MyIntPtr&) = delete;
	MyIntPtr& operator=(const MyIntPtr&) = delete;

	~MyIntPtr() { 
		if(myptr != nullptr)
			delete myptr; 
	}
	MyInt& operator*() {
		return *myptr;
	}

	MyInt* operator->() {
		return myptr;
	}
private:
	MyInt* myptr;
};


// Test code for dereferencing and member selection operator functions
// --------------------------------------------
int main() {

	MyIntPtr myptr{ new MyInt{ 12 } }; // explicit keyword effect
	std::cout << "*myptr : " << *myptr << "\n";
	std::cout << "myptr->getVal() : " << myptr->getVal() << "\n";
	
	myptr->setVal(10);
	std::cout << "myptr->getVal() : " << myptr->getVal() << "\n";

	return EXIT_SUCCESS;

	/*
		*myptr : [ 12 ]
		myptr->getVal() : 12
		myptr->getVal() : 10
	*/
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Class template definition for the user defined smart pointer class in the previous example with operator overloading
  - CTAD : Constructor Template Argument Deduction --> provides to deduce the type of template class

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include "myint.h"

// Template definition for user defined smart pointer class
// --------------------------------------------

template<typename T>
class SmartPtr {
public:
	explicit SmartPtr(T* ptr) : myptr{ ptr } {}
	SmartPtr(const SmartPtr&) = delete;
	SmartPtr& operator=(const SmartPtr&) = delete;
	
	~SmartPtr() {
		if (myptr != nullptr)
			delete myptr;
	}
	T& operator*() {
		return *myptr;
	}

	T* operator->() {
		return myptr;
	}
private:
	T* myptr;
};


// Test code for the user defined smart pointer class
// --------------------------------------------
int main() {

	SmartPtr<MyInt> myptr{ new MyInt{ 12 } }; 
	std::cout << "*myptr : " << *myptr << "\n";
	std::cout << "myptr->getVal() : " << myptr->getVal() << "\n";
	
	myptr->setVal(10);
	std::cout << "myptr->getVal() : " << myptr->getVal() << "\n";

	SmartPtr<std::string> myptr{ new std::string {"gamze"} }; 
	std::cout << "*myptr : " << *myptr << "\n";
	std::cout << "myptr->size() : " << myptr->size() << "\n";

	return EXIT_SUCCESS;

	/*
		*myptr : [ 12 ]
		myptr->getVal() : 12
		myptr->getVal() : 10

		*myptr : gamze
		myptr->size() : 5
	*/
}
```

/----------------------------------------------
/----------------------------------------------
