#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Node {
public:
	int key;
	int data;
	Node* next;
	Node* previous;

	Node() :key{ 0 }, data{ 0 }, next{ nullptr }, previous{ nullptr } {}
	Node(const int& key, const int& data) :key{ key }, data{ data }, next{ nullptr }, previous{ nullptr }{}
};

class DoublyLinkedList{
public:
	
	DoublyLinkedList() : head{nullptr} {}
	DoublyLinkedList(Node* node) {
		this->head = node;
	}

	// Checking if node exists using key value
	Node* nodeExists(const int& key) {
		Node* temp = nullptr;
		Node* ptr = head;
		while (ptr != nullptr) {
			if (ptr->key == key)
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

private:
	Node* head;
};


//int main() {
//
//	// Creating objects in stack 
//	Node node1(1, 10);
//	Node node2(2, 20);
//
//	
//
//	return EXIT_SUCCESS;
//}