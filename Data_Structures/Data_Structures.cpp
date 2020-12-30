//#define SINGLY_LINKED_LIST_BASIC
//#define SINGLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
//#define DOUBLY_LINKED_LIST_ARRAYS
//#define CIRCULAR_LINKED_LIST

/* Singly Linked List */
#if defined(SINGLY_LINKED_LIST_BASIC) || defined(SINGLY_LINKED_LIST)
	#include "11_Singly_Linked_List.h"
#endif


/* Doubly Linked List */
#if defined(DOUBLY_LINKED_LIST) || defined(DOUBLY_LINKED_LIST_ARRAYS)
	#include "12_Doubly_Linked_List.h"
#endif


/* Circular Linked List */
#if defined(CIRCULAR_LINKED_LIST) 
	#include "13_Circular_Linked_List.h"
#endif


