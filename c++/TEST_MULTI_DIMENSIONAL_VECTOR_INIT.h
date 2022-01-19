#ifndef TEST_MULTI_DIMENSIONAL_VECTOR_INIT
#define TEST_MULTI_DIMENSIONAL_VECTOR_INIT

#include<iostream>
#include<vector>


void test_multi_dimensional_vector_init() {
	// size of 10, initialize with 99
	std::vector<int> tmp(10, 99);
	std::vector<std::vector<int>> vec(5, tmp);

	for (auto i : vec) {
		for (auto j : i) {
			std::cout << j << " ";
		}
		std::cout << std::endl;
	}
}


#endif