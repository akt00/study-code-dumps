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


int chain(const vector<pair<int, int>>& p) {
	int n = p.size() - 1;
	vector<vector<int>> m(n + 1, vector<int>(n + 1, 0));
	
	for (auto l = 1; l <= n; l++) {
		// cout << l << endl;
		for (auto i = 0; i < n - l + 1; i++) {
			int j = i + l;
			m[i][j] = INT32_MAX;
			// cout << i << " " << j << endl;
			for (auto k = i; k < j; k++) {
				auto lb = i - 1;
				auto p1 = (lb < 0) ? p[0].first : p[lb].second;
				auto q = m[i][k] + m[k + 1][j] + p1 * p[k].second * p[j].second;

				if (q < m[i][j]) m[i][j] = q;
			}
		}
	}
	return m[0][m.size() - 1];
	
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (auto i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		v.push_back({ l, r });
	}

	cout << chain(v) << endl;
}
