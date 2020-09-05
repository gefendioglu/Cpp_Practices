#pragma once
#include <iostream>

template <typename T>
struct ValueCategory {
	constexpr static const char* ptrstr{ "PR Value" };
};

template <typename T>
struct ValueCategory<T&> {
	constexpr static const char* ptrstr{ "L Value" };
};

template <typename T>
struct ValueCategory<T&&> {
	constexpr static const char* ptrstr{ "X Value" };
};

#define valuecategory(exp) (std::cout << "Value category of \"" #exp"\" is : " << ValueCategory<decltype((exp))>::ptrstr << "\n");
