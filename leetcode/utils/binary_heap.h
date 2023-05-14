#pragma once


void create_binary_heap(vector<int>& v, bool asc=true) {

	auto size = v.size();
	auto max_heap = [&](int p) {
		int child;
		int parent = p;

		while (true) {
			int l_child = parent * 2 + 1;
			int r_child = l_child + 1;

			if (r_child < size) child = (v[l_child] < v[r_child]) ? r_child : l_child;
			else if (r_child == size) child = v[l_child];
			else break;

			if (v[parent] < v[child]) swap(v[parent], v[child]);
			parent = child;
		}
	};

	auto min_heap = [&](int p) {
		int child;
		int parent = p;

		while (true) {
			int l_child = parent * 2 + 1;
			int r_child = l_child + 1;

			if (r_child < size) child = (v[l_child] < v[r_child]) ? l_child : r_child;
			else if (r_child == size) child = v[l_child];
			else break;

			if (v[parent] > v[child]) swap(v[parent], v[child]);
			parent = child;
		}
	};

	int start = size / 2;
	for (auto i = start; i >= 0; i--) {
		if (asc) min_heap(i);
		else max_heap(i);
	}
}

bool validate(const vector<int>& v, bool asc=true) {
	for (auto i = 0; i < v.size() / 2; i++) {
		int lc = i * 2 + 1;
		int rc = lc + 1;

		if (rc < v.size()) {
			if (asc) {
				if (v[i] > v[lc] || v[i] > v[rc]) return false;
			}
			else {
				if (v[i] < v[lc] ||  v[i] < v[rc]) return false;
			}
		}
		else if (rc == v.size()) {
			if (asc && v[i] > v[lc]) return false;
			else if (v[i] < v[lc]) return false;
		}
		else break;
	}
	return true;
}
