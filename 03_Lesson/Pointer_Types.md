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

-Example: 
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

- Example: 
 - Non-const pointer types can point different addresses of objects  
 - Const pointer types can not point different addresses of objects. It must point the same object.  
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

- Example: There is no definition for reference arrays.

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

-Example: Initialization of pointer and reference arrays

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
