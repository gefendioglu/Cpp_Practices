#pragma once

// Doubly Linked List Implentation 
// --------------------------------------------------
// --------------------------------------------------

#ifdef DOUBLY_LINKED_LIST

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
	Node* nodeExists(const int& key);

	// Appending a node to the list
	void appendNode(Node* node);

	// Prepending a node to the list 
	// (attaching a node at the beginning of doubly linked list)
	

	// Deleting a node by an unique key value from a list
	void deleteNodeByKey(const int& key) 
	{
		
		Node* ptr = nodeExists(key);
		if (ptr == nullptr)
		{
			std::cout << "No node exist with this key : " << key << "\n";
		}
		else
		{
			if (head->key == key)
			{
				head = head->next;
				std::cout << "Head is unlinked from the list with this key value : " << key << "\n";
			}
			else
			{
				Node* nextNode = ptr->next;
				Node* prevNode = ptr->previous;

				// deleting a node at the end of a list
				if (nextNode == nullptr)
				{
					prevNode->next = nullptr;
					std::cout << "Node is deleted from the end of the list" << "\n";

				}
				// deleting a node in between different nodes from the list
				else
				{
					prevNode->next = nextNode;
					nextNode->previous = prevNode;
					std::cout << "Node is deleted in between different nodes from the list. " << "\n";
				}
			}
		}
	}
	
	// Updating a node by key value in the list
	void updateNodeByKey(const int& key, const int& data) 
	{
		Node* ptr = nodeExists(key);
		if (ptr != nullptr)
		{
			ptr->data = data;
			std::cout << "Node data is updated." << "\n";
		}
		else
		{
			std::cout << "Node data doesnt exist with the key value : " << key << "\n";
		}
	}

	//Printing the list
	void printList() {
		if (head ==nullptr)
		{
			std::cout << "No nodes in the list." << "\n";
		}
		else
		{
			std::cout << "Doubly Linked List Values : ";
			Node* temp = head;

			while (temp != nullptr)
			{
				std::cout << "(" << temp->key << "," << temp->data << ") <--> ";
				
				temp = temp->next;
			}
		}
	}

private:
	Node* head;
};

// Checking if node exists using key value
Node* DoublyLinkedList::nodeExists(const int& key)
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

void DoublyLinkedList::appendNode(Node* node)
{
	if (nodeExists(node->key) != nullptr)
	{
		std::cout << "Node is already exist with the key value : " << node->key << "\n";
		std::cout << "Append another node with differet key value. " << "\n";
	}
	else
	{
		if (head == nullptr)
		{
			head = node;
			std::cout << "Node is appended as a head node." << "\n";
		}
		else
		{
			Node* ptr = head;
			while (ptr->next != nullptr)
			{
				ptr = ptr->next;
			}
			ptr->next = node;
			node->previous = ptr;
			std::cout << "Node is appended. " << "\n";
		}

	}
}

void DoublyLinkedList::prependNode(Node* node)
{
	if (nodeExists(node->key) != nullptr)
	{
		std::cout << "Node is already exist with the key value : " << node->key << "\n";
		std::cout << "Prepend another node with differet key value. " << "\n";
	}
	else
	{
		if (head == nullptr)
		{
			head = node;
			std::cout << "Node is prepended as a head node." << "\n";
		}
		else
		{
			head->previous = node;
			node->next = head;
			head = node;
			std::cout << "Node is prepended " << "\n";
		}
	}
}

void prependNode(Node* node)
{
	if (nodeExists(node->key) != nullptr)
	{
		std::cout << "Node is already exist with the key value : " << node->key << "\n";
		std::cout << "Prepend another node with differet key value. " << "\n";
	}
	else
	{
		if (head == nullptr)
		{
			head = node;
			std::cout << "Node is prepended as a head node." << "\n";
		}
		else
		{
			head->previous = node;
			node->next = head;
			head = node;
			std::cout << "Node is prepended " << "\n";
		}
	}
}

// Inserting a node after a particular node in the list
void insertNodeAfter(const int& key, Node* node)
{
	Node* ptr = nodeExists(key);
	if (ptr == nullptr)
	{
		std::cout << "No node exist with this key : " << node->key << "\n";
	}
	else
	{
		if (nodeExists(node->key) != nullptr)
		{
			std::cout << "Node is already exist with the key value : " << node->key << "\n";
			std::cout << "Insert another node with differet key value. " << "\n";
		}
		else
		{

			Node* nextNode = ptr->next;

			// Inserting at the end of a list
			if (nextNode == nullptr)
			{
				ptr->next = node;
				node->previous = ptr;
				std::cout << "Node is inserted at the end of the list. " << "\n";
			}

			// Inserting in between the nodes in the list
			else
			{
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

int main() {

	DoublyLinkedList d;
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

#endif // DOUBLY_LINKED_LIST


// Doubly Linked List Implentation using Arrays (GeeksForGeeks)
// --------------------------------------------------
// --------------------------------------------------

#ifdef DOUBLY_LINKED_LIST_ARRAYS

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// A linked list node 
class Node
{
public:
	int data;
	Node* next;
	Node* prev;
};

/* Given a reference (pointer to pointer) to the head of a list
and an int, inserts a new node on the front of the list. */
void push(Node** head_ref, int new_data)
{
	/* 1. allocate node */
	Node* new_node = new Node();

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. Make next of new node as head and previous as NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	/* 4. change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* 5. move the head to Member to the new node */
	(*head_ref) = new_node;
}

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(Node* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL)
	{
		std::cout << "the given previous node cannot be NULL";
		return;
	}

	/* 2. allocate new node */
	Node* new_node = new Node();

	/* 3. put in the data */
	new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. Make the next of prev_node as new_node */
	prev_node->next = new_node;

	/* 6. Make prev_node as previous of new_node */
	new_node->prev = prev_node;

	/* 7. Change previous of new_node's next node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
of a DLL and an int, appends a new node at the end */
void append(Node** head_ref, int new_data)
{
	/* 1. allocate node */
	Node* new_node = new Node();

	Node* last = *head_ref; /* used in step 5*/

	/* 2. put in the data */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so
		make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		node as head */
	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

	return;
}

// This function prints contents of 
// linked list starting from the given node 
void printList(Node* node)
{
	Node* last;
	std::cout << "\nTraversal in forward direction \n";
	while (node != NULL)
	{
		std::cout << " " << node->data << " ";
		last = node;
		node = node->next;
	}

	std::cout << "\nTraversal in reverse direction \n";
	while (last != NULL)
	{
		std::cout << " " << last->data << " ";
		last = last->prev;
	}
}

/* Driver program to test above functions*/
int main()
{
	/* Start with the empty list */
	Node* head = NULL;

	// Insert 6. So linked list becomes 6->NULL 
	append(&head, 6);

	// Insert 7 at the beginning. So 
	// linked list becomes 7->6->NULL 
	push(&head, 7);

	// Insert 1 at the beginning. So 
	// linked list becomes 1->7->6->NULL 
	push(&head, 1);

	// Insert 4 at the end. So linked 
	// list becomes 1->7->6->4->NULL 
	append(&head, 4);

	// Insert 8, after 7. So linked 
	// list becomes 1->7->8->6->4->NULL 
	insertAfter(head->next, 8);

	std::cout << "Created DLL is: ";
	printList(head);

	return 0;
}

#endif // DOUBLY_LINKED_LIST_ARRAYS



