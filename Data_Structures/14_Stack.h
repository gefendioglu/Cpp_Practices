#pragma once

// Implementing Stack using Arrays
// --------------------------------------------------
// --------------------------------------------------

#ifdef STACK

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// Pros: 
// Easy to implement.
// Memory is saved as pointer are not involved.
// --------------------------------------------------
// Cons : 
// It is not dynamic.
// It doesn�t grow and shrink depending on needs at runtime.
// --------------------------------------------------

#define MAX 5

// To find minimum value of stack, 
// swap and selection sort function is required 
//--------------------------------------------------
void swap_int(int* xp, int* yp){
	int temp = *xp; 
	*xp = *yp;
	*yp = temp;
}

//--------------------------------------------------
void selectionSort(int* arr, int length){
	
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

//--------------------------------------------------
class Stack {
public:
	Stack() {
		top = -1;
		for (int i = 0; i < length; i++)
			arr[i] = 0;
	}

	~Stack() {}

	bool isEmpty();
	bool isFull();
	void push(int value);
	int pop();
	int peek();
	int count();
	void change(int index, int value);
	int minValue();
	void display();

private:
	int top;
	int arr[MAX];
	int length = sizeof(arr) / sizeof(arr[0]);

};

//--------------------------------------------------
bool Stack::isEmpty() {
	if (top < 0) {
		std::cout << "Stack Underflow\n";
		return true;
	}
	else
		return false;
}

//--------------------------------------------------
bool Stack::isFull() {
	if (top >= length) {
		std::cout << "Stack Overflow\n";
		return true;
	}
	else
		return false;
}

//--------------------------------------------------
void Stack::push(int value) {
	if (isFull()) {
		std::cout << "Stack is Full !!" << "\n";
	}
	else {
		top++;
		arr[top] = value;
		std::cout << value << " pushed into stack\n";
	}
}

//--------------------------------------------------
int Stack::pop() {

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

//--------------------------------------------------
int Stack::peek() {
	if (isEmpty()) {
		std::cout << "Stack is Empty !!" << "\n";
		return 0;
	}
	else {
		return arr[top];
	}
}

// --------------------------------------------------
int Stack::count() {
	return top + 1;
	// return length;
}

// --------------------------------------------------
void Stack::change(int index, int value) {
	arr[index] = value;
	std::cout << "Value is changed for this index :" << index << " with this value : " << value << "\n";
}

// --------------------------------------------------
int Stack::minValue() {
	selectionSort(arr, length);
	return arr[0];
}

//--------------------------------------------------
void Stack::display() {
	std::cout << "\nAll values in stack are: " << "\n";
	for (int i = length - 1; i >= 0; --i)
		std::cout << arr[i] << "\n";
}

// Long Test Code
//--------------------------------------------------
int main() {
	Stack stack;
	int option;
	int n1;
	int index;
	do
	{
		std::cout << "\n What operation do you want to choose? : \n";
		std::cout << "1. push()" << "\n";
		std::cout << "2. pop()" << "\n";
		std::cout << "3. isEmpty()" << "\n";
		std::cout << "4. isFull()" << "\n";
		std::cout << "5. peek()" << "\n";
		std::cout << "6. count()" << "\n";
		std::cout << "7. change()" << "\n";
		std::cout << "8. minValue()" << "\n";
		std::cout << "9. display()" << "\n";
		std::cout << "10. Clear Screen" << "\n";

		std::cin >> option;

		switch (option)
		{
		case 0:
			break;
		case 1:
			std::cout << "The value that you wanted to push : " << "\n";
			std::cin >> n1;
			if (stack.isFull())
				std::cout << "Stack is OVERFLOW!!!" << "\n";
			else
				stack.push(n1);
			break;
		case 2:
			std::cout << "The popped value : " << "\n";
			stack.pop();
			break;
		case 3:
			if (stack.isEmpty())
				std::cout << "Stack is EMPTY!!!" << "\n";
			else
				std::cout << "Stack is NOT EMPTY!!!" << "\n";
			break;
		case 4:
			if (stack.isFull())
				std::cout << "Stack is FULL!!!" << "\n";
			else
				std::cout << "Stack is NOT FULL!!!" << "\n";
			break;
		case 5:
			std::cout << "Which index that you want to take : " << "\n";
			std::cin >> index;
			stack.peek(index);
			break;
		case 6:
			std::cout << "What is the count of stack : " << "\n";
			stack.count();
			break;
		case 7:
			std::cout << "Which index that you want to change : " << "\n";
			std::cin >> index;
			std::cout << "Which value that you want to push : " << "\n";
			std::cin >> n1;
			stack.change(index, n1);
			break;
		case 8:
			std::cout << "What is the min value: " << stack.minValue() << "\n";
			
			break;
		case 9:
			stack.display();
			break;
		case 10:
			system("cls");
			break;
		default:
			std::cout << "Enter a proper option number" << "\n";
		}
	} while (option != 0);

}

// Short Test Code
//--------------------------------------------------
//int main() {
//
//	Stack s;
//	s.push(10);
//	s.push(20);
//	s.push(30);
//	s.display();
//
//	std::cout << s.pop() << " Popped from stack\n";
//	s.display();
//
//	return 0;
//	/*
//		10 pushed into stack
//		20 pushed into stack
//		30 pushed into stack
//
//		All values in stack are :
//		0
//		0
//		30
//		20
//		10
//		30 Popped from stack
//
//		All values in stack are :
//		0
//		0
//		0
//		20
//		10
//	*/
//}

#endif


// Implementing Stack using Linked List
// --------------------------------------------------
// --------------------------------------------------

#ifdef STACK_LINKED_LIST

// Pros: 
// The stack can grow and shrink according to the needs at runtime.
// --------------------------------------------------
// Cons : Requires extra memory due to involvement of pointer
// --------------------------------------------------

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
//--------------------------------------------------
class Stack {
public:
	Stack* newNode(int data);
	int isEmpty(Stack* next); 
	void push(Stack** root, int data);
	int pop(Stack** next);
	int peek(Stack* next);
private:
	int data;
	Stack* next;
};

//--------------------------------------------------
Stack* Stack::newNode(int data){
	Stack* stack = new Stack();
	stack->data = data;
	stack->next = nullptr;
	return stack;
}

//--------------------------------------------------
int Stack::isEmpty(Stack* next){
	//return !next;
	return (next == nullptr);
}

//--------------------------------------------------
void Stack::push(Stack** root, int data){
	Stack* stack = newNode(data);
	stack->next = *root;
	*root = stack;
	std::cout << data << " pushed to stack\n";
}

//--------------------------------------------------
int Stack::pop(Stack** next){
	if (isEmpty(*next))
		return INT_MIN;
	Stack* temp = *next;
	*next = (*next)->next;
	int popped = temp->data;
	free(temp);

	return popped;
}

//--------------------------------------------------
int Stack::peek(Stack* next){
	if (isEmpty(next))
		return INT_MIN;
	return next->data;
}

// Test Code
//--------------------------------------------------
int main(){

	Stack* next = nullptr;

	next->push(&next, 10);
	next->push(&next, 20);
	next->push(&next, 30);

	std::cout << next->pop(&next) << " popped from stack\n";
	std::cout << "Top element is " << next->peek(next) << "\n";

	return 0;

	/*
		10 pushed to stack
		20 pushed to stack
		30 pushed to stack
		30 popped from stack
		Top element is 20
	*/
}

#endif // STACK_LINKED_LIST


// Stack Implementation using Arrays with Templates
// --------------------------------------------------
// --------------------------------------------------

#ifdef STACK_TEMPLATES_ARRAYS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAX 5

template<typename T>
class Stack_Temp {
public:
	Stack() {
		top = -1;
		for (T i = 0; i < length; i++)
			arr[i] = 0;
	}
	~Stack() {}

	bool isEmpty();
	bool isFull();
	void push(T value);
	T pop();
	T peek();
	T count();
	void change(T index, T value);
	T minValue();
	void display();

private:
	T top;
	T arr[MAX];
	T length = sizeof(arr) / sizeof(arr[0]);
};

template<typename T>
void Stack_Temp<T>::change(T index, T value) {
	arr[index] = value;
	std::cout << "Value is changed for this index :" << index << " with this value : " << value << "\n";
}

// ... the other function implementations will be here


#endif // STACK_TEMPLATES_ARRAYS


