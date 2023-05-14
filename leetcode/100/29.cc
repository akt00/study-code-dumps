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

int main() {
	unsigned r, c, sy, sx, gy, gx;
	cin >> r >> c;
	cin >> sy >> sx;
	cin >> gy >> gx;

	vector<vector<char>> v;
	for (auto i = 0; i < r; i++) {
		vector<char> row;
		for (auto j = 0; j < c; j++) {
			char c;
			cin >> c;
			row.push_back(c);
		}
		v.push_back(row);
	}

	const vector<pair<int, int>> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	deque < pair<int, int> > q;
	q.push_back({ sy - 1, sx - 1 });

	set< pair<int, int> > s;
	s.insert({ sy-1, sx-1 });
	vector< vector<int> > dist(r, vector<int>(c, INT32_MAX));
	dist[sy - 1][sx - 1] = 0;
	
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop_front();

		for (auto i : moves) {
			pair<int, int> np = { cur.first + i.first, cur.second + i.second };
			if (np.first < 0 || np.second < 0 || np.first >= r || np.second >= c) continue;
			if (v[np.first][np.second] == '.' &&
				s.find(np) == s.end()) {
				// cout << np.first << "," << np.second << endl;
				if (dist[np.first][np.second] > dist[cur.first][cur.second] + 1) {
					// it's important to insert here to avoid multiple visits
					s.insert({ np.first, np.second });
					dist[np.first][np.second] = dist[cur.first][cur.second] + 1;
				}
				q.push_back(np);
			}
		}
	}
	cout << dist[gy - 1][gx - 1] << endl;
}
