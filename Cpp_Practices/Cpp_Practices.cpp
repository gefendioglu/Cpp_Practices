#include <iostream>
#include <list>
#include <set>

bool checkNesting(std::string str) {
	int count = 0;
	for (int i = 0; i < str.length(); ++i) {
		char ch = str.at(i);
		if (ch == '(') {
			++count;
		}
		else if (ch == ')') {
			--count;
			if (count < 0)
				return false;
		}
	}
	return count == 0;
}

int main()
{
	std::string str_test1 = "(())";
	std::string str_test2 = "()()";
	std::string str_test3 = "(()()";
	std::string str_test4 = ")(";

	std::set<std::string> str_test{ str_test1 ,str_test2, str_test3, str_test4 };
	for (const auto& i : str_test) {
		if (checkNesting(str_test.))
			std::cout << "True";

	}
	
}

//
//#include <cmath>
//#include <cstdio>
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <array>
//
//int* reverse_array(int* ptr, int size) {
//
//    int rvr_array[size];
//    for (int i = size - 1; i >= 0; --i) {
//        rvr_array[i] = *ptr;
//        ptr--;
//    }
//    return rvr_array;
//}
//
//int main() {
//
//    int size;
//    std::cin >> size;
//    if (size <= 1000 && size >= 1) {
//        int arr[size];
//        std::cout << size << "\n";
//    }
//
//    int value;
//    for (int i = 0; i < arr.length(); ++i) {
//        std::cin >> value;
//        arr[i] = value;
//        if (arr[i] >= 1 && arr[i] <= 10000) {
//            std::cout << arr[i] << " ";
//        }
//    }
//
//    int* ptr = reverse_array(arr, arr.length());
//    for (int i = 0; i < arr.length(); ++i) {
//        std::cout << *p[i] << " ";
//    }
//
//    return 0;
//}


