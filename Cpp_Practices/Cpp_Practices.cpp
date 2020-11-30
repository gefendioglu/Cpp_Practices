#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include <vector>

//int main()
//{
//    std::vector<double> v(100);
//    std::vector<double>* ptov = &v;
//    
//    char c = 'x';
//    char* ptochar = &c;
//   
//    double d = 1.0;
//    double* ptodouble = &d;
//    
//    std::string s{ "Lorem ipsum dolor sit amet, vis id quis invenire imperdiet" };
//    std::string* ptostring = &s;
//    
//    std::cout << "         sizeof(v): " << sizeof(v) << "\n";
//    std::cout << "      sizeof(ptov): " << sizeof(ptov) << "\n";
//    std::cout << "     sizeof(*ptov): " << sizeof(*ptov) << "\n";
//    std::cout << "         sizeof(c): " << sizeof(c) << "\n";
//    std::cout << "   sizeof(ptochar): " << sizeof(ptochar) << "\n";
//    std::cout << "  sizeof(*ptochar): " << sizeof(*ptochar) << "\n";
//    std::cout << "         sizeof(d): " << sizeof(d) << "\n";
//    std::cout << " sizeof(ptodouble): " << sizeof(ptodouble) << "\n";
//    std::cout << "sizeof(*ptodouble): " << sizeof(*ptodouble) << "\n";
//    std::cout << "         sizeof(s): " << sizeof(s) << "\n";
//    std::cout << " sizeof(ptostring): " << sizeof(ptostring) << "\n";
//    std::cout << "sizeof(*ptostring): " << sizeof(*ptostring) << "\n";
//    
//    int arr[5]{};
//    int* p = arr;
//    int(*ptr)[5] = &arr;
//
//    // On my machine int is 4 bytes and pointers are 8 bytes:
//    std::cout << "  sizeof(arr): " << (sizeof(arr)) << "\n";
//    std::cout << "  sizeof(p)  : " << (sizeof(p)) << "\n";
//    std::cout << " sizeof(*p)  : " << (sizeof(*p)) << "\n";
//    std::cout << "  sizeof(ptr): " << (sizeof(ptr)) << "\n";
//    std::cout << " sizeof(*ptr): " << (sizeof(*ptr)) << "\n";
//    return 0;
//}
