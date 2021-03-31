## Const Overloading 

- Because, T* and const T* are different types. The signature of the following function declarations are totally different.  

```cpp
int func(int*);
int func(const int* );

void foo(int&);
void foo(const int&);

int func(int*){}
int func(const int* ){}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Function Overload Resolution in the case of const overloading 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// const overloading - common in standard library 
void func(const int*);
void func(int*);


void foo(const int&);
void foo(int&);

int main() {
	const int x = 20;
	func(&x); // void func(const int*); is called 
	foo(x);   // void foo(const int&); is called 
} 
```

/----------------------------------------------
/----------------------------------------------
