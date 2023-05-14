#include <algorithm>
#include <bitset>
#include <cmath>
#include <deque>
#include <exception>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ull = unsigned long long;
using ll = long long;

int main() {
	ll n, m;
	cin >> n >> m;

	vector<ll> v(n);
	for (auto i = 0; i < n; i++) {
		cin >> v[i];
	}

	// sums of two
	v.push_back(0);
	vector<ll> sums = v;
	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j < n; j++) {
			sums.push_back(v[i] + v[j]);
		}
	}

	sort(sums.begin(), sums.end());

	ll max_val = 0;
	for (auto i : sums) {
		ll remainder = m - i;
		if (remainder < 0) continue;
		auto idx = upper_bound(sums.begin(), sums.end(), remainder) - sums.begin() - 1;
		// auto idx = lower_bound(sums.begin(), sums.end(), remainder + 1) - sums.begin() - 1;
		max_val = max(max_val, i + sums[idx]);
	}
	cout << max_val << endl;
}
