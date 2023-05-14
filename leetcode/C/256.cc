#include<iostream>
#include<vector>


int main() {
	using namespace std;
	int h1, h2, h3, w1, w2, w3;
	std::cin >> h1 >> h2 >> h3 >> w1 >> w2 >> w3;

	std::vector<std::vector<int>> mats;
	int count = 0;

	for (auto a = 1; a <= 28; a++) {
		for (auto b = 1; b<=28; b++) {
			for (auto d = 1; d <= 28; d++) {
				for (auto e = 1; e <= 28; e++) {

					int c = h1 - (a + b);
					if (c < 1 || c > 28) continue;

					int f = h2 - (d + e);
					if (f < 1 || f > 28) continue;

					int g = w1 - (a + d);
					if (g < 1 || g > 28) continue;

					int h = w2 - (b + e);
					if (h < 1 || h > 28) continue;

					int i = w3 - (c + f);
					if (i != h3 - (g + h)) continue;
					if (i < 1 || i > 28) continue;

					count++;
				}
			}
		}
	}
	cout << count << endl;
}
