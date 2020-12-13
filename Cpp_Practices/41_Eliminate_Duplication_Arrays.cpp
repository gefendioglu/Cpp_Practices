#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

using namespace std;

// Remove duplicates from sorted array (Using extra space)
// --------------------------------------------------
// --------------------------------------------------

// This function returns new size of modified array.
//int removeDuplicates(int* arr, int length)
//{
//	// Return, if array is empty or contains a single element 
//	if (length == 0 || length == 1)
//		return length;
//
//	int* temp = new int[length];
//
//	// Start traversing elements 
//	int j = 0;
//	for (int i = 0; i < length - 1; i++)
//		// If current element is not equal to next element then store that current element 
//		if (arr[i] != arr[i + 1]) {
//			temp[j] = arr[i];
//			j++;
//		}
//
//	// Store the last element as whether it is unique or repeated
//	// it hasn't stored previously 
//	temp[j] = arr[length - 1];
//	j++;
//	// Modify original array 
//	for (int i = 0; i < j; i++)
//		arr[i] = temp[i];
//
//	return j;
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 2, 3, 4, 4, 4, 5, 5 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//
//	// removeDuplicates() returns new size of array. 
//	length = removeDuplicates(arr, length);
//
//	// Print updated array 
//	for (int i = 0; i < length; i++)
//		cout << arr[i] << " ";  // 1 2 3 4 5
//
//	return 0;
//}


// Remove duplicates from sorted array (Constant extra space)
// --------------------------------------------------
// --------------------------------------------------

//int removeDuplicates(int* arr, int length){
//
//	if (length == 0 || length == 1)
//		return length;
//
//	// To store index of next unique element 
//	int j = 0;
//
//	// Doing same as done in Method 1
//	// Just maintaining another updated index i.e. j 
//	for (int i = 0; i < length - 1; i++)
//		if (arr[i] != arr[i + 1]) {
//			arr[j] = arr[i];
//			j++;
//		}
//
//	// Store the last element as whether it is unique or repeated
//	// it hasn't stored previously 
//	arr[j] = arr[length - 1];
//	j++;
//
//	return j;
//}
//
//int main()
//{
//	int arr[] = { 1, 2, 2, 3, 4, 4, 4, 5, 5 };
//	int length = sizeof(arr) / sizeof(arr[0]);
//
//	// removeDuplicates() returns new size of array. 
//	length = removeDuplicates(arr, length);
//
//	// Print updated array 
//	for (int i = 0; i < length; i++)
//		cout << arr[i] << " ";  // 1 2 3 4 5
//
//	return 0;
//}

// Matrix to Array Conversion 
// --------------------------------------------------
// --------------------------------------------------
//#define ROW 1
//#define COLUMN 4
//
//int main(){
//
//	int matrix[ROW][COLUMN] = { 1,2,3,4 };
//	int arr[ROW * COLUMN];
//
//	// output each matrix element's value 
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COLUMN; j++)
//		{
//			cout << "Element at x[" << i
//				<< "][" << j << "]: ";
//			cout << matrix[i][j] << endl;
//		}
//	}
//
//	// Turning a matrix to an array 
//	// n = rows by m = columns
//	// i goes from 0 to (n-1) and j from 0 to (m-1).
//	// matrix[ i ][ j ] = array[ i*m + j ].
//	// matrix[ i ][ j ][ k ] = array[ i*(N*M) + j*M + k ]
//	for (int row = 0; row < ROW; row++) {
//		for (int column = 0; column < COLUMN; column++)
//			arr[row * COLUMN + column] = matrix[row][column];
//	}
//
//	// printing array
//	int length = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < length; i++)
//		cout << "arr[" << i << "]:" << arr[i] << "\n";
//		
//	return 0;
//
//	/*
//		Element at x[0][0]: 1
//		Element at x[0][1] : 2
//		Element at x[0][2] : 3
//		Element at x[0][3] : 4
//		arr[0] : 1
//		arr[1] : 2
//		arr[2] : 3
//		arr[3] : 4
//	*/
//}