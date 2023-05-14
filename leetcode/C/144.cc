#include<iostream>
#include<cmath>
using namespace std;


int main() {

	int n;
	cin >> n;
	for (auto i = 1; i < 10; i++) {
		for (auto j = 1; j < 10; j++) {
			if (i * j == n) {
				cout << "Yes";
				exit(0);
			}
		}
	}
	cout << "No";
}
