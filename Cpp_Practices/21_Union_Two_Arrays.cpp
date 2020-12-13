#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<set> 
using namespace std;


// Finding union of two sorted arrays ( without Handling Duplicates) 
// --------------------------------------------------
// --------------------------------------------------

/* Function prints union of arr1[] and arr2[]
   arr1_length is the number of elements in arr1[]
   arr2_length is the number of elements in arr2[]
*/

//void printUnion(int* arr1, int* arr2, int arr1_length, int arr2_length){
//
//	int i = 0, j = 0;
//	while (i < arr1_length && j < arr2_length) {
//		if (arr1[i] < arr2[j]) {
//			cout << arr1[i] << " ";
//			i++;
//		}
//		else if (arr2[j] < arr1[i]) {
//			cout << arr2[j] << " ";
//			j++;
//		}
//
//		else {
//			// arr2[j] == arr1[i]
//			// or cout << arr1[i] << " ";
//			cout << arr2[j] << " "; 
//			i++;
//			j++;
//		}
//	}
//
//	/* Print remaining elements of the larger array */
//	while (i < arr1_length) {
//		cout << arr1[i] << " ";
//		i++;
//	}
//
//	while (j < arr2_length) {
//		cout << arr2[j] << " ";
//		j++;
//	}
//}
//
///* Driver program to test above function */
//int main()
//{
//	int arr1[] = { 1, 2, 4, 5, 6 };
//	int arr2[] = { 2, 3, 5, 7 };
//
//	int arr1_length = sizeof(arr1) / sizeof(arr1[0]);
//	int arr2_length = sizeof(arr2) / sizeof(arr2[0]);
//
//	printUnion(arr1, arr2, arr1_length, arr2_length);
//	// 1 2 3 4 5 6 7
//	return 0;
//}


// Finding union of two unsorted arrays arr1[] and arr2[]
// --------------------------------------------------
// --------------------------------------------------

// Prints union of arr1[0..arr1_length-1] and arr2[0..arr2_length-1]
//void printUnion(int* arr1, int* arr2, int arr1_length, int arr2_length){
//
//	set<int> hs;
//
//	// Insert the elements of arr1[] to set hs
//	for (int i = 0; i < arr1_length; i++)
//		hs.insert(arr1[i]);
//
//	// Insert the elements of arr2[] to set hs
//	for (int i = 0; i < arr2_length; i++)
//		hs.insert(arr2[i]);
//
//	// Print the content of set hs - it --> iterator
//	for (auto it = hs.begin(); it != hs.end(); it++)
//		cout << *it << " ";
//	cout << endl;
//}
//
//int main()
//{
//	int arr1[] = { 7, 1, 5, 2, 3, 6 };
//	int arr2[] = { 3, 8, 6, 20, 7 };
//
//	int arr1_length = sizeof(arr1) / sizeof(arr1[0]);
//	int arr2_length = sizeof(arr2) / sizeof(arr2[0]);
//
//	printUnion(arr1, arr2, arr1_length, arr2_length);
//	// 1 2 3 5 6 7 8 20
//	return 0;
//}



// TO BE CONTROLLED --> THE RESULT ÝS NOT CORRECT
// Finding union of two sorted arrays (Handling Duplicates) 
// --------------------------------------------------
// --------------------------------------------------


//void UnionArray(int* arr1, int* arr2, int arr1_length, int arr2_length) {
//
//	// Taking max element present in either array 
//	int m = arr1[arr1_length - 1];
//	int n = arr2[arr2_length - 1];
//
//	int ans = 0;
//
//	if (m > n)
//		ans = m;
//	else
//		ans = n;
//
//	// Finding elements from 1st array (non duplicates only). 
//	// Using another array for storing union elements.
//	// Assuming max element present in array is not more than 10^7 
//	int* newtable = new int[ans + 1];
//
//	// First element is always present in final answer 
//	std::cout << arr1[0] << " ";
//
//	// Incrementing the First element's count in it's corresponding index in newtable 
//	++newtable[arr1[0]];
//
//	// Starting traversing the first array from 1st index till last 
//	for (int i = 1; i < arr1_length; ++i) {
//		// Checking whether current element is not equal to it's previous element 
//		if (arr1[i] != arr1[i - 1]) {
//			std::cout << arr1[i] << " ";
//			++newtable[arr1[i]];
//		}
//	}
//
//	// Finding only non common elements from 2nd array 
//	for (int j = 0; j < arr2_length; j++) {
//		// By checking whether it's already present in newtable or not 
//		if (newtable[arr2[j]] == 0) {
//			std::cout << arr2[j] << " ";
//			++newtable[arr2[j]];
//		}
//	}
//}
//
//
///* Driver program to test above function */
//int main()
//{
//	int arr1[] = { 1, 2, 2, 2, 3 };
//	int arr2[] = { 2, 3, 4, 5 };
//
//	int arr1_length = sizeof(arr1) / sizeof(arr1[0]);
//	int arr2_length = sizeof(arr2) / sizeof(arr2[0]);
//
//	UnionArray(arr1, arr2, arr1_length, arr2_length);
//	// 1 2 3 (? NOT OK)
//
//	return 0;
//}