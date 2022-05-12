#ifndef TEST_C_MEMORY
#define TEST_C_MEMORY
#include<stdlib.h>
#include<iostream>


void test_c_memory() {

	// malloc: uninitialized memory allocation
	auto mloc = (int*)malloc(4 * sizeof(int));

	// calloc: zero initialized memory allocation
	auto cloc = (int*)calloc(4, sizeof(int));

	// aligned_malloc: guarantees the boundary for the byte size biggers than 2**3
	auto amloc = (double*)_aligned_malloc(16, 32);
	*(amloc) = 11.1;
	*(amloc + 1) = 22.2;
	std::cout << *(amloc) << std::endl;
	std::cout << *(amloc + 1) << std::endl;

	free(mloc);
	free(cloc);
	_aligned_free(amloc);
}

#endif
