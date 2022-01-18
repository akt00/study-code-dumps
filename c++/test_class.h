#ifndef TEST_CLASS
#define TEST_CLASS

#include<iostream>


class Test {
private:
	int value;
public:
	// providing default values invokes default constructor
	explicit Test(int val = 99) {
		std::cout << "constructor called" << std::endl;
		this->value = val;
	}

    // copy constructor and insertion operator should be overloaded when class holds dynamic objects
	// copy constructor is called when initializing class with Test t(tmp) or Test t = tmp
	Test(const Test& input) {
		std::cout << "copy constructor called" << std::endl;
		this->value = input.value;
	}

	// getter
	int getValue() { return value; }

	// returning class object, initialize with copy constructor 
	friend Test operator+ (const Test& t1, const Test& t2) {
		Test tmp(t1.value + t2.value);
		std::cout << "operator + = " << &tmp << std::endl;
		return tmp;
	}
};


void test_class() {

	Test t1(10), t2(12);
	auto sum = t1 + t2;
	std::cout << &sum << " = " << sum.getValue() << std::endl;

	Test t;
	std::cout << t.getValue() << std::endl;
}

#endif
