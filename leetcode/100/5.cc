#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
using u64 = unsigned long long;

int main() {
	unsigned a, b, c, x, y;
	cin >> a >> b >> c >> x >> y;
	unsigned sum = 0;

	while (true) {
		if (x > 0 && y > 0) {
			if (a + b > c * 2) sum += c * 2;
			else sum += a + b;
			x--;
			y--;
		}
		else if (x <= 0 && y > 0) {
			if (b > c * 2)  sum += c * 2;
			else sum += b;
			y--;
		}
		else if (x > 0 && y <= 0) {
			if (a > c * 2) sum += c * 2;
			else sum += a;
			x--;
		}
		else break;
	}

	cout << sum << endl;
}
