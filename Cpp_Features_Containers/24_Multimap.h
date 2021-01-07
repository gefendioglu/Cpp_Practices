#pragma once

#ifdef MULTIMAP

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map> 
#include <iterator> 

int main(){

	std::multimap <int, int> gquiz1; // empty multimap container 

	// insert elements in random order 
	gquiz1.insert(pair <int, int>(1, 40));
	gquiz1.insert(pair <int, int>(2, 30));
	gquiz1.insert(pair <int, int>(3, 60));
	gquiz1.insert(pair <int, int>(6, 50));
	gquiz1.insert(pair <int, int>(6, 10));

	// printing multimap gquiz1 
	std::multimap <int, int> ::iterator itr;
	std::cout << "\nThe multimap gquiz1 is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
		std::cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	std::cout << endl;

	//adding elements randomly, 
	// to check the sorted keys property 
	gquiz1.insert(pair <int, int>(4, 50));
	gquiz1.insert(pair <int, int>(5, 10));

	// printing multimap gquiz1 again 

	std::cout << "\nThe multimap gquiz1 after adding extra elements is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
		std::cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	std::cout << endl;

	// assigning the elements from gquiz1 to gquiz2 
	std::multimap <int, int> gquiz2(gquiz1.begin(),
		gquiz1.end());

	// print all elements of the multimap gquiz2 
	std::cout << "\nThe multimap gquiz2 after assign from gquiz1 is : \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		std::cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	std::cout << endl;

	// remove all elements up to 
	// element with value 30 in gquiz2 
	std::cout << "\ngquiz2 after removal of elements less than key=3 : \n";
	std::cout << "\tKEY\tELEMENT\n";
	gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		std::cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	// remove all elements with key = 4 
	int num;
	num = gquiz2.erase(4);
	std::cout << "\ngquiz2.erase(4) : ";
	std::cout << num << " removed \n";
	std::cout << "\tKEY\tELEMENT\n";
	for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
		std::cout << '\t' << itr->first
			<< '\t' << itr->second << '\n';
	}

	std::cout << std::endl;

	//lower bound and upper bound for multimap gquiz1 key = 5 
	std::cout << "gquiz1.lower_bound(5) : " << "\tKEY = ";
	std::cout << gquiz1.lower_bound(5)->first << '\t';
	std::cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second << std::endl;
	std::cout << "gquiz1.upper_bound(5) : " << "\tKEY = ";
	std::cout << gquiz1.upper_bound(5)->first << '\t';
	std::cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second << std::endl;

	return 0;

	/*
		The multimap gquiz1 is :
		KEY     ELEMENT
		1       40
		2       30
		3       60
		6       50
		6       10


		The multimap gquiz1 after adding extra elements is :
		KEY     ELEMENT
		1       40
		2       30
		3       60
		4       50
		5       10
		6       50
		6       10


		The multimap gquiz2 after assign from gquiz1 is :
		KEY     ELEMENT
		1       40
		2       30
		3       60
		4       50
		5       10
		6       50
		6       10


		gquiz2 after removal of elements less than key = 3 :
		KEY     ELEMENT
		3       60
		4       50
		5       10
		6       50
		6       10

		gquiz2.erase(4) : 1 removed
		KEY     ELEMENT
		3       60
		5       10
		6       50
		6       10

		gquiz1.lower_bound(5) : KEY = 5         ELEMENT = 10
		gquiz1.upper_bound(5) : KEY = 6         ELEMENT = 50
	
	*/


	
}

#endif // MULTIMAP
