#ifndef TEST_LAMBDA
#define TEST_LAMBDA

#include<iostream>


// https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-160
void lambda1() {
	int x = 10;
	auto a = [&]() { x = 15; }; // capture local variables
	a();
	std::cout << x << std::endl;
	std::cout << typeid(a).name() << std::endl;
}


void lambda2() {
	auto a = [](int x) {return x * 10; }; // takes arguments
	std::cout << a(5) << std::endl;
}


#endif