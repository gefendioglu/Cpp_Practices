## ENUM CLASS

- The underlined types of enum is "int" as default
- The underlined types of enum classes can be specified by the user
- enum class (scoped enums) should be preffered instead of enum types in C++ 

- String literals:
  - C   --> char[]
  - C++ --> const char[]

- The data type of character constant:
  - int (C)
  - char (C++) 

- No need to use typedef for user defined types  in C++:
  - struct Data {int Data; }

/----------------------------------------------
/----------------------------------------------

- **Example** :
```cpp
#include <iostream>
#include <assert.h>

enum Color{White, Gray, Black};

int main() {
	assert(sizeof(Color) == sizeof(int)); // true
}
```

/----------------------------------------------
/----------------------------------------------
