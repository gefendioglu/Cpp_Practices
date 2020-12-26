//#define SELECTION_SORT_1
//#define INSERTION_SORT_1
//#define BINARY_INSERTION_SORT
//#define OUICK_SORT_1
//#define THREE_WAY_QUICK_SORT
//#define QUICK_SORT_SINGLY_LINKED_LIST
//#define QUICK_SORT_DOUBLY_LINKED_LIST
//#define ITERATIVE_QUICK_SORT
//#define MERGE_SORT_RECURSIVE
//#define MERGE_SORT_SINGLY_LINKED_LIST
//#define MERGE_SORT_DOUBLY_LINKED_LIST
//#define BUBBLE_SORT
//#define OPTIMIZED_BUBBLE_SORT
#define HEAP_SORT

/* Selection Sort Algorithm */
#ifdef SELECTION_SORT_1
	#include "11_Selection_Sort.h"
#endif


/* Insertion Sort Algorithm */
#if defined(INSERTION_SORT_1) || defined(BINARY_INSERTION_SORT)
	#include "21_Insertion_Sort.h"
#endif


/* Quick Sort Algorithm */
#if defined(OUICK_SORT_1) || defined(THREE_WAY_QUICK_SORT) || defined(QUICK_SORT_SINGLY_LINKED_LIST) || defined(QUICK_SORT_DOUBLY_LINKED_LIST) || defined(ITERATIVE_QUICK_SORT)
	#include "31_Quick_Sort.h"
#endif


/* Merge Sort Algorithm */
#if defined(MERGE_SORT_RECURSIVE) || defined(MERGE_SORT_SINGLY_LINKED_LIST) || defined(MERGE_SORT_DOUBLY_LINKED_LIST)
	#include "41_Merge_Sort.h"
#endif


/* Bubble Sort Algorithm */
#if defined(BUBBLE_SORT) || defined(OPTIMIZED_BUBBLE_SORT)
	#include "51_Bubble_Sort.h"
#endif 


/* Heap Sort Algorithm */
#if defined(HEAP_SORT) 
	#include "61_Heap_Sort.h"
#endif 
