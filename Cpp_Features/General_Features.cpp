
//#define USER_DEFINED_LITERALS
//#define NON_STATIC_MEMBER_INIT
//#define FORWARD_DECLARATION
//#define INITIALIZER_LIST
//#define CONSTRUCTOR_INIT_LIST
//#define COPY_CTOR
//#define COPY_CTOR_ADDRESS
//#define USER_DECLARED_COPY_CTOR_ASSIGNMENT
//#define COPY_ASSIGNMENT
//#define VECTOR_CLASS_TEMPLATE
//#define STRING_IMPLEMENTATION

//#define STL_OPTIONAL
//#define STL_OPTIONAL_I
//#define STL_OPTIONAL_II
//#define STL_OPTIONAL_III
//#define STL_OPTIONAL_Example

#define FEATURE

/* General C++ Features */
// --------------------------------------------

#if defined(USER_DEFINED_LITERALS) || defined(NON_STATIC_MEMBER_INIT) || defined(FORWARD_DECLARATION) || defined(INITIALIZER_LIST) || defined(CONSTRUCTOR_INIT_LIST) || defined(COPY_CTOR) || defined(COPY_CTOR_ADDRESS) || defined(USER_DECLARED_COPY_CTOR_ASSIGNMENT) || defined(COPY_ASSIGNMENT) || defined(FEATURE)
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

#if defined(STL_OPTIONAL) || defined(STL_OPTIONAL_I)  || defined(STL_OPTIONAL_II) || defined(STL_OPTIONAL_III) || defined(STL_OPTIONAL_Example) 
	#include "STL.h"
#endif

