#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 


// Bubble Sort Algorithm
// --------------------------------------------
// --------------------------------------------

///* Function to swap two int elements */
//void swap(int* xp, int* yp){
//	int temp = *xp;
//	*xp = *yp;
//	*yp = temp;
//}
//
///* A function to implement bubble sort */
//void bubbleSort(int* arr, int length){
//	int i, j;
//	for (i = 0; i < length - 1; i++)
//
//		// Last i elements are already in place 
//		for (j = 0; j < length - i - 1; j++)
//			if (arr[j] > arr[j + 1])
//				swap(&arr[j], &arr[j + 1]);
//}
//
///* Function to print an array */
//void printArray(int arr[], int length)
//{
//	for (int i = 0; i < length; i++)
//		std::cout << arr[i] << " ";
//	std::cout << "\n";
//}
//
//int main(){
//
//	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//	
//	bubbleSort(arr, length);
//	std::cout << "Sorted array: \n";
//	
//	printArray(arr, length);
//	return 0;
//}



// Optimized Implementation of Bubble Sort Algorithm
// --------------------------------------------
// --------------------------------------------
//
///* Function to swap two int elements */
//void swap(int* xp, int* yp) {
//	int temp = *xp;
//	*xp = *yp;
//	*yp = temp;
//}
//
///* An optimized version of Bubble Sort */
//void bubbleSort(int* arr, int length)
//{
//	for (int i = 0; i < length - 1; i++)
//	{
//		bool swapped = false;
//		for (int j = 0; j < length - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				swap(&arr[j], &arr[j + 1]);
//				swapped = true;
//			}
//		}
//		// IF no two elements were swapped by inner loop, then break 
//		if (swapped == false)
//			break;
//	}
//}
//
///* Function to print an array */
//void printArray(int arr[], int length)
//{
//	std::cout << "Sorted array: ";
//	for (int i = 0; i < length; i++)
//		std::cout << arr[i] << " ";
//	std::cout << "\n";
//}
//
//int main() {
//
//	int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//
//	bubbleSort(arr, length);
//	printArray(arr, length);
//	return 0;
//
//	// Sorted array: 11 12 22 25 34 64 90
//}




