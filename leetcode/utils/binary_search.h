#pragma once

bool bs_loop(const vector<int>& v, int key) {
	int left = 0;
	int right = v.size() - 1;

	while (left < right) {
		int mid = left + right >> 1;
		if (key == v[mid]) return true;
		else if (key < v[mid]) right = mid;
		else left = mid + 1;
	}

	return (key == v[left]);
}

bool bs_recur(const vector<int>& v, int key, int left, int right) {
	if (left <= right) {
		int mid = left + right >> 1;
		if (key == v[mid]) return true;
		if (key < v[mid]) return bs_recur(v, key, left, mid - 1);
		else return bs_recur(v, key, mid + 1, right);
	}
	return false;
}
