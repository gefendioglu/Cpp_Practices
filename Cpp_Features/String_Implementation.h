#pragma once

#ifdef STRING_IMPLEMENTATION

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 

class Mystring {
public:
 	Mystring();
	Mystring(const char* val);
	~Mystring() { delete str; }

	// pop_back() function 
	void pop_bk();

	// push_back() function 
	void push_bk(char a);

	// To get the length 
	int get_length();

	// Function to copy the string of length len from position pos 
	void cpy(char s[], int len, int pos);

	// Swap strings function 
	void swp(Mystring& rhs);

	// Constructor with 1 arguments 
	Mystring(char* val);

	// Copy Constructor 
	Mystring(const Mystring& source);

	// Move Constructor 
	Mystring(Mystring&& source);

	// Overloading the assignment operator 
	Mystring& operator=(const Mystring& rhs);
	Mystring& operator=(const char* str);

	// Overloading the assignment operator 
	friend std::ostream& operator<<(std::ostream& os, const Mystring& obj);
	friend std::istream& operator>>(std::istream& is, Mystring& obj);
	friend Mystring& operator+(const Mystring& lhs, const Mystring& rhs);
	
private:
	char* str;
	int length;
};

// Constructor with no arguments 
Mystring::Mystring():str{ nullptr } {
	length = 0;
	str = new char[1];
	str[0] = '\0';
}

// Constructor with one argument 
Mystring::Mystring(const char* val) {

	if (val == nullptr) {
		length = 0;
		str = new char[1];
		str[0] = '\0';
	}
	else {
		length = strlen(val);
		str = new char[strlen(val) + 1];
		strcpy(str, val); // copying val --> str
	}
}

// Copy Constructor 
Mystring::Mystring(const Mystring& source) {
	str = new char[strlen(source.str) + 1];
	strcpy(str, source.str);
}

// Move Constructor 
Mystring::Mystring(Mystring&& source) {
	str = source.str;
	source.str = nullptr;
}

// Overloading the assignment operator 
Mystring& Mystring::operator=(const Mystring& rhs){
	
	if (this == &rhs)
		return *this;
	delete[] str;
	str = new char[strlen(rhs.str) + 1];
	strcpy(str, rhs.str);
	return *this;
}

//Mystring& Mystring::operator=(const char* str) {
//	delete[] str;
//	length= strlen(str);
//	str = new char[length + 1];
//
//}


// Overloading the plus operator 
//Mystring operator+(const Mystring& lhs,	const Mystring& rhs){
//	
//	int length = static_cast<int>(strlen(lhs.str)) + static_cast<int>(strlen(rhs.str));
//
//	char* buff = new char[length + 1];
//
//	// Copy the strings to buff[] 
//	strcpy(buff, lhs.str);
//	strcat(buff, rhs.str);
//
//	Mystring temp{ buff };
//	delete[] buff;
//
//	// Return the concatenated string 
//	return temp;
//}

Mystring& Mystring::operator+(const Mystring& st)
{
	char* temp = new char[len + st.len + 1];
	strcpy(temp, str);
	for (int i = 0; i <= st.len; i++)
	{
		*(temp + len + i) = *(st.str + i);
	}
	len = len + st.len;
	delete[] str;
	str = new char[len + 1];
	strcpy(str, temp);
	delete[] temp;
	return *this;

}

Mystring operator+(const char* s, String& st)
{
	String temp(s);
	return temp + st;
}

// Overloading the stream extraction operator 
std::istream& operator>>(std::istream& is, Mystring& obj){

	char* buff = new char[1000];
	is >> buff;
	obj = Mystring{ buff };
	delete[] buff;
	return is;
}

// Overloading the stream  insertion operator 
std::ostream& operator<<(std::ostream& os, const Mystring& obj){
	os << obj.str;
	return os;
}

// Function for swapping string 
void Mystring::swp(Mystring& rhs){
	Mystring temp{ rhs };
	rhs = *this;
	*this = temp;
}

// Function to copy the string 
void Mystring::cpy(char s[], int len,int pos){
	
	for (int i = 0; i < len; i++) {
		s[i] = str[pos + i];
	}
	s[len] = '\0';
}

// Function to implement push_bk 
void Mystring::push_bk(char a){
	
	// Find length of string 
	int length = static_cast<int>(strlen(str));
	char* buff = new char[length + 2];

	// Copy character from str to buff[] 
	for (int i = 0; i < length; i++) {
		buff[i] = str[i];
	}
	buff[length] = a;
	buff[length + 1] = '\0';

	// Assign the new string with char a to string str 
	*this = Mystring{ buff };
	delete[] buff;
}

// Function to implement pop_bk 
void Mystring::pop_bk(){

	int length = static_cast<int>(strlen(str));
	char* buff = new char[length];

	// Copy character from str to buff[] 
	for (int i = 0; i < length - 1; i++)
		buff[i] = str[i];
	buff[length] = '\0';

	// Assign the new string with char a to string str 
	*this = Mystring{ buff };
	delete[] buff;
}

// Function to implement get_length 
int Mystring::get_length(){
	return static_cast<int>(strlen(str));
}



int main()
{
	// Constructor with no arguments 
	Mystring a;

	// Convert string literal to char array 
	char temp[] = "Hello";

	// Constructor with one argument 
	Mystring b{ temp };

	// Copy constructor 
	Mystring c{ a };

	char temp1[] = "World";

	// One arg constructor called, then the move constructor 
	Mystring d{ Mystring{ temp } };

	// Remove last character from Mystring b 
	b.pop_bk();

	// Print string b 
	std::cout << "Mystring b: "	<< b << "\n";

	// Append last character from Mystring b 
	b.push_bk('o');

	// Print string b 
	std::cout << "Mystring b: "	<< b << "\n";

	// Print length of string b 
	std::cout << "Length of Mystring b: " << b << "\n";

	char arr[80];

	// Copy string b chars from length 0 to 3 
	b.cpy(arr, 3, 0);

	// Print string arr 
	std::cout << "arr is: " << arr << "\n";

	// Swap d and b 
	d.swp(b);

	// Print d and b 
	std::cout << d << " " << b << "\n";

	// Concatenate b and b with overloading '+' operator 
	d = b + b;

	// Print string d 
	std::cout << "string d: " << d << "\n";

	return 0;
}

#endif // STRING_IMPLEMENTATION
