#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <vector>
using namespace std;


bool bs(const vector<unsigned>& v, unsigned key, int left, int right) {
	if (left > right) return false;
	else {
		int mid = (left + right) / 2;
		if (key == v[mid]) return true;
		else if (key > v[mid]) return bs(v, key, mid + 1, right);
		else return bs(v, key, left, mid - 1);
	}
}

int main() {
	int n;
	cin >> n;
	vector<unsigned> s;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		s.push_back(tmp);
	}
	int q;
	cin >> q;
	vector<unsigned> t;
	for (int i = 0; i < q; i++) {
		int tmp;
		cin >> tmp;
		t.push_back(tmp);
	}
	int count = 0;
	for (unsigned i = 0; i < t.size(); i++) {
		if (bs(s, t[i], 0, s.size() - 1)) count++;
	}
	cout << count << endl;
}
