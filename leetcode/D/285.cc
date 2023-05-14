// BFS or DFS or Disjoint set
// find a cycle in a graph

#include <algorithm>
#include <bitset>
#include <cmath>
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
	unordered_map<string, string> um;
	for (auto i = 0; i < n; i++) {
		string l, r;
		cin >> l >> r;
		um.insert({ l, r });
	}

	set<string> s;
	string current;
	while (!um.empty()) {
		auto tmp = *um.begin();
		current = tmp.first;
		string next = tmp.second;
		s.insert(current);

		while (true) {
			if (s.find(next) != s.end()) {
				cout << "No" << endl;
				return 0;
			}

			um.erase(current);
			if (um.find(next) == um.end()) {
				s.clear();
				break;
			}
			else {
				s.insert(next);
				current = next;
				next = um[current];
			}
		}
	}
	cout << "Yes" << endl;
}
