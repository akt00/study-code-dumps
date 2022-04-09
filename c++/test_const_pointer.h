#ifndef TEST_CONST_POINTER
#define TEST_CONST_POINTER


// const pointer can not change the address it points to 
void test_const() {
	const int const_val = 99;
	int non_const = 199;

	int* ptr1 = &non_const; // non-const pointer to a non const value
	const int* ptr2 = &const_val; // non-const pointer to a const value, alternatively, int const*
	int* const ptr3 = &non_const; // const pointer to a non const value
	int const* const ptr4 = &const_val; // const pointer to a const value
}

#endif
