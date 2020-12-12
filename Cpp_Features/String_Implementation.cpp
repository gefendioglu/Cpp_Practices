//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring> 
//
//using namespace std;
//
//// Class Mystring 
//class Mystring {
//
//	// Prototype for stream insertion 
//	friend ostream&	operator<<(	ostream& os, const Mystring& obj);
//
//	// Prototype for stream extraction 
//	friend istream& operator>>(	istream& is, Mystring& obj);
//
//	// Prototype for '+' operator overloading 
//	friend Mystring operator+(const Mystring& lhs,const Mystring& rhs);
//	char* str;
//
//public:
//	// No arguments constructor 
//	Mystring();
//
//	// pop_back() function 
//	void pop_bk();
//
//	// push_back() function 
//	void push_bk(char a);
//
//	// To get the length 
//	int get_length();
//
//	// Function to copy the string of length len from position pos 
//	void cpy(char s[], int len, int pos);
//
//	// Swap strings function 
//	void swp(Mystring& rhs);
//
//	// Constructor with 1 arguments 
//	Mystring(char* val);
//
//	// Copy Constructor 
//	Mystring(const Mystring& source);
//
//	// Move Constructor 
//	Mystring(Mystring&& source);
//
//	// Overloading the assignment operator 
//	Mystring& operator=(const Mystring& rhs);
//
//	// Destructor 
//	~Mystring() { delete str; }
//};
//
//// Overloading the assignment operator 
//Mystring& Mystring::operator=(const Mystring& rhs){
//	
//	if (this == &rhs)
//		return *this;
//	delete[] str;
//	str = new char[strlen(rhs.str) + 1];
//	strcpy(str, rhs.str);
//	return *this;
//}
//
//// Overloading the plus operator 
//Mystring operator+(const Mystring& lhs,	const Mystring& rhs){
//	
//	int length = strlen(lhs.str)
//		+ strlen(rhs.str);
//
//	char* buff = new char[length + 1];
//
//	// Copy the strings to buff[] 
//	strcpy(buff, lhs.str);
//	strcat(buff, rhs.str);
//
//	// String temp 
//	Mystring temp{ buff };
//
//	// delete the buff[] 
//	delete[] buff;
//
//	// Return the concatenated string 
//	return temp;
//}
//
//// Overloading the stream  extraction operator 
//istream& operator>>(istream& is,Mystring& obj){
//
//	char* buff = new char[1000];
//	is >> buff;
//	obj = Mystring{ buff };
//	delete[] buff;
//	return is;
//}
//
//// Overloading the stream  insertion operator 
//ostream& operator<<(ostream& os,const Mystring& obj){
//	os << obj.str;
//	return os;
//}
//
//// Function for swapping string 
//void Mystring::swp(Mystring& rhs){
//	Mystring temp{ rhs };
//	rhs = *this;
//	*this = temp;
//}
//
//// Function to copy the string 
//void Mystring::cpy(char s[], int len,int pos){
//	
//	for (int i = 0; i < len; i++) {
//		s[i] = str[pos + i];
//	}
//	s[len] = '\0';
//}
//
//// Function to implement push_bk 
//void Mystring::push_bk(char a){
//	
//	// Find length of string 
//	int length = strlen(str);
//
//	char* buff = new char[length + 2];
//
//	// Copy character from str to buff[] 
//	for (int i = 0; i < length; i++) {
//		buff[i] = str[i];
//	}
//	buff[length] = a;
//	buff[length + 1] = '\0';
//
//	// Assign the new string with char a to string str 
//	*this = Mystring{ buff };
//
//	// Delete the temp buff[] 
//	delete[] buff;
//}
//
//// Function to implement pop_bk 
//void Mystring::pop_bk(){
//
//	int length = strlen(str);
//	char* buff = new char[length];
//
//	// Copy character from str to buff[] 
//	for (int i = 0; i < length - 1; i++)
//		buff[i] = str[i];
//	buff[length] = '\0';
//
//	// Assign the new string with char a to string str 
//	*this = Mystring{ buff };
//
//	// delete the buff[] 
//	delete[] buff;
//}
//
//// Function to implement get_length 
//int Mystring::get_length(){
//	return strlen(str);
//}
//
//// Function to illustrate Constructor with no arguments 
//Mystring::Mystring(): str{ nullptr }{
//	str = new char[1];
//	str[0] = '\0';
//}
//
//// Function to illustrate Constructor with one arguments 
//Mystring::Mystring(char* val){
//
//	if (val == nullptr) {
//		str = new char[1];
//		str[0] = '\0';
//	}
//	else {
//
//		str = new char[strlen(val) + 1];
//
//		// Copy character of val[] using strcpy 
//		strcpy(str, val);
//	}
//}
//
//// Function to illustrate Copy Constructor 
//Mystring::Mystring(const Mystring& source){
//
//	str = new char[strlen(source.str) + 1];
//	strcpy(str, source.str);
//}
//
//// Function to illustrate  Move Constructor 
//Mystring::Mystring(Mystring&& source){
//
//	str = source.str;
//	source.str = nullptr;
//}
//
//int main()
//{
//	// Constructor with no arguments 
//	Mystring a;
//
//	// Convert string literal to char array 
//	char temp[] = "Hello";
//
//	// Constructor with one argument 
//	Mystring b{ temp };
//
//	// Copy constructor 
//	Mystring c{ a };
//
//	char temp1[] = "World";
//
//	// One arg constructor called, then the move constructor 
//	Mystring d{ Mystring{ temp } };
//
//	// Remove last character from Mystring b 
//	b.pop_bk();
//
//	// Print string b 
//	cout << "Mystring b: "
//		<< b << endl;
//
//	// Append last character from Mystring b 
//	b.push_bk('o');
//
//	// Print string b 
//	cout << "Mystring b: "
//		<< b << endl;
//
//	// Print length of string b 
//	cout << "Length of Mystring b: "
//		<< b << endl;
//
//	char arr[80];
//
//	// Copy string b chars from length 0 to 3 
//	b.cpy(arr, 3, 0);
//
//	// Print string arr 
//	cout << "arr is: "
//		<< arr << endl;
//
//	// Swap d and b 
//	d.swp(b);
//
//	// Print d and b 
//	cout << d << " "
//		<< b << endl;
//
//	// Concatenate b and b with overloading '+' operator 
//	d = b + b;
//
//	// Print string d 
//	cout << "string d: "
//		<< d << endl;
//
//	return 0;
//}
