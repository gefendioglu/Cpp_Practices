#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


int main(){
	bool flag = false;
	++flag; // not an error in C++14, but error in C++17
} 
