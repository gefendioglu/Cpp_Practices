
## DOUBLY LINKED LISTS

## Node & Doubly Linked List Class Definitions 

```cpp
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

## The Operations of Doubly Linked Lists:

### Appending Node
  - Get the new node
    - Check if node exists with the same key
      - if true --> abort
      - if false --> continue
    - if head == nullptr then append at the beginning
      - else traverse to the end of the list to find a node to be appended 
   - Append new node at the end of doubly linked list

```cpp
	void appendNode(Node* node) {
		if (nodeExists(node->key) != nullptr)	{
			std::cout << "Node is already exist with the key value : " << node->key << "\n";
			std::cout << "Append another node with differet key value. " << "\n";
		}
		else {
			if (head == nullptr) {
				head = node;
				std::cout << "Node is appended as a head node." << "\n";
			}
			else {
				Node* ptr = head;
				while (ptr->next !=nullptr) {
					ptr = ptr->next;
				}
				ptr->next = node;
				node->previous = ptr;
				std::cout << "Node is appended. " << "\n";
			}
		}
	}
```

/----------------------------------------------
/----------------------------------------------

### Prepending Node
  - Get the new node
    - Check if node exists with the same key
      - if true --> abort
      - if false --> continue
    - head->previous = new_node
    - new_node->next = head
    - head = new_node

```cpp
	void prependNode(Node* node){
		if (nodeExists(node->key) != nullptr) {
			std::cout << "Node is already exist with the key value : " << node->key << "\n";
			std::cout << "Prepend another node with differet key value. " << "\n";
		}
		else {
			if (head == nullptr) {
				head = node;
				std::cout << "Node is prepended as a head node." << "\n";
			}
			else {
				head->previous = node;
				node->next = head;
				head = node;
				std::cout << "Node is prepended " << "\n";
			}
		}
	}
```

/----------------------------------------------
/----------------------------------------------

### Inserting Node
  - Get the new node & the key of node in the list after which you want to link this new node
    - Check if node exists with the same key as new node
      - if true --> abort
      - if false --> continue
  - Check if node exists with the key entered by user
    - if true --> abort
    - if false --> continue
  - Access node N after which you want to append new node new_node
    - if N is at the end, then 
      - N->next = new_node
      - new_node->previous = N
    - if N is in between, then
      - new_node->next = N->next
      - N->next->previous = new_node
      - new_node->previous = N
      - N->next = new_node

```cpp
void insertNodeAfter(const int& key, Node* node) {
		
		Node* ptr = nodeExists(key);
		if (ptr == nullptr) {
			std::cout << "No node exist with this key : " << node->key << "\n";
		}
		else {
			if (nodeExists(node->key) != nullptr) {
				std::cout << "Node is already exist with the key value : " << node->key << "\n";
				std::cout << "Insert another node with differet key value. " << "\n";
			}
			else {
				Node* nextNode = ptr->next;
				
				// Inserting at the end of a list
				if (nextNode == nullptr) {
					ptr->next = node;
					node->previous = ptr;
					std::cout << "Node is inserted at the end of the list. " << "\n";
				}

				// Inserting in between the nodes in the list
				else{
					// For the previous node with respect to the new node 
					node->next = nextNode;
					nextNode->previous = node;
					
					// For the next node with respect to the new node
					node->previous = ptr;
					ptr->next = node;

					std::cout << "Node is inserted between two different node in the list." << "\n";
				}
			}
		}
	}
```

/----------------------------------------------
/----------------------------------------------

### Deleting Node
  - Get the key of node that you want to delete
  - Check if node exists with the same key as new node
    - if true --> abort
    - if false --> continue
  - Check the head
    - if head == nullptr --> the list is empty
    - if head != nullptr && key matches head node --> head = head->next 
    - if head != nullptr && key doesnt match head node --> traverse to the node with the key
  - Check the node place
    - if node at the end --> prevNode->next == nullptr
    - if node is in between -->
      - prevNode->next = nextNode
      - nextNode->previous = prevNode

```cpp
	void deleteNodeByKey(const int& key) {
		
		Node* ptr = nodeExists(key);
		if (ptr == nullptr) {
			std::cout << "No node exist with this key : " << key << "\n";
		}
		else {
			if (head->key == key) {
				head = head->next;
				std::cout << "Head is unlinked from the list with this key value : " << key << "\n";
			}
			else {
				Node* nextNode = ptr->next;
				Node* prevNode = ptr->previous;

				// deleting a node at the end of a list
				if (nextNode == nullptr) {
					prevNode->next = nullptr;
					std::cout << "Node is deleted from the end of the list" << "\n";
				}
				// deleting a node in between different nodes from the list
				else {
					prevNode->next = nextNode;
					nextNode->previous = prevNode;
					std::cout << "Node is deleted in between different nodes from the list. " << "\n";
				}
			}
		}
	}
```

/----------------------------------------------
/----------------------------------------------

### Updating Node
  - Get the key of node that you want to delete
  - Check if node exists with the same key as new node
    - if true --> abort
    - if false --> continue
  - Traverse to that node
  - Update the data value

```cpp
void updateNodeByKey(const int& key, const int& data) {
		Node* ptr = nodeExists(key);
		if (ptr != nullptr) {
			ptr->data = data;
			std::cout << "Node data is updated." << "\n";
		}
		else {
			std::cout << "Node data doesnt exist with the key value : " << key << "\n";
		}
}
```

/----------------------------------------------
/----------------------------------------------

- **Printing a doubly linked list**: 

```cpp
	void printList() {
		if (head ==nullptr) {
			std::cout << "No nodes in the list." << "\n";
		}
		else {
			std::cout << "Doubly Linked List Values : ";
			Node* temp = head;

			while (temp != nullptr) {
				std::cout << "(" << temp->key << "," << temp->data << ") <--> ";
				temp = temp->next;
			}
		}
	}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Doubly Linked Lists Full Code Implementation

