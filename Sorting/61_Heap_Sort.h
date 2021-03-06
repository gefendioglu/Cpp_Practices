#pragma once

// Heap Sort Algorithm
// --------------------------------------------
// --------------------------------------------

#ifdef HEAP_SORT

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// To heapify a subtree rooted with node i which is an index in arr[]. 
// n : the size of heap

/* Function to swap two int elements */
void swap(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void heapify(int* arr, int length, int i)
{
	int largest = i;   // Initialize largest as root
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2

	// If left child is larger than root
	if (l < length && arr[l] > arr[largest])
		largest = l;

	// If right child is larger than largest so far
	if (r < length && arr[r] > arr[largest])
		largest = r;

	// If largest is not root
	if (largest != i) {
		std::swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree
		heapify(arr, length, largest);
	}
}

// Recursive heap sort function
void heapSort(int* arr, int length)
{
	// Build heap (rearrange array)
	for (int i = length / 2 - 1; i >= 0; i--)
		heapify(arr, length, i);

	// One by one extract an element from heap
	for (int i = length - 1; i > 0; i--) {
		// Move current root to end
		std::swap(arr[0], arr[i]);

		// call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

/* A utility function to print array of size n */
void printArray(int* arr, int n)
{
	for (int i = 0; i < n; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int length = sizeof(arr) / sizeof(arr[0]);

	heapSort(arr, length);

	std::cout << "Sorted array is : ";
	printArray(arr, length); // Sorted array is :5 6 7 11 12 13

	return 0;
}

#endif // HEAP_SORT



