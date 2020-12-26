#pragma once

#ifdef INSERTION_SORT_1

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

/* Function to sort an array using insertion sort*/
void insertionSort(int* arr, const int &length)
{
	for (int i = 1; i < length; ++i)
	{
		int key = arr[i];
		int j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size length 
void printArray(int* arr, const int &length)
{
	for (int i = 0; i < length; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

/* Client Code */
int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int length = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, length);
	printArray(arr, length); // 5 6 11 12 13

	return 0;
}

#endif // INSERTION_SORT_1


#ifdef BINARY_INSERTION_SORT

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
/*
	Time Complexity : The algorithm as a whole still has a running worst case running time of O(n^2) 
	because of the series of swaps required for each insertion.
*/

// A binary search based function to find the position 
// where item should be inserted in a[low..high]
int binarySearch(int* a, int item, int low, int high)
{
	if (high <= low)
		return (item > a[low]) ? (low + 1) : low;

	int mid = (low + high) / 2;

	if (item == a[mid])
		return mid + 1;

	if (item > a[mid])
		return binarySearch(a, item, mid + 1, high);

	return binarySearch(a, item, low, mid - 1);
}

// Function to sort an array a[] of size "length"
void insertionSort(int* a, int length)
{
	int loc, j, selected;

	for (int i = 1; i < length; ++i)
	{
		j = i - 1;
		selected = a[i];

		// find location where selected sould be inseretd
		loc = binarySearch(a, selected, 0, j);

		// Move all elements after location to create space
		while (j >= loc)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = selected;
	}
}

int main()
{
	int arr[] = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	int length = sizeof(arr) / sizeof(arr[0]);

	insertionSort(arr, length);

	printf("Sorted array: ");
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << " "; 

	// Sorted array: 0 12 17 23 31 37 46 54 72 88 100 
	return 0;
}

#endif // BINARY_INSERTION_SORT


// --------------------------------------------
// --------------------------------------------
