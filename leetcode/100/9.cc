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
	int n1;
	cin >> n1;
	vector<pair<int, int>> v;
	for (auto i = 0; i < n1; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x, y });
	}
	int n2;
	cin >> n2;
	set<pair<int, int>> v2;
	for (auto i = 0; i < n2; i++) {
		int x, y;
		cin >> x >> y;
		v2.insert({ x, y });
	}

	for (auto i : v2) {
		int x = i.first - v[0].first;
		int y = i.second - v[0].second;
		
		bool flag = true;
		for (auto j : v) {
			pair<int, int> trans = { j.first + x, j.second + y };
			if (v2.find(trans) == v2.end()) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << x << " " << y << endl;
			return 0;
		}
	}
}
