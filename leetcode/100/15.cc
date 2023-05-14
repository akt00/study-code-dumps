#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
using namespace std;


double dist(int x1, int y1, int x2, int y2) {
	int x = std::pow((x1-x2), 2);
	int y = std::pow((y1 - y2), 2);
	return std::sqrt((x + y));
}


int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> v;
	for (auto i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({x, y});
	}
	sort(v.begin(), v.end());
	double total_dist = 0;
	int count = 0;
	while (true) {
		count++;
		for (auto i = 0; i < v.size() - 1; i++) {
			total_dist += dist(v[i].first, v[i].second, v[i + 1].first, v[i + 1].second);
		}
		if (!std::next_permutation(v.begin(), v.end())) break;
	}
	cout << std::setprecision(15) << total_dist / count << endl;
}
