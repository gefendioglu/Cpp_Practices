
## Singly Linked Lists:
- Each data element in the list has a link (a pointer or reference) to the element that follows it in the list. 
- The first element in a singly linked list is referred to as the "head" of the list. 
- The last element in such a list is called the "tail".
- When defining classes in C++ for singly linked list, particularly in template form, it’s best to add copy constructors and copy assignment operators so you don’t depend on the compiler- generated versions.

/----------------------------------------------
/----------------------------------------------

### Tracking the Head Element (Inserting an element at the front of a list)
  - In C++, the head pointer could also be passed in by reference, or the function could return the new head pointer.

```cpp
// when return value is a class pointer type
IntElement* IntElement::insertInFront(IntElement** head, int data) {
	IntElement* newElem =new IntElement(data);
	if (!newElem)
		return nullptr;
	newElem->data = data;
	newElem->next = *head;  // The correct version passes in a pointer to the head pointer
	*head = newElem;
	return newElem;
}

// when return value is bool 
bool IntElement::insertInFront(IntElement** head, int data) {
	IntElement* newElem =new IntElement(data);
	if (!newElem)
		return false;
	newElem->data = data;
	newElem->next = *head;  // The correct version passes in a pointer to the head pointer
	*head = newElem;
	return true;
}
```

/----------------------------------------------
/----------------------------------------------

### Traversing a List
  - When traversing, you must always check that you haven’t reached the end of the list.
  - Deletion and insertion require a pointer or reference to the element immediately preceding the deletion or insertion location.

```cpp
IntElement* IntElement::find(IntElement* head, int data) {
	IntElement* elem = head;
	while (elem != nullptr && elem->getData() != data) {
		elem = elem->getNext();
	}
	return elem;
}
```

/----------------------------------------------
/----------------------------------------------

### Inserting and Deleting Elements
  - Any insertion or deletion of elements in the middle of a list requires modification of the previous element’s next pointer or reference.
  - If you’re given only the element to delete (or before which to insert), this requires traversal of the list from the head because there’s no other way to find the preceding element. 
  - Special care must be taken when the element to be deleted is the head of the list.
  - Deletion and insertion require a pointer or reference to the element immediately preceding the deletion or insertion location. 

/----------------------------------------------
/----------------------------------------------

- **Example**: First implementation for deleting elements  from a singly linked list

