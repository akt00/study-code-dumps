#include <algorithm>
#include <bitset>
#include <functional>
#include <iostream>
#include <set>
#include <vector>
using namespace std;


set<unsigned> all_combinations(const vector<unsigned>& v) {
	set<unsigned> s;
	unsigned max_val = 0;
	for (unsigned i = 0; i < v.size(); i++) {
		max_val <<= 1;
		max_val += 1U;
	}
	for (unsigned i = 0; i <= max_val; i++) {
		unsigned tmp = 1;
		unsigned sum = 0;
		for (unsigned j = 0; j < v.size(); j++) {
			if (tmp & i) {
				sum += v[j];
			}
			tmp <<= 1;
		}
		s.insert(sum);
	}
	return s;
}

int main() {

	unsigned n;
	cin >> n;
	vector<unsigned> v;
	for (unsigned i = 0; i < n; i++) {
		unsigned tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	unsigned q;
	cin >> q;
	vector<unsigned> totals;
	for (unsigned i = 0; i < q; i++) {
		unsigned tmp;
		cin >> tmp;
		totals.push_back(tmp);
	}

	set<unsigned> s = all_combinations(v);
	for (unsigned i=0;i<totals.size();i++) {
		if (s.find(totals[i]) != s.end()) {
			cout << "yes" << endl;
		}
		else {
			cout << "no" << endl;
		}
	}
}
