#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// C++ program for insertion sort 
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


