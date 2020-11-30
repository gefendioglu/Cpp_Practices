#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<array> 

// Recursive Function Solution
int factorial_rec(int n) {
	if (n > 1) { /* Recursive case */
		return factorial_rec(n - 1) * n;
	}
	else { // Base case ( 0! = 1! = 1 )
		return 1;
	}
}

// Iterative Function Solution
int factorial_ite(int n) {
	int i, val = 1;
	for (i = n; i > 1; i--) /* n = 0 or 1 falls through */ {
		val *= i;
	}
	return val;
}

/*
If you need a factorial function that returns all its intermediate results (factorials less than n), as well as the final result(n!), you would most naturally return these results as an integer array, which means the function needs to allocate an array.
*/

int doAllFactorials(int n, int* results, int level) {
	
	if (n > 1) { /* Recursive case */
		results[level] = n * doAllFactorials(n - 1, results, level + 1);
		return results[level];
	}
	else { /* Base case */
		results[level] = 1;
		return 1;
	}
}

int* allFactorials(int n) { /* Wrapper function */
	int* results;
	if (n == 0)
		results = new int[1]{};
	else
		results = new int[n]{};

	doAllFactorials(n, results, 0);

	return results;
}

//int main(void) {
//
//	std::cout << factorial_ite(3)<< std::endl;
//	std::cout << factorial_rec(0)<< std::endl;
//
//	int* res = allFactorials(3);
//	for (int i = 0; i < 3 ; ++i)
//		std::cout << res[i] << std::endl;
//
//	return 0;
//}

