#pragma once

// Vector Iterators
// --------------------------------------------
// --------------------------------------------

#ifdef VECTOR_ITERATORS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector> 

int main(){

	std::vector<int> g1;

	for (int i = 1; i <= 5; i++)
		g1.push_back(i);

	std::cout << "Output of begin and end: ";
	for (auto i = g1.begin(); i != g1.end(); ++i)
		std::cout << *i << " ";
	// Output of begin and end: 1 2 3 4 5

	std::cout << "\nOutput of cbegin and cend: ";
	for (auto i = g1.cbegin(); i != g1.cend(); ++i)
		std::cout << *i << " ";
	// Output of cbegin and cend : 1 2 3 4 5

	std::cout << "\nOutput of rbegin and rend: ";
	for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
		std::cout << *ir << " ";
	// Output of rbegin and rend : 5 4 3 2 1

	std::cout << "\nOutput of crbegin and crend : ";
	for (auto ic = g1.crbegin(); ic != g1.crend(); ++ic)
		std::cout << *ic << " ";
	// Output of crbegin and crend : 5 4 3 2 1

	return 0;
}

#endif // VECTOR_ITERATORS

// Vector Capacity
// --------------------------------------------
// --------------------------------------------

#ifdef VECTOR_CAPACITY

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector> 

using namespace std;

int main()
{
	std::vector<int> g1;

	for (int i = 1; i <= 5; ++i)
		g1.push_back(i);

	std::cout << "Size : " << g1.size();           // Size: 5
	std::cout << "\nCapacity : " << g1.capacity(); // Capacity : 6
	std::cout << "\nMax_Size : " << g1.max_size(); // Max_Size : 1073741823

	// resizes the vector size to 4 
	g1.resize(4); // Size : 4

	// prints the vector size after resize() 
	std::cout << "\nSize : " << g1.size();

	// checks if the vector is empty or not 
	if (g1.empty() == false)
		std::cout << "\nVector is not empty"; // Vector is not empty
	else
		std::cout << "\nVector is empty";

	// Shrinks the vector 
	g1.shrink_to_fit();
	std::cout << "\nVector elements are: ";
	for (auto it = g1.begin(); it != g1.end(); it++)
		std::cout << *it << " "; // Vector elements are : 1 2 3 4

	return 0;
}

#endif // VECTOR_CAPACITY


// Vector Element Access
// --------------------------------------------
// --------------------------------------------

#ifdef VECTOR_ACCESS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector> 

int main()
{
	std::vector<int> g1;

	for (int i = 1; i <= 10; i++)
		g1.push_back(i * 10);

	std::cout << "\nReference operator [g] : g1[2] = " << g1[2];
	// Reference operator [g] : g1[2] = 30

	std::cout << "\nat : g1.at(4) = " << g1.at(4);
	// at : g1.at(4) = 50

	std::cout << "\nfront() : g1.front() = " << g1.front();
	// front() : g1.front() = 10

	std::cout << "\nback() : g1.back() = " << g1.back();
	// back() : g1.back() = 100

	/* pointer to the first element */
	int* pos = g1.data();
	std::cout << "\nThe first element is " << *pos;
	// The first element is 10
	
	return 0;
}

#endif // VECTOR_ACCESS

// Vector Modifiers
// --------------------------------------------
// --------------------------------------------

#ifdef VECTOR_MODIFIERS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector> 

int main()
{
	vector<int> v;

	// Assign vector - fill the array with 10 five times
	v.assign(5, 10);

	std::cout << "The vector elements are: ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	// The vector elements are : 10 10 10 10 10


	// inserts 15 to the last position 
	v.push_back(15);
	int n = v.size();
	std::cout << "\nThe last element is: " << v[n - 1];
	// The last element is : 15

	// removes last element 
	v.pop_back();
	std::cout << "\nThe vector elements are: ";
	for (size_t i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	// The vector elements are : 10 10 10 10 10
 
	// inserts 5 at the beginning 
	v.insert(v.begin(), 5);
	std::cout << "\nThe first element is: " << v[0];
	// The first element is : 5

	// removes the first element 
	v.erase(v.begin());
	std::cout << "\nThe first element is: " << v[0];
	// The first element is : 10

	// inserts at the beginning 
	v.emplace(v.begin(), 5);
	std::cout << "\nThe first element is: " << v[0];
	// The first element is : 5

	// Inserts 20 at the end 
	v.emplace_back(20);
	n = v.size();
	std::cout << "\nThe last element is: " << v[n - 1];
	// The last element is : 20

	// erases the vector 
	v.clear();
	std::cout << "\nVector size after erase(): " << v.size();
	// Vector size after erase() : 0

	// two vector to perform swap 
	vector<int> v1, v2;
	v1.push_back(1);
	v1.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	std::cout << "\n\nVector 1: ";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << v1[i] << " ";
	// Vector 1 : 1 2

	std::cout << "\nVector 2: ";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << " ";
	// Vector 2 : 3 4

	// Swaps v1 and v2 
	v1.swap(v2);

	std::cout << "\nAfter Swap \nVector 1: ";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << v1[i] << " ";
	// Vector 1 : 3 4

	std::cout << "\nVector 2: ";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << v2[i] << " ";
	// Vector 2 : 1 2

	return 0;
}

#endif // VECTOR_MODIFIERS

