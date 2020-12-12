#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <array>

//// A singly linked list in C++
//class IntElement {
//public:
//	IntElement(const int& value) :next{ nullptr }, data{ value }{}
//	~IntElement() {}
//
//	// getter functions
//	IntElement* getNext()const { return next; }
//	const int& getData()const { return data; }
//
//	// setter functions
//	void setNext(IntElement* ptr) { next = ptr; }
//	void setData(const int& value) { data = value; }
//
//	// other linked list functions
//	IntElement* insertInFront(IntElement** head, int data);
//	IntElement* find(IntElement* head, int data);
//	bool deleteElement(IntElement** head, IntElement* deleteMe);
//	bool deleteElement_I(IntElement** head, IntElement* deleteMe);
//	void deleteList(IntElement** head);
//
//	// operator overloading function
//
//	friend std::ostream& operator<<(std::ostream& os, IntElement* ptr) {
//		return os << ptr->data << "\n";
//	}
//
//private:
//	IntElement* next;
//	int data;
//};
//
//IntElement* IntElement::insertInFront(IntElement** head, int data) {
//	IntElement* newElem = new IntElement(data);
//	if (!newElem)
//		return nullptr;
//	newElem->data = data;
//	newElem->next = *head;  // The correct version passes in a pointer to the head pointer
//	*head = newElem;
//	return newElem;
//}
//
//IntElement* IntElement::find(IntElement* head, int data) {
//	IntElement* elem = head;
//	while (elem != nullptr && elem->getData() != data) {
//		elem = elem->getNext();
//	}
//	return elem;
//}
//
//bool IntElement::deleteElement(IntElement** npp, IntElement* deleteMe) {
//
//	//IntElement* elem;
//
//	if (!npp || !*npp || !deleteMe) /* Check for null pointers */
//		return false;
//
//	while (*npp) {
//		if (*npp == deleteMe) {
//			/* npp points to head pointer (if deleteMe is first element) or to next pointer within preceding element */
//			*npp = deleteMe->next;
//			free(deleteMe);
//			return true;
//		}
//		/* Iterating for the next list element */
//		npp = &((*npp)->next);
//	}
//	/* deleteMe not found */
//	return false;
//}
//
//void IntElement::deleteList(IntElement** head)
//{
//	// First pointer points the first element of list
//	IntElement* deleteMe = *head;
//
//	while (deleteMe) {
//		// Second pointer points the next element of the element which will be deleted
//		IntElement* next = deleteMe->next;
//		// delete the element
//		free(deleteMe);
//		deleteMe = next;
//	}
//	*head = nullptr;
//}

//int main()
//{
//	// To Be Controlled - Exception Throw
//	IntElement* ilist = new IntElement(20);
//	IntElement** ptr_ilist = &ilist;
//	ilist->insertInFront(ptr_ilist,25);
//
//	IntElement* found = ilist->find(ilist->getNext(), 3);
//	std::cout << found << "\n";
//
//	return EXIT_SUCCESS;
//
//}


// ----------------------------------------------
// ----------------------------------------------


class Node {
public:
	int key;
	int data;
	Node* next;
	Node() :key{ 0 }, data{ 0 }, next{ nullptr } { }
	Node(const int& k, const int& d) :key{ k }, data{ d }, next{ nullptr } { }
};

class SinglyLinkedLists {
public:

