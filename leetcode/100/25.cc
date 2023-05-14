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

void dfs(set<pair<int, int>>& pts, set<pair<int, int>>& visited, pair<int, int> cp) {

	if (pts.find(cp) != pts.end()) {
		pts.erase(cp);
		visited.insert(cp);

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				pair<int, int> np = { cp.first + i, cp.second + j };
				dfs(pts, visited, np);
			}
		}
	}
}

int main() {

	vector<int> outs;
	while (true) {
		int x, y;
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		vector<vector<int>> v;
		set<pair<int, int>> pts;

		for (auto i = 0; i < y; i++) {
			vector<int> row;
			for (auto j = 0; j < x; j++) {
				int e;
				cin >> e;
				row.push_back(e);
				if (e != 0) pts.insert({ j, i });
			}
			v.push_back(row);
		}
		// for (auto i : pts) cout << i.first << ',' << i.second << endl;
		int count = 0;
		set<pair<int, int>> visited;
		while (!pts.empty()) {
			count++;
			auto start = *pts.begin();
			pts.erase(start);
			visited.insert(start);
			// cout << start.first << "," << start.second << endl;

			for (int i = -1; i <= 1; i++) {
				for (int j = -1; j <= 1; j++) {
					pair<int, int> np = { start.first + i, start.second + j };
					// cout << i << "," << j << endl;
					dfs(pts, visited, { start.first + i,start.second + j });
				}
			}
		}
		outs.push_back(count);
	}
	for (auto i : outs) std::cout << i << endl;
}
