#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using u64 = unsigned long long;


u64 find_highest(const vector<u64>& v, int idx) {
	u64 highest = v[0];
	for (auto i = 1; i < idx; i++) {
		if (highest < v[i]) highest = v[i];
	}
	return highest;
}


int main() {
	int n, k;
	cin >> n >> k;

	vector<u64> v;
	for (auto i = 0; i < n; i++) {
		u64 tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	u64 cur = 0;
	u64 max_val = pow(2, n) - 1;
	u64 min_cost = UINT64_MAX;
	while (cur <= max_val) {
		bitset<15> bs(cur);
		cur++;
		if (bs.count() != k) continue;
		// cout << bs.count() << endl;
		auto copy = v;
		u64 tmp_min = 0;
		// u64 h = 0;
		for (auto i = 0; i < n; i++) {
			if (bs[i] == 1) {
				auto h = find_highest(copy, i);
        // be careful to not override the h when i == 0
				if (i!=0 && h >= copy[i]) {
					tmp_min += (h + 1) - copy[i];
					copy[i] = h + 1;
				}
			}
		}
		if (tmp_min < min_cost) min_cost = tmp_min;
	}
	cout << min_cost << endl;
}


