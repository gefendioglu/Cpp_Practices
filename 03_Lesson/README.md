## R VALUE REFERENCES - L VALUE REFERENCES :
/----------------------------------------------
/----------------------------------------------
**Example:

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

**Example:

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

**Example:

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

**Example:  Pointers can be referenced for other pointers

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

**Example: L-Value References for functions : 

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

**Example:

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
- C   --> always call-by-value
- C++ --> depends on function definition

/----------------------------------------------
/---------------------------------------------

**Example:

- C++ --> 

```cpp
func(int);   // call-by-value OR 
func(int &); // call-by-reference
```
- C --> 

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

**Example: Swap Function with pointers - call by value

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

**Example: Swap Function with references - call by reference 

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

**Example:

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

**Example: getter function 

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

* Example: setter function (no conversion implicitly from const type --> non-const type)

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

/----------------------------------------------
/----------------------------------------------

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

## ASSIGNMENT 

* Example: Assigning a pointer and reference values 

```cpp
#include <iostream>

int main() {
	int firstNumber = 10;
	int secondNumber = 99;

	int* ptr = &firstNumber;
	int*& refPointer = ptr;

	std::cout << "ptr : " << ptr << "\n";				// ptr : 00AFFAF8
	std::cout << "refPointer : " << refPointer << "\n"; // refPointer : 00AFFAF8

	*refPointer = 300; // *refPointer --> firstNumber
	std::cout << "firstNumber : " << firstNumber << "\n";  // firstNumber : 300
		
	refPointer = &secondNumber;
	*refPointer = 700; // *refPointer --> secondNumber
	std::cout << "secondNumber : " << secondNumber << "\n"; // secondNumber : 700
}
```

/----------------------------------------------
/----------------------------------------------

* Example: Assigning references 

```cpp
#include <iostream>

int main() {
	int firstNumber = 10;
	int secondNumber = 99;

	int& ref1 = firstNumber;
	int& ref2 = ref1;
	++ref2; 
  
	std::cout << "ref1 : " << ref1 << "\n"; // ref1: 11
	std::cout << "ref2 : " << ref2 << "\n"; // ref2 : 11
}
```

/----------------------------------------------
/----------------------------------------------

## DEFAULT ARGUMENT :
- Fonksiyonlarýn Varsayýlan Argüman Almasý
- Programda ayný argüman deðerlerini alan fonksiyon çaðrýlarý için default tanýmlamalarýn yapýlmasý, hataya karþý koruma saðlar.
- Run-time maliyeti bulunmaz. Tamamen compile-time'a yönelik bir mekanizmadýr. 

/----------------------------------------------
/----------------------------------------------

- variadic function --> function with ellipses token

```cpp
#include <iostream>

void func(int x, int y, int z);
void variadicFunc(int, ...);     // variadic function
int Printf(const char* p, ...);  // variadic function

int main() {
	func(10, 20, 30);  // OK
	func(10, 20);      // NOT OK
	func(10);		   // NOT OK
	func();			   // NOT OK
	func(1, 2, 3, 4);  // NOT OK

	variadicFunc(10, 20, 30);  // OK
	variadicFunc(10, 20);      // OK
	variadicFunc(10);		   // OK
	variadicFunc();			   // NOT OK --> first parameter shall be filled !!!
	variadicFunc(1, 2, 3, 4);  // OK

	Printf("gamze", 20, 30);   // OK
	Printf("gamze", 20);       // OK
	Printf("gamze");		   // OK
	Printf();			       // NOT OK --> first parameter shall be filled !!!
	Printf("gamze", 2, 3, 4);  // OK
}
```

/----------------------------------------------
/----------------------------------------------

- Default argümanlarýn fonksiyon bildiriminde (function definition) yapýlmasý yaygýndýr. Ancak özel durumlarda fonksiyon tanýmlarýnda (function declaration) da uygulanmaktadýr. Ancak he  bildirimde hem de tanýmda yapýlmasý hatadýr.

