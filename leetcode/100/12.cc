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
	unordered_map<int, set<int>> um;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		if (um.find(x) == um.end()) um.insert({ x, {y} });
		else um[x].insert(y);

		if (um.find(y) == um.end()) um.insert({ y, {x} });
		else um[y].insert(x);
	}
	/*
	for (auto i : um) {
		cout << i.first << " ";
		for (auto j : i.second) cout << j << " ";
		cout << endl;
	}
	*/

	int max_val = pow(2, n) - 1;
	int cur = max_val;
	int max_rel = 1;
	// try all combinations of politicians
	while (cur > 0) {
		bitset<12> bs(cur);
		vector<int> v;
		for (int i = 0; i < n; i++) {
			if (bs[i] == 1) v.push_back(i + 1);
		}
		/*
		for (auto i : v) std::cout << i << " ";
		std::cout << endl;
		*/

		bool flag = true;
		// for each politician
		for (auto i : v) {
			if (um.find(i) == um.end()) {
				flag = false;
				break;
			}
			else {
				for (auto j : v) {
					if (i!=j && um[i].find(j) == um[i].end()) {
						flag = false;
						break;
					}
				}
			}
		}
		if (flag) {
			if (max_rel < bs.count()) max_rel = bs.count();
		}
		cur--;
	}
	std::cout << max_rel << endl;
}
