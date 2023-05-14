#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
using u64 = unsigned long long;

int main() {
	unsigned n, m;
	cin >> n >> m;
	vector<vector<u64>> mat;
	for (auto i = 0; i < n; i++) {

		vector<u64> row;
		for (auto i = 0; i < m; i++) {
			unsigned tmp;
			cin >> tmp;
			row.push_back(tmp);
		}
		mat.push_back(row);
	}

	u64 max = 0;
	for (auto i = 0; i < m; i++) {
		for (auto j = i; j < m; j++) {
			u64 score = 0;
			for (auto st = 0; st < n; st++) {
				score += std::max(mat[st][i], mat[st][j]);
			}
			max = (max < score) ? score : max;
		}
	}
	cout << max << endl;
}
