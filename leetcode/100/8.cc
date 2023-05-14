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
// find if 10^3 exists in s, instead of next_permutation
// least square, median value is minimul
int main() {
	int n;
	cin >> n;
	vector<u64> a, b;
	for (auto i = 0; i < n; i++) {
		u64 x, y;
		cin >> x >> y;
		a.push_back(x);
		b.push_back(y);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	u64 s = a[(0 + a.size()) / 2];
	u64 t = b[(0 + b.size()) / 2];
	// cout << s << " " << t << endl;
	u64 total = 0;
	for (auto i = 0; i < n; i++) {
		total += abs((int64_t)(a[i] - s));
		total += abs((int64_t)(a[i] - b[i]));
		total += abs((int64_t)(b[i] - t));
	}
	cout << total << endl;

}
