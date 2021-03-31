
## CIRCULAR LINKED LISTS

/----------------------------------------------
/----------------------------------------------

## Node & Circular Linked List Class Definitions

```cpp
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
	Node* nodeExists(const int& key) {
		Node* temp = nullptr;
		Node* ptr = head;
		while (ptr != nullptr) {
			if (ptr->key == key)
				temp = ptr;
			ptr = ptr->next;
		}
		return temp;
	}
private:
	Node* head;
};
```

/----------------------------------------------
/----------------------------------------------

## The Operations of Circular Linked Lists

### Appending Node
  - Get the new node
  - Check if the node exists with the same key value
    - if true --> abort
    - if false --> continue
  - Check if head Members nullptr or not
    - if head == nullptr --> append at the beginning of this circular list
    - if head != nullptr --> traverse to the end of this circular list
  - Append a new node at the end of a circular list

/----------------------------------------------
/----------------------------------------------

### Prepending Node
  - Get the new node
  - Check if the node exists with the same key value
    - if true --> abort
    - if false --> continue
  - Assign head value to a temporary pointer (ptr)
  - Use this ptr to traverse to the end of this circular list
  - Use this ptr to access next pointer of the last node to Member to this newly passed node
  - Member next pointer of new node to head pointer (to provide circularity)
  - Change the head pointer to new node 

/----------------------------------------------
/----------------------------------------------

### Inserting Node
  - Get the new Node & key value in the list after which you want to link this new node.
  - Check if the node exists with the same key value
    - if true --> abort
    - if false --> continue
  - Check if node exists with the key entered by user 
    - if false --> abort
    - if true --> continue 
  - Access node N after which you want to append new node new_N
    - if node to be inserted at the end
      - new_node->next = head;
      - previous_node->next = new_node;
    - if node to be inserted in between 
      - new_node->next = previous_node->next;
      - previous_node->next = new_node;

/----------------------------------------------
/----------------------------------------------

### Deleting Node
  - Get the key value of node you want to delete
  - Check if the node exists with the same key value
    - if true --> abort
    - if false --> continue
  - Check if head Members nullptr or not  
    - if head == nullptr --> list is empty
    - if head != nullptr & key value matches head node 
      - head = head->next;
      - last_node->next = head; 
    - if head != nullptr & key value doesnt match head node 
      - traverse to the node with the key value (ptr)
  - Check where the node is
    - If the node is at the end --> previous_node->next = head;
    - If the node is in between the nodes in the list
      - previous_node->next = ptr->next;

/----------------------------------------------
/----------------------------------------------

### Updating Node
  - Get the key value of node you want to update
  - Check if node exists with the same key value
    - if true --> abort
    - if false --> continue
  - Traverse to that node
  - Update the data value of a node in the list.

/----------------------------------------------
/----------------------------------------------

- **Example** : The implementation of Circular Linked List (TO BE COMPLETED)

```cpp
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
	Node* nodeExists(const int& key) {
		Node* temp = nullptr;
		Node* ptr = head;
		while (ptr != nullptr) {
			if (ptr->key == key)
				temp = ptr;
			ptr = ptr->next;
		}
		return temp;
	}

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

	do {
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

		switch (option)	{
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
```

/----------------------------------------------
/----------------------------------------------

