#ifndef TEST_UNION
#define TEST_UNION

#include<iostream>

/* union shares the memory space with member variables 
*  memory space is the multiples of 8 bits
*  used for registor management etc..
*/
union  book {
	char name[8];
	int price;
};


void test_union() {
	book b = { "hello" };
	b.price = 999;
	std::cout << "sizeof b = " << sizeof(b) << std::endl;
	std::cout << b.name << std::endl;
	std::cout << b.price << std::endl;
}

#endif