#include <algorithm>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using u64 = unsigned long long;

// dfs
bool partial_sum(int idx, const int k, int sum, const vector<int> &v) {
	if (sum == k) return true;

	if (idx < v.size()) {
		if(partial_sum(idx + 1, k, sum, v)) return true;
		if(partial_sum(idx + 1, k, sum+v[idx], v)) return true;
	}
	return false;
}


int main() {
	int n;
	cin >> n;
	vector<int> v;
	for (auto i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int k;
	cin >> k;

	auto ret = partial_sum(0, k, 0, v);
	if (ret) cout << "Yes\n";
	else cout << "No\n";
}
