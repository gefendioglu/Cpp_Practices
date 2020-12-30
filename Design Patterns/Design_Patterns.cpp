//#define CREATIONAL_FACTORY
//#define CREATIONAL_ABSTRACT_FACTORY
//#define CREATIONAL_BUILDER
#define CREATIONAL_PROTOTYPE
#define CREATIONAL_SINGLETON


/* Creational Factory Method */
#if defined(CREATIONAL_FACTORY) 
	#include "11_Creational_Factory.h"
#endif

/* Creational Abstract Factory Method */
#if defined(CREATIONAL_ABSTRACT_FACTORY) 
	#include "12_Creational_Abstract_Factory.h"
#endif

/* Creational Builder Method */
#if defined(CREATIONAL_BUILDER) 
	#include "13_Creational_Builder.h"
#endif

/* Creational Prototype Method */
#if defined(CREATIONAL_PROTOTYPE) 
	#include "14_Creational_Prototype.h"
#endif

/* Creational Prototype Factory Method */
#if defined(CREATIONAL_PROTOTYPE_FACTORY) 
	#include "14_Creational_Prototype_Factory.h"
#endif

/* Creational Singleton Method */
#if defined(CREATIONAL_SINGLETON) 
	#include "15_Creational_Singleton.h"
#endif





