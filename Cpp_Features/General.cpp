
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

using ull = unsigned long long;
constexpr ull operator"" _KB(ull no){
    return no * 1024;
}
constexpr ull operator"" _MB(ull no){
    return no * (1024_KB);
}

int main() {

    std::cout << 1_KB << "\n";
    std::cout << 5_MB << "\n";
}
