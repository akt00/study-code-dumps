#ifndef ALGORITHM_SORT_MERGESORT
#define ALGORITHM_SORT_MERGESORT


namespace algorithm::sort {

	// create a max heap within the range from parent_node to max_heap_size
	template<typename T>
	void merge(std::vector<T>& vec, int left, int mid, int right) {
	
		// store the left values to buffer
		std::vector<T> buffer;
		for (int i = left; i <= mid; i++) buffer.push_back(vec[i]);

		int buffer_counter = 0;
		int vec_counter = mid + 1;
		int merge_counter = left;

		while (buffer_counter < buffer.size() && vec_counter <= right) {
			vec[merge_counter++] = (buffer[buffer_counter] <= vec[vec_counter]) ?
				buffer[buffer_counter++] : vec[vec_counter++];
		}

		while (buffer_counter < buffer.size()) {
			vec[merge_counter++] = buffer[buffer_counter++];
		}
	}

	// right = size - 1
	template<typename T>
	void mergesort(std::vector<T>& vec, int left, int right) {

		if (left < right) {
			int mid = (int)(left + right) / 2;
			mergesort(vec, left, mid);
			mergesort(vec, mid + 1, right);
			// merge left and right
			merge(vec, left, mid, right);
		}
	}
}

#endif // ALGORITHM_SORT_MERGESORT