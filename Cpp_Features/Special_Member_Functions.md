## SPECIAL MEMBER FUNCTIONS

- Compiler writes these default functions (to default (generate, synthesize) a special member function)

- The types of special member functions:
  - default constructor
  - copy constructor
  - copy assignment function 
  - move constructor  (added with C++11)
  - move assignment function  (added with C++11)
  - destructor

- Only special member functions can be defaulted using "default" keyword

- The declaration types of special member functions: 
  - not-declared 
  - user declared 
    - defined by user
      - defaulted by user with "default" keyword
      - deleted by user with "delete" keyword
  - implicitly declared 
    - defaulted by compiler 
    - deleted by compiler 

- The important rule for **implicitly declared and deleted by compiler**: If the compiler writes the special member function of a class according to the rules of the language (implicitly declared & defulted by compiler) and violates the rules of the language at the same time, the compiler will not throw a syntax error. Instead, it deletes the function.

/----------------------------------------------
/----------------------------------------------

- **Example** : Implicitly declared and deleted by compiler

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Data {
public:
	// no default ctor for Data class
	Data(int);
};

class Info {
private:
	// default ctor is defaulted, but in private access modifier
	Info();
};

class Member {
public:

private:
	Data data;
	Info info;
};

int main() {

	Member member; // ERROR, because Member() = delete; implicitly
		       // the default ctor of "Member" can not be referenced
		       // it is a deleted function 
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : not-declared default ctor 

```cpp
class Data {
public:
	Data(int) {} // Default ctor is not-declared
	~Data() = default; 
private:
	int counter = 0; 
};

int main() {
	Data data;       // ERROR, no default ctor
	Data data{ 10 }; // NOT ERROR,	Data(int) {}
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : user declared 

```cpp
class Data {
public:
	Data();   // user declared, not defined
	Data() {} // user declared, defined
	Data() = default; // user declared, defaulted
	Data() = delete;  // user declared, deleted
private:
	int counter = 0; 
};
```

/----------------------------------------------
/----------------------------------------------

- **Example** : implicitly declared, deleted default ctor
 
```cpp
class Data {
public:
	Data(int); 
private:
	int counter = 0; 
};

// Member class default ctor is deleted by compiler
// implicitly declared, deleted
class Member {
private:
	Data mx;
};

int main() {
	Member member; // ERROR
		             // Attempting to reference a deleted function
}
```
/----------------------------------------------
/----------------------------------------------
