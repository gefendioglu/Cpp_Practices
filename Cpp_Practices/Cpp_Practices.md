## C++ PRACTICES

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - Write a program that prints the numbers from 1 to 100. 
  - If a number is divisible by 3, print “Fizz” instead of the number, 
  - If a number is divisible by 5, print “Buzz” instead of the number, 
  - If a number is divisible by both 3 and 5, print “FizzBuzz” instead of the number.
```cpp
#include <iostream>

int main()
{
    for (int i = 1; i <= 100; ++i) {
        bool divByThree = (i % 3 == 0);
        bool divByFive = (i % 5 == 0);
        if (divByThree && divByFive) {
            std::cout << "FizzBuzz" << "\n";
        }
        else if (divByThree) {
            std::cout << "Fizz" << "\n";
        }
        else if (divByFive) {
            std::cout << "Buzz" << "\n";
        }
        else {
            std::cout << i << "\n";
        }
    }
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Write a function that reverses a string without using any library functions.
```cpp
#include <iostream>
#include <string>

std::string reverse(std::string& str) {
	std::string out = "";
	for (size_t i = str.length() - 1; i >= 0; --i)
		out += str.at(i);
	return out;
}

int main()
{
	std::string str = "Gamze Efendioglu";
	reverse(str);
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Given an unsorted list of integers, write a function that returns a new list with all duplicate values removed.
```cpp
#include <iostream>
#include <list>

std::list<int> removeDuplicates(const std::list<int>& in) {
	std::list<int> out;
	for (auto ival : in) {
		bool found = false;
		for (auto oval : out) {
			if (ival == oval) {
				found = true;
				break;
			}
		}
		if (!found) 
			out.push_back(ival);
	}
	return out;
}

int main()
{
	std::list<int> ilist{ 1, 5, 6, 8, 9, 4, 5, 6, 7, 9, 1, 2, 5 };
	std::cout << "old list : "; 
	for (auto i : ilist)
		std::cout << i << " ";

	std::cout << "\n\n";

	std::list<int> new_list = removeDuplicates(ilist);
	std::cout << "new list : ";
	for (auto i : new_list)
		std::cout << i << " "; // not the same sequence 

	std::cout << "\n\n";
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - The same problem can be solved by converting the list to a set, which doesn’t allow duplicated values. 
  - Sets don’t preserve the original ordering of their data (as the problem statement doesn’t require that ordering be preserved).
```cpp
#include <iostream>
#include <list>
#include <unordered_set>

std::list<int> removeDuplicates(const std::list<int>& in) {
	std::unordered_set<int> s(in.begin(), in.end());
	std::list<int> out(s.begin(), s.end());
	return out;
}

int main()
{
	std::list<int> ilist{ 1, 5, 6, 8, 9, 4, 5, 6, 7, 9, 1, 2, 5 };
	std::cout << "old list : "; 
	for (auto i : ilist)
		std::cout << i << " ";

	std::cout << "\n\n";

	std::list<int> new_list = removeDuplicates(ilist);
	std::cout << "new list : ";
	for (auto i : new_list)
		std::cout << i << " "; // not the same sequence 

	std::cout << "\n\n";
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 
  - You are given a string that contains left and right parenthesis characters.
  - Write code to determine whether the parentheses are correctly nested. 
  - For example, the strings "(())" and "()()" are correctly nested but "(()()" and ")(" are not.

- **Solution** :
  - There will be an equal number of left and right parentheses (counting problem)
  - Using a single variable that tracks the relative number of left and right parentheses.
  - Increment a counter when you see a left parenthesis, and decrement it when you see a right parenthesis.
  - If at the end the counter is nonzero, you know you don’t have a properly nested string.
  - For the final case ")(" the final counter value would be zero, so you would erroneously conclude that the nesting was correct.
  - It’s not sufficient for there to be merely the same number of right and left parentheses; every right parenthesis has to come after a left parenthesis that it’s paired with.
  - Put in terms of the counter that you’re using, it’s not sufficient for it to end at zero; it also has to never be negative.
  - The counter can only become negative after it’s decremented, so you can just check immediately following the decrement.



