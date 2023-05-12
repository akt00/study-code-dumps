#ifndef ALGORTIHM_SORT_QUICKSORT
#define ALGORITHM_SORT_QUICKSORT



namespace algorithm::sort {

	// right must be the size - 1 when called first time
	template<typename T>
	void quicksort(std::vector<T>& vec, int left, int right) {

		int pl = left;
		int pr = right;
		int mid = (left + right) / 2;
		int pivot = vec[mid];

		while (pl <= pr) {
			while (vec[pl] < pivot) pl++;
			while (vec[pr] > pivot) pr--;
			if (pl < pr) std::swap(vec[pl++], vec[pr--]);
			else if (pl == pr) pl++, pr--;
		}

		if (left < pr) quicksort(vec, left, pr);
		if (pl < right) quicksort(vec, pl, right);
	}
}

#endif // !ALGORTIHM_SORT_QUICKSORT