#include "algorithm.h"
#include "utils/utils.h"
#include <cstdlib>
#include <iostream>
using namespace algorithm;
using namespace std;


void insertionSrot(vector<int>& v) {
	
	for (auto i = 1; i < v.size(); i++) {
		auto key = v[i];
		auto j = i;
		while (j > 0) {
			if (v[j] < v[j - 1]) v[j] = v[j - 1];
			else break;
			j--;
		}
		v[j] = key;
	}
}


int main(void) {
	{
		std::vector<int> vec;
		for (auto i = 0; i < 100; i++) {
			vec.push_back((int)i);
		}
		auto copy = vec;
		insertionSrot(copy);
		bool valid = utils::ValidateSortedArray<std::vector<int>, int>(vec, copy, (unsigned)vec.size(), true);
		if (valid) cout << "passed\n";
	}
}
