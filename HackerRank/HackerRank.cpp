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


