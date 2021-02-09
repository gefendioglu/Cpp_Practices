
//#define REVERSE_STRING
//#define SINGLY_LINKED_LIST_BASIC
//#define SINGLY_LINKED_LIST
//#define DOUBLY_LINKED_LIST
//#define DOUBLY_LINKED_LIST_ARRAYS
//#define CIRCULAR_LINKED_LIST
//#define STACK
//#define STACK_LINKED_LIST
//#define STACK_TEMPLATES_ARRAYS
//#define BINARY_SEARCH_TREE
//#define HEAP
//#define QUEUE
#define QUEUE_ARRAYS
//#define QUEUE_LINKED_LIST
//#define CIRCULAR_QUEUE


/* Strings*/
#if defined(REVERSE_STRING)
	#include "00_Strings.h"
#endif


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

/* Stack */
#if defined(STACK) || defined(STACK_LINKED_LIST) || defined(STACK_TEMPLATES_ARRAYS)
#include "14_Stack.h"
#endif

/* Binary Tree */
#if defined(BINARY_SEARCH_TREE)
#include "21_Binary_Tree.h"
#endif

/* Heap */
#if defined(HEAP)
#include "22_Heap.h"
#endif

/* Queue */
#if defined(QUEUE) || defined(QUEUE_ARRAYS) || defined(QUEUE_LINKED_LIST) 
#include "31_Queue.h"
#endif

/* Circular Queue */
#if defined(CIRCULAR_QUEUE)
#include "32_Circular_Queue.h"
#endif

