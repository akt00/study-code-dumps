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
	int n;
	cin >> n;

	map< int, vector<int> > graph;
	for (int i = 0; i < n; i++) {
		int key, k;
		cin >> key >> k;
		graph.insert({ key, {} });
		for (int j = 0; j < k; j++) {
			int tmp;
			cin >> tmp;
			graph[key].push_back(tmp);
		}
	}

	deque<int> q;
	q.push_back((*graph.begin()).first);
	set<int> s;
	unordered_map<int, int> dist;
	dist.insert({ q.front(), 0 });
	while (!q.empty()) {
		int node = q.front();
		if (node == 0) break;
		q.pop_front();
		s.insert(node);
		// traverse the list
		for (int i : graph[node]) {
			if (dist.find(i) == dist.end()) {
				dist.insert({ i, dist[node] + 1 });
			}
			else if (dist[i] > (dist[node] + 1)) dist[i] = dist[node] + 1;

			if (s.find(i) == s.end()) {
				s.insert(i);
				q.push_back(i);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist.find(i) == dist.end()) {
			cout << i << " " << -1 << endl;
		}
		else {
			cout << i << " " << dist[i] << endl;
		}
	}
}
