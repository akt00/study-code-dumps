#include"pch.h"
#include"../Algorithms/utils/utils.h"
#include<filesystem>
using namespace algorithm;


TEST(UtilsTest, TestFindMinIndex) {

	std::vector<int> vec1 = {1,2,3,4,5};
	ASSERT_EQ(utils::FindMinIndex(vec1, (unsigned) vec1.size()), 0);
	std::vector<int> vec2 = {10, 2, -1, 4, 5};
	ASSERT_EQ(utils::FindMinIndex(vec2, (unsigned) vec2.size()), 2);
	std::vector<int> vec3 = {5, 4, 3, 2, 1};
	ASSERT_EQ(utils::FindMinIndex(vec3, (unsigned) vec3.size()), 4);
}

TEST(UtilsTest, TestFindMaxIndex) {

	std::vector<int> vec1 = { 1,2,3,4,5 };
	ASSERT_EQ(utils::FindMaxIndex(vec1, (unsigned) vec1.size()), 4);
	std::vector<int> vec2 = { 10, 2, -1, 4, 5 };
	ASSERT_EQ(utils::FindMaxIndex(vec2, (unsigned) vec2.size()), 0);
	std::vector<int> vec3 = { 5, 4, 10, 2, 1 };
	ASSERT_EQ(utils::FindMaxIndex(vec3, (unsigned) vec3.size()), 2);
}

TEST(UtilsTest, SequentialSearch) {

	int list[] = { 0,1,2,3,4,5 };

	for (auto i = 0; i < 6; i++) {
		auto index = utils::SequentialSearch(list, 6, i);
		ASSERT_EQ(i, index);
	}
}

TEST(UtilsTest, TestBinarySearch) {

	int list[] = {0,1,2,3,4,5};

	for (auto i = 0; i < 6; i++) {
		auto index = utils::BinarySearch(list, 6, i);
		ASSERT_EQ(i, index);
	}
}

TEST(UtilsTest, TestGenerateRandomArray) {

	auto vec1 = utils::GenerateRandomArray<int>(1000);
	ASSERT_EQ(1000, vec1.size());
}

TEST(UtilsTest, TestGenerateValidateSortedArray) {

	auto sorted = utils::GenerateSortedArray<int>();
	auto flag = utils::ValidateSortedArray<std::vector<int>, int>(sorted, sorted, (unsigned) sorted.size());
	ASSERT_EQ(flag, true);
}

TEST(UtilsTest, TestLoadCSV) {
	
	const char* filepath = "../../Algorithms/data/iris.csv";
	auto ret = std::filesystem::exists(filepath);
	ASSERT_EQ(ret, true);
	auto lines = utils::LoadCSV(filepath);
	std::string first_line("5.1,3.5,1.4,0.2,0");
	ASSERT_EQ(first_line, lines[0]);
	ASSERT_EQ(lines.size(), 150);
}

TEST(UtilsTest, TestParseLinesCSV) {

	const char* filepath = "../../Algorithms/data/iris.csv";
	auto ret = std::filesystem::exists(filepath);
	ASSERT_EQ(ret, true);
	auto lines = utils::LoadCSV(filepath);
	auto parsed_line = utils::ParseLineCSV<float>(lines[0]);
	ASSERT_EQ(parsed_line.size(), 5);
	float first_line[5] = { 5.1f,3.5f,1.4f,0.2f,0.f };
	for (auto i = 0; i < 5; i++) {
		ASSERT_FLOAT_EQ(parsed_line[i], first_line[i]);
	}
}

TEST(UtilsTest, TestLoadIris) {

	const char* filepath = "../../Algorithms/data/iris.csv";
	auto ret = std::filesystem::exists(filepath);
	ASSERT_EQ(ret, true);
	auto dataset = utils::LoadIris(filepath);
	auto features = dataset.first;
	ASSERT_EQ(features.size(), 150);
	ASSERT_EQ(features[0].size(), 4);
	float first_line_feature[4] = { 5.1f,3.5f,1.4f,0.2f };
	for (auto i = 0; i < 4; i++) {
		ASSERT_FLOAT_EQ(features[0][i], first_line_feature[i]);
	}
	auto labels = dataset.second;
	ASSERT_EQ(labels.size(), 150);
	ASSERT_EQ(labels[0], 0);
}

TEST(UtilsTest, TestTranspose2dVector) {

	const char* filepath = "../../Algorithms/data/iris.csv";
	auto ret = std::filesystem::exists(filepath);
	ASSERT_EQ(ret, true);
	auto dataset = utils::LoadIris(filepath);
	auto features = dataset.first;
	ASSERT_EQ(features.size(), 150);
	ASSERT_EQ(features[0].size(), 4);
	auto transposed = utils::Transpose2dVector(features);
	ASSERT_EQ(transposed.size(), 4);
	ASSERT_EQ(transposed[0].size(), 150);
}