#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<set> 
using namespace std;


// Intersection of sorted arrays arr1[] and arr2[]
// --------------------------------------------------
// --------------------------------------------------

/* Function prints Intersection of arr1[] and arr2[]
	arr1_length is the number of elements in arr1[]
	arr2_length is the number of elements in arr2[] 
*/

//void printIntersection(int* arr1, int* arr2, int arr1_length, int arr2_length){
//
//	int i = 0, j = 0;
//
//	while (i < arr1_length && j < arr2_length) {
//		if (arr1[i] < arr2[j])
//			i++;
//		else if (arr2[j] < arr1[i])
//			j++;
//		else /* if arr1[i] == arr2[j] */
//		{
//			cout << arr2[j] << " "; // or cout << arr1[i] << " "; 
//			i++;
//			j++;
//		}
//	}
//}
//
//int main()
//{
//	int arr1[] = { 1, 2, 4, 5, 6 };
//	int arr2[] = { 2, 3, 5, 7 };
//
//	int arr1_length = sizeof(arr1) / sizeof(arr1[0]);
//	int arr2_length = sizeof(arr2) / sizeof(arr2[0]);
//	
//	printIntersection(arr1, arr2, arr1_length, arr2_length);
//	// 2 5
//	return 0;
//}


// Intersection of unsorted arrays arr1[] and arr2[]
// --------------------------------------------------
// --------------------------------------------------

//void printIntersection(int* arr1, int* arr2, int arr1_length,
//	int arr2_length)
//{
//	// Using Hash Set
//	set<int> hs;
//
//	// Insert the elements of arr1[] to set S
//	for (int i = 0; i < arr1_length; ++i)
//		hs.insert(arr1[i]);
//
//	for (int i = 0; i < arr2_length; ++i)
//		// If element is present in set then push it to vector V
//		if (hs.find(arr2[i]) != hs.end())
//			cout << arr2[i] << " ";
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
//	printIntersection(arr1, arr2, arr1_length, arr2_length);
//	// 3 6 7
//
//	return 0;
//}

// 
// --------------------------------------------------
// --------------------------------------------------
