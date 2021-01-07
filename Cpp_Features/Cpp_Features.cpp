
//#define FUNCTION_OVERLOADING
//#define CLASSES
//#define INHERITANCE_I
//#define MULTIPLE_INHERITANCE_I
//#define MULTIPLE_INHERITANCE_II
//#define DIAMOND_PROBLEM
//#define MULTILEVEL_INHERITANCE
//#define INHERITANCE_EXAMPLE_I
//#define INHERITANCE_EXAMPLE_II
//#define SMART_POINTERS
//#define SMART_POINTERS_UNIQUE
//#define SMART_POINTERS_SHARED
#define SMART_POINTERS_WEAK
#define FUNCTION_TEMPLATES
#define FUNCTION_TEMPLATES_BUBBLE_SORT
#define CLASS_TEMPLATES_BUBBLE_SORT
#define CLASS_TEMPLATES_ARRAY_CLASS
#define CLASS_TEMPLATES_MULTIPLE_ARG_I
#define CLASS_TEMPLATES_MULTIPLE_ARG_II
#define CLASS_TEMPLATES_DEFAULT_VALUE
#define CLASS_TEMPLATES_NONTYPE_PARAMETERS
#define TEMPLATES_METAPROGRAMMING
#define FUNCTION_TEMPLATES_STATIC_VARIABLES
#define CLASS_TEMPLATES_STATIC_VARIABLES


// --------------------------------------------

/* Function Overloading */
#if defined(FUNCTION_OVERLOADING) 
	#include "27_Function_Overloading.h"
#endif

// --------------------------------------------

/* Classes */
#if defined(CLASSES) 
	#include "25_Classes.h"
#endif

// --------------------------------------------

/* Inheritance */
#if defined(INHERITANCE_I) || defined(MULTIPLE_INHERITANCE_I) || defined(MULTIPLE_INHERITANCE_II) || defined(DIAMOND_PROBLEM) || defined(MULTILEVEL_INHERITANCE) || defined(INHERITANCE_EXAMPLE_I) || defined(INHERITANCE_EXAMPLE_II)
	#include "28_Inheritance.h"
#endif

// --------------------------------------------

/* Smart Pointers */
#if defined(SMART_POINTERS) || defined(SMART_POINTERS_UNIQUE) || defined(SMART_POINTERS_WEAK)
	#include "30_Smart_Pointers.h"
#endif

// --------------------------------------------

/* Templates */
#if defined(FUNCTION_TEMPLATES) || defined(FUNCTION_TEMPLATES_BUBBLE_SORT) || defined(CLASS_TEMPLATES_BUBBLE_SORT) || defined(CLASS_TEMPLATES_ARRAY_CLASS) || defined(CLASS_TEMPLATES_MULTIPLE_ARG_I) || defined(CLASS_TEMPLATES_MULTIPLE_ARG_II) || defined(CLASS_TEMPLATES_DEFAULT_VALUE) || defined(CLASS_TEMPLATES_NONTYPE_PARAMETERS) || defined(TEMPLATES_METAPROGRAMMING) || defined(FUNCTION_TEMPLATES_STATIC_VARIABLES) || defined(CLASS_TEMPLATES_STATIC_VARIABLES)
	#include "31_Templates.h"
#endif

// --------------------------------------------

