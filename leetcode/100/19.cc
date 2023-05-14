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
using u64 = unsigned long long;
static int g;
int bs(const vector<int>& stores, int key, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		if (key == stores[mid]) return 0;
		else if (key > stores[mid]) return bs(stores, key, mid + 1, right);
		else return bs(stores, key, left, mid - 1);
	}
	else if (left >= right) {
		int mid = (left + right) / 2;
		if (key == stores[mid]) return 0;
		else if (key < stores[mid]) {
			return min(abs(key - stores[mid - 1]), abs(key - stores[mid]));
		}
		else {
			if (mid == (stores.size() - 1)) {
				return min(abs(key - stores[mid]), abs(g - key));
			}
			else {
				return min(abs(stores[mid] - key), abs(stores[mid + 1] - key));
			}
		}
	}
	// else throw exception("bs: out of bound error");
	else return -1;
}

int main() {
	int d, n, m;
	cin >> d;
	g = d;
	cin >> n;
	cin >> m;

	vector<int> stores(1, 0), dests;
	for (auto i = 0; i < n-1; i++) {
		int tmp;
		cin >> tmp;
		stores.push_back(tmp);
	}
	sort(stores.begin(), stores.end());
	/*
	for (auto i : stores) cout << i << " ";
	cout << endl;
	*/
	for (auto i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		dests.push_back(tmp);
	}
	//cout << bs(stores, 6, 0, stores.size() - 1);
	u64 total = 0;
	for (auto i : dests) {
		total += bs(stores, i, 0, stores.size() - 1);
	}
	cout << total << endl;
}
