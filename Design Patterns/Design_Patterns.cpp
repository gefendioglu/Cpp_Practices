//#define CREATIONAL_FACTORY
//#define CREATIONAL_FACTORY_I
//#define CREATIONAL_FACTORY_II
//#define CREATIONAL_ABSTRACT_FACTORY_PROBLEM
//#define CREATIONAL_ABSTRACT_FACTORY
//#define CREATIONAL_FUNCTIONAL_FACTORY
//#define CREATIONAL_BUILDER
//#define CREATIONAL_BUILDER_I
//#define CREATIONAL_PROTOTYPE_I
//#define CREATIONAL_PROTOTYPE_II
//#define CREATIONAL_PROTOTYPE_III
//#define CREATIONAL_PROTOTYPE_FACTORY
#define CREATIONAL_SINGLETON
// ----------------------------------------------
// ----------------------------------------------
//#define BEHAVIORAL_CHAIN_OF_RESPONSIBILIY
//#define BEHAVIORAL_COMMAND_EXAMPLE_I
//#define BEHAVIORAL_COMMAND_EXAMPLE_II
//#define BEHAVIORAL_ITERATOR
//#define BEHAVIORAL_INTERPRETER
//#define BEHAVIORAL_MEDIATOR
//#define BEHAVIORAL_MEMENTO
//#define BEHAVIORAL_OBSERVER
//#define BEHAVIORAL_VISITOR
//#define BEHAVIORAL_STATE
//#define BEHAVIORAL_STRATEGY_EXAMPLE_I
//#define BEHAVIORAL_STRATEGY_EXAMPLE_II
//#define BEHAVIORAL_TEMPLATE
// ----------------------------------------------
// ----------------------------------------------
//#define STRUCTURAL_ADAPTER_CLASSICAL
//#define STRUCTURAL_ADAPTER_PLUGGIN_I
//#define STRUCTURAL_ADAPTER_PLUGGIN_II
//#define STRUCTURAL_BRIDGE_I
//#define STRUCTURAL_BRIDGE_II
//#define STRUCTURAL_COMPOSITE_I
//#define STRUCTURAL_COMPOSITE_II
//#define STRUCTURAL_COMPOSITE_III
//#define STRUCTURAL_DECORATOR_I
//#define STRUCTURAL_DECORATOR_II
//#define STRUCTURAL_FACADE_I
//#define STRUCTURAL_FLIGHTWEIGHT_I
//#define STRUCTURAL_PROXY_I
//#define STRUCTURAL_PROXY_VIRTUAL
//#define STRUCTURAL_PROXY_COMMUNICATION



/* CREATIONAL TYPE DESIGN PATTERNS */
// ----------------------------------------------
// ----------------------------------------------

/* Creational Factory Design Pattern */
#if defined(CREATIONAL_FACTORY) || defined(CREATIONAL_FACTORY_I) || defined(CREATIONAL_FACTORY_II)
	#include "11_Creational_Factory.h"
#endif

// ----------------------------------------------
// ----------------------------------------------

/* Creational Abstract Factory Design Pattern */
#if defined(CREATIONAL_ABSTRACT_FACTORY_PROBLEM) || defined(CREATIONAL_ABSTRACT_FACTORY) || defined(CREATIONAL_FUNCTIONAL_FACTORY)
	#include "12_Creational_Abstract_Factory.h"
#endif

// ----------------------------------------------
// ----------------------------------------------

/* Creational Builder Desing Pattern */
#if defined(CREATIONAL_BUILDER) || defined(CREATIONAL_BUILDER_I)
	#include "13_Creational_Builder.h"
#endif

// ----------------------------------------------
// ----------------------------------------------

/* Creational Prototype Design Pattern */
#if defined(CREATIONAL_PROTOTYPE_I) || defined(CREATIONAL_PROTOTYPE_II) || defined(CREATIONAL_PROTOTYPE_III)
	#include "14_Creational_Prototype.h"
#endif

// ----------------------------------------------
// ----------------------------------------------

/* Creational Prototype Factory Desing Pattern */
#if defined(CREATIONAL_PROTOTYPE_FACTORY) 
	#include "14_Creational_Prototype_Factory.h"
#endif

