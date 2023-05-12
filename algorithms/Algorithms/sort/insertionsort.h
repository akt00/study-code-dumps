#ifndef ALGORITHM_SORT_INSERTIONSORT
#define ALGORITHM_SORT_INSERTIONSORT


namespace algorithm::sort {

	template<typename T>
	void insertionsort(std::vector<T>& vec) {

		for (auto i = 1; i < vec.size(); i++) {
			T key = vec[i];
			auto j = i;
			while (j > 0 && key < vec[j - 1]) {
				vec[j] = vec[j - 1];
				j -= 1;
			}
			vec[j] = key;
		}
	}
}

#endif ALGORITHM_SORT_INSERTIONSORT