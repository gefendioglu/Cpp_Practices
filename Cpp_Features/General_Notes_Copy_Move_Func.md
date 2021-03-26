### General Notes on Move & Copy Operations: 

- **Rule of Zero Rule**: If the definition of default ctor is sufficient for a class, the writing task for the other special member functions can be assigned to compiler. 

- If the destructor has to be written by user (in the case of existing at least a pointer data member), the other big three members (copy operations) shall be defined by the user too. 

- If big three members are written by user --> it is generally necessary to write the big five member functions (adding move operations)

- If the copy operations of a class are deleted, then move operations are not declared by compiler implicitly. In this case, this kind of classes has the feature of non-copyable and non-movable. 

- Some classes in standard library are not copyable (copy operations are deleted), but movable (move operations are declared & defined). For example, smart pointer class. Smart pointer classes in <memory> library. 
  - Smartpointer(const Smartpointer& ref) = delete;
  - Smartpointer& operator=(const Smartpointer& ref) = delete;
  - Smartpointer(Smartpointer&& ref);
  - Smartpointer& operator=(Smartpointer&& ref);

/----------------------------------------------
/----------------------------------------------

- **Example** : Non-copyable, but movable class example (std::cout)
  - **cout** is a non-copyable, but movable class in **ostream** class

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void func(std::ostream ost);

int main() {
	func(std::cout); // ERROR, std::cout is non-copyable 
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : Non-copyable, but movable class example (smart pointer)

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <memory>

int main() {

	std::unique_ptr<int> uptr1{ new int };
	std::unique_ptr<int> uptr2{ new int };
	
	// ERROR, non-copyable --> copy ctor is deleted!
	std::unique_ptr<int> uptr3{ up2 }; 
	
	// ERROR, non-copyable --> copy assignment is deleted!
	uptr1 = uptr2;

	// NOT ERROR, movable --> move ctor is defined!
	std::unique_ptr<int> uptr4{ std::move(uptr2) };

	// NOT ERROR, movable --> move assignment is defined!
	uptr1 = std::move(uptr2); 

	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : An exceptional case for calling copy ctor instead of move ctor

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

// default ctor, copy ctor is defined
// move ctor is defined in private access modifier
class Data {
public:
	Data(){}
	Data(const Data&){ std::cout << "copy ctor is called...\n"; }
private:
	Data(Data&&){}
};

class Member { Data data; };

int main() {

	Member mem1;
	Member mem2{ mem1 }; // copy ctor is called... 
	Member mem3{ std::move(mem1) }; // copy ctor is called...
	
	return EXIT_SUCCESS;
}
```

/----------------------------------------------
/----------------------------------------------

- The following usage is very common in standard library: 

```cpp
void func(const Data& ref) { 
	Data data = ref; // copying ref parameter
}

void func(Data&& ref) {
	Data data = std::move(ref); // moving ref parameter
}
```

/----------------------------------------------
/----------------------------------------------

- **Example** : The push_back function of vector class is overloaded like mentioned above. 

```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

class Data{
public:
	Data() = default;
	Data(const Data& ref) {
		std::cout << "copy ctor is called...\n";
	}
	
	// main aim is to move the object sending as argument
	Data(Data&& ref) {
		std::cout << "move ctor is called...\n";
	}
 
};

int main() {

	std::vector<Data> data_vec;
	data_vec.reserve(100);

	Data data;
	data_vec.push_back(data);   // data is L-Value expr.							        
	                            // push_back(const Data&) is called
				    // copy ctor is called...
	data_vec.push_back(Data{}); // Data{} is R-Value expr.
				    // push_back(Data&&) is called
				    // move ctor is called...
	return EXIT_SUCCESS;

	/*
		copy ctor is called...
		move ctor is called...
	*/
}
```

/----------------------------------------------
/----------------------------------------------
