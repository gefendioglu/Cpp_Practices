#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>


void swap_int(int* xp, int* yp)
{
	int temp = *xp; //Dereferencing the pointer
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int* arr, int length)
{
	
	// One by one move boundary of unsorted subarray 
	for (int i = 0; i < length - 1; ++i)
	{
		// Find the minimum element in unsorted array 
		int min_idx = i;
		for (int j = i + 1; j < length; ++j)
			if (arr[j] < arr[min_idx])
				min_idx = j;

		// Swap the found minimum element with the first element 
		swap_int(&arr[min_idx], &arr[i]);
	}
}

class Stack {
public:
	Stack() {
		top = -1;
		for (int i = 0; i < length; i++)
			arr[i] = 0;
	}

	~Stack() {}

	void push(int value) {
		if (isFull()) {
			std::cout << "Stack is Full !!" << "\n";
		}
		else {
			top++;
			arr[top] = value;
		}

	}

	int pop() {

		if (isEmpty()) {
			std::cout << "Stack is Empty !!" << "\n";
			return 0;
		}
		else {
			int popValue = arr[top];
			arr[top] = 0;
			top--;
			return popValue;
		}

	}

	bool isEmpty() {

		if (top == -1)
			return true;
		else
			return false;
	}

	bool isFull() {
		if (top == length)
			return true;
		else
			return false;
	}

	int peek(int index) {
		if (isEmpty()) {
			std::cout << "Stack is Empty !!" << "\n";
			return 0;
		}
		else
		{
			return arr[index];
		}
	}

	int count() {
		return top + 1;
	}

	void change(int index, int value) {
		arr[index] = value;
		std::cout << "Value is changed for this index :" << "\n";

	}


	int minValue() {
		// Calling binary search function here!!
		selectionSort(arr, length);
		return arr[0];

	}

	void display() {
		std::cout << "All values in stack are: " << "\n";
		for (int i = length - 1; i >= 0; --i)
		{
			std::cout << arr[i] << "\n";
		}
	}

private:
	int top;
	int arr[5];
	int length = sizeof(arr) / sizeof(arr[0]);

};

//int main() {
//	Stack stack;
//	int option;
//	int n1;
//	int index;
//	do
//	{
//		std::cout << "\n What operation do you want to choose? : \n";
//		std::cout << "1. push()" << "\n";
//		std::cout << "2. pop()" << "\n";
//		std::cout << "3. isEmpty()" << "\n";
//		std::cout << "4. isFull()" << "\n";
//		std::cout << "5. peek()" << "\n";
//		std::cout << "6. count()" << "\n";
//		std::cout << "7. change()" << "\n";
//		std::cout << "8. minValue()" << "\n";
//		std::cout << "9. display()" << "\n";
//		std::cout << "10. Clear Screen" << "\n";
//
//		std::cin >> option;
//
//		switch (option)
//		{
//		case 0:
//			break;
//		case 1:
//			std::cout << "The value that you wanted to push : " << "\n";
//			std::cin >> n1;
//			if (stack.isFull())
//				std::cout << "Stack is OVERFLOW!!!" << "\n";
//			else
//				stack.push(n1);
//			break;
//		case 2:
//			std::cout << "The popped value : " << "\n";
//			stack.pop();
//			break;
//		case 3:
//			if (stack.isEmpty())
//				std::cout << "Stack is EMPTY!!!" << "\n";
//			else
//				std::cout << "Stack is NOT EMPTY!!!" << "\n";
//			break;
//		case 4:
//			if (stack.isFull())
//				std::cout << "Stack is FULL!!!" << "\n";
//			else
//				std::cout << "Stack is NOT FULL!!!" << "\n";
//			break;
//		case 5:
//			std::cout << "Which index that you want to take : " << "\n";
//			std::cin >> index;
//			stack.peek(index);
//			break;
//		case 6:
//			std::cout << "What is the count of stack : " << "\n";
//			stack.count();
//			break;
//		case 7:
//			std::cout << "Which index that you want to change : " << "\n";
//			std::cin >> index;
//			std::cout << "Which value that you want to push : " << "\n";
//			std::cin >> n1;
//			stack.change(index, n1);
//			break;
//		case 8:
//			std::cout << "What is the min value: " << stack.minValue() << "\n";
//			
//			break;
//		case 9:
//			stack.display();
//			break;
//		case 10:
//			system("cls");
//			break;
//		default:
//			std::cout << "Enter a proper option number" << "\n";
//		}
//	} while (option != 0);
//
//}

