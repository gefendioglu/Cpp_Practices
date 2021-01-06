
#define SEQUENCE_ARRAY
#define SEQUENCE_VECTOR_ITERATORS
#define SEQUENCE_VECTOR_CAPACITY
#define SEQUENCE_VECTOR_ACCESS
#define SEQUENCE_VECTOR_MODIFIERS

/* Sequence Array */
#if defined(SEQUENCE_ARRAY) 
	#include "11_Sequence_Array.h"
#endif

/* Sequence Vector */
#if defined(SEQUENCE_VECTOR_ITERATORS) || defined(SEQUENCE_VECTOR_CAPACITY) || defined(SEQUENCE_VECTOR_ACCESS) || defined(SEQUENCE_VECTOR_MODIFIERS)
	#include "12_Sequence_Vector.h"
#endif