```cpp
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
			if (ptr->key == key) {
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
	}

	// Appending a node to the list
	void appendNode(Node* node) {
		if (nodeExists(node->key) != nullptr)	{
			std::cout << "Node is already exist with the key value : " << node->key << "\n";
			std::cout << "Append another node with differet key value. " << "\n";
		}
		else {
			if (head == nullptr) {
				head = node;
				std::cout << "Node is appended as a head node." << "\n";
			}
			else {
				Node* ptr = head;
				while (ptr->next !=nullptr)	{
					ptr = ptr->next;
				}
				ptr->next = node;
				node->previous = ptr;
				std::cout << "Node is appended. " << "\n";
			}
		}
	}

	// Prepending a node to the list (attaching a node at the beginning of list)
	void prependNode(Node* node) {
		if (nodeExists(node->key) != nullptr)	{
			std::cout << "Node is already exist with the key value : " << node->key << "\n";
			std::cout << "Prepend another node with differet key value. " << "\n";
		}
		else {
			if (head == nullptr) {
				head = node;
				std::cout << "Node is prepended as a head node." << "\n";
			}
			else {
				head->previous = node;
				node->next = head;
				head = node;
				std::cout << "Node is prepended " << "\n";
			}
		}
	}

	// Inserting a node after a particular node in the list
	void insertNodeAfter(const int& key, Node* node) {
		Node* ptr = nodeExists(key);
		if (ptr == nullptr)	{
			std::cout << "No node exist with this key : " << node->key << "\n";
		}
		else {
			if (nodeExists(node->key) != nullptr) {
				std::cout << "Node is already exist with the key value : " << node->key << "\n";
				std::cout << "Insert another node with differet key value. " << "\n";
			}
			else {
				Node* nextNode = ptr->next;
				
				// Inserting at the end of a list
				if (nextNode == nullptr) {
					ptr->next = node;
					node->previous = ptr;
					std::cout << "Node is inserted at the end of the list. " << "\n";
				}

				// Inserting in between the nodes in the list
				else {
					// For the previous node with respect to the new node 
					node->next = nextNode;
					nextNode->previous = node;
					
					// For the next node with respect to the new node
					node->previous = ptr;
					ptr->next = node;

					std::cout << "Node is inserted between two different node in the list." << "\n";
				}
			}
		}
	}

	// Deleting a node by an unique key value from a list
	void deleteNodeByKey(const int& key) {
		
		Node* ptr = nodeExists(key);
		if (ptr == nullptr)	{
			std::cout << "No node exist with this key : " << key << "\n";
		}
		else {
			if (head->key == key)	{
				head = head->next;
				std::cout << "Head is unlinked from the list with this key value : " << key << "\n";
			}
			else {
				Node* nextNode = ptr->next;
				Node* prevNode = ptr->previous;

				// deleting a node at the end of a list
				if (nextNode == nullptr) {
					prevNode->next = nullptr;
					std::cout << "Node is deleted from the end of the list" << "\n";
				}
				// deleting a node in between different nodes from the list
				else {
					prevNode->next = nextNode;
					nextNode->previous = prevNode;
					std::cout << "Node is deleted in between different nodes from the list. " << "\n";
				}
			}
		}
	}
	
	// Updating a node by key value in the list
	void updateNodeByKey(const int& key, const int& data)	{
		Node* ptr = nodeExists(key);
		if (ptr != nullptr) {
			ptr->data = data;
			std::cout << "Node data is updated." << "\n";
		}
		else {
			std::cout << "Node data doesnt exist with the key value : " << key << "\n";
		}
	}

	//Printing the list
	void printList() {
		if (head ==nullptr) {
			std::cout << "No nodes in the list." << "\n";
		}
		else {
			std::cout << "Doubly Linked List Values : ";
			Node* temp = head;
			while (temp != nullptr)	{
				std::cout << "(" << temp->key << "," << temp->data << ") <--> ";
				temp = temp->next;
			}
		}
	}
private:
	Node* head;
};

int main() {

	DoublyLinkedList d;
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
			d.appendNode(n1);
			break;
		case 2:
			std::cout << "Prepending a node,enter a key and data of the node to be prepended " << "\n";
			std::cin >> n1->key;
			std::cin >> n1->data;
			d.prependNode(n1);
			break;
		case 3:
			std::cout << "Inserting a node, enter the key of existing node after which you want to insert this new node " << "\n";
			std::cin >> k1;
			std::cin >> n1->key;
			std::cin >> n1->data;
			d.insertNodeAfter(k1, n1);
			break;
		case 4:
			std::cout << "Deleting a node, enter a key of the node to be deleted" << "\n";
			std::cin >> k1;
			d.deleteNodeByKey(k1);
			break;
		case 5:
			std::cout << "Updating a node, enter key and new data to be updated";
			std::cout << k1;
			std::cout << data1;
			d.updateNodeByKey(k1, data1);
			break;
		case 6:
			d.printList();
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
