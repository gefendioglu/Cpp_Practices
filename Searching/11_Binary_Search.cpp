#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<vector> 


//int binarySearch(int[] array, int target){
//	return binarySearch(array, target, 0, array.length - 1);
//}
//
//int binarySearch(int[] array, int target, int lower, int upper) {
//	int center, range;
//	range = upper - lower;
//	if (range < 0) {
//		throw new BSException("Element not in array");
//	}
//	if (array[lower] > array[upper]) {
//		throw new BSException("Array not sorted");
//	}
//	center = (range / 2) + lower;
//	if (target == array[center]) {
//		return center;
//	}
//	else if (target < array[center]) {
//		return binarySearch(array, target, lower, center - 1);
//	}
//	else {
//		return binarySearch(array, target, center + 1, upper);
//	}
//}
//
////The method that follows is a more efficient, iterative analog of the recursive binary search :
//int iterBinarySearch(int[] array, int target) {
//	int lower = 0, upper = array.length - 1;
//	int center, range;
//	while (true) {
//		range = upper - lower;
//		if (range < 0) {
//			throw new BSException("Element not in array");
//		}
//		if (array[lower] > array[upper]) {
//			throw new BSException("Array not sorted");
//		}
//		center = (range / 2) + lower;
//		if (target == array[center]) {
//			return center;
//		}
//		else if (target < array[center]) {
//			upper = center - 1;
//		}
//		else {
//			lower = center + 1;
//		}
//	}
//}

// ---------------------------------------------------------
// ---------------------------------------------------------

// Iterative Implementation
int binarySearch_it(std::vector<int>* vec, int left, int right, int number) {
	while (left <= right) {
		int mid = (right - left / 2);

		if (vec->at(mid) == number)
			return mid;
		else if (vec->at(mid) < number)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

// Recursive Implementation
int binarySearch_rec(std::vector<int>* vec, int left, int right, int number)
{
	if (left <= right) {
		int mid = left + (right - left) / 2;

		// If the element is present at the middle itself 
		if (vec->at(mid) == number)
			return mid;

		// If element is smaller than mid, 
		// thenit can only be present in left sub-vector 
		if (vec->at(mid) > number)
			return binarySearch_rec(vec, left, mid - 1, number);

		// Else the element can only be present in right sub-vector 
		return binarySearch_rec(vec, mid + 1, right, number);
	}

	// We reach here when element is not present in vector 
	return -1;
}

int getIndex(std::vector<int>* vec, int K)
{
	//The iterator value belongs to K value
	auto it = find(vec->begin(), vec->end(), K);

	// If element was found
	if (it != vec->end())
	{
		int index = it - (vec->begin());
		return index;
	}
	else {
		return -1;
	}
}

int main() {
	int number, output;
	std::vector<int> ivec = { 1,2,3,4,5,6,7,8,9,10 };
	/*std::cout << "Enter 10 integers in ascending order : " << "\n";
	for (size_t i = 0; i < ivec.size(); ++i)
	{
		ivec.push_back(i);
	}*/
	std::cout << "Enter one number that you want to search in vector: " << "\n";
	std::cin >> number;
	int left = getIndex(&ivec, ivec.front());
	int right = getIndex(&ivec, ivec.back());
	output = binarySearch_rec(&ivec, left, right, number);

	if (output == -1)
		std::cout << "No Match Found" << "\n";
	else
		std::cout << "Match is found at this index position : " << output << "\n";

	return EXIT_SUCCESS;
}