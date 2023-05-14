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


int cost(const vector<bitset<10000>>& v, int m) {
	int n = v.size();
	int cost = 0;
	for (auto i = 0; i < m; i++) {
		int heads = 0;
		for (auto j = 0; j < n; j++) {
			if (v[j][i] == 1) heads++;
		}
		cost += min(n - heads, heads);
	}
	return cost;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<bitset<10000>> v;
	for (int i = 0; i < n; i++) {
		bitset<10000> b;
		for (int j = 0; j < m; j++) {
			int tmp;
			cin >> tmp;
			b[j] = tmp;
		}
		v.push_back(b);
	}

	int cur = 0;
	int max_val = pow(2, n) - 1;
	int min_c = n * m;
	while (cur <= max_val) {
		bitset<10> bs(cur);
		auto copy = v;

		for (auto i = 0; i < n; i++) {
			if (bs[i] == 1) copy[i].flip();
		}

		auto c = cost(copy, m);

		if (c < min_c) min_c = c;

		cur++;
	}

	// cout << cost(v, m) << endl;
	cout << (n*m) - min_c << endl;
}
