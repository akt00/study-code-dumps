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

// *there is no height limit. be cautious
int main() {
	ll n;
	cin >> n;
	vector<ll> h(n), s(n);
	for (auto i = 0; i < n; i++) cin >> h[i] >> s[i];

	vector<ll> limits(n);
	// right is closer to int64_max
	ll left = 0, right = 1e14;

	auto check = [&](ll mid) {
		// calculate time limits for each
		for (auto i = 0; i < n; i++) {
			if (mid - h[i] < 0) return false;
			ll limit = (mid - h[i]) / s[i];
			// if (limit < 0) return false;
			limits[i] = limit;
		}

		sort(limits.begin(), limits.end());
		// validate time limits
		for (auto i = 0; i < n; i++) {
			if (i > limits[i]) return false;
		}
		return true;
	};

	while (left < right) {
		ll mid = (left + right) / 2;
		if (check(mid)) right = mid;
		else left = mid + 1;
	}
	cout << left << endl;
}
