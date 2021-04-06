

/* FUNCTION OVERLOADING */
// --------------------------------------------
//#define FUNCTION_OVERLOADING


/* OPERATOR OVERLOADING */
// --------------------------------------------
//#define OPERATOR_OVERLOADING
//#define OPERATOR_OVERLOADING_II
#define OPERATOR_OVERLOADING_III
//#define OPERATOR_OVERLOADING_IV


/* CLASS DEFINITIONS */
// --------------------------------------------
//#define CLASSES
//#define STATIC_MEMBERS


/* INHERITANCE */
// --------------------------------------------
//#define INHERITANCE_I
//#define MULTIPLE_INHERITANCE_I
//#define MULTIPLE_INHERITANCE_II
//#define DIAMOND_PROBLEM
//#define DIAMOND_PROBLEM_II
//#define MULTILEVEL_INHERITANCE
//#define INHERITANCE_EXAMPLE_I
//#define INHERITANCE_EXAMPLE_II


/* SMART pointer */
// --------------------------------------------
//#define SMART_POINTER
//#define SMART_POINTER_UNIQUE
//#define SMART_POINTER_SHARED
//#define SMART_POINTER_WEAK


/* TEMPLATES */
// --------------------------------------------
//#define FUNCTION_TEMPLATES
//#define FUNCTION_TEMPLATES_BUBBLE_SORT
//#define CLASS_TEMPLATES_BUBBLE_SORT
//#define CLASS_TEMPLATES_ARRAY_CLASS
//#define CLASS_TEMPLATES_MULTIPLE_ARG_I
//#define CLASS_TEMPLATES_MULTIPLE_ARG_II
//#define CLASS_TEMPLATES_DEFAULT_VALUE
//#define CLASS_TEMPLATES_NONTYPE_PARAMETERS
//#define TEMPLATES_METAPROGRAMMING
//#define FUNCTION_TEMPLATES_STATIC_VARIABLES
//#define CLASS_TEMPLATES_STATIC_VARIABLES
//#define CLASS_TEMPLATES_SPECIALIZATION
//#define VARIADIC_FUNCTION_TEMPLATES


/* COPY & MOVE OPERATIONS */
// --------------------------------------------
//#define COPY_CTOR
//#define COPY_CTOR_ADDRESS
//#define COPY_ASSIGNMENT
//#define MOVE_CTOR_ASSIGNMENT
//#define COPY_MOVE_OPERATIONS


/* VIRTUAL CTOR && DTOR */
// --------------------------------------------
//#define VIRTUAL_COPY_CTOR
//#define VIRTUAL_DESTRUCTOR
//#define VIRTUAL_CONSTRUCTOR
//#define PURE_VIRTUAL_DESTRUCTOR
//#define CONSTRUCTORS_VIRTUAL_BASES


/* VIRTUAL FUNCTIONS */
// --------------------------------------------
//#define VIRTUAL_FUNCTIONS_DERIVED_CLASSES
//#define PRIVATE_VIRTUAL_FUNCTIONS
//#define VIRTUAL_FUNCTIONS_CONSTRUCTORS
//#define VIRTUAL_FUNCTIONS_DEFAULT_ARG
//#define VIRTUAL_pointer
//#define VIRTUAL_FUNCTIONS_I
//#define VIRTUAL_FUNCTIONS_II
//#define VIRTUAL_NONVIRTUAL_FUNCTIONS
//#define VIRTUAL_INLINE_FUNCTIONS
//#define VIRTUAL_FUNCTIONS_COMPOSITION
//#define VIRTUAL_FUNCTIONS_MULTIPLE_INHERITANCE


/* Function Overloading */
#if defined(FUNCTION_OVERLOADING) 
	#include "27_Function_Overloading.h"
#endif

// --------------------------------------------

