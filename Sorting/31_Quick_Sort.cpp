#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// QuickSort 
// --------------------------------------------
// --------------------------------------------

//// A utility function to swap two elements 
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//// This function takes last element as pivot
//// places the pivot element at its correct position in sorted array
//// places all smaller (smaller than pivot) to left of pivot
//// places all greater elements to right of pivot 
//int partition(int* arr, int low, int high)
//{
//	int pivot = arr[high]; // pivot value is the last element 
//	int i = (low - 1);     // Index of smaller element 
//
//	for (int j = low; j <= high - 1; ++j)
//	{
//		// If current element is smaller than the pivot 
//		if (arr[j] < pivot)
//		{
//			i++; // increment index of smaller element 
//			swap(&arr[i], &arr[j]);
//		}
//	}
//	swap(&arr[i + 1], &arr[high]);
//	return (i + 1);
//}
//
///* 
//	The main recursive function that implements QuickSort
//	arr[] --> Array to be sorted
//	low   --> Starting index
//	high  --> Ending index 
//*/
//void quickSort(int* arr, int low, int high)
//{
//	if (low < high)
//	{
//		/* pi is partitioning index, arr[p] is now at right place */
//		int pi = partition(arr, low, high);
//
//		/* When pi is at right place, it is necessary to sort before and after pivot place*/
//		quickSort(arr, low, pi - 1);  // sorting elements before partition
//		quickSort(arr, pi + 1, high); // sorting elements after partition
//	}
//}
//
///* Function to print an array */
//void printArray(int arr[], int length)
//{
//	for (int i = 0; i < length; ++i)
//		std::cout << arr[i] << " ";
//	std::cout << "\n";
//}
//
//
//int main()
//{
//	int arr[] = { 10, 80, 30, 90, 40, 50, 70 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	
//	quickSort(arr, 0, length - 1); 
//	// low = 0, high = length - 1
//
//	std::cout << "Sorted array: ";
//	printArray(arr, length); 
//	// Sorted array: 10, 30, 40, 50, 70, 80, 90
//	
//	return 0;
//}



// 3-way QuickSort 
// --------------------------------------------
// --------------------------------------------

//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
//// A utility function to print an array
//void printarr(int a[], int n)
//{
//	for (int i = 0; i < n; ++i)
//		printf("%d ", a[i]);
//	printf("\n");
//}
//
///* 
//	This function partitions a[] in three parts
//	a) a[l..i] contains all elements smaller than pivot
//	b) a[i+1..j-1] contains all occurrences of pivot
//	c) a[j..r] contains all elements greater than pivot 
//*/
//
//// It uses Dutch National Flag Algorithm
//void partition(int a[], int low, int high, int& i, int& j)
//{
//	// To handle 2 elements
//	if (high - low <= 1) {
//		if (a[high] < a[low])
//			swap(&a[high], &a[low]);
//		i = low;
//		j = high;
//		return;
//	}
//
//	int mid = low;
//	int pivot = a[high];
//	while (mid <= high) {
//		if (a[mid] < pivot)
//			swap(&a[low++], &a[mid++]);
//		else if (a[mid] == pivot)
//			mid++;
//		else if (a[mid] > pivot)
//			swap(&a[mid], &a[high--]);
//	}
//
//	// update i and j
//	i = low - 1;
//	j = mid; // or high+1
//}
//
//// 3-way partition based quick sort
//void quicksort(int a[], int low, int high)
//{
//	if (low >= high) // 1 or 0 elements
//		return;
//
//	int i, j;
//
//	// Note that i and j are passed as reference
//	partition(a, low, high, i, j);
//
//	// Recur two halves
//	quicksort(a, low, i);
//	quicksort(a, j, high);
//}

//int main()
//{
//	int a[] = { 4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4 };
//	int size = sizeof(a) / sizeof(int);
//	printarr(a, size);
//	
//	quicksort(a, 0, size - 1);
//	printarr(a, size);
//	return 0;
//}



// QuickSort on Singly Linked List
// --------------------------------------------
// --------------------------------------------



// QuickSort on Doubly Linked List
// --------------------------------------------
// --------------------------------------------



// Iterative QuickSort
// --------------------------------------------
// --------------------------------------------