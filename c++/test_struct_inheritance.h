#ifndef TEST_STRUCT_INHERITANCE
#define TEST_STRUCT_INHERITANCE

#include<string>
#include<iostream>


template<typename T>
struct base {
	T value;
	std::string str;
	auto getValue() -> decltype(T{}) {
		return value;
	}
	auto getStr() -> decltype(std::string{}) {
		return str;
	}
	void printValues() {
		std::cout << "value = " << value << std::endl;
		std::cout << "str = " << str << std::endl;
	}
};


template <typename T> struct child;
template <> struct child<base<int>> : public base<int> {};

#endif