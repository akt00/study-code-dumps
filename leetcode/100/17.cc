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

bool check_back_slash(const vector<vector<int>>& v) {

	for (auto i = 0; i < 8; i++) {
		// - axis
		int y = 0, x = i;
		int count = 0;
		while (y < 8 && x < 8) {
			if (v[y][x] != 0) count++;
			if (count > 1) return false;
			y++, x++;
		}
		// | axis
		y = i, x = 0;
		count = 0;
		while (y < 8 && x < 8) {
			if (v[y][x] != 0) count++;
			if (count > 1) return false;
			y++, x++;
		}
	}
	return true;
}

bool check_slash(const vector<vector<int>>& v) {

	for (auto i = 0; i < 8; i++) {
		// _ axis
		int y = 0, x = i;
		int count = 0;
		while (x >= 0 && y < 8) {
			if (v[y][x] != 0) count++;
			if (count > 1) return false;
			y++, x--;
		}
		// | axis
		y = i, x = v.size() - 1;
		count = 0;
		while (x >= 0 && y < 8) {
			if (v[y][x] != 0) count++;
			if (count > 1) return false;
			y++, x--;
		}
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> v(8, vector<int>(8, 0));
	set<int> sx;
	set<int> sy;
	for (auto i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[x][y] = 1;
		sx.insert(x);
		sy.insert(y);
	}

	vector<int> combs;
	for (auto i = 0; i < 8; i++) {
		if (sx.find(i) == sx.end()) combs.push_back(i);
	}

	while (true) {

		auto copy = v;
		auto iter = combs.begin();
		// generate a combination
		for (auto i = 0; i < 8; i++) {
			if (sy.find(i) == sy.end()) {
				copy[*iter][i] = 1;
				iter++;
				if (iter == combs.end()) break;
			}
		}
		if (check_back_slash(copy) && check_slash(copy)) {
			for (auto i : copy) {
				for (auto j : i) {
					if (j == 0) cout << ".";
					else cout << "Q";
				}
				cout << endl;
			}
			return 0;
		}
		if (!next_permutation(combs.begin(), combs.end())) break;
	}
}
