#include <iostream>

int command = 45;

int& refFunc() {
	return command;
}

int main() {

	refFunc() = 100; // refFunc() is a L-Value
	std::cout << "command: " << command << "\n"; // command = 100
}

	







