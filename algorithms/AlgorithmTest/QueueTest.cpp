#include"pch.h"
#include"../Algorithms/container/queue.h"
using namespace algorithm;


TEST(QueueTest, TestEmpty) {

	container::queue<int> q;
	ASSERT_EQ(q.empty(), true);
	q.push(1);
	ASSERT_EQ(q.empty(), false);
}

TEST(QueueTest, TestInsertion) {

	container::queue<int> q1;
	q1.push(1);
	q1.push(2);
	decltype(q1) q2;
	q2.push(1);
	ASSERT_EQ(q2.size(), 1);
	q2 = q1;
	ASSERT_EQ(q2.size(), 2);
	ASSERT_EQ(q2.front(), 1);
	ASSERT_EQ(q2.back(), 2);


}

TEST(QueueTest, TestBasics) {

	container::queue<int> q;
	ASSERT_EQ(q.size(), 0);
	q.push(1);
	q.push(2);
	q.push(3);
	ASSERT_EQ(q.size(), 3);
	ASSERT_EQ(q.front(), 1);
	auto& front = q.front();
	ASSERT_EQ(q.back(), 3);
	auto& back = q.back();
	ASSERT_EQ(q.back(), 3);

	auto q_copy(q);
	ASSERT_EQ(q_copy.size(), q.size());
	ASSERT_EQ(q.size(), 3);
	q.pop();
	ASSERT_EQ(q.size(), 2);
	q.clear();
	ASSERT_EQ(q.size(), 0);
}

TEST(QueueTest, TestSwap) {

	container::queue<int> q1;
	q1.push(1);
	decltype(q1) q2;
	q2.push(11);
	q2.push(12);
	ASSERT_EQ(q1.size(), 1);
	ASSERT_EQ(q2.size(), 2);

	q1.swap(q2);
	ASSERT_EQ(q1.size(), 2);
	ASSERT_EQ(q2.size(), 1);

	ASSERT_EQ(q1.front(), 11);
	ASSERT_EQ(q1.back(), 12);
	q1.pop();
	ASSERT_EQ(q1.front(), 12);

	ASSERT_EQ(q2.front(), 1);
	q2.pop();
	q2.pop();
	q2.pop();
	ASSERT_EQ(q2.size(), 0);
}