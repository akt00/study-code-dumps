#include"pch.h"
#include"../Algorithms/container/stack.h"
using namespace algorithm;


TEST(StackTest, TestEmpty) {

	container::stack<int> s;
	ASSERT_EQ(s.empty(), true);
	s.push(1);
	ASSERT_EQ(s.empty(), false);
}

TEST(StackTest, TestInsertion) {

	container::stack<int> s1;
	s1.push(1);
	s1.push(2);
	ASSERT_EQ(s1.size(), 2);
	container::stack<int> s2;
	s2 = s1;
	ASSERT_EQ(s1.size(), s2.size());
	ASSERT_EQ(s2.top(), 2);
}

TEST(StackTest, TestBasics) {

	container::stack<int> s;
	ASSERT_EQ(s.size(), 0);
	s.push(1);
	s.push(2);
	s.push(3);
	ASSERT_EQ(s.size(), 3);
	ASSERT_EQ(s.top(), 3);

	auto s_copy(s);
	ASSERT_EQ(s_copy.size(), s.size());
	ASSERT_EQ(s.size(), 3);
	s.pop();
	ASSERT_EQ(s.size(), 2);
	s.clear();
	ASSERT_EQ(s.size(), 0);
	s.push(10);
	ASSERT_EQ(s.size(), 1);
	ASSERT_EQ(s.top(), 10);
}

TEST(StackTest, TestSwap) {

	container::stack<int> s1;
	s1.push(1);
	decltype(s1) s2;
	s2.push(11);
	s2.push(12);
	ASSERT_EQ(s1.size(), 1);
	ASSERT_EQ(s2.size(), 2);
	
	s1.swap(s2);
	ASSERT_EQ(s1.size(), 2);
	ASSERT_EQ(s2.size(), 1);

	ASSERT_EQ(s1.top(), 12);
	s1.pop();
	ASSERT_EQ(s1.top(), 11);
	
	ASSERT_EQ(s2.top(), 1);
	s2.pop();
	s2.pop();
	s2.pop();
	ASSERT_EQ(s2.size(), 0);
}