```cpp
#include <iostream>

void func(int , int , int z = 10);
void foo1(int x = 30, int y = 20 , int z = 10);

void foo2(int x, int y = 20 , int);		    // Syntax Error
void foo3(int x, int y = 20 , int z = 10);  // Not Syntax Error

int main() {
	func(10, 20, 30);  // OK --> z = 30
	func(10, 20);      // OK --> z = 10
	func(10);		   // NOT OK --> second argument shall be sent !
	func();			   // NOT OK --> first and second arguments shall be sent !
	func(1, 2, 3, 4);  // NOT OK --> No fourth parameters in function declaration

	foo1();       // OK --> foo1(30,20,10);
	foo1(1);      // OK --> foo1(1,20,10);
	foo1(1, 2);   // OK --> foo1(1,2,10);
	foo1(1, 2,3); // OK --> foo1(1,2,3);
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int g = 45;
int func(int y = g + 5) {
	return y;
}

int main() {
	std::cout << "func(120) : " << func(120) << "\n";  // func(120) : 120
	std::cout << "func() : " << func() << "\n";        // func() : 50
} 
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

int func(int x, int y) {
	return x + y;
}

int funcDefArg(int x, int y = 10) {
	return x + y;
}

int foo(int y = func(15, 25)) {
	return y;
}

int fooDefArg(int y = funcDefArg(15)) {
	return y;
}

int main() {
	std::cout << "foo(func(27, 37)) : " << foo(func(27, 37)) << "\n"; // : 64
	std::cout << "foo(125) : " << foo(125) << "\n"; // foo(125) : 125 
	std::cout << "foo() : " << foo() << "\n";       // foo() : 40

	std::cout << "fooDefArg(funcDefArg(27)) : " << fooDefArg(funcDefArg(27)) << "\n"; 
	// fooDefArg(funcDefArg(27)) : 37
	std::cout << "fooDefArg(125) : " << fooDefArg(125) << "\n"; // fooDefArg(125) : 125
	std::cout << "fooDefArg() : " << fooDefArg() << "\n"; // fooDefArg() : 25
}
```

/----------------------------------------------
/----------------------------------------------

* Ara not: Fonksiyonlarýn hayata gelme sýrasý 

```cpp
#include <iostream>

int foo() {
	std::cout << "foo() is called !!! : " << "\n"; 
	return 10;
}

int globalVal = foo();

int main() {
	std::cout << "main() is called !!! : " << "\n";
	// Result: 
	// foo() is called !!!  --> first global function
	// main() is called !!! --> then main function
}
```

/----------------------------------------------
/----------------------------------------------
```cpp
func(12, , 45); // NOT OK --> all right arguments shall be filled !!!
```
/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

void foo(int x = 1, int y = 2, int z = 3);

int main() {
	
	foo();           // 1, 2, 3
	foo(10);		 // 10, 2, 3
	foo(10, 20);     // 10, 20, 3
	foo(10, 20, 30); // 10, 20, 30
}

void foo(int x, int y, int z) {
	std::cout << x << " , " << y << " , " << z <<  "\n";
}
```

/----------------------------------------------
/----------------------------------------------

- Default arguments for references 

```cpp
#include <iostream>

int globalVal = 25;

int func(int& ref = globalVal) {
	return ref + 5;
}

int main() {
	int value = 5;
	std::cout << "func(5)  : " << func(value) << "\n"; // func(5) : 10
	std::cout << "func()   : " << func() << "\n";      // func()-> func(globalValue): 30
}
```

/----------------------------------------------
/----------------------------------------------

- Default arguments for functions with pointer parameters  

```cpp
#include <iostream>

int globalVal = 25;

void func(int* ptr = nullptr) {
	std::cout << "func() is called !!! " << "\n";
}

int main() {
	int value = 10;
	func(&value);   // OK 
	func();			// OK --> func(nullptr);
}
```

/----------------------------------------------
/----------------------------------------------

- Default arguments for functions with string parameters (const char*) 

```cpp
#include <iostream>

void funcErr(std::string ptr = "Not enough memory !!") {
	std::cout << ptr << "\n";
}

int main() {
	funcErr("gamze");   // OK --> funcErr("gamze"); 
	funcErr();	    // OK --> func("Not enough memory !!");
}
```

/----------------------------------------------
/----------------------------------------------
```cpp
int* ptr;
void func(int& ref = *ptr);
```
/----------------------------------------------
/----------------------------------------------

- Default arguments for functions defined in a header file

```cpp
#include <iostream>

//func.h
void func(int x, int y, int z);
void func(int x, int y, int z = 0); // redecleration 

int main() {
	func(1, 2, 3); // OK --> func(1,2,3);
	func(1, 2);    // OK --> func(1,2,0);
	func(1);       // NOT OK --> All the left side parameters shall be filled
}
```

/----------------------------------------------
/----------------------------------------------

- Calling default arguments with wrapper functions

```cpp
#include <iostream>

void func(int x, int y, int z) {
	std::cout << "func(int x, int y, int z) is called !!! " << "\n";

}

void wrapperFunc(int x, int z, int y = 10) {
	func(x, y, z);
	std::cout << "wrapperFunc(int x, int z, int y = 10) is called !!! " << "\n";
}

int main() {
	wrapperFunc(10,20,30);  // OK     --> func(10,20,30);
	wrapperFunc(10,20);     // OK     --> func(10,10,20);
	wrapperFunc(10);        // NOT OK !!! 
}
```

/----------------------------------------------
/----------------------------------------------

```cpp
#include <iostream>

void processDate(int day, int month, int year = -1);
void processDate(int day, int month, int year) {
	if (year == -1) {

	}
}

void time(time_t *ptr = nullptr){}
void func(int *ptr = nullptr){}

int main() {
	time();
	func();
}
```

/----------------------------------------------
/----------------------------------------------
