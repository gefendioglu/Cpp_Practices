## UNDEFINED BEHAVIOUR :
- Always avoid undefined behaviour (ub)
- The reason samples for undefined behaviour 
  - Dereferencing null pointers
  - Changing string literals (read only)
  - Changing variables which assigned as const
  - Overflowing for signed variables
  - No returning value for a function
  - Using uninitialized auto variables 

## UNSPECIFIED BEHAVIOUR :
- do not rely on unspecified behaviour
- It depends on compiler type
- It depends on the implementation (compiler here), implementation is not required to document which behaviour occurs; range of possible behaviours usually specified in standard
  
* Implementation Defined Behaviour: 
	- try not to rely on implemetation defined behaviour
	- this behaviour should be documented

/----------------------------------------------
/----------------------------------------------

#### Example: Unspecified Behaviour

```cpp

#include <iostream>

int main() {

	int x = 10, y = 20;
	bool flag = &x > & y; // flag = true OR flag = false

	std::cout << "flag : " << flag << "\n";
}
```

/----------------------------------------------
/----------------------------------------------


```cpp
#include <iostream>

int func1();
int func2();

int main() {

	int x = func1()*5 + func2();
	// which function is called first ? Not clear!
}
```
/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int g = 10;

int func1(int x, int y) { return x + y;}
int func2() {
	g += 5;
	return 100;
}
int func3() { return g + 3; }

int main() {

	int number = func1(func2(), func3());
	// which function is called first ? Not clear!
	// x value can be changed compiler to compiler

	std::cout << "number : " << number << "\n";
}
```
/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>
#include <cstdint>

int main() {

	int firstNumber;
	int32_t secondNumber; // guaranteed that secondNumber -->  32 bits 
}
```

## R VALUE REFERENCES - L VALUE REFERENCES :

```cpp
#include <iostream>

int main() {

	int firstNumber = 10;
	int& ref = firstNumber; // ref --> L value ref. ref = firstNumber
	int* const ptr = &firstNumber; // (*ptr) = firstNumber

	std::cout << "ref : " << ref << "\n";     // ref = 10
	std::cout << "(*ptr) : " << *ptr << "\n"; // (*ptr) = 10 
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int main() {

	int firstNumber = 10;
	int& ref = firstNumber; // ref --> L value ref. ref = firstNumber

	// int& referans = 10;
	// referans --> L Value , 10 --> R-Value
	// Error: 'initializing': cannot convert from 'int' to 'int &'

	int* const ptr = &firstNumber; // (*ptr) = firstNumber

	std::cout << "ref : " << ref << "\n";     // ref = 10
	std::cout << "(*ptr) : " << *ptr << "\n"; // (*ptr) = 10
}
```
/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int main() {

	int array[5]{ 0,1,2,3,4 };
	int (&refArray)[5] = array;
	auto &referansArray = array;
	// if auto is used  --> auto  = int* referansArray
	// if auto& is used --> auto = int (&referansArray)[5]

	std::cout << "(&refArray) : " << (&refArray) << "\n"; // (&refArray) = 006FF7F4
	std::cout << "(&refArray) address: " << refArray << "\n";     // refArray = 006FF7F4
	std::cout << "referansArray address: " << referansArray << "\n"; // referansArray = 006FF7F4
}
```

/----------------------------------------------
/----------------------------------------------

* Pointers can be referenced for other pointers

```cpp
#include <iostream>

int main() {

	int number = 10;
	int* ptr = &number;   // (*ptr) --> number = 10
	int** ptrptr = &ptr;  // ptrptr --> &ptr
	int**& ref = ptrptr;  // ref --> ptrptr 
	
	std::cout << "(*ptr) : " << *ptr << "\n";     // *ptr  = 10
	std::cout << "(ptrptr) : " << ptrptr << "\n"; // ptrptr = 005BFB4C
	std::cout << "(**ref) : " << **ref << "\n";   // **ref = 10
	std::cout << "(++**ref) : " << ++**ref << "\n";   // ++**ref = 11
	std::cout << "(&ref) : " << &ref << "\n";     // &ref = 005BFB40
}
```

/----------------------------------------------
/----------------------------------------------

* L-Value References for functions : 

```cpp
void  func(Type x); //  call by value
```
/----------------------------------------------
```cpp
void  func(Type *ptr); // call by reference (nesneyi hem okur hem de yazar)
void  func(Type &ref); // call by reference (nesneyi hem okur hem de yazar)
```
/----------------------------------------------
```cpp
void  func(const Type *ptr); // call by reference (nesneden sadece okuma yapar)
void  func(const Type &ref); // call by reference (nesneden sadece okuma yapar)
```
/----------------------------------------------
```cpp
Type  *func();  // return value is the address of object
Type  &func();  // return value is the reference of object 
```
/----------------------------------------------
```cpp
const Type  *func(); --> return value is the address of object
const Type  &func(); --> return value is the reference of object 
```
/----------------------------------------------
/----------------------------------------------
```cpp
Type func(); 
func();                   //R-Value expression
Type &ref = func();       // NOT OK
const Type &ref = func(); // OK --> R-Value expression
```
```cpp
Type &func(); 
func(); 	    // L-Value expression
Type &ref = func(); // OK --> L-Value expression
```
/----------------------------------------------
/---------------------------------------------

## CALL BY VALUE - CALL BY REFERENCE :

* C   --> always call-by-value
  C++ --> depends on function definition
  
```cpp
func(int);   // call-by-value OR 
func(int &); // call-by-reference
```
* C --> 

```cpp
setfunc(T *ptr);        // --> set function, setter, mutator
getfunc(const T *ptr);  // --> get function, getter, accessor 
			// --> copy only pointer size, not all data
			// --> applicable especially for arrays