```cpp
bool IntElement::deleteElement(IntElement** head, IntElement* deleteMe)
{
	IntElement* elem;
	if (!head || !*head || !deleteMe) /* Check for null pointers */
		return false;

	elem = *head;
	if (deleteMe == *head) { /* special case for head */
		*head = elem->next;
		free(deleteMe);
		return true;
	}
	while (elem) {
		if (elem->next == deleteMe) {
			/* elem is element preceding deleteMe */
			elem->next = deleteMe->next;
			free(deleteMe);
			return true;
		}
		elem = elem->next;
	}
	/* deleteMe not found */
	return false;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example**: Second implementation for deleting elements from a singly linked list 

```cpp
bool IntElement::deleteElement_I(IntElement** npp, IntElement* deleteMe) {

	IntElement* elem;

	if (!npp || !*npp || !deleteMe) /* Check for null pointers */
		return false;

	while (*npp) {
		if (*npp == deleteMe) {
			/* npp points to head pointer (if deleteMe is first element) or to next pointer within preceding element */
			*npp = deleteMe->next;
			free(deleteMe);
			return true;
		}
		/* Iterating for the next list element */
		npp = &((*npp)->next);
	}
	/* deleteMe not found */
	return false;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Deleting all list elements
  - Performing deletions raises another issue in languages without garbage collection, like C or C++. 
  - Do you advance the pointer first or free the element first? 
    - If you advance the pointer first, then the freeing is impossible because you overwrote the pointer to the element to be freed. 
	- If you free the element first, advancing the pointer is impossible, because it involves reading the next pointer in the element that was just freed.
	- The solution is to use two pointers !!!

```cpp
void IntElement::deleteList(IntElement** head) {
	// First pointer points the first element of list
	IntElement* deleteMe = *head;

	while (deleteMe) {
		// Second pointer points the next element of the element which will be deleted
		IntElement* next = deleteMe->next;
		// delete the element
		free(deleteMe);
		deleteMe = next;
	}
	*head = nullptr;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Singly Linked List Full Implementation (not using templates)
  - Test code shall be verified!

```cpp
#include <iostream>
#include <array>

// A singly linked list in C++
class IntElement {
public:
	IntElement(const int &value) :next{ nullptr }, data{ value }{}
	~IntElement() {}

	// getter functions
	IntElement* getNext()const { return next; }
	const int& getData()const { return data; }

	// setter functions
	void setNext(IntElement* ptr) { next = ptr; }
	void setData(const int& value) { data = value; }

	// other linked list functions
	IntElement* insertInFront(IntElement** head, int data);
	IntElement* find(IntElement* head, int data);
	bool deleteElement(IntElement** head, IntElement* deleteMe);
	bool deleteElement_I(IntElement** head, IntElement* deleteMe);
	void deleteList(IntElement** head);

	//operator overloading function for operator <<
	//std::ostream& operator<<(std::ostream& str, IntElement* ptr);
private:
	IntElement* next;
	int data;
};

IntElement* IntElement::insertInFront(IntElement** head, int data) {
	IntElement* newElem =new IntElement(data);
	if (!newElem)
		return nullptr;
	newElem->data = data;
	newElem->next = *head;  // The correct version passes in a pointer to the head pointer
	*head = newElem;
	return newElem;
}

IntElement* IntElement::find(IntElement* head, int data) {
	IntElement* elem = head;
	while (elem != nullptr && elem->getData() != data) {
		elem = elem->getNext();
	}
	return elem;
}

bool IntElement::deleteElement(IntElement** npp, IntElement* deleteMe) {

	IntElement* elem;
	if (!npp || !*npp || !deleteMe) /* Check for null pointers */
		return false;

	while (*npp) {
		if (*npp == deleteMe) {
			/* npp points to head pointer (if deleteMe is first element) or to next pointer within preceding element */
			*npp = deleteMe->next;
			free(deleteMe);
			return true;
		}
		/* Iterating for the next list element */
		npp = &((*npp)->next);
	}
	/* deleteMe not found */
	return false;
}

void IntElement::deleteList(IntElement** head)
{
	// First pointer points the first element of list
	IntElement* deleteMe = *head;

	while (deleteMe) {
		// Second pointer points the next element of the element which will be deleted
		IntElement* next = deleteMe->next;
		// delete the element
		free(deleteMe);
		deleteMe = next;
	}
	*head = nullptr;
}

int main()
{
	IntElement ilist(0);
	//ilist.insertInFront(&ilist.getNext(), ilist.getData());
	//IntElement *ptr = ilist.find(ilist.getNext(), 6);
	//std::cout << *ptr << "\n";
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Singly Linked List Example

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

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
	Node* nodeExists(const int& key);

	// Appending a node to the singly linked list
	void appendNode(Node* node);

	// Prepending a node at the beginning of singly linked list
	void prependNode(Node* node);

	// Inserting a node after a particular node (with the given key value) in the list
	void insertNodeAfter(const int& key, Node* node);

	// Deleting a node by unique key from the singly linked list
	void deleteNodeByKey(const int& key);

	// Updating a node using a unique key value
	void updateNodeByKey(const int& key, int data);

	void printList();
private:
	Node* head;

};

Node* SinglyLinkedLists::nodeExists(const int& key) {
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


// Appending a node to the singly linked list
void SinglyLinkedLists::appendNode(Node* node) {
	if (nodeExists(node->key) != nullptr) // there exist a node
	{
		std::cout << "Node already exists : " << node->key << "\n";
	}
	else {
		// if only one value in the singly linked list
		if (head == nullptr) {
			head = node;
			std::cout << "Node is appended !!!" << "\n";
		}
		// if more than one nodes in the singly linked list
		else {
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
void SinglyLinkedLists::prependNode(Node* node) {
	if (nodeExists(node->key) != nullptr) // there exist a node
	{
		std::cout << "Node already exists : " << node->key << "\n";
	}
	else {
		//No need to traverse the list
		node->next = head;
		head = node;
		std::cout << "Node is prepended !!!" << "\n";
	}
}

// Inserting a node after a particular node (with the given key value) in the list
void SinglyLinkedLists::insertNodeAfter(const int& key, Node* node) {
	Node* ptr = nodeExists(key);
	// key value checking 
	if (ptr == nullptr) {
		std::cout << "No node exists with key value : " << key << "\n";
	}
	// if the key value exists, a new node can be inserted 
	else {
		// node value checking
		// there exist a node
		if (nodeExists(node->key) != nullptr) {
			std::cout << "Node already exists : " << node->key << "\n";
		}
		// if not exist this node, we can insert it
		else {
			node->next = ptr->next;
			ptr->next = node; // the previous node shall point the inserted node address
			std::cout << "Node is inserted !!!" << "\n";
		}
	}
}

// Deleting a node by unique key from the singly linked list
void SinglyLinkedLists::deleteNodeByKey(const int& key) {
	// if the list is empty
	if (head == nullptr) {
		std::cout << "Singly Linked List is already empty!!!" << "\n";
	}
	else if (head != nullptr) {
		// for the deletion of first node 
		if (head->key = key) {
			head = head->next;
			std::cout << "Node is UNLINKED with keys value : " << key << "\n";
		}
		// for the deletion of middle nodes
		else {
			Node* temp = nullptr;
			Node* prevptr = head;
			Node* currentptr = head->next;
			// if there is a node 
			while (currentptr != nullptr) {
				// if the deleted key is equal to this one 
				if (currentptr->key == key) {
					temp = currentptr;
					currentptr = nullptr;
				}
				else {
					prevptr = prevptr->next; // head->next
					currentptr = currentptr->next; //head->next->next
				}
			}
			// temp = currentptr;
			if (temp != nullptr) {
				prevptr->next = temp->next; // currenptr->next
				std::cout << "Node is UNLINKED with key values : " << key << "\n";
			}
			// temp == nullptr
			else {
				std::cout << "Node doesnt exist with the key value: " << key << "\n";
			}
		}
	}
}

// Updating a node using a unique key value
void SinglyLinkedLists::updateNodeByKey(const int& key, int data) {
	Node* ptr = nodeExists(key);
	if (ptr != nullptr) {
		ptr->data = data;
		std::cout << "Node is UPDATED !!!" << "\n";
	}
	else {
		std::cout << "Node doesnt exist with this key value : " << key << "\n";
	}
}

// Printing nodes in a singly linked list
void SinglyLinkedLists::printList() {
	if (head == nullptr) {
		std::cout << "No nodes can be printed in singly linked list" << "\n";
	}
	// if there is at least one node in a singly linked list
	else {
		std::cout << "Singly Linked List Values: ";
		Node* temp = head;

		// while temp doesnt point the last node
		while (temp != nullptr) {
			std::cout << "( " << temp->key << ", " << temp->data << " )--> ";
			temp = temp->next;
		}
	}
}

int main() {

	SinglyLinkedLists s;
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
		// dynamic memory allocation - heap
		// it provides globally accessing the object
		// in this case, there is a pointer in stack memory pointing to the object address located in heap memory
		Node* n1 = new Node();

		// static memory allocation - stack 
		// Node n2;  

		switch (option)
		{
		case 0:
			break;
		case 1:
			std::cout << "Appending a node, enter a key and data of the node to be appended" << "\n";
			std::cin >> n1->key;
			std::cin >> n1->data;
			s.appendNode(n1);
			break;
		case 2:
			std::cout << "Prepending a node,enter a key and data of the node to be prepended " << "\n";
			std::cin >> n1->key;
			std::cin >> n1->data;
			s.prependNode(n1);
			break;
		case 3:
			std::cout << "Inserting a node, enter the key of existing node after which you want to insert this new node " << "\n";
			std::cin >> k1;
			std::cin >> n1->key;
			std::cin >> n1->data;
			s.insertNodeAfter(k1, n1);
			break;
		case 4:
			std::cout << "Deleting a node, enter a key of the node to be deleted" << "\n";
			std::cin >> k1;
			s.deleteNodeByKey(k1);
			break;
		case 5:
			std::cout << "Updating a node, enter key and new data to be updated";
			std::cout << k1;
			std::cout << data1;
			s.updateNodeByKey(k1, data1);
			break;
		case 6:
			s.printList();
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
