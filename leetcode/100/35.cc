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


int main() {
	int n, w;
	cin >> n >> w;
	vector<pair<int, int>> v;
	for (auto i = 0; i < n; i++) {
		int _v, _w;
		cin >> _v >> _w;
		v.push_back({_v, _w});
	}

	vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
	for (auto i = 0; i < n; i++) {
		for (auto j = 0; j <= w; j++) {
			if (j < v[i].second) {
				dp[i + 1][j] = dp[i][j];
			}
			else {
				dp[i + 1][j] = max(dp[i][j], dp[i][j - v[i].second] + v[i].first);
			}
		}
	}
	cout << dp[dp.size() - 1][dp[0].size() - 1] << endl;
}
