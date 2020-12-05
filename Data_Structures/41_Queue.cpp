
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Queue {
public:
	Queue() {
		front = -1;
		rear = -1;
		for (int i = 0; i < length; i++)
			arr[i] = 0;
	}

	~Queue() {}

	// getter functions
	void getData()const {
		for (int i = 0; i < length; i++)
			std::cout << arr[i] << "\n";
	}

	// other queue functions
	void enqueue(int value) {
		if (isFull())
		{
			std::cout << "Queue is Full!!! " << "\n";
			return;
		}
		else if (isEmpty())
		{
			rear = front = 0;
		}
		else
		{
			rear++;
		}
		arr[rear] = value;
	}

	int dequeue() {

		int x = 0;
		if (isEmpty())
		{ 
			std::cout << "Queue is Empty!!! " << "\n";
			return 0;
		}
		// Whenever only one value in the queue --> rear = front = 0
		else if (front == rear)
		{
			// If the queue has one value 
			x = arr[front];
			arr[front] = 0;
			front = rear = -1;
		}
		else
		{
			// If the queue has more than one value
			x = arr[front];
			arr[front] = 0;
			front++;
		}

		return x;
	}

	bool isEmpty() {
		if (front == -1 && rear == -1)
			return true;
		else
			return false;
	}

	bool isFull() {

		if (rear == length -  1)
			return true;
		else
			return false;
	}

	int count() {
		return (rear - front + 1);
	}

private:
	int front;
	int rear;
	int arr[5];
	int length = sizeof(arr) / sizeof(arr[0]);
};

//int main() {
//
//	Queue q1;
//	int option, value;
//
//	do
//	{
//		std::cout << "\n\n What operation do you want to perform : " << "\n";
//		std::cout << " Enter 0 to exit  " << "\n";
//		std::cout << "1. Enqueue() " << "\n";
//		std::cout << "2. Dequeue() " << "\n";
//		std::cout << "3. isEmpty() " << "\n";
//		std::cout << "4.  isFull() " << "\n";
//		std::cout << "5.   count() " << "\n";
//		std::cout << "6. display() " << "\n";
//		std::cout << "5. Clear Screen " << "\n";
//
//		std::cin >> option;
//		switch (option)
//		{
//		case 0:
//
//			break;
//
//		case 1:
//			std::cout << "enter an item to enqueue in the queue " << "\n";
//			std::cin >> value;
//			q1.enqueue(value);
//			break;
//
//		case 2:
//			std::cout << "denqueue value from the queue " << q1.dequeue()<< "\n";
//			
//			break;
//
//		case 3:
//			if (q1.isEmpty())
//				std::cout << "Queue is Empty" << "\n";
//			else
//				std::cout << "Queue is not Empty" << "\n";
//			break;
//		case 4:
//			if (q1.isFull())
//				std::cout << "Queue is Full" << "\n";
//			else
//				std::cout << "Queue is not Full" << "\n";
//
//			break;
//		case 5:
//			std::cout << "Count of the queue " << q1.count() << "\n";
//			
//			break;
//		case 6:
//			std::cout << "Display the queue " << "\n";
//			q1.getData();
//			break;
//		case 7:
//			system("cls");
//			break;
//		default:
//			std::cout << "Enter proper number :" << "\n";
//			break;
//		}
//
//	} while (option != 0);
//
//	return 0;
//}