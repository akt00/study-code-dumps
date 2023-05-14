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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> v(m, vector<int>{});
	for (auto i = 0; i < m; i++) {
		int k;
		cin >> k;
		for (auto j = 0; j < k; j++) {
			int tmp;
			cin >> tmp;
			v[i].push_back(tmp);
		}
	}
	/*
	for (auto i : v) {
		for (auto j : i) cout << j << " ";
		cout << endl;
	}
	*/
	vector<int> p;
	for (auto i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		p.push_back(tmp);
	}
	/*
	for (auto i : p) cout << i << " ";
	cout << endl;
	*/
	int max_val = pow(2, n) - 1;
	int perms = 0;
	int cur = 0;
	while (cur <= max_val) {
		bool flag = true;
		bitset<10> bs(cur);
		// for each light
		for (auto i = 0; i < v.size();i++) {
			int ons = 0;
			// count how many are on
			for (auto j : v[i]) {
				if (bs[j-1] == 1) ons++;
			}
			// cout << ons << endl;
			// if the light is off
			if (ons % 2 != p[i]) {
				flag = false;
				break;
			}
		}
		if (flag) perms++;
		cur++;
	}
	cout << perms << endl;
}
