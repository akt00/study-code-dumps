#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <string>
//#include <unordered_map>
#include <vector>
using namespace std;
// using u64 = unsigned long long;

vector<string> split(string s, const char delim){
	vector<string> list;
	while (true) {
		size_t pos = s.find(delim);
		if (pos == string::npos) {
			list.push_back(s);
			return list;
		}

		list.push_back(s.substr(0, pos));
		s.erase(0, pos + 1);
	}
}


static int ft = 0;
static int dt = 0;

void dfs(int node, const vector<vector<int>>& graph, set<int>& visited, vector<vector<int>>& outs) {
	dt++;
	// std::cout << "node: " << node << " discovery time: " << dt << std::endl;

	outs[node - 1][0] = node;
	outs[node - 1][1] = dt;
		 
	for (int i = 1; i < graph[node - 1].size(); i++) {
		int next_node = graph[node - 1][i];
		if (next_node == 0) break;
		if (visited.find(next_node) == visited.end()) {
			visited.insert(next_node);
			dfs(next_node, graph, visited, outs);
		}
	}
	dt++;
	ft = (ft < dt) ? dt : ft;
	outs[node - 1][2] = ft;
}

int main() {
	int n;
	cin >> n;
	cin.ignore();
	vector<vector<int>> v;
	for (int i = 0; i < n; i++) {
		string s;
		getline(cin, s);
		vector<string> ret = split(s, ' ');

		vector<int> tmp;
		for (string i : ret) tmp.push_back(stoi(i));
		v.push_back(tmp);
	}

	vector<vector<int>> outs(n, vector<int>(3, 0));
	set<int> visited;
	// travarse the list
	for (vector<int> i : v) {
		int node = i[0];
		if (visited.find(node) == visited.end()) {
			visited.insert(node);
			// travarse the elements in a list
			dfs(node, v, visited, outs);
		}
	}

	for (vector<int> i : outs) {
		for (int j = 0; j < i.size(); j++) {
			if (j == 0) cout << i[j];
			else cout << " " << i[j];
		}
		cout << endl;
	}
}
