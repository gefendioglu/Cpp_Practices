
//#define USER_DEFINED_LITERALS
//#define NON_STATIC_MEMBER_INIT
//#define FORWARD_DECLARATION
//#define VECTOR_CLASS_TEMPLATE
#define STRING_IMPLEMENTATION

// --------------------------------------------

/* General C++ Features */
#if defined(USER_DEFINED_LITERALS) || defined(NON_STATIC_MEMBER_INIT) || defined(FORWARD_DECLARATION) 
	#include "General_Features.h"
#endif

// --------------------------------------------

/* Vector Implementation */
#if defined(VECTOR_CLASS_TEMPLATE)
	#include "Vector_Implement.h"
#endif

// --------------------------------------------

/* String Implementation */
#if defined(STRING_IMPLEMENTATION)
	#include "String_Implementation.h"
#endif

// --------------------------------------------
