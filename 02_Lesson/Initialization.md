## INITIALIZATION

- There are lots of initialization methods in C++
	- copy initialization
	- default initialization
	- zero initialization
  
- The syntax type of initialization: 
	- copy initialization
	- value initialization (direct initialization)
	- uniform initialization (brace initialization)

- What are the reasons of using uniform initialization?
	- narrowing conversion
	- most vexing parse : 
	  If the definition has the meaning both variable and function at the same time (because of using paranthesis)
    
- What is indetermined value? 

/----------------------------------------------
/----------------------------------------------

- **Example** : 
```cpp
#include <iostream>

int randomNumber; // default : zero initialization for global variables 

int main() {
	
	// Default initialization and undefined behaviour
	// The value is indetermined value 
	int number; 
	int *ptr; 

	// Copy initialization
	int inum = 10; 
	double dnum = 2.3;
	
	// Zero initializaiton
	static int snum; // default : zero initialization for static local variables
	bool flag = false;
	int* iptr = nullptr;
	long double ldnum = 0;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : 
```cpp
#include <iostream>

struct Data {};

int main() {
	// Copy init. 
	int number1 = 10; 

	// Value init. (direct init.)
	int number2(20); 
	int number3{};
	Data myData{};
	int func();    // --> NOT value init.,it is function  declaration
	Data myData(); // --> NOT value init.,it is function  declaration

	// Uniform init. (brace init.)
	int number4{ 30 };
	int primes[]{2,3,5,7,11,13};
	
	int* firstPtr{ primes }; // --> int* secondPtr = &primes[0];
	int* secondPtr = &primes[0];

	std::cout << "Dereferencing firstPtr (*firstPtr): "<< *firstPtr << "\n";
	std::cout << "Dereferencing secondPtr (*secondPtr): "<< *secondPtr << "\n";
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** :  Narrowing conversion sample
```cpp
#include <iostream>

int main() {
	// Narrowing conversion: (double --> int) 
	double dnumber = 2.6;
	int copyInit = dnumber;     // Warning : possible loss of data 
	int directInit(dnumber);    // Warning : possible loss of data
	int uniformInit{ dnumber }; // Error : narrowing conversion 

	std::cout << "dnumber: " << dnumber << "\n";
	std::cout << "copyInit: " << copyInit << "\n";
	std::cout << "directInit: " << directInit << "\n";
	std::cout << "uniformInit: " << uniformInit << "\n";
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Most vexing parse sample: 
```cpp
#include <iostream>

struct Data {};
struct Stream {
	Stream(Data);
};

int main() {
	
	// Function declaration, not a direct init.
	// warning C4930 :prototyped function not called (was a variable definition intended ? )
	Stream firstStream(Data());
	
	// Uniform initialization, not a function declaration
	Stream secondStream{ Data() }; 
}
```

/----------------------------------------------
/----------------------------------------------