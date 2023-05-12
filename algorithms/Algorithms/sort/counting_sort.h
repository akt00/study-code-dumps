#ifndef ALGORITHM_SORT_COUNTINGSORT
#define ALGORTIHM_SORT_COUNTINGSORT


namespace algorithm::sort {

	void countingsort(std::vector<unsigned>& vec, unsigned max_value) {

		// index from 0 to max_value
		std::vector<unsigned> counter(max_value + 1, 0);
		
		for (auto i = 0; i < vec.size(); i++) {
			counter[vec[i]]++;
		}

		unsigned index = 0;
		for (auto i = 0; i < counter.size(); i++) {
			while (counter[i] > 0) {
				vec[index++] = static_cast<unsigned>(i);
				counter[i]--;
			}
		}
	}
}

#endif