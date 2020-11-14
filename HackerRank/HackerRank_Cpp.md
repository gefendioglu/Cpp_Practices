## HACKERRANK - CPP
/----------------------------------------------
/----------------------------------------------

- **Example**:
  - The function is declared with a void return type, so there is no value to return.
  - Modify the values in memory so that contains their sum and  contains their absoluted difference.
  - Input Format: Input will contain two integers,  and , separated by a newline.
  - Sample Input: 4 5, Sample Output: 9 1 
```cpp
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <cmath>

void update(int* a, int* b) {
    // Complete this function    
    int temp = *a;
    *a = (*a) + (*b);
    *b = std::abs(temp - (*b));
}

int main() {
    int a, b;
    int* pa = &a, * pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
```

/----------------------------------------------
/----------------------------------------------
