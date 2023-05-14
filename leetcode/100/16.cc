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
	string p, q;
	string tmp = "";
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		p += tmp;
	}
	for (int i = 0; i < n; i++) {
		char tmp;
		cin >> tmp;
		q += tmp;
	}

	string s = "";
	for (auto i = 1; i <= n; i++) {
		s += to_string(i);
	}
	int count = 1;
	int p_pos = 0, q_pos = 0;
	while (p_pos == 0 || q_pos == 0) {
		if (p == s) p_pos = count;
		if (q == s) q_pos = count;
		count++;
		if (!next_permutation(s.begin(), s.end())) break;
	}
	cout << abs(p_pos - q_pos) << endl;
}
