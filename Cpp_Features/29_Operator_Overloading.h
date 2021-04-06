

// Operator Overloading 
// --------------------------------------------
// --------------------------------------------

#ifdef OPERATOR_OVERLOADING

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
	void print() {
		std::cout << real << " + i" << imag << "\n";
	}
private:
	int real, imag;
};


int main() {

	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2; // An example call to "operator+" 
	c3.print();

	return EXIT_SUCCESS;
}

#endif OPERATOR_OVERLOADING

// Operator overloading for comparison and arithmetic operators
// --------------------------------------------
// --------------------------------------------

#ifdef OPERATOR_OVERLOADING_II

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

	// Exception handling shall be applied for the followig operator functions (operator+=, operator-=, operator*=, operator/=)  
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


// test code 
// --------------------------------------------
int main() {

	std::cout << std::boolalpha;

	for (;;) {

		auto mval1{ MyInt::random() };
		auto mval2{ MyInt::random() };

		// test code for comparison operator functions 
		std::cout << mval1 << " <  " << mval2 << " = " << (mval1 < mval2) << "\n";
		std::cout << mval1 << " <= " << mval2 << " = " << (mval1 <= mval2) << "\n";
		std::cout << mval1 << " >  " << mval2 << " = " << (mval1 > mval2) << "\n";
		std::cout << mval1 << " >= " << mval2 << " = " << (mval1 >= mval2) << "\n";
		std::cout << mval1 << " == " << mval2 << " = " << (mval1 == mval2) << "\n";
		std::cout << mval1 << " != " << mval2 << " = " << (mval1 != mval2) << "\n";

		// test code for arithmetic operator functions
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

#endif OPERATOR_OVERLOADING_II


// Operator overloading for arithmetic operators (in class) and prefix/postfix operators 
// --------------------------------------------
// --------------------------------------------

#ifdef OPERATOR_OVERLOADING_III

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<conio.h> 
#include "utility.h" 

// myint.h --> like as int typed class
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

// template definition for user defined smart pointer class
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

// In global space, how to write prefix and postfix operator funcs.
//inline MyInt& operator++(MyInt); // prefix ++
//inline MyInt operator++(MyInt, int); // postfix ++ 


// Test code for prefix/postfix operator functions
// --------------------------------------------
int main() {

	std::cout << std::boolalpha;

	//for (;;) {

	//	auto mval1{ MyInt::random() };
	//	auto mval2{ MyInt::random() };
	//	
	//	std::cout << "mval1 : " << mval1 << "\n";
	//	std::cout << "++mval1 : " << ++mval1 << "\n";
	//	std::cout << "mval1++ : " << mval1++ << "\n\n";
	//	
	//	std::cout << "mval2 : " << mval2 << "\n";
	//	std::cout << "--mval2 : " << --mval2 << "\n";
	//	std::cout << "mval2-- : " << mval2-- << "\n";
	//	//_getch();
	//	//system("cls");
	//}

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

	/*
		mval1 : [ 169 ]
		++mval1 : [ 170 ]
		mval1++ : [ 170 ]

		mval2 : [ 478 ]
		--mval2 : [ 477 ]
		mval2-- : [ 477 ]
	*/
}

#endif OPERATOR_OVERLOADING_III



// Operator overloading for user defined array class & const overloading   
// --------------------------------------------
// --------------------------------------------

#ifdef OPERATOR_OVERLOADING_IV

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

	MyArray arr{ 10, 5 };
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

	auto cval = carr[4]; // OK, thanks to const overloading
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

#endif OPERATOR_OVERLOADING_IV