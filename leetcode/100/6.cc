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
// find if 10^3 exists in s, instead of next_permutation

int main() {
	int n;
	string s;
	cin >> n;
	cin >> s;

	int count = 0;

	for (auto i = 0; i < 10; i++) {
		for (auto j = 0; j < 10; j++) {
			for (auto k = 0; k < 10; k++) {
				string p = "";
				p += to_string(i) + to_string(j) + to_string(k);
				bool flag = false;
				
				int idx = 0;
				int p_idx = 0;
				while (idx < s.size()) {
					if (s[idx] == p[p_idx]) {
						p_idx++;
						if (p_idx == p.size()) count++;
					}
					idx++;
				}
			}
		}
	}

	cout << count << endl;
}
