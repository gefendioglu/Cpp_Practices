## LINKED LISTS

- Three basic kinds of linked lists exist: 
  - Singly linked lists
  - Doubly linked lists 
  - Circular linked lists 

## Singly Linked Lists
- Each data element in the list has a link (a pointer or reference) to the element that follows it in the list. 
- The first element in a singly linked list is referred to as the "head" of the list. 
- The last element in such a list is called the "tail".
- When defining classes in C++ for singly linked list, particularly in template form, it’s best to add copy constructors and copy assignment operators so you don’t depend on the compiler- generated versions.

**Note**: The class IntElement is a linked list class defined by user and all definitions are at the end of this section

/----------------------------------------------
/----------------------------------------------

- **Example**: Tracking the Head Element (Inserting an element at the front of a list)
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
```

```cpp
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

- **Example**: Traversing a List
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

- **Example**: Inserting and Deleting Elements
  - Any insertion or deletion of elements in the middle of a list requires modification of the previous element’s next pointer or reference.
  - If you’re given only the element to delete (or before which to insert), this requires traversal of the list from the head because there’s no other way to find the preceding element. 
  - Special care must be taken when the element to be deleted is the head of the list.
  - Deletion and insertion require a pointer or reference to the element immediately preceding the deletion or insertion location. 

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
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Singly Linked List Implementation (not using templates) - Client Code shall be written !!!
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

	//operator overloading function ???
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

- **Example** : Stack Implementation (TO BE COMPLETED)
  - The createStack function sets the stack pointer to NULL and returns success
  - The push function allocates the new element, checks for failure, sets the data of the new element, places it at the top of the stack, and adjusts the stack pointer.
  - The pop operation checks that the stack isn’t empty, fetches the data from the top element, adjusts the stack pointer, and frees the element that is no longer on the stack. 
  - Although deleteStack could call pop repeatedly, it’s more efficient to simply traverse the data structure, freeing as you go. Don’t forget that you need a temporary pointer to hold the address of the next element while you free the current one.
  - The createStack and deleteStack functions become the constructor and destructor, respectively.
  - A more complete C++ implementation should include a copy constructor and assignment operator, because the default versions created by the compiler could lead to multiple deletes of the same Element due to inadvertent sharing of elements between copies of a Stack.


/----------------------------------------------
/----------------------------------------------
