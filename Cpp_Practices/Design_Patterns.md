## DESIGN PATTERNS

- Design patterns are guidelines for identifying and solving common design problems in object-oriented programming.
- There are 23 fundamental design patterns. These patterns are grouped into three basic categories: creational, behavioral, and structural.
- The main reason is that they provide best practices solutions to common software design problems based on the collected wisdom of many programmers.
- The second reason is that design patterns provide a concise vocabulary for discussing design problems and their solutions. 
- The wrong design pattern can add unnecessary complexity to an application, and an incorrect or inefficient implementation of a pattern can introduce bugs or compromise performance.
- Some work has also been done to identify patterns that should not be used. These “anti-patterns” are common pitfalls or improper practices that lead to inefficient, ineffective, difficult-to-understand, or difficult-to-maintain code.

/----------------------------------------------
/----------------------------------------------

## Singleton Pattern

- The Singleton pattern ensures that at most one instance of a class exists at any given time.
- An application cannot create new instances—all methods are accessed through the singleton. The application obtains the singleton by invoking a “static function” exposed by the class.
- Singletons are also sometimes used as a substitute for global variables. Many people consider using singletons to store global data as an anti-pattern.
- Why is a singleton better than a set of static methods?
  - Inheritance and interfaces. Singletons are objects. They can inherit from base classes and implement interfaces.
  - Possible multiplicity. You can change your mind and create multiple objects (for example, one per thread) without changing a lot of code.
  - Dynamic binding. The actual class used to create the singleton can be determined at run time, not at compile time.
- The disadvantages of implementing singleton design pattern? 
  - A singleton may slow the application’s startup time as it initializes
  - It may hold onto resources longer than necessary, because normally a singleton isn’t destroyed until the application ends.

- **Example** : Singleton Pattern 
  - Using a logging class to write debugging messages to the console. 
  - How would you implement this logging facility using the Singleton pattern?


/----------------------------------------------
/----------------------------------------------
