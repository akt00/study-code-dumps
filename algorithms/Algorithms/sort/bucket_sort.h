#ifndef ALGORITHM_SORT_BUCKETSORT
#define ALGORTIHM_SORT_BUCKETSORT

#ifndef ALGORITHM_SORT_INSERTIONSORT
#include "./insertionsort.h"
#endif // !ALGORITHM_SORT_INSERTIONSORT


namespace algorithm::sort {

	// as of now, only positive integers are supported
	template<typename T>
	void bucketsort(std::vector<T>& vec, T max, int key_size) noexcept(false) {
		std::vector<std::vector<int>> bucket(key_size, std::vector<int>(0));

		int size = vec.size();
		int bucket_thresh = (int)max / key_size;
		if (bucket_thresh <= 0) {
			throw std::invalid_argument("key_size is too large");
		}
		for (auto i = 0; i < size; i++) {
			int key_value = (int)vec[i] / bucket_thresh;
			if (key_value < key_size) {
				bucket[key_value].push_back(vec[i]);
			}
			else {
				bucket[key_size - 1].push_back(vec[i]);
			}
		}
		int k = 0;
		for (auto i = 0; i < key_size; i++) {
			int bucket_size = bucket[i].size();
			// sort::insertionsort(bucket[i]);
			int j = 0;
			while (j < bucket_size) {
				vec[k++] = bucket[i][j++];
			}
		}
	}
}

#endif