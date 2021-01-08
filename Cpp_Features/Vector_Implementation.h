#pragma once

#ifdef VECTOR_CLASS_TEMPLATE

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

template <typename T>
class vectorClass {
public:
	vectorClass() {
		arr = new T[1];
		capacity = 1;
		currentElement = 0; 
	}

	void push(T data);
	void push(int data, int index);
	T get(int index);
	void pop();
	int size();
	int getcapacity();
	void print();

private:
	T* arr;
	int capacity;
	int currentElement;
};

// Adding an element at vector end 
template <typename T>
void vectorClass<T>::push(T data) {

	if (currentElement == capacity) {
		// Double the capacity
		T* temp = new T[2 * capacity];

		// Copying old array elements to new array
		for (int i = 0; i < capacity; ++i) {
			temp[i] = arr[i];
		}

		// Deleting previous array
		delete[] arr;
		capacity *= 2;
		arr = temp;
	}

	// Inserting data
	arr[currentElement] = data;
	currentElement++;
}

// Adding element at any index
// Function overloading for push function
template <typename T>
void vectorClass<T>::push(int data, int index) {

	// if index is equal to capacity, this
	// function is the same as push(T data)
	if (index == capacity)
		push(data);
	else
		arr[index] = data;
}

// Extracting an element at any index
template <typename T>
T vectorClass<T>::get(int index) {
	// if index is within the range
	if (index < currentElement)
		return arr[index];
	// if index is not within the range // TODO ?
	return index;
}

// Deleting the last element
template <typename T>
void vectorClass<T>::pop() {
	currentElement--;
}

// Get size of the vector
template <typename T>
int vectorClass<T>::size() {
	return currentElement;
}

// Get capacity of the vector
template <typename T>
int vectorClass<T>::getcapacity() {
	return capacity;
}

// Print array elements
template <typename T>
void vectorClass<T>::print() {
	for (int i = 0; i < currentElement; ++i) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

int main(){
	
	vectorClass<int> ivec;
	vectorClass<char> cvec;
	ivec.push(10);
	ivec.push(20);
	ivec.push(30);
	ivec.push(40);
	ivec.push(50);

	cvec.push(71);
	cvec.push(72);
	cvec.push(73);
	cvec.push(74);

	std::cout << "Vector size : " << ivec.size() << "\n";
	std::cout << "Vector capacity : " << ivec.getcapacity() << "\n";

	std::cout << "Vector elements : ";
	ivec.print();

	ivec.push(100, 1);

	std::cout << "\nAfter updating 1st index" << "\n";

	std::cout << "Vector elements of type int : ";
	ivec.print();
	std::cout << "Vector elements of type char : ";
	cvec.print();
	std::cout << "Element at 1st index of type int: " << ivec.get(1)
		<< "\n";
	std::cout << "Element at 1st index of type char: "
		<< cvec.get(1) << "\n";

	ivec.pop();
	cvec.pop();


	std::cout << "\nAfter deleting last element" << "\n";;

	std::cout << "Vector size of type int: " << ivec.size() << "\n";
	std::cout << "Vector size of type char: " << cvec.size()
		<< "\n";
	std::cout << "Vector capacity of type int : "
		<< ivec.getcapacity() << "\n";
	std::cout << "Vector capacity of type char : "
		<< cvec.getcapacity() << "\n";

	std::cout << "Vector elements of type int: ";
	ivec.print();
	std::cout << "Vector elements of type char: ";
	cvec.print();

	return 0;

	/*
	Vector size : 5
	Vector capacity : 8
	Vector elements : 10 20 30 40 50

	After updating 1st index
	Vector elements of type int : 10 100 30 40 50
	Vector elements of type char : G H I J
	Element at 1st index of type int: 100
	Element at 1st index of type char: H

	After deleting last element
	Vector size of type int: 4
	Vector size of type char: 3
	Vector capacity of type int : 8
	Vector capacity of type char : 4
	Vector elements of type int: 10 100 30 40
	Vector elements of type char: G H I
	
	*/
}

#endif // VECTOR_CLASS_TEMPLATE