	SinglyLinkedLists() :head{ nullptr } {}
	SinglyLinkedLists(Node* head) {
		this->head = head;
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


	// Appending a node to the singly linked list
	void appendNode(Node* node) {
		if (nodeExists(node->key) != nullptr) // there exist a node
		{
			std::cout << "Node already exists : " << node->key << "\n";
		}
		else
		{
			// if only one value in the singly linked list
			if (head == nullptr) {
				head = node;
				std::cout << "Node is appended !!!" << "\n";
			}
			// if more than one nodes in the singly linked list
			else
			{
				Node* ptr = head;
				while (ptr->next != nullptr) {
					ptr = ptr->next;
				}
				// when ptr->next = nullptr (it means it is the last node)
				ptr->next = node;
				std::cout << "Node is appended !!!" << "\n";
			}
		}
	}

	// Prepending a node at the beginning of singly linked list
	void prependNode(Node* node) {
		if (nodeExists(node->key) != nullptr) // there exist a node
		{
			std::cout << "Node already exists : " << node->key << "\n";
		}
		else
		{
			//No need to traverse the list
			node->next = head;
			head = node;
			std::cout << "Node is prepended !!!" << "\n";
		}
	}

	// Inserting a node after a particular node (with the given key value) in the list
	void insertNodeAfter(const int& key, Node* node) {
		Node* ptr = nodeExists(key);
		// key value checking 
		if (ptr == nullptr)
		{
			std::cout << "No node exists with key value : " << key << "\n";
		}
		else // if the key value exists, a new node can be inserted 
		{
			// node value checking
			if (nodeExists(node->key) != nullptr) // there exist a node
			{
				std::cout << "Node already exists : " << node->key << "\n";
			}
			else // if not exist this node, we can insert it
			{
				node->next = ptr->next;
				ptr->next = node; // the previous node shall point the inserted node address
				std::cout << "Node is inserted !!!" << "\n";
			}

		}

	}

	// Deleting a node by unique key from the singly linked list
	void deleteNodeByKey(const int& key) {
		if (head == nullptr) // if the list is empty
		{
			std::cout << "Singly Linked List is already empty!!!" << "\n";
		}
		else if (head != nullptr)
		{
			if (head->key = key) // for the deletion of first node 
			{
				head = head->next;
				std::cout << "Node is UNLINKED with keys value : " << key << "\n";
			}
			else // for the deletion of middle nodes
			{
				Node* temp = nullptr;
				Node* prevptr = head;
				Node* currentptr = head->next;
				while (currentptr != nullptr) // if there is a node 
				{
					// if the deleted key is equal to this one 
					if (currentptr->key == key)
					{
						temp = currentptr;
						currentptr = nullptr;
					}
					else
					{
						prevptr = prevptr->next; // head->next
						currentptr = currentptr->next; //head->next->next
					}
				}

				if (temp != nullptr) // temp = currentptr;
				{
					prevptr->next = temp->next; // currenptr->next
					std::cout << "Node is UNLINKED with key values : " << key << "\n";
				}
				else // temp == nullptr
				{
					std::cout << "Node doesnt exist with the key value: " << key << "\n";
				}
			}
		}
	}

	// Updating a node using a unique key value
	void updateNodeByKey(const int& key, int data) {
		Node* ptr = nodeExists(key);
		if (ptr != nullptr)
		{
			ptr->data = data;
			std::cout << "Node is UPDATED !!!" << "\n";
		}
		else
		{
			std::cout << "Node doesnt exist with this key value : " << key << "\n";
		}
	}

	// Printing nodes in a singly linked list
	void printList() {
		if (head == nullptr)
		{
			std::cout << "No nodes can be printed in singly linked list" << "\n";
		}
		else // if there is at least one node in a singly linked list
		{
			std::cout << "Singly Linked List Values: ";
			Node* temp = head;

			// while temp doesnt point the last node
			while (temp != nullptr) {
				std::cout << "( " << temp->key << ", " << temp->data << " )--> ";
				temp = temp->next;
			}
		}
	}

private:
	Node* head;

};

//int main() {
//
//	SinglyLinkedLists s;
//	int option;
//	int k1 = 0;
//	int data1 = 0;
//	do
//	{
//		std::cout << "\n What operation do you want to choose? : \n";
//		std::cout << "1.      appendNode()" << "\n";
//		std::cout << "2.     prependNode()" << "\n";
//		std::cout << "3. insertNodeAfter()" << "\n";
//		std::cout << "4. deleteNodeByKey()" << "\n";
//		std::cout << "5. updateNodeByKey()" << "\n";
//		std::cout << "6.       printList()" << "\n";
//		std::cout << "7.      Clear Screen" << "\n";
//
//		std::cin >> option;
//		// dynamic memory allocation - heap
//		// it provides globally accessing the object
//		// in this case, there is a pointer in stack memory pointing to the object address located in heap memory
//		Node* n1 = new Node();
//
//		// static memory allocation - stack 
//		// Node n2;  
//
//		switch (option)
//		{
//		case 0:
//			break;
//		case 1:
//			std::cout << "Appending a node, enter a key and data of the node to be appended" << "\n";
//			std::cin >> n1->key;
//			std::cin >> n1->data;
//			s.appendNode(n1);
//			break;
//		case 2:
//			std::cout << "Prepending a node,enter a key and data of the node to be prepended " << "\n";
//			std::cin >> n1->key;
//			std::cin >> n1->data;
//			s.prependNode(n1);
//			break;
//		case 3:
//			std::cout << "Inserting a node, enter the key of existing node after which you want to insert this new node " << "\n";
//			std::cin >> k1;
//			std::cin >> n1->key;
//			std::cin >> n1->data;
//			s.insertNodeAfter(k1, n1);
//			break;
//		case 4:
//			std::cout << "Deleting a node, enter a key of the node to be deleted" << "\n";
//			std::cin >> k1;
//			s.deleteNodeByKey(k1);
//			break;
//		case 5:
//			std::cout << "Updating a node, enter key and new data to be updated";
//			std::cout << k1;
//			std::cout << data1;
//			s.updateNodeByKey(k1, data1);
//			break;
//		case 6:
//			s.printList();
//			break;
//		case 7:
//			system("cls");
//			break;
//		default:
//			std::cout << "Enter a proper option number" << "\n";
//		}
//
//	} while (option != 0);
//
//	//// While not using a menu screen
//	//Node node1(1, 10);
//	//Node node2(2, 20);
//	//Node node3(3, 30);
//	//Node node4(4, 40);
//
//	//// Creating a singly linked list with a node (node1)
//	//SinglyLinkedLists s(&node1);
//
//	//// Appending a node (node2) at the end of linked list
//	//s.appendNode(&node2);
//
//	//// Prepending a node (node3) at the beginning of linked list
//	//s.prependNode(&node3);
//
//	//// Inserting a node (node4) after the node which its key is 2. 
//	//s.insertNodeAfter(2, &node4);
//
//	//// Updating the data (55) of an exist node (key = 3) 
//	//s.updateNodeByKey(3, 55);
//
//	//// Deleting an exist node (key = 3) from the singly linked list 
//	//s.deleteNodeByKey(3);
//
//	return EXIT_SUCCESS;
//}