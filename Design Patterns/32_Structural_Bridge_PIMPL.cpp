//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <cstddef>
//#include <type_traits>
//
//class PersonImpl {
//public:
//	void greet(std::string& name) {
//		std::cout << "hello " << name << "\n";
//	}
//};
//
//// --------------------------------------------
//// --------------------------------------------
//
//
//
//class Person {
//public:
//	Person() {
//		// Compile time safety
//		static_assert(sizeof(m_impl) >= sizeof(PersonImpl), " ");
//		new(&m_impl) PersonImpl;
//	}
//
//	~Person() {
//		reinterpret_cast<PersonImpl*>(&m_impl)->~PersonImpl();
//	}
//
//	void greet() {
//		reinterpret_cast<PersonImpl*>(&m_impl)->greet(m_name);
//	}
//
//private:
//	static constexpr size_t  m_size = 1024;
//	using pimpl_storage_t = std::aligned_storage<m_size, std::alignment_of_v<max_align_t>>::type;
//
//	std::string m_name;
//	pimpl_storage_t m_impl;
//};
//
//
//
//
//
