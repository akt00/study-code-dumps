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
/*
c=&b
a=5 &a=000000A52E3DFE60
*b=5 b=000000A52E3DFE60 &b=000000A52E3DFE68
**c=5 *c=000000A52E3DFE60 c=000000A52E3DFE68 &c=000000A52E3DFE70
*c=b
a=5 &a=000000A52E3DFE60
*b=5 b=000000A52E3DFE60 &b=000000A52E3DFE68
**c=5 *c=000000A52E3DFE60 c=0000023ED5713150 &c=000000A52E3DFE70
d=b
a=5 &a=000000A52E3DFE60
*b=5 b=000000A52E3DFE60 &b=000000A52E3DFE68
*d=5 d=000000A52E3DFE60 &d=000000A52E3DFE78
*/
