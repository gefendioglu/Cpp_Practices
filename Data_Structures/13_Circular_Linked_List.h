#pragma once

// Circular Linked List Implentation 
// --------------------------------------------------
// --------------------------------------------------

#ifdef CIRCULAR_LINKED_LIST

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Node {
public:
	int key;
	int data;
	Node* next;

	Node() :key{ 0 }, data{ 0 }, next{ nullptr } {}
	Node(const int& key, const int& data) :key{ key }, data{ data }, next{ nullptr }{}
};

class CircularLinkedList {
public:

	CircularLinkedList() : head{ nullptr } {}
	CircularLinkedList(Node* node) {
		this->head = node;
	}

	// Checking if node exists using key value
	Node* nodeExists(const int& key)
	{
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

	// Appending a node 
	void appendNode(Node* node);
	void prependNode(Node* node);
	void insertNodeAfter(const int& key, Node* node);
	void deleteNodeByKey(const int& key);
	void updateNodeByKey(const int& key, const int& data);
	void printList();

private:
	Node* head;
};

void CircularLinkedList::appendNode(Node* node) {}
void CircularLinkedList::prependNode(Node* node) {}
void CircularLinkedList::insertNodeAfter(const int& key, Node* node) {}
void CircularLinkedList::deleteNodeByKey(const int& key) {}
void CircularLinkedList::updateNodeByKey(const int& key, const int& data) {}
void CircularLinkedList::printList() {}

int main() {

	CircularLinkedList c;
	int option;
	int k1 = 0;
	int data1 = 0;

	do
	{
		std::cout << "\n What operation do you want to choose? : \n";
		std::cout << "1.      appendNode()" << "\n";
		std::cout << "2.     prependNode()" << "\n";
		std::cout << "3. insertNodeAfter()" << "\n";
		std::cout << "4. deleteNodeByKey()" << "\n";
		std::cout << "5. updateNodeByKey()" << "\n";
		std::cout << "6.       printList()" << "\n";
		std::cout << "7.      Clear Screen" << "\n";

		std::cin >> option;
		Node* n1 = new Node();

		switch (option)
		{
		case 0:
			break;
		case 1:
			std::cout << "Appending a node, enter a key and data of the node to be appended" << "\n";
			std::cin >> n1->key;
			std::cin >> n1->data;
			c.appendNode(n1);
			break;
		case 2:
			std::cout << "Prepending a node,enter a key and data of the node to be prepended " << "\n";
			std::cin >> n1->key;
			std::cin >> n1->data;
			c.prependNode(n1);
			break;
		case 3:
			std::cout << "Inserting a node, enter the key of existing node after which you want to insert this new node " << "\n";
			std::cin >> k1;
			std::cin >> n1->key;
			std::cin >> n1->data;
			c.insertNodeAfter(k1, n1);
			break;
		case 4:
			std::cout << "Deleting a node, enter a key of the node to be deleted" << "\n";
			std::cin >> k1;
			c.deleteNodeByKey(k1);
			break;
		case 5:
			std::cout << "Updating a node, enter key and new data to be updated";
			std::cout << k1;
			std::cout << data1;
			c.updateNodeByKey(k1, data1);
			break;
		case 6:
			c.printList();
			break;
		case 7:
			system("cls");
			break;
		default:
			std::cout << "Enter a proper option number" << "\n";
		}

	} while (option != 0);

	return EXIT_SUCCESS;
}


#endif // CIRCULAR_LINKED_LIST