// ----------------------------------------------
// ----------------------------------------------

/* Creational Singleton Design Pattern */
#if defined(CREATIONAL_SINGLETON) 
	#include "15_Creational_Singleton.h"
#endif

/* BEHAVIORAL TYPE DESIGN PATTERNS */
// ----------------------------------------------
// ----------------------------------------------

/* Behavioral Chain Of Responsibility Design Pattern */
#if defined(BEHAVIORAL_CHAIN_OF_RESPONSIBILITY) 
	#include "21_Behavioral_Chain_of_Responsibility.h"
#endif

/* Behavioral Command Design Pattern */
#if defined(BEHAVIORAL_COMMAND_EXAMPLE_I) || defined(BEHAVIORAL_COMMAND_EXAMPLE_II)
	#include "22_Behavioral_Command.h"
#endif

/* Behavioral Iterator Design Pattern */
#if defined(BEHAVIORAL_ITERATOR) 
	#include "23_Behavioral_Iterator.h"
#endif

/* Behavioral Interpreter Design Pattern */
#if defined(BEHAVIORAL_INTERPRETER) 
	#include "24_Behavioral_Interpreter.h"
#endif

/* Behavioral Mediator Design Pattern */
#if defined(BEHAVIORAL_MEDIATOR) 
	#include "25_Behavioral_Mediator.h"
#endif

/* Behavioral Memento Design Pattern */
#if defined(BEHAVIORAL_MEMENTO) 
	#include "26_Behavioral_Memento.h"
#endif

/* Behavioral Observer Design Pattern */
#if defined(BEHAVIORAL_OBSERVER) 
	#include "27_Behavioral_Observer.h"
#endif

/* Behavioral Visitor Design Pattern */
#if defined(BEHAVIORAL_VISITOR) 
	#include "28_Behavioral_Visitor.h"
#endif

/* Behavioral State Design Pattern */
#if defined(BEHAVIORAL_STATE) 
	#include "29_Behavioral_State.h"
#endif

/* Behavioral Strategy Design Pattern */
#if defined(BEHAVIORAL_STRATEGY_EXAMPLE_I) || defined(BEHAVIORAL_STRATEGY_EXAMPLE_II)
	#include "29_Behavioral_Strategy.h"
#endif

/* Behavioral Template Design Pattern */
#if defined(BEHAVIORAL_TEMPLATE) 
	#include "29_Behavioral_Template.h"
#endif


/* STRUCTURAL TYPE DESIGN PATTERNS */
// ----------------------------------------------
// ----------------------------------------------

/* Structural Adapter Design Pattern */
#if defined(STRUCTURAL_ADAPTER_CLASSICAL) || defined(STRUCTURAL_ADAPTER_PLUGGIN_I) || defined(STRUCTURAL_ADAPTER_PLUGGIN_II)
	#include "30_Structural_Adapter.h"
#endif

/* Structural Bridge Design Pattern */
#if defined(STRUCTURAL_BRIDGE_I) || defined(STRUCTURAL_BRIDGE_II) 
	#include "31_Structural_Bridge.h"
#endif

/* Structural Composite Design Pattern */
#if defined(STRUCTURAL_COMPOSITE_I) || defined(STRUCTURAL_COMPOSITE_II) || defined(STRUCTURAL_COMPOSITE_III) 
	#include "32_Structural_Composite.h"
#endif

/* Structural Decorator Design Pattern */
#if defined(STRUCTURAL_DECORATOR_I) || defined(STRUCTURAL_DECORATOR_II)  
	#include "33_Structural_Decorator.h"
#endif

/* Structural Facade Design Pattern */
#if defined(STRUCTURAL_FACADE_I) 
	#include "34_Structural_Facade.h"
#endif

/* Structural Flightweight Design Pattern */
#if defined(STRUCTURAL_FLIGHTWEIGHT_I) 
	#include "35_Structural_Flyweight.h"
#endif


/* Structural Proxy Design Pattern */
#if defined(STRUCTURAL_PROXY_I) || defined(STRUCTURAL_PROXY_VIRTUAL) || defined(STRUCTURAL_PROXY_COMMUNICATION) 
#include "36_Structural_Proxy.h"
#endif