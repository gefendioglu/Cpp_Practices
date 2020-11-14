#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <array>

void reverse_array(int *ptr, int size) {
    
    int* ptr_reverse = new int[size];

    for (int i = size - 1; i >= 0; --i) {
        ptr_reverse[i] = *ptr;
        std::cout << ptr_reverse[i] << " ";
        ptr++;
    }
}

int main() {

    int size;
    std::cin >> size;
    if (size <= 1000 && size >= 1) {
        int *ptr = new int[size];
        
        if (ptr == nullptr)
            std::cout << "Error: memory could not be allocated";
        std::cout << size << "\n";
        
        for (int i = 0; i < size; ++i) {
            std::cin >> ptr[i];
            if (ptr[i] >= 1 && ptr[i] <= 10000) {
                std::cout << ptr[i] << " ";
            }
        }

        reverse_array(ptr, size);
    }

    
}
