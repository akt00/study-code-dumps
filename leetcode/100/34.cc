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


int fib(int n) {
	vector<int> v(n, 1);

	for (auto i = 2; i < n; i++) {
		v[i] = v[i - 1] + v[i - 2];
	}
	return v.back();
}

int main() {
	int n;
	cin >> n;
	cout << fib(n+1) << endl;
}
