
## REFERENCE TYPES

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of reference value sample 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void func(int& ra, const int& rb){
	std::cout << "rb : " << rb << "\n"; // rb : 0
	ra = 1; // ra, rb --> ival --> rb = 1
	std::cout << "rb : " << rb << "\n"; // rb : 1
}

int main(){

	int ival = 0;
	func(ival, ival); // ra --> ival, rb --> ival
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of reference value sample 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int foo(int& x, int& y){

	x = 3; // x = y = 3;
	y = 4; // y = x = 4;
	return x + y; // x+y = 4+4 = 8 --> return value : 8
}

int main(){

	int x = 1; 
	int y = 2; 
	int z = foo(x, x); // x --> x, y --> x; z = 8

	std::cout << "x : " << x << "\n"; // x : 4
	std::cout << "y : " << y << "\n"; // y : 2
	std::cout << "y : " << z << "\n"; // z : 8 
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The usage of reference value sample

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(){

	int x{ 1 }, y{ };
	
	// y++ -- > R - Value expr. and is not assigned r1 ref.
	// it is assigned a temporary object
	const int& r1 = x > 0 ? x : y++; 
	
	// ++y -- > L - Value expr.and is assigned r2 ref.
	// x > 0 ? x : ++y -- > L - Value expr. and r2 ref to x 
	const int& r2 = x > 0 ? x : ++y;
	
	x = 5;
	std::cout << "r1 : "  << r1 << "\n"; // r1 : 1
	std::cout << "r2 : "  << r2 << "\n"; // r2 : 5 
  
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : A sample for the usage of auto keyword with references 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// The return value is the object value  
int& func(int& r) {
	++r;
	return r;
}

int main(){

	int x = 10;
	auto f = func; // int &(*f)(int &) = func; function pointer
	auto y = f(x);  // x : 11, y : 11, y is not ref.
	auto& r = f(x); // x : 12, r : 12, r is ref for x
	r += 400; // r = 12+400 = 412 --> x : 212
	y += 50;  // y = 11+50 = 61 

	std::cout << "x : " << x << "\n"; // x : 412
	std::cout << "y : " << y << "\n"; // y : 61

}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : A sample for the usage of auto keyword with references 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(){

	int x = 10;
	int* ptr = &x;

	auto r1 = x;     // r1 is not ref for x, int r1 = 10;
	auto r2 = *ptr;  // r2 is not ref. for ptr, int r2 = *ptr; 
	auto r3 = r2;    // r3 is not ref for r2, int r3 = r2= *ptr; 
	auto& r4 = ptr;  // r4 is a ref for ptr, int *(&r4) = ptr;
	auto& r5 = *ptr; // r5 is a ref for ptr, int &r5 = *ptr; 

	r1 += 3;   // r1 = 3+10 = 13
	r2 += 13;  // r2 = 10+13 = 23
	r3 += 20;  // r3 = 23+20 = 43
	*r4 += r2; // *r4 = (*r4)+r2 = 10+23=33 --> *ptr = 33
	++r5;      // r5 = *ptr = 33 --> ++r5 = 34 --> x=34

	std::cout << "x : " << x << "\n"; // x : 34

}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : A sample for the usage of reference values 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(){

	int x = 10;
	int& r1 = x;   // r1 ref. --> x = 10 
	auto r2 = x;   // r2 = 10
	auto& r3 = r2; // r3 ref. --> r2 = 10

	r2 += 5;  // r2 = 10 + 5 = 15 
	r3 += 20; // r3 = 15 + 20 = 35 (r3 ref. --> r2 =35 )
	++x;      // x = 11 --> r1 ref. --> x --> r1 = 11

	std::cout << "r1 + r2 + r3 : " << r1 + r2 + r3 <<"\n"; 
	// r1 + r2 + r3 : 11 + 35 + 35 : 81
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : A sample for the usage of auto keyword with references and pointer

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(){

	int a[] = { 10, 20, 30, 40 };
	auto p = a;  // int *p = a; --> array decay and p is a pointer
	auto& r = p; // int *(&r)[] = p; --> ref for a pointer
	++r;  // ++r --> ++p --> a[1]
	++p;  // ++p --> a[2] --> r is a ref for p pointer *r=a[2]=30
	
  std::cout << "*r :" << *r <<  "\n"; // *r :30
  
}
```

/----------------------------------------------
/----------------------------------------------

## Forwarding Reference 

- Related to perfect forwarding mechanism (auto &&refref = expr;)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

int main(){

	int x = 10;
	int y = 20;

	// forwarding reference (both ref1 and ref2)
	// universal reference (called by Scott Meyers)
	auto&& ref1 = x;      // OK, x --> L-Value 
	// ref1 is initialized a L-value, so ref1 is a L-value
	
	auto&& ref2 = x + 10; // OK,  x + 10 --> R-Value
	// ref2 is initialized a R-value, so ref2 is a R-value
    
	// R-Value ref. (both ref3 and ref4)
	int&& ref3 = x;    // NOT OK, x is L-Value is not assigned to R-Value ref. syntax error 
	int&& ref4 = x+10; // OK,  x + 10 --> R-Value, ref4 is alsı R-Value ref. here 
  
}
```

/----------------------------------------------
/----------------------------------------------
