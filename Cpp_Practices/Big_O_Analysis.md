## BIG O ANALYSIS : 

- The general procedure for Big-O runtime analysis is as follows:
  1. Figure out what the input is and what n represents.
  2. Express the number of operations the algorithm performs in terms of n.
  3. Eliminate all but the highest-order terms.
  4. Remove all constant factors

- Which Algorithm Is Better? (From the best to the worst) 
  - O(1) : The fastest running time (constant running time)
  - O(log n) : A logarithmic running time if it increases logarithmically in proportion to the input size.
  - O(n) : A linear algorithm’s running time increases in direct proportion to the input size.
  - O(n log n) : A quasilinear algorithm is midway between a linear algorithm and a polynomial algorithm.
  - O(nc) : A polynomial algorithm grows quickly based on the size of the input.
  - O(cn) : An exponential algorithm grows even faster than a polynomial algorithm.
  - O(n!) : A factorial algorithm grows the fastest and becomes quickly unusable for even small values of n.
  - Algorithms that run in constant-O(1), logarithmic-O(log n), linear-O(n) , or quasilinear-O(n log n) time are preferred !!!

/----------------------------------------------
/----------------------------------------------

- **Example**: Big O Analysis
  - Consider a simple function that returns the maximum value stored in an array of nonnegative integers. The size of the array is n.
  - What are the complexities of CompareToMax and CompareToAll functions?
  - In CompareToMax, each array element was compared once to a maximum value. Thus, the input items are each examined once, resulting in n examinations. --> O(n)
  - In CompareToMax, the best-case, average-case, and worst-case running times are identical. Regardless of the arrangement of the values in the array, the algorithm is always O(n).

  - In CompareToAll, this function may compare each of n elements to n other elements. Thus you have nxn examinations, so this is an O(n^2) algorithm.
  - The analysis of CompareToAll 
    - a worst-case scenario: the maximum value was at the end of the array ---> O(n^2)
    - an average case scenario: the largest value is in the middle
	    - checking n(n/2) = n^2/2 times --> O(n^2/2) running time
	    - the average case for CompareToAll is no better than the worst case ---> O(n^2)
     - a best-case scenario: the maximum value is at the beginning of the array
       - The maximum value is compared to all other values only once --> O(n) 
  - As the array grows, the number of comparisons in CompareToAll becomes much larger than in CompareToMax

  - There is a check in CompareToMax to ensure that the array is not empty and a step that initializes the curMax variable. It may seem more accurate to call this an O(n + 2) function to reflect these extra operations. As n approaches infinity, the difference between n and n + 2 is insignificant, so the constant term can be ignored.
  - Similarly, for an algorithm running in n + n^2 time, the difference between n^2 and n + n^2 is negligible for a very large n.
  - In Big-O analysis you eliminate all but the highest-order term.

```cpp
#include <iostream>
#include <array>

// Returns the largest value in an array of n non-negative integers 
int CompareToMax(int array[], int n) {
	int curMax, i;

	// Make sure that there is at least one element in the array.
	if (n <= 0)
		return -1;

	// Set the largest number so far to the first array value.
	curMax = array[0];

	// Compare every number with the largest number so far. 
	for (i = 1; i < n; i++) {
		if (array[i] > curMax) {
			curMax = array[i];
		}
	}
	return curMax;
}

int CompareToAll(int array[], int n) {

	int i, j;
	bool isMaxValue;

	// Make sure that there is at least one element in the array.
	if (n <= 0)
		return -1;

	for (i = 0; i < n; ++i)
	{
		isMaxValue = true;
		for (j = 0; j < n; ++j)
		{
			// See if any value is greater.
			if (array[j] > array[i]) {
				isMaxValue = false; // array[i] is not the largest value.
				break;
			}
		}
		// If isMaxValue is true, no larger value exists; array[i] is max.
		if (isMaxValue)
			break;
	}
	return array[i];
}

int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	std::cout << "max value : " << CompareToAll(arr, sizeof(arr) / sizeof(&arr[0])) << "\n";

	std::cout << "max value : " << CompareToMax(arr, sizeof(arr) / sizeof(&arr[0])) << "\n";
	// max value : 9
}
```cpp
/----------------------------------------------
/----------------------------------------------
