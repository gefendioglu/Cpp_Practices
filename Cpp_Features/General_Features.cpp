
//#define USER_DEFINED_LITERALS
//#define NON_STATIC_MEMBER_INIT
//#define FORWARD_DECLARATION
//#define INITIALIZER_LIST
//#define FEATURE
//#define VECTOR_CLASS_TEMPLATE
//#define STRING_IMPLEMENTATION

//#define STL_OPTIONAL
//#define STL_OPTIONAL_I
//#define STL_OPTIONAL_II
#define STL_OPTIONAL_III

/* General C++ Features */
// --------------------------------------------

#if defined(USER_DEFINED_LITERALS) || defined(NON_STATIC_MEMBER_INIT) || defined(FORWARD_DECLARATION) || defined(INITIALIZER_LIST) || defined(FEATURE) 
	#include "General_Features.h"
#endif


/* Vector Implementation */
// --------------------------------------------

#if defined(VECTOR_CLASS_TEMPLATE)
	#include "Vector_Implement.h"
#endif


/* String Implementation */
// --------------------------------------------

#if defined(STRING_IMPLEMENTATION)
	#include "String_Implementation.h"
#endif

/* STL Operations */
// --------------------------------------------

#if defined(STL_OPTIONAL) || defined(STL_OPTIONAL_I)  || defined(STL_OPTIONAL_II) || defined(STL_OPTIONAL_III) 
	#include "STL.h"
#endif

