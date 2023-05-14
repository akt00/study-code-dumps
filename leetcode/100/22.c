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
#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
using ull = unsigned long long;
using ll = long long;

double calc(double p, double x) {
	return p / pow(2, x / 1.5) + x;
}

void solve_ternary(double p) {
	double lt = 0;
	double rt = p;
	while (abs(rt - lt) > 1e-6) {

		double c1 = (lt * 2 + rt) / 3;
		double c2 = (lt + rt * 2) / 3;
		double lv = calc(p, c1);
		double rv = calc(p, c2);
		if (lv >= rv) lt = c1;
		else rt = c2;
	}
	auto ret = calc(p, lt);
	cout << setprecision(12) << ret << endl;
}

// p / pow(2, x/1.5) + x
int main() {
	double p;
	cin >> p;

	solve_ternary(p);
	

	// gradient method not working for non-smooth functions?
	/*
	auto grad = [&](ll x) {
		return (double)1 - log(2) * 2 * pow(2, -x / 1.5);
	};

	double left = 0, right = p;
	while (abs(right - left) > 1e-6) {
		double mid = (left + right) / 2;
		auto ret = grad(mid);
		if (ret < 0) left = mid;
		else right = mid;
	}
	auto out = calc(p, left);
	if(out < p) cout << setprecision(12) << out << endl;
	else cout << setprecision(12) << p << endl;
	*/
}