/* Operator Overloading */
#if defined(OPERATOR_OVERLOADING) || defined(OPERATOR_OVERLOADING_II)  || defined(OPERATOR_OVERLOADING_III) || defined(OPERATOR_OVERLOADING_IV) 
#include "29_Operator_Overloading.h"
#endif

// --------------------------------------------

/* Classes */
#if defined(CLASSES) || defined(STATIC_MEMBERS) 
	#include "25_Classes.h"
#endif

// --------------------------------------------

/* Inheritance */
#if defined(INHERITANCE_I) || defined(MULTIPLE_INHERITANCE_I) || defined(MULTIPLE_INHERITANCE_II) || defined(DIAMOND_PROBLEM) || defined(DIAMOND_PROBLEM_II) || defined(MULTILEVEL_INHERITANCE) || defined(INHERITANCE_EXAMPLE_I) || defined(INHERITANCE_EXAMPLE_II)
	#include "28_Inheritance.h"
#endif

// --------------------------------------------

/* Smart Pointers */
#if defined(SMART_POINTER) || defined(SMART_POINTER_UNIQUE) || defined(SMART_POINTER_WEAK)
	#include "30_Smart_Pointers.h"
#endif

// --------------------------------------------

/* Templates */
#if defined(FUNCTION_TEMPLATES) || defined(FUNCTION_TEMPLATES_BUBBLE_SORT) || defined(CLASS_TEMPLATES_BUBBLE_SORT) || defined(CLASS_TEMPLATES_ARRAY_CLASS) || defined(CLASS_TEMPLATES_MULTIPLE_ARG_I) || defined(CLASS_TEMPLATES_MULTIPLE_ARG_II) || defined(CLASS_TEMPLATES_DEFAULT_VALUE) || defined(CLASS_TEMPLATES_NONTYPE_PARAMETERS) || defined(TEMPLATES_METAPROGRAMMING) || defined(FUNCTION_TEMPLATES_STATIC_VARIABLES) || defined(CLASS_TEMPLATES_STATIC_VARIABLES) || defined(CLASS_TEMPLATES_SPECIALIZATION) || defined(VARIADIC_FUNCTION_TEMPLATES)
	#include "31_Templates.h"
#endif

// --------------------------------------------


/* Copy & Move Operations */
#if defined(COPY_CTOR) || defined(COPY_CTOR_ADDRESS) || defined(COPY_MOVE_OPERATIONS) || defined(COPY_ASSIGNMENT) || defined(MOVE_CTOR_ASSIGNMENT) 
#include "38_Copy_Move_Func.h"
#endif

// --------------------------------------------


/* Virtual Copy Constructors */
#if defined(VIRTUAL_COPY_CTOR) 
	#include "Virtual_Copy_Ctor.h"
#endif

// --------------------------------------------

/* Virtual Constructors && Destructors */
#if defined(VIRTUAL_DESTRUCTOR)  || defined(VIRTUAL_CONSTRUCTOR) || defined(PURE_VIRTUAL_DESTRUCTOR) || defined(CONSTRUCTORS_VIRTUAL_BASES)
	#include "Virtual_Dtor_Ctor.h"
#endif


// --------------------------------------------

/* Virtual Functions */
#if defined(VIRTUAL_FUNCTIONS_DERIVED_CLASSES)  || defined(PRIVATE_VIRTUAL_FUNCTIONS) || defined(VIRTUAL_FUNCTIONS_CONSTRUCTORS) || defined(VIRTUAL_FUNCTIONS_DEFAULT_ARG) || defined(VIRTUAL_pointer) || defined(VIRTUAL_FUNCTIONS) || defined(VIRTUAL_NONVIRTUAL_FUNCTIONS) || defined(VIRTUAL_INLINE_FUNCTIONS) || defined(VIRTUAL_FUNCTIONS_II) || defined(VIRTUAL_FUNCTIONS_COMPOSITION) || defined(VIRTUAL_FUNCTIONS_MULTIPLE_INHERITANCE)
	#include "Virtual_Functions.h"
#endif

// --------------------------------------------









