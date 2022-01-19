#ifndef TEST_RETURN_BY_REFERENCE
#define TEST_RETURN_BY_REFERENCE

#include<iostream>

/*
*  when returning a reference, it must be declared with static
*  non-static nor dynamic object gets deleted from stack once out of scope
*/
int& returning_reference() {

	static int i = 10;
	// referencing a pointer object is confusing and could cause memory leak
	/*
	int *val = new int(99);
	int& ref = *val;
	*/
	std::cout << i << " " << &i << std::endl;
	return i;
}



#endif