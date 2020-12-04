#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <array>

// A singly linked list in C++
class IntElement {
public:
	IntElement(const int& value) :next{ nullptr }, data{ value }{}
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

	// operator overloading function

	friend std::ostream& operator<<(std::ostream& os, IntElement* ptr){
		return os << ptr->data << "\n";
	}

private:
	IntElement* next;
	int data;
};

IntElement* IntElement::insertInFront(IntElement** head, int data) {
	IntElement* newElem = new IntElement(data);
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

	//IntElement* elem;

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