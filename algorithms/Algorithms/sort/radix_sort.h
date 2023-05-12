#ifndef ALGORITHM_SORT_RADIXSORT
#define ALGORTIHM_SORT_RADIXSORT

namespace algorithm::sort {

	void radixCount(std::vector<int>& vec, int radix) {
		int size = vec.size();
		std::vector<int> output;
		output.resize(size);
		int count[10]{ 0 };

		int i;
		// count the occurrences for each int
		for (i = 0; i < size; i++) {
			count[vec[i] / radix % 10]++;
		}
		// calculate the last position of the group position in output
		for (i = 1; i < 10; i++) {
			count[i] += count[i - 1];
		}
		// 
		for (i = size - 1; i >= 0; i--) {
			output[count[vec[i] / radix % 10] - 1] = vec[i]; // performs radix sort, insert from the last position 
			count[(vec[i] / radix) % 10]--; // reduce the last position by 1
		}
		// copy back to vec
		for (i = 0; i < size; i++) {
			vec[i] = output[i];
		}
	}

	// digits: number of digits of max value
	void radixsort(std::vector<int>& vec, int digits) {

		for (int i = 0; i < digits; i++) {
			int radix = std::pow(10, i);
			std::cout << "radix= " << radix << std::endl;
			radixCount(vec, radix);
		}
	}
}


#endif