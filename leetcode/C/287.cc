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
using ull = unsigned long long;
using ll = long long;

// Path graph
// undirected graph

/*
* 1. n = e + 1
* 2. adjacent edges <= 2
* 3. all nodes connected
*/

int main() {
	int n, m;
	cin >> n >> m;
	// n = e + 1
	if (n != (m + 1)) {
		cout << "No" << endl;
		return 0;
	}
	vector<vector<int>> v(n+1);

	for (auto i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	// adjacent edges <= 2
	for (auto i : v) {
		if (i.size() > 2) {
			cout << "No" << endl;
			return 0;
		}
	}

	set<int> visited;
	deque<int> q;
	q.push_back(1);
	visited.insert(1);
	// all nodes connected
	while (!q.empty()) {
		auto curr = q.front();
		q.pop_front();

		for (auto i : v[curr]) {
			if (visited.find(i) == visited.end()) {
				visited.insert(i);
				q.push_back(i);
			}
		}
	}

	for (auto i = 1; i <= n; i++) {
		if (visited.find(i) == visited.end()) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}
