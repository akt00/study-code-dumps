#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main() {

	auto check = [](string s, char ch) {
		for (auto i : s) {
			if (i == ch) return true;
		}
		return false;
	};

	string s;
	cin >> s;

	int max = 0;
	int cur = 0;
	for (auto i : s) {
		if (check({ "ACGT" }, i)) cur++;
		else {
			max = (max < cur) ? cur : max;
			cur = 0;
		}
	}
	max = (max < cur) ? cur : max;
	cout << max << endl;
}
