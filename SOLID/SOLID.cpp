//#define SINGLE_RESPONSIBILITY
//#define BEFORE_OPEN_CLOSED_I
//#define AFTER_OPEN_CLOSED_I
//#define BEFORE_LISKOV_SUBSTITUTION_I
//#define AFTER_LISKOV_SUBSTITUTION_I
//#define INTERFACE_SEGREGATION_I
#define DEPENDENCY_INVERSION

/* SOLID PRINCIPLES */
// ----------------------------------------------
// ----------------------------------------------

/* Single Responsibility Principle */
#if defined(SINGLE_RESPONSIBILITY)
	#include "1_Single_Responsibility.h"
#endif

/* Open - Closed Principle */
#if defined(BEFORE_OPEN_CLOSED_I) || defined(AFTER_OPEN_CLOSED_I)
	#include "2_Open_Closed.h"
#endif

/* Liskov Substitution Principle */
#if defined(BEFORE_LISKOV_SUBSTITUTION_I) || defined(AFTER_LISKOV_SUBSTITUTION_I)
	#include "3_Liskov_Substitution.h"
#endif

/* Interface Segregation Principle */
#if defined(INTERFACE_SEGREGATION_I)
	#include "4_Interface_Segregation.h"
#endif

/* Dependency Inversion Principle */
#if defined(DEPENDENCY_INVERSION)
	#include "5_Dependency_Inversion.h"
#endif