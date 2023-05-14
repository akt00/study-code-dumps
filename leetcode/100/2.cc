#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(n+1, 1);

	for (auto i = 2; i <= n; i++) {
		
		int mult = 1;
		while (mult * i <= n) {
			v[mult * i] ++;
			mult++;
		}
	}

	int count = 0;
	for (auto i = 1; i < v.size(); i+=2) {
		if (v[i] == 8)count++;
	}
	cout << count << endl;
}
