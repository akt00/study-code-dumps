#ifndef ALGORITHM_SORT_HEAPSORT
#define ALGORITHM_SORT_HEAPSORT


namespace algorithm::sort {

	// create a max heap within the range from parent_node to max_heap_size
	template<typename T>
	void max_heap(std::vector<T>& vec, int parent_node, int max_heap_size) {

		int child;
		int parent = parent_node;

		while (true) {
			int left_child = parent * 2 + 1;
			int right_child = left_child + 1;

			if (right_child < max_heap_size) {
				child = (vec[left_child] < vec[right_child]) ? right_child : left_child;
			}
			// if right child out of heap range
			else if (right_child == max_heap_size) {
				child = left_child;
			}
			// if both children out of heap range
			else break;

			if (vec[parent] < vec[child]) std::swap(vec[parent], vec[child]);
			parent = child;
		}
	}

	template<typename T>
	void heapsort(std::vector<T>& vec) {

		int size = (int) vec.size();
		// create a binary heap
		for (int i = (size - 1) / 2; i >= 0; i--) {
			max_heap(vec, i, size);
		}
		// sort the binary heap in ascending order
		for (int i = (size - 1); i > 0; i--) {
			std::swap(vec[0], vec[i]);
			max_heap(vec, 0, i);
		}
	}
}

#endif // ALGORITHM_SORT_HEAPSORT