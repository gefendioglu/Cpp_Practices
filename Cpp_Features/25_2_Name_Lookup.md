## Name Lookup

- The results of name lookup in C++:
  - syntax error 
    - compiler can not find any definitions related to the name)
	  - compiler can find more than one definitions related to the name (ambiguity error)
    - compiler can understand what the name is

- Name lookup rules in C+:
  - name lookup is ended after finding the name, not started again
  - name hiding (name masking, name shadowing)
  - The order of controls in C++: 
    - name lookup
	  - context control (R-Value, L-Value expression assignment error)
	  - access control (using access specifiers: public, private, protected)

/----------------------------------------------
/----------------------------------------------

- **Example** : Name Lookup Sample (name hiding)

```cpp
int main() {

	int printf = 0;
	printf("gamze"); // name lookup error, cause printf name is found in the same function scope

}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Name Lookup Sample (name hiding)
- 
```cpp
int func(int);

int main() {
	int func = 0;
	func(12); // name lookup error, func name is found
	func++;   // not a syntax error
}
```

/----------------------------------------------
/----------------------------------------------

### When is a name searched in Class Scope?
- The name is in the right operand wrt. dot operator (member selection operator)
- The name is in the right operand wrt. arrow operator (member selection operator)
- The name is in the right operand wrt. scope resolution operator (::)
  - Namespace::right_operand OR ClassName::right_operand

/----------------------------------------------
/----------------------------------------------
