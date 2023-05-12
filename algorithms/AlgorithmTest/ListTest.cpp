#include"pch.h"
#include"../Algorithms/container/list.h"
using namespace algorithm;


TEST(ListTest, TestEmpty) {

	container::list<int> l;
	ASSERT_EQ(l.empty(), true);
	l.push_back(1);
	ASSERT_EQ(l.empty(), false);
}

TEST(ListTest, TestPushPop) {

	container::list<int> l;
	l.push_back(1);
	l.push_back(2);
	ASSERT_EQ(l.back(), 2);
	ASSERT_EQ(l.size(), 2);
	
	l.push_front(3);
	ASSERT_EQ(l.front(), 3);

	l.pop_back();
	ASSERT_EQ(l.back(), 1);
	l.pop_front();
	ASSERT_EQ(l.front(), 1);
	ASSERT_EQ(l.size(), 1);

	l.pop_back();
	l.pop_back();
	ASSERT_EQ(l.size(), 0);

	l.push_back(10);
	ASSERT_EQ(l.size(), 1);
	ASSERT_EQ(l.back(), 10);
}


TEST(ListTest, TestInsertion) {

	container::list<int> l1;
	l1.push_front(1);
	l1.push_front(2);
	ASSERT_EQ(l1.size(), 2);

	decltype(l1) l2;
	l2.push_back(11);
	ASSERT_EQ(l2.size(), 1);
	l2 = l1;
	ASSERT_EQ(l2.size(), 2);
	ASSERT_EQ(l2.front(), 2);
	ASSERT_EQ(l2.back(), 1);
}

TEST(ListTest, TestIterator) {

	container::list<int> l;
	for (auto i = 0; i < 5; i++) {
		l.push_back(i);
	}

	int count = 0;
	for (auto i : l) {
		ASSERT_EQ(i, count);
		count += 1;
	}

	auto ret1 = l.find(3);
	ASSERT_EQ(*ret1, 3);
	*ret1 = 11;
	ASSERT_EQ(l.find(3), l.end());
	ASSERT_EQ(*l.find(11), 11);

	auto ret2 = l.find(10);
	ASSERT_EQ(ret2, l.end());
}

TEST(ListTest, TestMerge) {

	container::list<int> l1;
	l1.push_back(4);
	l1.push_back(11);
	l1.push_back(13);


	container::list<int> l2;
	l2.push_back(1);
	l2.push_back(5);
	l2.push_back(14);

	int arr[6] = { 1,4,5,11,13,14 };
	int count = 0;
	l1.merge(l2);
	for (auto i : l1) {
		ASSERT_EQ(i, arr[count]);
		count += 1;
	}

	ASSERT_EQ(l1.size(), 6);
	ASSERT_EQ(l2.size(), 0);
}

TEST(ListTest, TestMergesort) {


	container::list<int> l1;
	l1.push_back(4);
	l1.push_back(11);
	l1.push_back(13);
	l1.push_back(1);
	l1.push_back(5);
	l1.push_back(14);

	int arr[6] = { 1,4,5,11,13,14 };
	int count = 0;
	l1.sort();
	for (auto i : l1) {
		ASSERT_EQ(i, arr[count]);
		count += 1;
	}

	ASSERT_EQ(l1.size(), 6);
}