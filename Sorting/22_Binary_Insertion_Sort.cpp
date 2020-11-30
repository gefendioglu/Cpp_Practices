// C program for implementation of 
// binary insertion sort
#include <stdio.h>

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

// Client Code
int main()
{
	int a[] = { 37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54 };
	int length = sizeof(a) / sizeof(a[0]), i;

	insertionSort(a, length);

	printf("Sorted array: \n");
	for (i = 0; i < length; i++)
		printf("%d ", a[i]); 

	// Sorted array: 0 12 17 23 31 37 46 54 72 88 100 
	return 0;
}

/*
	Time Complexity : The algorithm as a whole still has a running worst case running time of O(n^2) because of the series of swaps required for each insertion.
*/
