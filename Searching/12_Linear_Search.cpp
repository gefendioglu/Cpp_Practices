#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<vector> 

void linearSearch(std::vector<int>* vec, int number) {
	int temp = -1;
	for (size_t i = 0; i < vec->size(); ++i)
	{
		if (vec->at(i) == number) {
			std::cout << "Element is found at location : " << i << "\n";
			temp = 0;
		}
	}
	if (temp == -1)
		std::cout << "No element is found !!!" << "\n";
}

//int main() {
//
//	int num;
//	std::vector<int> ivec = { 1,22,34,5,7 };
//	do
//	{
//		std::cout << "Please enter an element to search (Exit with -1) : " << "\n";
//		
//		std::cin >> num;
//
//		linearSearch(&ivec, num);
//
//	} while (num != -1);
//	
//
//	return EXIT_SUCCESS;
//}