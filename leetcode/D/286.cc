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
using u64 = unsigned long long;
// dynamic programming. bit dp?

int main() {
	int n, x;
	cin >> n >> x;

	vector<pair<int, int>> v;
	for (auto i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a, b });
	}

	vector<vector<int>> dp(n + 1, vector<int>(x+1, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= x; j++) {
			// number of currencies
			for (int k = 0; k <= v[i].second; k++) {
				// if j is equal or bigger than a * k
				int amt = v[i].first * k;
				if (j >= amt) {
					// all muptiples of a is set to true
					// if dp[i][j-amt] is true, then j is expressed with a*k + dp[i][j-amt]
					if (dp[i][j - amt]) dp[i + 1][j] = true;
				}
			}
		}
	}
	/*
	for (auto i : dp) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	*/

	if (dp[n][x]) cout << "Yes" << endl;
	else cout << "No" << endl;
}
