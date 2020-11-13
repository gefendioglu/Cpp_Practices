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


