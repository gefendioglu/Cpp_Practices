#pragma once

// Circular Queue Implementation
// --------------------------------------------------
// --------------------------------------------------

#ifdef CIRCULAR_QUEUE

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class CircularQueue {
public:
	CircularQueue() {
		front = -1;
		rear = -1;
		itemCount = 0;
		for (int i = 0; i < length; ++i)
			arr[i] = 0;
	}

	~CircularQueue() {}

	// getter functions
	void getData()const;

	// queue functions
	void enqueue(int value);
	int dequeue();
	bool isEmpty();
	bool isFull();
	int count();

private:
	int front;
	int rear;
	int arr[5];
	int length = sizeof(arr) / sizeof(arr[0]);
	int itemCount;
};

// --------------------------------------------------

void CircularQueue::getData()const {
	
	for (int i = 0; i < length; ++i)
		std::cout << arr[i] << "\n";
}

// --------------------------------------------------

void CircularQueue::enqueue(int value) {
	
	if (isFull()) {
		std::cout << "Queue is Full!!! " << "\n";
		return;
	}
	else if (isEmpty()) {
		rear = front = 0;
	}
	else {
		rear = (rear + 1) % length;
	}

	itemCount++;
	arr[rear] = value;
}

// --------------------------------------------------

int CircularQueue::dequeue() {

	int x = 0;
	if (isEmpty()) {
		std::cout << "Queue is Empty!!! " << "\n";
		return 0;
	}
	// Whenever only one value in the queue --> rear = front = 0
	else if (front == rear)	{
		// If the queue has one value 
		x = arr[front];
		arr[front] = 0;
		front = rear = -1;
	}
	else {
		// If the queue has more than one value
		x = arr[front];
		arr[front] = 0;
		front = (front + 1) % length;
	}
	itemCount--;
	return x;
}

// --------------------------------------------------

bool CircularQueue::isEmpty() {
	
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

// --------------------------------------------------

bool CircularQueue::isFull() {

	if ((rear + 1) % length == front)
		return true;
	else
		return false;
}

// --------------------------------------------------

int CircularQueue::count() {
	return itemCount;
}

// --------------------------------------------------

int main() {

	CircularQueue q1;
	int option, value;

	do
	{
		std::cout << "\n\n What operation do you want to perform : " << "\n";
		std::cout << " Enter 0 to exit  " << "\n";
		std::cout << "1. Enqueue() " << "\n";
		std::cout << "2. Dequeue() " << "\n";
		std::cout << "3. isEmpty() " << "\n";
		std::cout << "4.  isFull() " << "\n";
		std::cout << "5.   count() " << "\n";
		std::cout << "6. display() " << "\n";
		std::cout << "5. Clear Screen " << "\n";

		std::cin >> option;
		switch (option)
		{
		case 0:

			break;

		case 1:
			std::cout << "enter an item to enqueue in the queue " << "\n";
			std::cin >> value;
			q1.enqueue(value);
			break;

		case 2:
			std::cout << "denqueue value from the queue " << q1.dequeue() << "\n";

			break;

		case 3:
			if (q1.isEmpty())
				std::cout << "Queue is Empty" << "\n";
			else
				std::cout << "Queue is not Empty" << "\n";
			break;
		case 4:
			if (q1.isFull())
				std::cout << "Queue is Full" << "\n";
			else
				std::cout << "Queue is not Full" << "\n";

			break;
		case 5:
			std::cout << "Count of the queue " << q1.count() << "\n";

			break;
		case 6:
			std::cout << "Display the queue " << "\n";
			q1.getData();
			break;
		case 7:
			system("cls");
			break;
		default:
			std::cout << "Enter proper number :" << "\n";
			break;
		}

	} while (option != 0);

	return 0;
}

#endif // CIRCULAR_QUEUE