#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

int factorial(int n) {
	if (n > 1) { /* Recursive case */
		return factorial(n - 1) * n;
	}
	else { // Base case ( 0! = 1! = 1 )
		return 1;
	}
}

int main()
{
	std::cout << factorial(5) << "\n";
	return 0;
}