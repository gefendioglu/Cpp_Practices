#pragma once

// Queue Implementation using Arrays
// --------------------------------------------------
// --------------------------------------------------

#ifdef QUEUE

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAX 5

// --------------------------------------------------

class Queue {
public:
	Queue() : front{ -1 }, rear{ -1 }{
		for (int i = 0; i < length; i++)
			arr[i] = 0;
	}

	~Queue() {}

	// getter functions
	void getData()const;
	int getFront()const;
	int getRear()const;
	
	// queue functions
	bool isEmpty();
	bool isFull();
	void enqueue(int value);
	int dequeue();
	int count();

private:
	int front;
	int rear;
	int arr[MAX];
	int length = sizeof(arr) / sizeof(arr[0]);
};

// --------------------------------------------------

void Queue::getData()const {
	for (int i = 0; i <  length; i++)
		std::cout << arr[i] << "\n";
}
// --------------------------------------------------

int Queue::getFront()const {
	return arr[front];
}

// --------------------------------------------------

int Queue::getRear()const {
	return arr[rear];
}

// --------------------------------------------------

bool Queue::isEmpty() {
	
	if (front == -1 && rear == -1)
		return true;
	else
		return false;
}

// --------------------------------------------------

bool Queue::isFull() {

	if (rear == length - 1)
		return true;
	else
		return false;
}

// --------------------------------------------------

void Queue::enqueue(int value) {
	
	if (isFull()){
		std::cout << "Queue is Full!!! " << "\n";
		return;
	}
	else if (isEmpty())	{
		rear = front = 0;
	}
	else {
		rear++;
	}
	arr[rear] = value;
}

// --------------------------------------------------

int Queue::dequeue() {

	int x = 0;
	if (isEmpty()) {
		std::cout << "Queue is Empty!!! " << "\n";
		return 0;
	}
	// Whenever one value in the queue --> rear = front = 0
	else if (front == rear) {
		// If the queue has one value 
		x = arr[front];
		arr[front] = 0;
		front = rear = -1;
	}
	else {
		// If the queue has more than one value
		x = arr[front];
		arr[front] = 0;
		front++;
	}

	return x;
}

// --------------------------------------------------

int Queue::count() {
	return (rear - front + 1);
}

// Test Code
// --------------------------------------------------

int main() {

	Queue q1;
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
			std::cout << "denqueue value from the queue " << q1.dequeue()<< "\n";
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

// Short Test Code
//int main()
//{
//	Queue q;
//
//	q.enqueue(10);
//	q.enqueue(20);
//	q.enqueue(30);
//	q.enqueue(40);
//	q.getData();
//
//	std::cout << "Front value : " << q.getFront() << "\n";
//	std::cout << "Rear value : " << q.getRear() << "\n";
//
//	return 0;
//	/*
//		10
//		20
//		30
//		40
//		0
//		Front value : 10
//		Rear value : 40
//	*/
//
//}

#endif // QUEUE

// TO BE VERIFIED
// Queue Implementation using Arrays (GeeksForGeeks)
// --------------------------------------------------
// --------------------------------------------------

#ifdef QUEUE_ARRAYS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// --------------------------------------------------
class Queue {
public:
	Queue(){
		front = -1;
		rear = -1; 
		size = 0;
		capacity = 0;
		array = nullptr;
	}

	~Queue(){}
	
	// getter functions
	int getFront(Queue* queue);
	int getRear(Queue* queue);
	
	// queue functions
	Queue* createQueue(unsigned capacity);
	bool isFull(Queue* queue);
	bool isEmpty(Queue* queue);
	void enqueue(Queue* queue, int item);
	int dequeue(Queue* queue);

private:
	int front, rear, size;
	unsigned capacity;
	int* array;
};

// --------------------------------------------------
Queue* Queue::createQueue(unsigned int capacity) {
	
	Queue* queue = new Queue();
	queue->capacity = capacity;
	queue->rear = capacity - 1;
	queue->array = new int[(queue->capacity * sizeof(int))];
	
	return queue;
}

// Queue is full when size becomes equal to the capacity 
// --------------------------------------------------
bool Queue::isFull(Queue* queue) {
	return (queue->size == queue->capacity);
}

// Queue is empty when size is 0 
// --------------------------------------------------
bool Queue::isEmpty(Queue* queue) {
	return (queue->size == 0);
}

// Function to add an item to the queue, changes rear and size 
// --------------------------------------------------
void Queue::enqueue(Queue* queue, int item) {
	
	if (isFull(queue))
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
	std::cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue, changes front and size 
// --------------------------------------------------
int Queue::dequeue(Queue* queue) {
	
	if (isEmpty(queue))
		return INT_MIN;
	int item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	
	return item;
}

// Function to get front of queue 
// --------------------------------------------------
int Queue::getFront(Queue* queue) {
	
	if (isEmpty(queue))
		return INT_MIN;
	
	return queue->array[queue->front];
}

// Function to get rear of queue 
// --------------------------------------------------

int Queue::getRear(Queue* queue) {
	
	if (isEmpty(queue))
		return INT_MIN;
	
	return queue->array[queue->rear];
}

// Test Code 
// --------------------------------------------------
int main() {

	Queue* queue = new Queue();
	
	queue->createQueue(1000);
	queue->enqueue(queue, 10);
	queue->enqueue(queue, 20);
	queue->enqueue(queue, 30);
	queue->enqueue(queue, 40);

	std::cout << queue->dequeue(queue)	<< " dequeued from queue\n";
	
	return 0;
}

#endif // QUEUE_ARRAYS


// Queue Implementation using Linked List (GeeksForGeeks)
// --------------------------------------------------
// --------------------------------------------------

#ifdef QUEUE_LINKED_LIST

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main() {

	return 0;
}

#endif // QUEUE_LINKED_LIST

