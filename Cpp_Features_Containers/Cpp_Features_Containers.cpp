
//#define ARRAY
//#define VECTOR_ITERATORS
//#define VECTOR_CAPACITY
//#define VECTOR_ACCESS
//#define VECTOR_MODIFIERS
//#define DEQUE
//#define FORWARD_LIST
//#define LIST
//#define SET
//#define MAP
//#define MAP_FIND
//#define MAP_LOWER_BOUND
//#define MAP_UPPER_BOUND
//#define MAP_EQUAL_RANGE
//#define MULTISET
//#define MULTIMAP
//#define UNORDERED_SET
//#define UNORDERED_MAP_I
//#define UNORDERED_MAP_II
//#define UNORDERED_MAP_III
//#define UNORDERED_MULTISET_I
//#define UNORDERED_MULTIMAP_I
//#define TUPLE 
#define STRING_REVERSE_WORDS_I
#define STRING_REVERSE_WORDS_II

/* Array */
#if defined(ARRAY) 
	#include "11_Array.h"
#endif

/* Vector */
#if defined(VECTOR_ITERATORS) || defined(VECTOR_CAPACITY) || defined(VECTOR_ACCESS) || defined(VECTOR_MODIFIERS)
	#include "12_Vector.h"
#endif

/* Deque */
#if defined(DEQUE) 
	#include "13_Deque.h"
#endif

/* Forward List */
#if defined(FORWARD_LIST) 
	#include "14_Forward_List.h"
#endif

/* List */
#if defined(LIST) 
	#include "15_List.h"
#endif

/* Set */
#if defined(SET) 
	#include "21_Set.h"
#endif

/* Map */
#if defined(MAP) || defined(MAP_FIND) || defined(MAP_LOWER_BOUND) || defined(MAP_UPPER_BOUND) || defined(MAP_EQUAL_RANGE)
	#include "22_Map.h"
#endif

/* MultiSet */
#if defined(MULTISET) 
	#include "23_MultiSet.h"
#endif

/* MultiMap */
#if defined(MULTIMAP) 
	#include "24_Multimap.h"
#endif

/* MultiMap */
#if defined(MULTIMAP) 
	#include "24_Multimap.h"
#endif

/* Unordered Set */
#if defined(UNORDERED_SET) 
	#include "31_Unordered_Set.h"
#endif

/* Unordered Map */
#if defined(UNORDERED_MAP_I) || defined(UNORDERED_MAP_II) || defined(UNORDERED_MAP_III)
	#include "32_Unordered_Map.h"
#endif

/* Unordered MultiSet */
#if defined(UNORDERED_MULTISET_I) 
	#include "33_Undordered_Multiset.h"
#endif

/* Unordered MultiMap */
#if defined(UNORDERED_MULTIMAP_I) 
	#include "34_Unordered_Multimap.h"
#endif

/* Tuple */
#if defined(TUPLE) 
#include "41_Tuple.h"
#endif

/* String */
#if defined(STRING_REVERSE_WORDS_I) || defined(STRING_REVERSE_WORDS_II) 
	#include "51_String.h"
#endif