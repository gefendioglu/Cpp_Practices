#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 


// Selection Sort
// --------------------------------------------
// --------------------------------------------

//// C++ program for implementation of selection sort 
//void swap(int* xp, int* yp)
//{
//	int temp = *xp; //Dereferencing the pointer
//	*xp = *yp;
//	*yp = temp;
//}
//
//void selectionSort(int* arr, int length)
//{
//	// One by one move boundary of unsorted subarray 
//	for (int i = 0; i < length - 1; ++i)
//	{
//		// Find the minimum element in unsorted array 
//		int min_idx = i;
//		for (int j = i + 1; j < length; ++j)
//			if (arr[j] < arr[min_idx])
//				min_idx = j;
//
//		// Swap the found minimum element with the first element 
//		swap(&arr[min_idx], &arr[i]);
//	}
//}
//
///* Function to print an array */
//void printArray(int* arr, int length)
//{
//	for (int i = 0; i < length; ++i)
//		std::cout << arr[i] << " ";
//	std::cout << "\n";
//}
//
//int main()
//{
//	int arr[] = { 64, 25, 12, 22, 11 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//
//	selectionSort(arr, length);
//	std::cout << "Sorted array: " << "\n";
//	printArray(arr, length); // 11 12 22 25 64
//  
//  return 0;
//
//}



 