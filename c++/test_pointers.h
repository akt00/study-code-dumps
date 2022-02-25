#ifndef TEST_POINTERS
#define TEST_POINTERS

#include<iostream>


void test_pointers() {
	int a = 5;
	int* b;
	int** c;
	
	b = &a;
	
	c = &b;
	std::cout << "c=&b" << std::endl;
	std::cout << "a=" << a << " &a=" << &a << std::endl;
	std::cout << "*b=" << *b << " b=" << b << " &b=" << &b << std::endl;
	std::cout << "**c=" << **c << " *c=" << *c << " c=" << c << " &c=" << &c << std::endl;
	
	c = new int*;  // necessary
	*c = b;
	std::cout << "*c=b" << std::endl;
	std::cout << "a=" << a << " &a=" << &a << std::endl;
	std::cout << "*b=" << *b << " b=" << b << " &b=" << &b << std::endl;
	std::cout << "**c=" << **c << " *c=" << *c << " c=" << c << " &c=" << &c << std::endl;

	int* d;
	// indirect pointer through b. d points to a in this case.
	d = b;
	std::cout << "d=b" << std::endl;
	std::cout << "a=" << a << " &a=" << &a << std::endl;
	std::cout << "*b=" << *b << " b=" << b << " &b=" << &b << std::endl;
	std::cout << "*d=" << *d << " d=" << d << " &d=" << &d << std::endl;
}

#endif
