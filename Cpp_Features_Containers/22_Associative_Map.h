#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iterator> 
#include <map> 


// std::map
// --------------------------------------------
// --------------------------------------------

//using namespace std;
//
//int main()
//{
//
//	// empty map container 
//	map<int, int> gquiz1;
//
//	// insert elements in random order 
//	gquiz1.insert(pair<int, int>(1, 40));
//	gquiz1.insert(pair<int, int>(2, 30));
//	gquiz1.insert(pair<int, int>(3, 60));
//	gquiz1.insert(pair<int, int>(4, 20));
//	gquiz1.insert(pair<int, int>(5, 50));
//	gquiz1.insert(pair<int, int>(6, 50));
//	gquiz1.insert(pair<int, int>(7, 10));
//
//	// printing map gquiz1 
//	// map<int, int>::iterator itr;
//
//	cout << "\nThe map gquiz1 is : \n";
//	cout << "\tKEY\tELEMENT\n";
//	for (auto itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
//		cout << '\t' << itr->first
//			<< '\t' << itr->second << '\n';
//	}
//	cout << endl;
//
//	// assigning the elements from gquiz1 to gquiz2 
//	map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
//
//	// print all elements of the map gquiz2 
//	cout << "\nThe map gquiz2 after"
//		<< " assign from gquiz1 is : \n";
//	cout << "\tKEY\tELEMENT\n";
//	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
//		cout << '\t' << itr->first
//			<< '\t' << itr->second << '\n';
//	}
//	cout << endl;
//
//	// remove all elements up to element with key=3 in gquiz2 
//	cout << "\ngquiz2 after removal of elements less than key=3 : \n";
//	cout << "\tKEY\tELEMENT\n";
//	gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
//	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
//		cout << '\t' << itr->first
//			<< '\t' << itr->second << '\n';
//	}
//
//	// remove all elements with key = 4 
//	int num;
//	num = gquiz2.erase(4);
//	cout << "\ngquiz2.erase(4) : ";
//	cout << num << " removed \n";
//	cout << "\tKEY\tELEMENT\n";
//	for (auto itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
//		cout << '\t' << itr->first
//			<< '\t' << itr->second << '\n';
//	}
//
//	cout << endl;
//
//	// lower bound and upper bound for map gquiz1 key = 5 
//	cout << "gquiz1.lower_bound(5) : "
//		<< "\tKEY = ";
//	cout << gquiz1.lower_bound(5)->first << '\t';
//	cout << "\tELEMENT = "
//		<< gquiz1.lower_bound(5)->second << endl;
//	cout << "gquiz1.upper_bound(5) : "
//		<< "\tKEY = ";
//	cout << gquiz1.upper_bound(5)->first << '\t';
//	cout << "\tELEMENT = "
//		<< gquiz1.upper_bound(5)->second << endl;
//
//	return 0;
//}



// std::map::find()
// --------------------------------------------
// --------------------------------------------

//using namespace std;
//
//int main()
//{
//	// declaring map of char and int 
//	map< char, int > mp;
//
//	// declaring iterators 
//	map<char, int>::iterator it;
//	map<char, int>::iterator it1;
//
//	// inserting values 
//	mp['a'] = 5;
//	mp['b'] = 10;
//	mp['c'] = 15;
//	mp['d'] = 20;
//	mp['e'] = 30;
//
//	// using find() to search for 'b' key found 
//	// "it" has address of key value pair. 
//	it = mp.find('b');
//
//	if (it == mp.end())
//		cout << "Key-value pair not present in map";
//	else
//		cout << "Key-value pair present : "
//		<< it->first << "->" << it->second;
//
//	cout << endl;
//
//	// using find() to search for 'm' key not found 
//	// "it1" has address of end of map. 
//	it1 = mp.find('m');
//
//	if (it1 == mp.end())
//		cout << "Key-value pair not present in map";
//	else
//		cout << "Key-value pair present : "
//		<< it1->first << "->" << it1->second;
//
//	return 0;
//
//	/*
//		Key - value pair present : b->10
//		Key - value pair not present in map
//	*/
//	
//
//}



// std::map::lower_bound()
// --------------------------------------------
// --------------------------------------------


//  std::map::upper_bound()
// --------------------------------------------
// --------------------------------------------


//  std::map::equal - range()
// --------------------------------------------
// --------------------------------------------

