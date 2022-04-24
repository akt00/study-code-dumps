#ifndef TEST_FORWARD
#define TEST_FORWARD
#include<iostream>
#include<utility>
#include<memory>
// accepts only rvalue
void test_forward_helper(int&& arg) {
    std::cout << arg << std::endl;
}

void test_forward() {
  int i = 99;
  test_forward(std::forward<int>(i)); // converting lvalue to rvalue
}


#endif // TEST_FORWARD
