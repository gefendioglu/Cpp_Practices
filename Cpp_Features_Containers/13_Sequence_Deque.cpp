#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque> 


// std::deque
// --------------------------------------------
// --------------------------------------------

using namespace std;

void showdq(deque<int> g){
	// deque<int>::iterator it;
	for (auto it = g.begin(); it != g.end(); ++it)
		cout << " " << *it;
	cout << '\n';
}

int main() {

	deque <int> gquiz;
	gquiz.push_back(10);
	gquiz.push_front(20);
	gquiz.push_back(30);
	gquiz.push_front(15);
	cout << "The deque gquiz is : ";
	showdq(gquiz);
	// 	The deque gquiz is : 15 20 10 30

	cout << "\ngquiz.size() : " << gquiz.size(); 
	// gquiz.size() : 4

	cout << "\ngquiz.max_size() : " << gquiz.max_size(); 
	// gquiz.max_size() : 1073741823

	cout << "\ngquiz.at(2) : " << gquiz.at(2); 
	// gquiz.at(2) : 10

	cout << "\ngquiz.front() : " << gquiz.front(); 
	// gquiz.front() : 15

	cout << "\ngquiz.back() : " << gquiz.back(); 
	// gquiz.back() : 30

	cout << "\ngquiz.pop_front() : "; 
	// gquiz.pop_front() : 20 10 30

	gquiz.pop_front();
	showdq(gquiz);
	cout << "\ngquiz.pop_back() : "; 
	// gquiz.pop_back() : 20 10

	gquiz.pop_back();
	showdq(gquiz);

	return 0;
}



// std::deque
// --------------------------------------------
// --------------------------------------------