func(T value);		// --> copy all amount of data
```

* C --> 

```cpp
setfunc(T *ptr);        // --> output parameters
getfunc(const T *ptr);  // --> input parameters
```

* C++ --> 

```cpp
class Data{};
void setter(Data &ref);       // --> the parameter will be changed
void getter(const Data& ref); // --> the parameter will only be read
```

/----------------------------------------------
/----------------------------------------------

* Swap Function with pointers - call by value

```cpp
#include <iostream>

void Swap(int *ptr1, int *ptr2) {
	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}

int main() {
	int firstNumber = 35;
	int secondNumber = 43;

	Swap(&firstNumber, &secondNumber);

	std::cout << "firstNumber : " << firstNumber << "\n";     // firstNumber = 43 
	std::cout << "secondNumber : " << secondNumber << "\n";     // secondNumber = 35
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Swap Function with references - call by reference 

```cpp
#include <iostream>

void Swap(int &ref1, int &ref2) {
	int temp = ref1;
	ref1 = ref2;
	ref2 = temp;
}

int main() {
	int firstNumber = 35;
	int secondNumber = 43;

	Swap(firstNumber, secondNumber);

	std::cout << "firstNumber : " << firstNumber << "\n";     // firstNumber = 43 
	std::cout << "secondNumber : " << secondNumber << "\n";     // secondNumber = 35
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int main() {
	int firstNumber = 35;
	const int& ref1 = firstNumber;
	int const& ref2 = firstNumber;
	int& const ref3 = firstNumber;

	// ref1 = 30; --> Error: expression must be a modifiable lvalue
	// ++ref1; --> Error: expression must be a modifiable lvalue
}
```

/----------------------------------------------
/----------------------------------------------

* Example: getter function 

```cpp
#include <iostream>

int getter(const int& ref) {
	return ref;
}

int main() {
	int firstNumber = 35;
	const int secondNumber = 43;
	
	std::cout << "getter(firstNumber): " << getter(firstNumber)<<"\n";
	std::cout << "getter(secondNumber): " << getter(secondNumber)<<"\n";
}
```

/----------------------------------------------
/----------------------------------------------

* Example: setter function, no conversion from const --> non-const

```cpp
#include <iostream>

int setter(int& ref) {
	ref = 15;
	return ref;
}

int main() {
	int firstNumber = 35;
	const int secondNumber = 43;
	
	std::cout << "getter(firstNumber): " << setter(firstNumber)<<"\n";
	
	//std::cout << "getter(secondNumber): " << setter(secondNumber)<<"\n";

// Error: qualifiers dropped in binding reference of type "int &" to initializer of type "const int"

// Error : 'int setter(int &)' : cannot convert argument 1 from 'const int' to 'int &'
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int main() {

	int firstNumber = 35;
	const int& ref = firstNumber; // firstNumber --> L-Value  
	const int& ref = 10; // 10 --> R Value 
	
	// A temporary object was defined for R Value 
	// int temp_object{10};
	// const int &ref = temp_object;
}
```

/----------------------------------------------
/----------------------------------------------

* Example: no conversion from const ref --> non-const ref

```cpp
#include <iostream>

int main() {

	int firstNumber = 35;
	const int& ref1 = firstNumber; // firstNumber --> L-Value  
	const int& ref2 = 10; // 10 --> R Value 
	// A temporary object was defined for R Value 
	// int temp_object{10};
	// const int &ref = temp_object;

	// int& reference = ref2;
	// Error: 'initializing' cannot convert from 'const int' to 'int &'	
}
```

/----------------------------------------------
/----------------------------------------------

* Example: no reference to reference definition

```cpp
#include <iostream>

int main() {

	int number = 35;
	int& ref1 = number;
	int& ref2 = ref1; // ref2 = number
	int& ref3 = ref2; // ref3 = number

	std::cout << "number: " << number << "\n"; // number = 35
	std::cout << "ref1: " << ref1 << "\n"; // ref1 = 35
	std::cout << "ref2: " << ref2 << "\n"; // ref2 = 35
	std::cout << "ref3: " << ref3 << "\n"; // ref3 = 35

	++ref1;
	++ref2;
	++ref3;

	std::cout << "number: " << number << "\n"; // number = 38
	std::cout << "ref1: " << ref1 << "\n"; // ref1 = 38
	std::cout << "ref2: " << ref2 << "\n"; // ref2 = 38
	std::cout << "ref3: " << ref3 << "\n"; // ref3 = 38
}
```

/----------------------------------------------
/----------------------------------------------


## RETURN VALUE

* When return value is a pointer: 

```cpp
int* ptrFunc() {
	static int number = 10;
	//....
	return &number;
}
```

* When return value is a reference: 

```cpp
int& refFunc() {
	static int number = 10;
	//....
	return number;
}
```

/----------------------------------------------
/----------------------------------------------

* Example: When function return value is reference, then the function is a L-Value (1)

```cpp
#include <iostream>

int command = 45;

int& refFunc() {
	return command;
}

int main() {

	refFunc() = 100; // refFunc() is a L-Value
	std::cout << "command: " << command << "\n"; // command = 100
}
```

/----------------------------------------------
/----------------------------------------------

* Example: When function return value is reference, then the function is a L-Value (2)

```cpp
#include <iostream>

int command = 45;

int& refFunc() {
	return command;
}

int main() {

	int& ref = refFunc();
	ref = 500;
	std::cout << "command : " << command << "\n"; // command : 500
}
```

/----------------------------------------------
/----------------------------------------------

* Example: When function return value is reference or address --> undefined behaviour

```cpp
#include <iostream>

int& refFunc() {
	int x = 10;
	return x; 
	// warning C4172: returning address of local variable or temporary: x
}

int* ptrFunc() {
	int x = 10;
	return &x; 
	// warning C4172: returning address of local variable or temporary: x
}

int main() {

	int& ref = refFunc();
	std::cout << "ref : " << ref << "\n"; // ref: 10

	int* ptr = ptrFunc();
	std::cout << "ptr : " << ptr << "\n"; // ptr : 008FF7A0
}
```

/----------------------------------------------
/----------------------------------------------

* Hangi nesne parametre olarak alindiysa onun adresi ile geri dönülebilir. 

```cpp
struct Data {
	int x, y, z;
};

struct Data *func(struct Data *ptr){
	
	//...
	return ptr;
}
```

/----------------------------------------------
/----------------------------------------------

* Nesnenin kendisi parametre olarak alinir ve geri dönüþ degeri de kendisi olur

```cpp
struct Data& reffunc(struct Data &ref) { 

	//...
	return ref;
}
```

## POINTER TYPES: 
- Invalid Pointer: 
  - otomatik ömürlü tanımlanan pointer için ilk değer verilmezse
  - bir pointer a dinamik ömürlü nesnenin adresi atandıysa/ilk değer verilirse ve pointer değişkenin hayatı devam ederken onun gösterdiği nesnenin hayatı biterse
  
- Valid pointer: 
  - Bir pointer bir dizinin son elemanının adresini tutarken, değeri bir arttırılırsa dizinin bittiği yerin adresini tutuyor olacaktır 
  
- Değeri nullptr olan bir pointer değişken hiçbir nesneyi göstermemektedir. Asla derefere edilmemelidir. 
- "Null pointer" kavramı mevcut; ancak "null reference" kavramı bulunmaz!

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int main() {
	int* ptr = nullptr;
	std::cout << "(*ptr) : " << *ptr << "\n"; 
	// Exception thrown : read access violation.
}
```

/----------------------------------------------	
/----------------------------------------------

### The Comparisons for References and Pointers:
- Referanslara ilk değer vermek zorunlu, ilk değer vermeden referans oluşturulamaz ! 
- Pointer değişkenlere ilk değer vermek zorunlu değildir. 
- "Reference to reference" kavramı yoktur; ancak "pointer to pointer" kavramı mecvuttur. 

/----------------------------------------------	
/----------------------------------------------

- Pointer değişken farklı nesne adreslerini gösterebilir. Kendisi const olmak zorunda değildir. 

```cpp
#include <iostream>

int main() {
	int firstNumber = 10;
	int secondNumber = 99;

	int *ptr = &firstNumber;
	ptr = &secondNumber; // OK
	//...
	int* const ptr2 = &secondNumber; // const pointer
	ptr2 = &firstNumber; // NOT OK
}
```

/----------------------------------------------
/----------------------------------------------
- Referanslardan oluşan bir dizi yazılamaz. 

```cpp
#include <iostream>

int x, y, z, t;

int main() {
	int* ptrArray[] = { &x, &y, &z, &t }; // OK
	int& refArray[] = { x, y, z, t };     // NOT OK
	// Error C2234 'refArray': arrays of references are illegal	
}
```

/----------------------------------------------
/----------------------------------------------

- Initialization of pointer and reference arrays:

```cpp
#include <iostream>

int main() {
	int a[10] = {0}; 
	int(*ptrArray)[10] = &a;
	int(&refArray)[10] = a;
}
```

/----------------------------------------------
/----------------------------------------------

