//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream> 
//
///* C++ implementation of QuickSort */
//// A utility function to swap two elements 
//void swap(int* a, int* b)
//{
//	int temp = *a;
//	*a = *b;
//	*b = temp;
//}
//
///* 
//	This function takes last element as pivot, 
//	places the pivot element at its correct position in sorted array, and 
//	places all smaller (smaller than pivot) to left of pivot and 
//	places all greater elements to right of pivot 
//*/
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
//
///* Function to print an array */
//void printArray(int arr[], int length)
//{
//	for (int i = 0; i < length; ++i)
//		std::cout << arr[i] << " ";
//	std::cout << "\n";
//}
//
///* Client Code*/
////int main()
////{
////	int arr[] = { 10, 80, 30, 90, 40, 50, 70 };
////	int length = sizeof(arr) / sizeof(arr[0]);
////	
////	quickSort(arr, 0, length - 1); // low = 0, high = length - 1
////	std::cout << "Sorted array: \n";
////	
////	printArray(arr, length); // Sorted array: 10, 30, 40, 50, 70, 80, 90
////	return 0;
////}
//
