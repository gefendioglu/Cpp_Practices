## Scope Definition 

- Scope Definitions in C:
  - file scope
  - block scope
  - function prototype scope
  - function scope

- Scope Definitions in C++:
  - namespace scope
  - class scope 
  - block scope
  - function prototype scope
  - function scope

/----------------------------------------------
/----------------------------------------------

- **Example** : Scope Definitions in C++

```cpp
int x = 10;       // file scope, global variables
void func(int x); // function prototype scope
void func(double dval) { // function scope
	int y = 20;     // block scope, in func() func scope
}

class MyClass {
	int x;          // class scope
};
```

/----------------------------------------------
/----------------------------------------------
