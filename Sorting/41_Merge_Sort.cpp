#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// C++ program for Merge Sort

// Merges two subarrays of arr[].
// First subarray is  : arr[left..middle]
// Second subarray is : arr[middle+1..right]
void merge(int arr[], int left, int middle, int right)
{
	int n1 = middle - left + 1;
	int n2 = right - middle;

	// Create temp sub-arrays 
	int* left_arr = new int[n1] {};
	int* right_arr = new int[n2] {};

	// Copy original array to temp sub-arrays "left_arr" and "right_arr"
	for (int i = 0; i < n1; i++)
		left_arr[i] = arr[left + i];

	for (int j = 0; j < n2; j++)
		right_arr[j] = arr[middle + 1 + j];

	// Merge the temp sub-arrays back into arr[left..right]

	// Initial index of first sub-array
	int i = 0;

	// Initial index of second sub-array
	int j = 0;

	// Initial index of merged sub-array
	int k = left;

	while (i < n1 && j < n2) {
		if (left_arr[i] <= right_arr[j]) {
			arr[k] = left_arr[i];
			i++;
		}
		else {
			arr[k] = right_arr[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of "left_arr", if there are any
	while (i < n1) {
		arr[k] = left_arr[i];
		i++;
		k++;
	}

	// Copy the remaining elements of "right_arr", if there are any
	while (j < n2) {
		arr[k] = right_arr[j];
		j++;
		k++;
	}
}

/* "left" is for left index and "right" is right index of the sub-array of arr to be sorted */
void mergeSort(int arr[], int left, int right) {

	if (left >= right) {
		return; //returns recursively
	}

	int middle = (left + right - 1) / 2;
	mergeSort(arr, left, middle);      // left part of array  - left sub-array
	mergeSort(arr, middle + 1, right); // right part of array - right sub-array
	merge(arr, left, middle, right);   // merge two sub-arrays
}

// Function to print an array
void printArray(int* A, int size)
{
	for (int i = 0; i < size; i++)
		std::cout << A[i] << " ";
}

// Client Code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Given array is : \n";
	printArray(arr, arr_size);  // Given array is : 12 11 13 5 6 7 

	mergeSort(arr, 0, arr_size - 1);

	std::cout << "\nSorted array is : \n";
	printArray(arr, arr_size);  // Sorted array is : 5 6 7 11 12 13
	return 0;
}

