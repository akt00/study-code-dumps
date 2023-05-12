#include "pch.h"
#include "../Algorithms/sort/sort.h"
#include "../Algorithms/utils/utils.h"
using namespace algorithm;


TEST(SortTest, TestInsertionsort) {

	// test sorted array in asc
	{
		std::vector<int> vec;
		for (auto i = 0; i < 100; i++) {
			vec.push_back((int)i);
		}
		auto copy = vec;
		sort::insertionsort(copy);
		bool valid = utils::ValidateSortedArray<std::vector<int>, int>(vec, copy, (unsigned)vec.size(), true);
		ASSERT_EQ(valid, true);
	}

	// test randomly generated array in desc
	{
		for (auto i = 0; i < 100; i++) {
			auto vec = utils::GenerateRandomArray<int>((unsigned)rand() % 10000);

			auto copy = vec;
			sort::insertionsort(copy);
			bool valid = utils::ValidateSortedArray<std::vector<int>, int>(vec, copy, (unsigned)vec.size(), true);
			ASSERT_EQ(valid, true);
		}
	}
}

TEST(SortTest, TestQuicksort) {

	// test sorted array in asc
	{
		std::vector<int> vec;
		for (auto i = 0; i < 100; i++) {
			vec.push_back((int) i);
		}
		auto copy = vec;
		sort::quicksort(copy, 0, (int) vec.size() - 1);
		bool valid = utils::ValidateSortedArray<std::vector<int>, int>(vec, copy, (unsigned)vec.size(), true);
		ASSERT_EQ(valid, true);
	}

	// test randomly generated array in desc
	{
		for (auto i = 0; i < 100; i++) {
			auto vec = utils::GenerateRandomArray<int>((unsigned) rand()%10000);

			auto copy = vec;
			sort::quicksort(copy, 0, (unsigned) vec.size() - 1);
			bool valid = utils::ValidateSortedArray<std::vector<int>, int>(vec, copy, (unsigned)vec.size(), true);
			ASSERT_EQ(valid, true);
		}
	}
}

TEST(SortTest, TestHeapsort) {

	// test sorted array in asc
	{
		std::vector<int> vec;
		for (auto i = 0; i < 100; i++) {
			vec.push_back((int)i);
		}
		auto copy = vec;
		sort::heapsort(copy);
		bool valid = utils::ValidateSortedArray<std::vector<int>, int>(vec, copy, (unsigned)vec.size(), true);
		ASSERT_EQ(valid, true);
	}

	// test randomly generated array in desc
	{
		for (auto i = 0; i < 100; i++) {
			auto vec = utils::GenerateRandomArray<int>((unsigned)rand() % 10000);

			auto copy = vec;
			sort::heapsort(copy);
			bool valid = utils::ValidateSortedArray<std::vector<int>, int>(vec, copy, (unsigned)vec.size(), true);
			ASSERT_EQ(valid, true);
		}
	}
}

TEST(SortTest, TestMergesort) {

	// test sorted array in asc
	{
		std::vector<int> vec;
		for (auto i = 0; i < 100; i++) {
			vec.push_back((int)i);
		}
		auto copy = vec;
		sort::mergesort(copy, 0, (int) copy.size() - 1);
		bool valid = utils::ValidateSortedArray<std::vector<int>, int>(vec, copy, (unsigned)vec.size(), true);
		ASSERT_EQ(valid, true);
	}

	// test randomly generated array in desc
	{
		for (auto i = 0; i < 100; i++) {
			auto vec = utils::GenerateRandomArray<int>((unsigned)rand() % 10000);

			auto copy = vec;
			sort::mergesort(copy, 0, (int) copy.size() - 1);
			bool valid = utils::ValidateSortedArray<std::vector<int>, int>(vec, copy, (unsigned)vec.size(), true);
			ASSERT_EQ(valid, true);
		}
	}
}


TEST(SortTest, TestCountingsort) {

	// test sorted array in asc
	{
		std::vector<unsigned> vec;
		for (auto i = 0; i < 100; i++) {
			vec.push_back((int)i);
		}
		auto copy = vec;
		auto max_idx = utils::FindMaxIndex(copy, copy.size());
		sort::countingsort(copy, copy[max_idx]);
		bool valid = utils::ValidateSortedArray<std::vector<unsigned>, int>(vec, copy, (unsigned)vec.size(), true);
		ASSERT_EQ(valid, true);
	}

	// test randomly generated array in desc
	{
		for (auto i = 0; i < 100; i++) {
			auto vec = utils::GenerateRandomArray<unsigned>((unsigned)rand() % 10000);

			auto copy = vec;
			auto max_idx = utils::FindMaxIndex(copy, copy.size());
			sort::countingsort(copy, copy[max_idx]);
			bool valid = utils::ValidateSortedArray<std::vector<unsigned>, int>(vec, copy, (unsigned)vec.size(), true);
			ASSERT_EQ(valid, true);
		}
	}
}